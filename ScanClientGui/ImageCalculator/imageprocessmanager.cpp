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
}

void ImageProcessManager::processScanData(QVector<QVector<quint16>> *scanData, quint16 imageSize)
{
    for(int scanNumber = 0; scanNumber < 100; scanNumber++)
    {
        qInfo() << m_logName + QString("processScanData scan %1").arg(scanNumber);
        ImageProcessTask* task = new ImageProcessTask(scanData->at(scanNumber), scanNumber);
        connect(task, SIGNAL(done(quint16)), this, SLOT(finishedProcessing(quint16)));
        m_threadPool->start(task);
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

void ImageProcessManager::finishedProcessing(quint16 scanNumber)
{
    qInfo() << m_logName + QString("finished processing scan %1").arg(scanNumber);
}
