#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <QGenericMatrix>
#include <QThreadPool>
#include <QVector>
#include <QRunnable>
#include <QObject>

class ScanData;
class ProcessorTask;

class Processor : public QObject
{
    Q_OBJECT

    public:
        Processor(int processors);

        bool process(QVector<quint16> scanData, quint16 scanNumber);
        QThreadPool* m_threadPool;


    private slots:


    private:
        int m_processors;
        QVector<ProcessorTask*> m_activeTasks;


};

#endif // PROCESSOR_H
