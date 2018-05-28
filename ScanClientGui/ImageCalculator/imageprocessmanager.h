#ifndef IMAGEPROCESSMANAGER_H
#define IMAGEPROCESSMANAGER_H

#include <QObject>
#include <QVector>

#include "ProcessorManager/processor.h"

class ImageProcessManager
{
private:
    QString m_logName;
    Processor *m_scanProcessor;

public:
    ImageProcessManager();
    void processScanData(QVector<QVector<quint16>> *scanData, quint16 imageSize);
};

#endif // IMAGEPROCESSMANAGER_H
