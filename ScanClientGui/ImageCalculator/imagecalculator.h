#ifndef IMAGECALCULATOR_H
#define IMAGECALCULATOR_H

#include <QTransform>
#include <QImage>

class ImageCalculator
{
public:
    ImageCalculator();
    void setDimensions(quint8 numberOfSensors, quint32 pixelWidth, double innerDiameter, double outerDiamter);
    void calculateBeam(QVector<quint16> sensorIntensityList, quint16 sourceMask, QImage &image);
    void mergeImages(QImage &image, double angle, QImage &destinationImage);
    double getLinearFunction(double a, double X, double b);

private:
    QString m_logName;
    bool m_dimensionsSet;
    quint16 m_numberOfSensors;
    quint16 m_numberOfSources;
    quint16 m_sensorDistance;
    quint16 m_sourceDistance;
    quint16 m_sensorOffset;
    quint32 m_pixelWidth;
    quint32 m_pixelWidthSum;
    double m_innerDiameter;
    double m_outerDiamter;

    double m_diameterRatio;
    quint32 m_virtualCanvasSize;
    quint32 m_xOffset;
    quint32 m_yOffset;

    QColor calculateColorSum(QColor &color1, QColor &color2);
    quint32 getRotationOffset(double angle, double imageWidth);

};

#endif // IMAGECALCULATOR_H
