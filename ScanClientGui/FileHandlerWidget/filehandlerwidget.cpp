#include "filehandlerwidget.h"

FileHandlerWidget::FileHandlerWidget(QWidget *parent) :
    QWidget(parent)
{
    m_loadSettingsButton = new QPushButton(this);
    m_loadScanButton = new QPushButton(this);
    m_editSettingsButton = new QPushButton(this);
    m_mainGridLayout = new QGridLayout(this);

    m_loadSettingsButton->setText("Load Settings");
    m_loadSettingsButton->setToolTip("load settings file");
    m_loadScanButton->setText("Load scan");
    m_loadScanButton->setToolTip("load scan data");
    m_editSettingsButton->setText("Edit settings");
    m_editSettingsButton->setToolTip("open settings editor");

    m_mainGridLayout->addWidget(m_loadSettingsButton, 0, 0, 1, 1);
    m_mainGridLayout->addWidget(m_editSettingsButton, 1, 0, 1, 1);
    m_mainGridLayout->addWidget(m_loadScanButton, 2, 0, 1, 1);

    connect(m_loadSettingsButton, SIGNAL(clicked(bool)), this, SLOT(loadSettings()));
    connect(m_loadScanButton, SIGNAL(clicked(bool)), this, SLOT(loadScan()));
    connect(m_editSettingsButton, SIGNAL(clicked(bool)), this, SLOT(editSettings()));

    setLayout(m_mainGridLayout);
}

FileHandlerWidget::~FileHandlerWidget()
{

}

void FileHandlerWidget::loadSettings()
{
    emit loadSettingsSignal();
}

void FileHandlerWidget::loadScan()
{
    emit loadScanSignal();
}

void FileHandlerWidget::editSettings()
{
    emit editSettingsSignal();
}
