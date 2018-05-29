#ifndef IMAGEPROCESSMANAGER_H
#define IMAGEPROCESSMANAGER_H

#include <QObject>
#include <QVector>
#include <QThreadPool>
#include <QVector>
#include <QRunnable>

#include "imageprocesstask.h"

class ImageProcessManager : public QObject
{
    Q_OBJECT

private:
    QString m_logName;
    QThreadPool* m_threadPool;
    QVector<ImageProcessTask*> m_activeTasks;
    quint16 m_scanIterator;
    quint16 m_numberOfScans;

    QVector<ImageProcessTask *> m_processTaskVector;

public:
    ImageProcessManager();
    void processScanData(QVector<QVector<quint16>> *scanData, quint16 numberOfScans);
    void startNewTask();

private slots:
    void finishedProcessing(quint16 scanNumber);

};

#endif // IMAGEPROCESSMANAGER_H
