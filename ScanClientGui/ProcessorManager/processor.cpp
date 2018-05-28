#include "processor.h"

#include "processortask.h"

Processor::Processor(int processors)
    : m_processors(processors)
{
    m_threadPool = QThreadPool::globalInstance();
    m_threadPool->setMaxThreadCount(processors);
    m_threadPool->setExpiryTimeout(10000);    
}

bool Processor::process(QVector<quint16> scanData, quint16 scanNumber)
{
    ProcessorTask* task = new ProcessorTask(&scanData, scanNumber);
    //connect(task, SIGNAL(done(ProcessorResult)), this, SLOT(gatherResult(ProcessorResult)));

    //m_activeTasks.push_back(task);

    m_threadPool->start(task);

    return true;
}


