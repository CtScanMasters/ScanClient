#ifndef IMAGEVIEWERWIDGET_H
#define IMAGEVIEWERWIDGET_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class ImageViewerWidget;
}

class ImageViewerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ImageViewerWidget(QWidget *parent = 0);
    ~ImageViewerWidget();

public slots:
    void openFolder();
    void openFolder(QString filepath);
    void next();
    void previous();
    void getImageNames();
    QImage getImage(quint32 iterator);
    void setImages();
    void startTimerScroll();
    void stopTimerScroll();


private:
    Ui::ImageViewerWidget *ui;
    QString m_logName;
    QString m_folderPath;
    QStringList m_fileNameList;
    quint32 m_imageIterator;

    QTimer m_scrollTimer;

};

#endif // IMAGEVIEWERWIDGET_H
