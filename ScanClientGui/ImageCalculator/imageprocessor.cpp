#include "imageprocessor.h"
#include <QDebug>
#include <QCoreApplication>
#include <QDir>
#include <QPainter>
#include <QDateTime>

ImageProcessor::ImageProcessor()
{
    m_imageSize             = 0;
    m_numberOfScansPerArray = 0;
    m_scanDataOffset        = 0;
    m_arrayDataSize         = 0;
    m_scanCount             = 0;
    m_arrayNumber           = 0;
    m_imageWidthDivider     = 0;
    m_numberOfSensors       = 0;
    m_innerDiameter         = 0;
    m_outerdiameter         = 0;
}


void ImageProcessor::setPresets(quint16 numberOfscansPerArray, quint16 arrayDataSize, quint16 imageSize)
{
    m_numberOfScansPerArray = numberOfscansPerArray;
    m_arrayDataSize = arrayDataSize;
    m_scanDataOffset = m_numberOfScansPerArray * m_arrayDataSize;
    m_imageSize = imageSize;    //Image resolution
    m_imageWidthDivider = 2;    //Result image resolution
    m_numberOfSensors = 8;      //Sensor in array
    m_innerDiameter = 70;
    m_outerdiameter = 140;

    m_imageCalculator.setDimensions(m_numberOfSensors, m_imageSize, m_innerDiameter, m_outerdiameter);
}

QImage ImageProcessor::processData(QVector<quint16> *scanData, quint16 scanNumber)
{
    m_scanDataVector = scanData;

    createSumImage();

    for(int i = 0; i < 8; i++)
    {
        createArrayImage();
        createArraySenseList(i, 128);
        createArraySumImage(i);
        clearArrayImage();
        createScanSumImage(i);
    }

//    m_imageCalculator.thresHoldImage(m_sumImage);

    QString imageTag;
    QDateTime dateTime;
    dateTime = QDateTime::currentDateTime();
    imageTag.append(dateTime.toString("yyyy-MM-dd hh:mm:ss"));
    imageTag.append(QString(" - scan: %1").arg(scanNumber,3,10, QChar('0')));

    QPainter p;
    p.begin(&m_sumImage);
    p.setPen(QPen(Qt::white, 2));
    p.setFont(QFont("Times", 8, QFont::Bold));
    p.drawText(20,20,imageTag);
    p.drawEllipse(72,72,240,240);
    p.end();

    clearSumImage();

    return(m_sumImage);
}

void ImageProcessor::createArraySenseList(quint16 arrayNumber, quint16 contrast)
{
    for(int source = 0; source < m_numberOfScansPerArray; source++)
    {
        for(int sensor = 3; sensor < m_arrayDataSize; sensor++)
        {
            m_sensorValueVector.append((quint16)((double)((m_scanDataVector->
                    at(source * m_arrayDataSize + (arrayNumber * m_scanDataOffset) + sensor)
                                           / contrast) + 0.5 )));

        }
        calculateScanBeams(source);
        m_sensorValueVector.clear();
    }
}

void ImageProcessor::calculateScanBeams(quint16 source)
{

    m_imageCalculator.calculateBeam(m_sensorValueVector, 0x0001 << m_scanDataVector->
                                  at(source * m_arrayDataSize + 2), *m_imageVector.at(source));

}

void ImageProcessor::createArraySumImage(quint16 arrayNumber)
{
    for(int i = 0; i < 8; i++)
    {

        m_imageCalculator.mergeImages(*m_imageVector.at(i), 0.0, *m_sumImageVector.at(arrayNumber));

        QPainter p;
        QPen pen;

        pen.setColor(Qt::white);
        p.begin(m_sumImageVector.at(arrayNumber));
        p.setPen(pen);
        p.setFont(QFont("Times", 8, QFont::Bold));
        p.drawText(10,128,QString::number(arrayNumber));

        pen.setColor(qRgb(205,205,205));
        p.setPen(pen);
        p.drawRect(5,5,245,245);
        p.end();
    }
}

void ImageProcessor::createScanSumImage(quint16 arrayNumber)
{
    m_imageCalculator.mergeImages(*m_sumImageVector.at(arrayNumber), arrayNumber * 22.5, m_sumImage);
}

void ImageProcessor::createSumImage()
{   
    for(int i = 0; i < m_numberOfScansPerArray; i++)
    {
        m_sumImageVector.append(new QImage(m_imageSize, m_imageSize, QImage::Format_Grayscale8));
        m_sumImageVector.at(i)->fill(qRgb(0,0,0));
    }

    m_sumImage = QImage(m_imageSize  + (m_imageSize / m_imageWidthDivider), m_imageSize +
                            (m_imageSize / m_imageWidthDivider), QImage::Format_Grayscale8);
    m_sumImage.fill(qRgb(0,0,0));
}
void ImageProcessor::clearSumImage()
{
    for(int i = 0; i < m_sumImageVector.size(); i++)
    {
        delete m_sumImageVector.at(i);
    }

    m_sumImageVector.clear();
}
void ImageProcessor::createArrayImage()
{
    for(int i = 0; i < m_numberOfScansPerArray; i++)
    {
        m_imageVector.append(new QImage(m_imageSize, m_imageSize, QImage::Format_Grayscale8));
        m_imageVector.at(i)->fill(qRgb(0,0,0));
    }
}
void ImageProcessor::clearArrayImage()
{
    for(int i = 0; i < m_imageVector.size(); i++)
    {
        delete m_imageVector.at(i);
    }

    m_imageVector.clear();
}

