#ifndef IMAGECALCULATOR_H
#define IMAGECALCULATOR_H

#include <QTransform>
#include <QImage>


class ImageCalculator
{
public:
    ImageCalculator();
    void setDimensions(quint8 numberOfSensors, quint16 pixelWidth, quint16 innerDiameter, quint16 outerDiamter);
    void calculateBeam(QList<quint16> sensorIntensityList, quint16 sourceMask, QImage &image);
    void mergeImages(QImage &image, double angle, QImage &destinationImage);

private:
    bool m_dimensionsSet;
    quint8 m_numberOfSensors;
    quint8 m_numberOfSources;
    quint8 m_sensorDistance;
    quint8 m_sourceDistance;
    quint8 m_sensorOffset;
    quint16 m_pixelWidth;
    quint16 m_pixelWidthSum;
    quint16 m_arrayWidth;
    quint16 m_innerDiameter;
    quint16 m_outerDiamter;

    QColor calculateColorSum(QColor color1, QColor color2);
    quint16 getRotationOffset(double angle, double imageWidth);

};

#endif // IMAGECALCULATOR_H
