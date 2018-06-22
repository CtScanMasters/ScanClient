#ifndef IMAGEPROCESSTASK_H
#define IMAGEPROCESSTASK_H

#include <QObject>
#include <QRunnable>
#include <QVector>

class ImageProcessTask : public QObject, public QRunnable
{
    Q_OBJECT

    public:
        ImageProcessTask();
        ImageProcessTask(QVector<quint16> scanData, quint16 scanNumber, QString filepath);

        bool busy() const;


    public slots:

    signals:
        void done(quint16);


    private:
        void run();
        void processingDone();

        QVector<quint16> m_scanData;
        quint16 m_scanNumber;
        bool m_busy;
        QString m_filepath;


};

#endif // IMAGEPROCESSTASK_H
