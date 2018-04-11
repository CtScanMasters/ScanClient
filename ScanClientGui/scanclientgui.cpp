#include "scanclientgui.h"
#include "ui_scanclientgui.h"



ScanClientGui::ScanClientGui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ScanClientGui)
{
    ui->setupUi(this);

    m_arrayCount = 8;
    m_tcpIsConnected = false;

    buildArrayTab();
    buildTcpClient();
    buildActuatorControl();


}

ScanClientGui::~ScanClientGui()
{
    tcpDisconnect();
    delete ui;
}

void ScanClientGui::buildArrayTab()
{
    m_arrayBox1 = new QGroupBox(ui->arrayControl);
    m_arrayBoxGridLayout1 = new QGridLayout(m_arrayBox1);
    m_arrayTabGridLayout = new QGridLayout(ui->arrayControl);
    m_arrayBox1->setTitle("Array control");

    for(int i = 0; i < m_arrayCount; i++)
    {
        m_arrayWidgetList.append(new ArrayWidget(m_arrayBox1));
        m_arrayWidgetList.at(i)->setNumber(i);

        if(i < (m_arrayCount / 2))
        {
            m_arrayBoxGridLayout1->addWidget(m_arrayWidgetList.at(i), i, 0, 1, 2);
        }
        else
        {
            m_arrayBoxGridLayout1->addWidget(m_arrayWidgetList.at(i), i - (m_arrayCount / 2), 2, 1, 2);
        }
    }
    m_arrayTabGridLayout->addWidget(m_arrayBox1, 0, 0, (m_arrayCount / 2), 4);
}

void ScanClientGui::buildTcpClient()
{
    m_tcpClient = new TcpClient;
    connect(ui->tcpControlWidget, SIGNAL(connectToHostSignal()), this, SLOT(tcpConnect()));
    connect(ui->tcpControlWidget, SIGNAL(disconnectFromHostSignal()), this, SLOT(tcpDisconnect()));
    connect(m_tcpClient, SIGNAL(socketStateChangedSignal()), this, SLOT(tcpStateChange()));
    ui->tcpControlWidget->setClientIpAddress(m_tcpClient->handleRetreiveIpAddress());
}

void ScanClientGui::tcpConnect()
{
    bool ok = false;
    m_tcpClient->setHostIpAddress(ui->tcpControlWidget->getHostIpAddress());
    m_tcpClient->setHostPort(ui->tcpControlWidget->getHostPort().toLongLong(&ok));
    m_tcpClient->connectToHost();
}

void ScanClientGui::tcpDisconnect()
{
    m_tcpClient->disconnectFromHost();
    m_tcpIsConnected = false;
}

void ScanClientGui::tcpStateChange()
{
    ui->tcpControlWidget->setStatus(m_tcpClient->getSocketState());

    if(m_tcpClient->getSocketState() == "connected")
    {
        m_tcpIsConnected = true;
    }
    else
    {
        m_tcpIsConnected = false;
    }
}

void ScanClientGui::tcpSendData()
{
    if(m_tcpIsConnected)
    {
        m_tcpClient->sendData(m_dataBufferOut);
        m_dataBufferOut.clear();
    }
    else
    {
        qDebug() << "GUI no data send TCP not connected";
    }
}

void ScanClientGui::buildActuatorControl()
{
    connect(ui->actuatorControlWidget, SIGNAL(jogBackSignal()), this, SLOT(actuatorJogBack()));
    connect(ui->actuatorControlWidget, SIGNAL(jogForwardSignal()), this, SLOT(actuatorJogForward()));
    connect(ui->actuatorControlWidget, SIGNAL(homeActuatorSignal()), this, SLOT(actuatorHome()));
}

void ScanClientGui::actuatorJogBack()
{
    m_dataBufferOut.append(0x01);
    m_dataBufferOut.append(0x01);
    tcpSendData();
}

void ScanClientGui::actuatorJogForward()
{
    m_dataBufferOut.append(0x01);
    m_dataBufferOut.append(0x02);
    tcpSendData();
}

void ScanClientGui::actuatorHome()
{
    m_dataBufferOut.append(0x01);
    m_dataBufferOut.append(0x03);
    tcpSendData();

}
