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
    clearData();

    m_numberOfScans = numberOfScans;
    m_scanIterator = 0;

    for(int i = 0; i < 1000; i++)
    {
        m_filepath = QCoreApplication::applicationDirPath()
                            + QString("/IMG%1/")
                                .arg(i,3,10, QChar('0'));


        if(!QDir(m_filepath).exists() && (i < 999))
        {
            QDir().mkdir(m_filepath);
            qInfo () << m_logName + "files saved in " + m_filepath;
            break;
        }
        if(i > 999)
        {
            qWarning() << "all foldernames occupied";
            break;
        }
    }

    for(quint16 scanNumber = 0; scanNumber < m_numberOfScans; scanNumber++)
    {
        m_processTaskVector.append(new ImageProcessTask(scanData->at(scanNumber), scanNumber, m_filepath));
    }

    for(int scanNumber = 0; scanNumber < 8; scanNumber++)
    {
        startNewTask();
    }
}

void ImageProcessManager::startNewTask()
{
    qInfo() << m_logName + QString("processScanData scan %1").arg(m_scanIterator);
    emit startProcessing(m_scanIterator);
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
    else
    {
        emit processingDone(m_filepath);
    }

}

void ImageProcessManager::clearData()
{
    for(int i = 0; i < m_processTaskVector.size(); i++)
    {
        delete m_processTaskVector.at(i);
    }
    m_processTaskVector.clear();
}
