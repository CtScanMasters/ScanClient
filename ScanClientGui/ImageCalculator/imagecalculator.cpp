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
    image.fill(qRgb(0,0,0));

    quint16 imageWidth = image.width();
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

                for(int k = 0; k < imageWidth; k++)
                {

                    x = k;

                    a1 = (((source * m_sourceDistance) + m_sensorOffset) - (((sensor * m_sensorDistance) + m_sensorOffset) - (0.5 * m_sensorDistance))) / imageWidth;
                    b1 = ((sensor * m_sensorDistance) + m_sensorOffset) - (0.5 * m_sensorDistance);

                    a2 = (((source * m_sourceDistance) + m_sensorOffset) - (((sensor * m_sensorDistance) + m_sensorOffset) + (0.5 * m_sensorDistance))) / imageWidth;
                    b2 = ((sensor * m_sensorDistance) + m_sensorOffset)  + (0.5 * m_sensorDistance);

                    y1 = (quint16)(a1 * x + b1);
                    y2 = (quint16)(a2 * x + b2);

                    for(int k = 0; k < (y2 - y1); k++)
                    {
                        QColor color1 = image.pixelColor(y1 + k, x);
                        QColor color2 = qRgb(sensorIntensityList.at(sensor),sensorIntensityList.at(sensor),sensorIntensityList.at(sensor));
                        image.setPixelColor(y1 + k, x, calculateColorSum(color1, color2));
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
    quint16 imageWidth = image.width();
    quint16 imageHeight = image.height();
    QTransform rotationMatrix;
    quint16 rotationalOffset = getRotationOffset(rotationAngle, imageWidth);

    rotationMatrix.rotate(rotationAngle);
    image = image.transformed(rotationMatrix);
    imageWidth = image.width();
    imageHeight = image.height();

    quint16 offset = m_pixelWidth / 2;

    for(int x = 0; x < imageWidth; x++)
    {
        for(int y = 0; y < imageHeight ; y++)
        {
            QColor color1 = image.pixelColor(x, y);
            QColor color2 = destinationImage.pixelColor((x + offset) - rotationalOffset , (y + offset) - rotationalOffset);

            destinationImage.setPixelColor((x + offset) - rotationalOffset, (y + offset) - rotationalOffset, calculateColorSum(color1, color2));
        }
    }
}

QColor ImageCalculator::calculateColorSum(QColor color1, QColor color2)
{
    int r1 = 0;
    int g1 = 0;
    int b1 = 0;
    int a1 = 0;

    int r2 = 0;
    int g2 = 0;
    int b2 = 0;
    int a2 = 0;

    color1.getRgb(&r1, &g1, &b1, &a1);
    color2.getRgb(&r2, &g2, &b2, &a2);

    r1 += r2;
    g1 += g2;
    b1 += b2;

    if(r1 > 255)
        r1 = 255;
    if(g1 > 255)
        g1 = 255;
    if(b1 > 255)
        b1 = 255;

    QColor color;
    color.setRgb(r1, g1, b1);

    return(color);
}
