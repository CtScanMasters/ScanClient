#include "imagecalculator.h"
#include <QDebug>
#include <QtMath>
#include <QPainter>

ImageCalculator::ImageCalculator()
{

}

void ImageCalculator::setDimensions(quint8 numberOfSensors, quint32 pixelWidth, double innerDiameter, double outerDiamter)
{    
    m_numberOfSensors = numberOfSensors;
    m_numberOfSources = m_numberOfSensors;
    m_pixelWidth = pixelWidth;
    m_innerDiameter = innerDiameter;
    m_outerDiamter = outerDiamter;

    m_diameterRatio = m_outerDiamter / m_innerDiameter;
    m_virtualCanvasSize = (quint32)((double)(m_pixelWidth * m_diameterRatio));                   //Virtual canvas is made bigger, we are only interested in inner diameter
    m_xOffset = (quint32)(((double)m_virtualCanvasSize - m_pixelWidth) / 4) + 0.5;            //Move centre point in X direction
    m_yOffset = m_xOffset;                                                                  //Inner diameter is a circle so no need for different yOffset
    m_sensorDistance = (quint16)((double)(m_pixelWidth / (numberOfSensors +1)) + 0.5);
    m_sourceDistance = m_sensorDistance;

    m_dimensionsSet = true;
}

void ImageCalculator::calculateBeam(QVector<quint16> sensorIntensityList, quint16 sourceMask, QImage &image)
{
    quint32 y1 = 0;
    double a1 = 0;
    double b1 = 0;
    quint32 y2 = 0;
    double a2 = 0;
    double b2 = 0;

    for(quint16 sourceIterator = 0; sourceIterator < m_numberOfSources; sourceIterator++)
    {
        quint16 source = sourceIterator + 1;

        if((sourceMask >> sourceIterator) & 0x0001)
        {
            for(quint16 sensorIterator = 0; sensorIterator < m_numberOfSensors; sensorIterator++)
            {
                quint16 sensor = sensorIterator + 1;

                for(quint32 x = 0; x < m_pixelWidth; x++)
                {
                    a1 = (((source * m_sourceDistance)) - (((sensor * m_sensorDistance)) - (0.5 * m_sensorDistance))) / m_virtualCanvasSize;
                    b1 = ((sensor * m_sensorDistance)) - (0.5 * m_sensorDistance);

                    a2 = (((source * m_sourceDistance)) - (((sensor * m_sensorDistance)) + (0.5 * m_sensorDistance))) / m_virtualCanvasSize;
                    b2 = ((sensor * m_sensorDistance))  + (0.5 * m_sensorDistance);

                    y1 = (quint32)((a1 * (x + m_xOffset) + b1) + 0.5);  //y = ax + b;
                    y2 = (quint32)((a2 * (x + m_xOffset) + b2) + 0.5);

                    for(quint32 y = y1; y < y2; y++)
                    {
                        QColor color = qRgb(sensorIntensityList.at(sensorIterator),sensorIntensityList.at(sensorIterator),sensorIntensityList.at(sensorIterator));
                        image.setPixelColor(x, y, color);
                    }
                }
            }
        }
    }
}

quint32 ImageCalculator::getRotationOffset(double angle, double imageWidth)
{

    if(angle > 90)
        angle -= 90;

    angle = (M_PI / 180) * angle;
    double offset = (qSin((M_PI / 4) + angle) * qSqrt(2) * (imageWidth / 2)) - (imageWidth / 2);

    offset += 0.5;

    return((quint16)offset);

}

void ImageCalculator::mergeImages(QImage &image, double angle, QImage &destinationImage)
{        
    quint16 rotationAngle = (quint16)(angle + 0.5);
    QTransform rotationMatrix;
    quint16 rotationalOffset = getRotationOffset(rotationAngle, m_pixelWidth);

    rotationMatrix.rotate(rotationAngle);
    image = image.transformed(rotationMatrix);
    quint16 imageWidth = image.width(); //After matrix transform image width has increased;

    quint16 centerOffset = (destinationImage.width() - m_pixelWidth) / 2;    //Make sure source image is placed in middel of destination image

    for(int x = 0; x < imageWidth - 1; x++)
    {
        for(int y = 0; y < imageWidth - 1; y++)
        {
            QColor color1 = image.pixelColor(x, y);
            if(color1.red() != 0)
            {
                QColor color2 = destinationImage.pixelColor((x + centerOffset) - rotationalOffset , (y + centerOffset) - rotationalOffset);
                destinationImage.setPixelColor((x + centerOffset) - rotationalOffset, (y + centerOffset) - rotationalOffset, calculateColorSum(color1, color2));
            }            
        }
    }
}

QColor ImageCalculator::calculateColorSum(QColor &color1, QColor &color2)
{

    //Only one value is important RGB will all raise
    //with same value when using grayscale
    int r1 = color1.red();
    int r2 = color2.red();

    r1 += r2;

    if(r1 > 255)
        r1 = 255;

    return(QColor(r1, r1, r1));
}

void ImageCalculator::thresHoldImage(QImage &image)
{
    for(int x = 0; x < image.width(); x++)
    {
        for(int y = 0; y < image.height(); y++)
        {
            QColor color1 = image.pixelColor(x, y);
            if(color1.red() < 200)
            {
                image.setPixelColor(x ,y, qRgb(0,0,0));
            }

        }
    }
}
