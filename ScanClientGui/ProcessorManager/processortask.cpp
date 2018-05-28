#include "processortask.h"
#include <QThread>
#include <QTime>
#include <QCoreApplication>
#include <QDir>
#include <QDebug>

#include "ImageCalculator/imageprocessor.h"

ProcessorTask::ProcessorTask()
{

}

ProcessorTask::ProcessorTask(QVector<quint16> *scanData, quint16 scanNumber)
{
    setAutoDelete(false);
    m_scanData = scanData.at(m_scanNumber);
}

void ProcessorTask::run()
{
    // We are busy now!
    m_busy = true;

    qInfo() << "ProcessorTask - run: " + QString("scanData: %1").arg(m_scanNumber);

    ImageProcessor imageProcessor;
    imageProcessor.setPresets(8, 11, 255);

    QImage image = imageProcessor.processData(&m_scanData, m_scanNumber);
//    QPixmap pixMapSum = QPixmap::fromImage(image);
//    ui->imagingWidget->setPixmap(pixMapSum);

    QString filepath;

    filepath = QCoreApplication::applicationDirPath()
                        + QString("/IMG%1/")
                            .arg(0,3,10, QChar('0'));
    if(!QDir(filepath).exists())
    {
        QDir().mkdir(filepath);
    }

    image.save(filepath + QString("SUM%1.png").arg(m_scanNumber,3,10, QChar('0')));


    // Prepare the results and stick the original scandata in there.
//    ProcessorResult result;
//    result.setScanData(m_scanData);

    // Done!
    processingDone();
}

void ProcessorTask::processingDone()
{
    // Nope, not busy anymore.
    m_busy = false;
    qDebug() <<"ProcessorTask - processingDone: " + QString("scanData: %1").arg(m_scanNumber);
}

bool ProcessorTask::busy() const
{
    return m_busy;
}
