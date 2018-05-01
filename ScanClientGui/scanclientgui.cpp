#include "scanclientgui.h"
#include "ui_scanclientgui.h"
#include <QDebug>

ScanClientGui::ScanClientGui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ScanClientGui)
{
    ui->setupUi(this);

    m_dataLogger = MessageLogger::getInstance();
    m_dataLogger->setTextEdit(ui->plainTextEdit);

    m_logName = "ScanClientGui : ";

    buildMainGui();
}

ScanClientGui::~ScanClientGui()
{    
    tcpDisconnect();
    qInfo() << m_logName + "EXIT";
    delete ui;
}

void ScanClientGui::buildMainGui()
{
    qInfo() << m_logName + "starting";
    qInfo() << "by CTScanMasters 2018 V1.0";

    m_arrayCount = 8;
    m_tcpIsConnected = false;
    m_sourceMask = 0;

    buildArrayTab();
    buildTcpClient();
    buildActuatorControl();

    ui->scatterPlot->setAxisRange(0,0,15);
    ui->scatterPlot->setAxisRange(1,0,6);
    ui->scatterPlot->setAxisRange(2,0,5);
}

void ScanClientGui::buildArrayTab()
{
    qInfo() << m_logName + "buildArrayTab";

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

    connect(m_arrayWidgetList.at(0), SIGNAL(sourceSetSignal(quint8)), this, SLOT(arraySetSource(quint8)));
}

void ScanClientGui::buildTcpClient()
{
    qInfo() << m_logName + "buildTcpClient";

    m_tcpClient = new TcpClient;
    connect(ui->tcpControlWidget, SIGNAL(connectToHostSignal()), this, SLOT(tcpConnect()));
    connect(ui->tcpControlWidget, SIGNAL(disconnectFromHostSignal()), this, SLOT(tcpDisconnect()));
    connect(m_tcpClient, SIGNAL(socketStateChangedSignal()), this, SLOT(tcpStateChange()));
    connect(m_tcpClient, SIGNAL(newDataAvailableSignal()), this, SLOT(arrayGetSensor()));
    ui->tcpControlWidget->setClientIpAddress(m_tcpClient->handleRetreiveIpAddress());
}

void ScanClientGui::tcpConnect()
{
    qInfo() << m_logName + "tcpConnect";

    bool ok = false;
    m_tcpClient->setHostIpAddress(ui->tcpControlWidget->getHostIpAddress());
    m_tcpClient->setHostPort(ui->tcpControlWidget->getHostPort().toLongLong(&ok));
    m_tcpClient->connectToHost();
}

void ScanClientGui::tcpDisconnect()
{
    qInfo() << m_logName + "tcpDisconnect";

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
        qWarning() << m_logName + "tcpSendData: NOT CONNECTED";
    }
}

void ScanClientGui::buildActuatorControl()
{
    qInfo() << m_logName + "buildActuatorControl";

    connect(ui->actuatorControlWidget, SIGNAL(jogBackSignal()), this, SLOT(actuatorJogBack()));
    connect(ui->actuatorControlWidget, SIGNAL(jogForwardSignal()), this, SLOT(actuatorJogForward()));
    connect(ui->actuatorControlWidget, SIGNAL(homeActuatorSignal()), this, SLOT(actuatorHome()));
}

void ScanClientGui::arraySetSource(quint8 sourceMask)
{
    qInfo() << m_logName + "arraySetSource";

    m_sourceMask = sourceMask;

    QByteArray dataOutArray;
    QDataStream dataOutStream(&dataOutArray, QIODevice::ReadWrite);
    dataOutStream << m_sourceMask;
    m_tcpClient->sendData(dataOutArray);

//    ui->plainTextEdit->appendPlainText(QString("Source mask: %1").arg(QString::number(sourceMask,2)));
}

void ScanClientGui::arrayGetSensor()
{
    qInfo() << m_logName + "arrayGetSensor";

    QByteArray dataInArray;
    m_tcpClient->getReceivedData(dataInArray);

    QList<uint16_t> dataInList;
    QDataStream dataInStream(&dataInArray, QIODevice::ReadWrite);
    dataInStream >> dataInList;

    for(int i = 0; i < 8; i++)
    {
        if(i < dataInList.size())
        {
            m_arrayWidgetList.at(0)->setBarValue(i, quint64(dataInList.at(i) * 3.22));
//            ui->plainTextEdit->appendPlainText(QString("Sensor %1 value: %2").arg(i).arg(dataInList.at(i) * 3.22));
        }
    }

    drawGraph(dataInList, m_sourceMask);
}

void ScanClientGui::drawGraph(QList<uint16_t> sensorValueList, quint8 source)
{
    qInfo() << m_logName + "drawGraph";

    QScatterDataArray scatterArray;
    quint8 sensorPosition;

    for(int i = 0; i < 8; i++)
    {
        sensorPosition = (source >> i) & 1;
        if(sensorPosition)
        {
            scatterArray.append(QVector3D(15,i,3));
        }
    }

    for(int i = 0; i < sensorValueList.size(); i++)
    {
        if((sensorValueList.at(i) * 3.22) < 2000)
        {
            scatterArray.append(QVector3D(0,i,3));
        }
    }

    ui->scatterPlot->setData(scatterArray);

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
