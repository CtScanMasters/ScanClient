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
    m_progressBar = new QProgressBar(this);
    m_statusLineEdit = new QLineEdit();
    m_mainGridLayout = new QGridLayout(this);

    m_startScanButton->setText("Start");
    m_startScanButton->setToolTip("initiate scan sequence");
    m_stopScanButton->setText("Stop");
    m_stopScanButton->setToolTip("stop running scan sequence");
    m_statusLabel->setText("Status: ");    
    m_progressBar->setValue(0);
    m_progressBar->setAlignment(Qt::AlignCenter);
    m_statusLineEdit->setReadOnly(true);
    m_statusLineEdit->setPlaceholderText("unknown");

    m_mainGridLayout->addWidget(m_statusLabel,      0, 0, 1, 1);
    m_mainGridLayout->addWidget(m_statusLineEdit,   0, 1, 1, 3);
    m_mainGridLayout->addWidget(m_progressBar,      1, 0, 2, 4);
    m_mainGridLayout->addWidget(m_startScanButton,  3, 0, 1, 2);
    m_mainGridLayout->addWidget(m_stopScanButton,   3, 2, 1, 2);

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
