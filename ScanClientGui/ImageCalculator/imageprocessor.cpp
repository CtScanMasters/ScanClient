#include "imageprocessor.h"
#include <QDebug>
#include <QCoreApplication>
#include <QDir>

ImageProcessor::ImageProcessor()
{

    m_imageSize             = 0;
    m_numberOfScansPerArray = 0;
    m_scanDataOffset        = 0;
    m_arrayDataSize         = 0;
    m_scanCount             = 0;
    m_scanNumber            = 0;
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
    m_scanNumber = 1;
    m_imageSize = imageSize;    //Image resolution
    m_imageWidthDivider = 2;    //Result image resolution
    m_numberOfSensors = 8;      //Sensor in array
    m_innerDiameter = 70;
    m_outerdiameter = 140;

    m_imageCalculator.setDimensions(m_numberOfSensors, m_imageSize, m_innerDiameter, m_outerdiameter);
}

QImage ImageProcessor::processData(QVector<QVector<quint16>> *scanData)
{
    m_scanDataVector = scanData;

    createImageBuffers();
    createArraySenseList(0, 64);
    createArraySumImage();

    QString filepath;

    for(int i = 0; i < 1000; i++)
    {
        filepath = QCoreApplication::applicationDirPath()
                            + QString("/IMG%1/")
                                .arg(i,3,10, QChar('0'));


        if(!QDir(filepath).exists() && (i < 999))
        {
            QDir().mkdir(filepath);
            break;
        }
        if(i > 999)
        {
            qWarning() << "all foldernames occupied";
            break;
        }
    }

    m_sumImage.save(filepath + "sum.png");

    return(m_sumImage);
}

void ImageProcessor::createImageBuffers()
{

    for(int i = 0; i < m_numberOfScansPerArray; i++)
    {
        m_imageVector.append(new QImage(m_imageSize, m_imageSize, QImage::Format_Grayscale8));
        m_imageVector.at(i)->fill(qRgb(0,0,0));
    }


    m_sumImage = QImage(m_imageSize  + (m_imageSize / m_imageWidthDivider), m_imageSize +
                            (m_imageSize / m_imageWidthDivider), QImage::Format_Grayscale8);
    m_sumImage.fill(qRgb(0,0,0));
}

void ImageProcessor::createArraySenseList(quint16 arrayNumber, quint16 contrast)
{

    for(int source = 0; source < m_numberOfScansPerArray; source++)
    {
        for(int sensor = 3; sensor < m_arrayDataSize; sensor++)
        {
            m_sensorValueVector.append((quint16)((double)((m_scanDataVector->at(m_scanNumber - 1).at(source * m_arrayDataSize + (arrayNumber * m_scanDataOffset) + sensor)
                                           / contrast) + 0.5 )));

            qDebug() << "Scan:   " << m_scanDataVector->at(m_scanNumber - 1).at((source * m_arrayDataSize + (arrayNumber * m_scanDataOffset)) + 0);
            qDebug() << "Source: " << m_scanDataVector->at(m_scanNumber - 1).at((source * m_arrayDataSize + (arrayNumber * m_scanDataOffset)) + 1);
            qDebug() << "Sensor: " << m_scanDataVector->at(m_scanNumber - 1).at((source * m_arrayDataSize + (arrayNumber * m_scanDataOffset)) + 2);
        }
        qDebug() << m_sensorValueVector;


        calculateScanBeams(source);
    }
}

void ImageProcessor::calculateScanBeams(quint16 source)
{
    m_imageCalculator.calculateBeam(m_sensorValueVector, 0x0001 << m_scanDataVector->at(m_scanNumber)
                                  .at(source * m_arrayDataSize + 2), *m_imageVector.at(source));

}

void ImageProcessor::createArraySumImage()
{
    for(int i = 0; i < 8; i++)
    {
        m_imageCalculator.mergeImages(*m_imageVector.at(i), 0.0, m_sumImage);
    }
}

void ImageProcessor::createScanSumImage()
{

}

void ImageProcessor::clearData()
{
    for(int i = 0; i < m_imageVector.size(); i++)
    {
        delete m_imageVector.at(i);
    }

     m_sensorValueVector.clear();
}

