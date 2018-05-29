#include <QCoreApplication>
#include <QDir>
#include <QDebug>

#include "imageprocessmanager.h"
#include "imageprocessor.h"
#include "imageprocesstask.h"


ImageProcessManager::ImageProcessManager()
{
    m_logName = "ImageProcessManager: ";
    qInfo() << m_logName + "build";

    m_threadPool = QThreadPool::globalInstance();
    m_threadPool->setMaxThreadCount(16);
    m_threadPool->setExpiryTimeout(10000);
    m_scanIterator = 0;
    m_numberOfScans = 0;
}

void ImageProcessManager::processScanData(QVector<QVector<quint16>> *scanData, quint16 numberOfScans)
{
    m_numberOfScans = numberOfScans;
    m_scanIterator = 0;

    for(quint16 scanNumber = 0; scanNumber < m_numberOfScans; scanNumber++)
    {
        m_processTaskVector.append(new ImageProcessTask(scanData->at(scanNumber), scanNumber));
    }

    for(int scanNumber = 0; scanNumber < 8; scanNumber++)
    {
        startNewTask();
    }

//    for(int scanNumber = 0; scanNumber < scanData->size(); scanNumber++)
//    {
//        qInfo() << m_logName + QString("processScanData scan: %1").arg(scanNumber);

//        ImageProcessor imageProcessor;
//        imageProcessor.setPresets(8, 11, imageSize);

//        QVector<quint16> data = scanData->at(scanNumber);

//        QImage image = imageProcessor.processData(&data, scanNumber);
//    //    QPixmap pixMapSum = QPixmap::fromImage(image);
//    //    ui->imagingWidget->setPixmap(pixMapSum);

//        QString filepath;

//        filepath = QCoreApplication::applicationDirPath()
//                            + QString("/IMG%1/")
//                                .arg(0,3,10, QChar('0'));
////        if(!QDir(filepath).exists())
////        {
////            QDir().mkdir(filepath);
////        }

//        image.save(filepath + QString("SUM%1.png").arg(scanNumber,3,10, QChar('0')));
//    }
}

void ImageProcessManager::startNewTask()
{
    qInfo() << m_logName + QString("processScanData scan %1").arg(m_scanIterator);
    connect(m_processTaskVector.at(m_scanIterator), SIGNAL(done(quint16)), this, SLOT(finishedProcessing(quint16)));
    m_threadPool->start(m_processTaskVector.at(m_scanIterator));
    m_scanIterator++;
}

void ImageProcessManager::finishedProcessing(quint16 scanNumber)
{
    qInfo() << m_logName + QString("finished processing scan %1").arg(scanNumber);

    if(m_scanIterator < m_numberOfScans)
    {
        startNewTask();
    }

}
