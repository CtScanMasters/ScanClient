#include "scanwidget.h"
#include <QDebug>

ScanWidget::ScanWidget(QWidget *parent) :
    QWidget(parent)
{
    m_logName = "ScanWidget : ";
    qInfo() << m_logName + "creating widget";

    m_startScanButton = new QPushButton(this);
    m_stopScanButton = new QPushButton(this);
    m_statusLabel = new QLabel(this);
    m_NumberOfScansLabel = new QLabel(this);
    m_scanLineEdit = new QLineEdit(this);
    m_progressBar = new QProgressBar(this);
    m_statusLineEdit = new QLineEdit();
    m_mainGridLayout = new QGridLayout(this);

    m_startScanButton->setText("Start");
    m_startScanButton->setToolTip("initiate scan sequence");
    m_startScanButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_stopScanButton->setText("Stop");
    m_stopScanButton->setToolTip("stop running scan sequence");
    m_stopScanButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_statusLabel->setText("Status: ");
    m_NumberOfScansLabel->setText("Number of scans: ");
    m_scanLineEdit->setText(QString::number(100));
    m_scanLineEdit->setValidator( new QIntValidator(10, 200, this));

    m_progressBar->setValue(0);
    m_progressBar->setAlignment(Qt::AlignCenter);
    QPalette palette = m_progressBar->palette();
    palette.setColor(QPalette::Text, qRgb(0,0,0));
    palette.setColor(QPalette::HighlightedText, qRgb(0,0,0));
    m_progressBar->setPalette(palette);
    m_statusLineEdit->setReadOnly(true);
    m_statusLineEdit->setPlaceholderText("unknown");

    m_mainGridLayout->addWidget(m_statusLabel,       0, 0, 1, 1);
    m_mainGridLayout->addWidget(m_statusLineEdit,    0, 1, 1, 3);
    m_mainGridLayout->addWidget(m_NumberOfScansLabel,1, 0, 1, 1);
    m_mainGridLayout->addWidget(m_scanLineEdit,      1, 1, 1, 3);
    m_mainGridLayout->addWidget(m_progressBar,       2, 0, 2, 4);
    m_mainGridLayout->addWidget(m_startScanButton,   4, 0, 1, 2);
    m_mainGridLayout->addWidget(m_stopScanButton,    4, 2, 1, 2);

    connect(m_startScanButton, SIGNAL(clicked(bool)), this, SLOT(startScan()));
    connect(m_stopScanButton, SIGNAL(clicked(bool)), this, SLOT(stopScan()));

    setLayout(m_mainGridLayout);



}

ScanWidget::~ScanWidget()
{

}

void ScanWidget::setStatus(QString status, quint8 progress)
{
    m_statusLineEdit->setText(status);
    m_progressBar->setValue(progress);

    if(progress > (m_progressBar->maximum() / 2))
    {
        QPalette palette = m_progressBar->palette();
        palette.setColor(QPalette::Text, qRgb(255,255,255));
        palette.setColor(QPalette::HighlightedText, qRgb(255,255,255));
        m_progressBar->setPalette(palette);
    }
    else
    {
        QPalette palette = m_progressBar->palette();
        palette.setColor(QPalette::Text, qRgb(0,0,0));
        palette.setColor(QPalette::HighlightedText, qRgb(0,0,0));
        m_progressBar->setPalette(palette);
    }

    qInfo() << m_logName + "setStatus: " + status + QString(" %1 %").arg(progress);

}

void ScanWidget::startScan()
{
    qInfo() << m_logName + "emitStartScanSignal";
    emit startScanSignal();
}

void ScanWidget::stopScan()
{
    qInfo() << m_logName + "emitStopScanSignal";
    emit stopScanSignal();
}

void ScanWidget::setEnabled(bool status)
{
    m_startScanButton->setEnabled(status);
    m_stopScanButton->setEnabled(status);
}

void ScanWidget::isScanning(bool status)
{
    if(status)
    {
        m_startScanButton->setEnabled(false);
        m_stopScanButton->setEnabled(true);
    }
    else
    {
        m_startScanButton->setEnabled(true);
        m_stopScanButton->setEnabled(false);
    }
}

quint8 ScanWidget::getNumberOfScans()
{
    bool ok;
    QString scans = m_scanLineEdit->text();
    quint8 number = scans.toUShort(&ok,10);
    return(number);
}
