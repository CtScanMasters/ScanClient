#include "imageprocesstask.h"
#include <QThread>
#include <QTime>
#include <QCoreApplication>
#include <QDir>
#include <QDebug>

#include "imageprocessor.h"

ImageProcessTask::ImageProcessTask()
{

}

ImageProcessTask::ImageProcessTask(QVector<quint16> scanData, quint16 scanNumber, QString filepath)
{
    setAutoDelete(false);
    m_scanNumber = scanNumber;
    m_filepath = filepath;

    for(int i = 0; i < scanData.size(); i++)
    {
        m_scanData.append(scanData.at(i));
    }

}

void ImageProcessTask::run()
{
    // We are busy now!
    m_busy = true;

    ImageProcessor imageProcessor;
    imageProcessor.setPresets(8, 11, 256);

    QImage image = imageProcessor.processData(&m_scanData, m_scanNumber);

    image.save(m_filepath + QString("SUM%1.png").arg(m_scanNumber,3,10, QChar('0')));

    // Done!
    processingDone();
}

void ImageProcessTask::processingDone()
{
    // Nope, not busy anymore.
    m_busy = false;
    emit done(m_scanNumber);
}

bool ImageProcessTask::busy() const
{
    return m_busy;
}

