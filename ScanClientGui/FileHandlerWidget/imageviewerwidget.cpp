#include "imageviewerwidget.h"
#include "ui_imageviewerwidget.h"
#include <QFileDialog>
#include <QDirIterator>
#include <QDebug>

ImageViewerWidget::ImageViewerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageViewerWidget)
{
    ui->setupUi(this);

    m_logName = "ImageViewerWidget : ";

    qInfo() << m_logName + "build";

    m_imageIterator = 2;

    ui->pushButtonNext->setEnabled(false);
    ui->pushButtonPrevious->setEnabled(false);



    connect(ui->pushButtonOpen, SIGNAL(clicked(bool)), this, SLOT(openFolder()));
    connect(ui->pushButtonNext, SIGNAL(clicked(bool)), this, SLOT(next()));
    connect(ui->pushButtonPrevious, SIGNAL(clicked(bool)), this, SLOT(previous()));
    connect(ui->pushButtonNext, SIGNAL(pressed()), this, SLOT(startTimerScroll()));
    connect(ui->pushButtonNext, SIGNAL(released()), this, SLOT(stopTimerScroll()));
    connect(ui->pushButtonPrevious, SIGNAL(pressed()), this, SLOT(startTimerScroll()));
    connect(ui->pushButtonPrevious, SIGNAL(released()), this, SLOT(stopTimerScroll()));

}

ImageViewerWidget::~ImageViewerWidget()
{
    delete ui;
}

void ImageViewerWidget::openFolder()
{
    QDir dir;
    m_folderPath = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                dir.absolutePath(),
                                                QFileDialog::ShowDirsOnly
                                                | QFileDialog::DontResolveSymlinks);

    dir = m_folderPath;
    ui->labelFilePath->setText("Folder: " + m_folderPath);
    qInfo() << m_logName + "open folder:" + m_folderPath;

    getImageNames();

    ui->pushButtonNext->setEnabled(true);
    ui->pushButtonPrevious->setEnabled(true);
}

void ImageViewerWidget::openFolder(QString filepath)
{
    QDir dir;
    m_folderPath = filepath;

    dir = m_folderPath;
    ui->labelFilePath->setText("Folder: " + m_folderPath);
    qInfo() << m_logName + "open folder:" + m_folderPath;

    getImageNames();

    ui->pushButtonNext->setEnabled(true);
    ui->pushButtonPrevious->setEnabled(true);
}

void ImageViewerWidget::next()
{
    if((m_imageIterator + 5) < m_fileNameList.size())
    {
        m_imageIterator += 1;
        setImages();
    }
}

void ImageViewerWidget::previous()
{
    if(m_imageIterator > 0)
    {
        m_imageIterator -= 1;

        if(m_imageIterator < 1)
        {
            m_imageIterator = 1;
        }
        setImages();
    }
}

void ImageViewerWidget::getImageNames()
{
    m_fileNameList.clear();

    QDirIterator dirIterator(m_folderPath, QDir::NoFilter, QDirIterator::NoIteratorFlags);

    while (dirIterator.hasNext())
    {
        QFile file(dirIterator.next());
        file.open(QIODevice::ReadOnly);
        m_fileNameList.append(file.fileName());
    }

    ui->labelScans->setText(QString("Scans: %1").arg(m_fileNameList.size()-2));

    setImages();
}

void ImageViewerWidget::setImages()
{
    ui->labelImage1->setPixmap(QPixmap::fromImage(QImage(getImage(m_imageIterator))));
    ui->labelImage2->setPixmap(QPixmap::fromImage(QImage(getImage(m_imageIterator + 1))));
    ui->labelImage3->setPixmap(QPixmap::fromImage(QImage(getImage(m_imageIterator + 2))));
    ui->labelImage4->setPixmap(QPixmap::fromImage(QImage(getImage(m_imageIterator + 3))));
    ui->labelImage5->setPixmap(QPixmap::fromImage(QImage(getImage(m_imageIterator + 4))));
    ui->labelImage6->setPixmap(QPixmap::fromImage(QImage(getImage(m_imageIterator + 5))));

    ui->labelScans->setText(QString("Scans: %1 / %2").arg(m_imageIterator).arg(m_fileNameList.size()-2));
}

QImage ImageViewerWidget::getImage(quint32 iterator)
{
    if((iterator > 0) && (iterator < m_fileNameList.size()))
    {
        return (QImage(m_fileNameList.at(iterator)));
    }
    else
    {
        QImage image(0,0,QImage::Format_Grayscale8);
        image.fill(qRgb(0,0,0));
        return image;
    }

}

void ImageViewerWidget::startTimerScroll()
{
    QObject* sender = QObject::sender();

    if(sender == ui->pushButtonNext)
    {
        connect(&m_scrollTimer, SIGNAL(timeout()), this, SLOT(next()));
    }
    if(sender == ui->pushButtonPrevious)
    {
        connect(&m_scrollTimer, SIGNAL(timeout()), this, SLOT(previous()));
    }
    m_scrollTimer.start(250);
}

void ImageViewerWidget::stopTimerScroll()
{
    QObject* sender = QObject::sender();

    m_scrollTimer.stop();

    if(sender == ui->pushButtonNext)
    {
        disconnect(&m_scrollTimer, SIGNAL(timeout()), this, SLOT(next()));
    }
    if(sender == ui->pushButtonPrevious)
    {
        disconnect(&m_scrollTimer, SIGNAL(timeout()), this, SLOT(previous()));
    }
}
