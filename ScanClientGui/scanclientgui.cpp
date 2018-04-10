#include "scanclientgui.h"
#include "ui_scanclientgui.h"



ScanClientGui::ScanClientGui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ScanClientGui)
{
    ui->setupUi(this);

    buildGui();
}

ScanClientGui::~ScanClientGui()
{
    delete ui;
}

void ScanClientGui::buildGui()
{
    m_fileHandlerBox = new QGroupBox(this);
    m_scanBox = new QGroupBox(this);
    m_connectionBox = new QGroupBox(this);
    m_actuatorBox = new QGroupBox(this);
    m_exitButton = new  QPushButton(this);

    m_scatterWidget = new  ScatterWidget(this);
    m_actuatorWidget = new  ActuatorWidget(this);
    m_fileHandlerWidget = new  FileHandlerWidget(this);
    m_scanWidget = new  ScanWidget(this);
    m_arrayWidgetList = new QList();
}
