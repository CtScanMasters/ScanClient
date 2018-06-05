#ifndef IMAGEPROCESSMANAGER_H
#define IMAGEPROCESSMANAGER_H

#include <QObject>
#include <QVector>


class ImageProcessManager
{
private:
    QString m_logName;

public:
    ImageProcessManager();
    void processScanData(QVector<QVector<quint16>> *scanData, quint16 imageSize);
};

#endif // IMAGEPROCESSMANAGER_H
