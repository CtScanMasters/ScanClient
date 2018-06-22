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
    void thresHoldImage(QImage &image);

private:
    QString m_logName;
    bool m_dimensionsSet;
    double m_numberOfSensors;
    double m_numberOfSources;
    double m_sensorDistance;
    double m_sourceDistance;
    double m_sensorOffset;
    double m_pixelWidth;
    double m_pixelWidthSum;
    double m_innerDiameter;
    double m_outerDiamter;

    double m_diameterRatio;
    double m_virtualCanvasSize;
    double m_xOffset;
    double m_yOffset;

    QColor calculateColorSum(QColor &color1, QColor &color2);
    quint32 getRotationOffset(double angle, double imageWidth);

};

#endif // IMAGECALCULATOR_H
