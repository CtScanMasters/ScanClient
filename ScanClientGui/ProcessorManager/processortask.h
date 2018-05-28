#ifndef PROCESSORTASK_H
#define PROCESSORTASK_H

#include "ProcessorManager/processor.h"

#include <QRunnable>

class ProcessorTask : public QObject, public QRunnable
{
    Q_OBJECT

    public:
        ProcessorTask();
        ProcessorTask(QVector<quint16> *scanData, quint16 scanNumber);

        bool busy() const;


    public slots:

    signals:
        void done();


    private:
        void run();
        void processingDone();

        QVector<quint16> m_scanData;
        quint16 m_scanNumber;
        bool m_busy;


};

#endif // PROCESSORTASK_H
