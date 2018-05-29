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
        QImage processData(QVector<quint16> *scanData, quint16 scanNumber);


    public slots:

    private:
        QString m_logName;
        void createArraySenseList(quint16 arrayNumber, quint16 contrast);
        void calculateScanBeams(quint16 source);
        void createArraySumImage(quint16 arrayNumber);
        void createScanSumImage(quint16 arrayNumber);
        void createSumImage();
        void clearSumImage();
        void createArrayImage();
        void clearArrayImage();

        QVector<quint16> *m_scanDataVector;
        QVector<QImage* > m_imageVector;
        QVector<QImage* > m_sumImageVector;
        QVector<quint16> m_sensorValueVector;
        QImage m_sumImage;
        ImageCalculator m_imageCalculator;
        quint32 m_imageSize;
        quint16 m_numberOfScansPerArray;
        quint16 m_scanDataOffset;
        quint16 m_arrayDataSize;
        quint16 m_scanCount;
        quint16 m_arrayNumber;
        quint16 m_imageWidthDivider;
        quint8 m_numberOfSensors;
        double m_innerDiameter;
        double m_outerdiameter;


		
	private slots:

	signals:


};

#endif // IMAGEPROCESSOR_H
