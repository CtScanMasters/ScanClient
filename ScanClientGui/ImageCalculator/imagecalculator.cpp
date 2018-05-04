#include "imagecalculator.h"
#include <QDebug>
#include <QtMath>
#include <QPainter>

ImageCalculator::ImageCalculator()
{
    m_dimensionsSet = false;
}


void ImageCalculator::setDimensions(quint8 numberOfSensors, quint16 pixelWidth, quint16 innerDiameter, quint16 outerDiamter)
{
    m_numberOfSensors = numberOfSensors;
    m_numberOfSources = m_numberOfSensors;
    m_pixelWidth = pixelWidth;
    m_innerDiameter = innerDiameter;
    m_outerDiamter = outerDiamter;

    double angleAlpha = (M_PI / 180) * 22.5;

    m_pixelWidthSum = (quint16)((double)(pixelWidth * 2));
    m_arrayWidth = (quint16)( ( ( ( (double)m_pixelWidth / 2.0) * qTan(angleAlpha) + 0.5) * 2));
    m_sensorDistance = (quint16)((double)(m_arrayWidth / numberOfSensors) + 0.5);
    m_sourceDistance = m_sensorDistance;
    m_sensorOffset = (quint16)(double)( ( (m_pixelWidth - (m_sensorDistance * (m_numberOfSensors - 1))) + 0.5) / 2);

    m_dimensionsSet = true;
}

void ImageCalculator::calculateBeam(QList<quint16> sensorIntensityList, quint16 sourceMask, QImage &image)
{
    quint16 offset = (quint16)((double)((m_pixelWidth / 3) + 0.5));
    quint8 source = 0;
    quint16 x = 0;
    quint16 y1 = 0;
    double a1 = 0;
    double b1 = 0;
    quint16 y2 = 0;
    double a2 = 0;
    double b2 = 0;


    for(int i = 0; i < m_numberOfSources; i++)
    {
        if((sourceMask >> i) & 0x0001)
        {
            source = i;

            for(int j = 0; j < 8; j++)
            {
                quint16 sensor = j;

                for(int k = offset; k < m_pixelWidth - offset; k++)
                {
                    x = k;

                    a1 = (((source * m_sourceDistance) + m_sensorOffset) - (((sensor * m_sensorDistance) + m_sensorOffset) - (0.5 * m_sensorDistance))) / m_pixelWidth;
                    b1 = ((sensor * m_sensorDistance) + m_sensorOffset) - (0.5 * m_sensorDistance);

                    a2 = (((source * m_sourceDistance) + m_sensorOffset) - (((sensor * m_sensorDistance) + m_sensorOffset) + (0.5 * m_sensorDistance))) / m_pixelWidth;
                    b2 = ((sensor * m_sensorDistance) + m_sensorOffset)  + (0.5 * m_sensorDistance);

                    y1 = (quint16)(a1 * x + b1);
                    y2 = (quint16)(a2 * x + b2);

                    for(int l = 0; l < (y2 - y1); l++)
                    {
                        QColor color2 = qRgb(sensorIntensityList.at(sensor),sensorIntensityList.at(sensor),sensorIntensityList.at(sensor));
                        image.setPixelColor(y1 + l, x, color2);
                    }
                }
            }
        }
    }
}

quint16 ImageCalculator::getRotationOffset(double angle, double imageWidth)
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
    quint8 offsetFactor = 32;

    rotationMatrix.rotate(rotationAngle);
    image = image.transformed(rotationMatrix);

    quint16 centerOffset = (destinationImage.width() - m_pixelWidth) / 2;    //Make sure source image is placed in middel of destination image
    quint16 offset = (quint16)((double)((m_pixelWidth / offsetFactor) + 0.5));

    for(int x = offset * (offsetFactor / 4); x < m_pixelWidth - (offset * (offsetFactor / 16)); x++)
    {
        for(int y = offset * (offsetFactor / 4); y < m_pixelWidth - (offset * (offsetFactor / 16)); y++)
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

    //Only one value is important RGB will all raise with same value when using grayscal
    int r1 = color1.red();
    int r2 = color2.red();

    r1 += r2;

    if(r1 > 255)
        r1 = 255;

    return(QColor(r1, r1, r1));
}
