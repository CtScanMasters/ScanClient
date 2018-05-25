#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <QObject>
#include <QVector>
#include <QImage>

#include "imagecalculator.h"


class ImageProcessor : public QObject
{
    Q_OBJECT

    public:
        ImageProcessor();
        void setPresets(quint16 numberOfscansPerArray, quint16 arrayDataSize, quint16 imageSize);
        QImage processData(QVector<QVector<quint16>> *scanData);


    public slots:

    private:
        void createImageBuffers();
        void createArraySenseList(quint16 arrayNumber, quint16 contrast);
        void calculateScanBeams(quint16 source);
        void createArraySumImage();
        void createScanSumImage();
        void clearData();

        QVector<QVector<quint16>> *m_scanDataVector;
        QVector<QImage* > m_imageVector;
        QVector<quint16> m_sensorValueVector;
        QImage m_sumImage;
        ImageCalculator m_imageCalculator;
        quint16 m_imageSize;
        quint16 m_numberOfScansPerArray;
        quint16 m_scanDataOffset;
        quint16 m_arrayDataSize;
        quint16 m_scanCount;
        quint16 m_scanNumber;
        quint16 m_arrayNumber;
        quint16 m_imageWidthDivider;
        quint16 m_numberOfSensors;
        quint16 m_innerDiameter;
        quint16 m_outerdiameter;


		
	private slots:

	signals:


};

#endif // IMAGEPROCESSOR_H
