#include "scanclientgui.h"
#include "ui_scanclientgui.h"
#include <QDebug>
#include <QDir>
#include "ImageCalculator/imagecalculator.h"

ScanClientGui::ScanClientGui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ScanClientGui)
{
    ui->setupUi(this);

    m_dataLogger = MessageLogger::getInstance();
    m_dataLogger->setTextEdit(ui->plainTextEdit);

    m_logName = "ScanClientGui : ";

    m_arrayCount = 8;
    m_tcpIsConnected = false;
    m_sourceMask = 0;

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
//    qInfo() << m_logName + "starting";
//    qInfo() << "by CTScanMasters 2018 V1.0";

    ui->plainTextEdit->appendPlainText("by CTScanMasters 2018 V1.0");

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
    connect(m_tcpClient, SIGNAL(newDataAvailableSignal()), this, SLOT(getMeasurement()));
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

    qInfo() << m_logName + "arrayGetSensor Sensor: " << dataInList << "Source: 0x" << QString::number(m_sourceMask, 16);
//    drawGraph(dataInList, m_sourceMask);
}

void ScanClientGui::getMeasurement()
{   

    QByteArray dataInArray;
    m_tcpClient->getReceivedData(dataInArray);

    QList<quint16> sensorIntensity;
    QDataStream dataInStream(&dataInArray, QIODevice::ReadWrite);
    dataInStream >> sensorIntensity;

//    for(int i = 0; i < 8; i++)
//    {
////        if(i < dataInList.size())
////        {
////            m_arrayWidgetList.at(0)->setBarValue(i, quint64(dataInList.at(i) * 3.22));
//////            ui->plainTextEdit->appendPlainText(QString("Sensor %1 value: %2").arg(i).arg(dataInList.at(i) * 3.22));
////        }
//    }

    const quint16 imageWidth = 255;
    quint8 numberOfSensors = 8;

    ImageCalculator imageCalculator;
    imageCalculator.setDimensions(numberOfSensors, imageWidth, 60, 120);

    for(int i = 0; i < 8; i++)
    {
        m_imageList.append(new QImage(imageWidth, imageWidth, QImage::Format_Grayscale8));
        m_imageList.at(i)->fill(qRgb(0,0,0));
    }


//    for(int i = 0; i < 8; i++)
//    {
//        sensorIntensity.append(32);
//    }

    QImage imageSum(imageWidth * 2, imageWidth * 2, QImage::Format_Grayscale8);
    imageSum.fill(qRgb(0,0,0));


    quint8 sourceMask = 0x01;
    for(int i = 0; i < 8; i++)
    {
        QList<quint16> list;
        for(int j = 0; j < 8; j++)
        {
            list.append((quint16)((double)((sensorIntensity.at((i * 8)+ j)) / 32.0) + 0.5 ));
        }
        //qInfo() << m_logName + "getMeasurement: " << list;
        imageCalculator.calculateBeam(list, sourceMask << i, *m_imageList.at(i));
    }

//    imageCalculator.calculateBeam(sensorIntensity, 0x01, *m_imageList.at(0));
//    imageCalculator.calculateBeam(sensorIntensity, 0x02, *m_imageList.at(1));
//    imageCalculator.calculateBeam(sensorIntensity, 0x04, *m_imageList.at(2));
//    imageCalculator.calculateBeam(sensorIntensity, 0x08, *m_imageList.at(3));
//    imageCalculator.calculateBeam(sensorIntensity, 0x10, *m_imageList.at(4));
//    imageCalculator.calculateBeam(sensorIntensity, 0x20, *m_imageList.at(5));
//    imageCalculator.calculateBeam(sensorIntensity, 0x40, *m_imageList.at(6));
//    imageCalculator.calculateBeam(sensorIntensity, 0x80, *m_imageList.at(7));

//    for(int i = 0; i < 4; i++)
//    {
//        imageCalculator.mergeImages(*m_imageList.at(i), i * 45, imageSum);
//    }

//    for(int i = 4; i < 8; i++)
//    {
//        imageCalculator.mergeImages(*m_imageList.at(i), ((i-4.0) * 45.0) + 22.5, imageSum);
//    }

        for(int i = 0; i < 8; i++)
        {
            imageCalculator.mergeImages(*m_imageList.at(i), 0.0, imageSum);
        }

//    imageSum.invertPixels();

    QPixmap pixMapSum = QPixmap::fromImage(imageSum);

    ui->imagingWidget->setPixmap(pixMapSum);

    QString filepath;

    for(int i = 0; i < 1000; i++)
    {
        filepath = QCoreApplication::applicationDirPath()
                            + QString("/IMG%1/")
                                .arg(i,3,10, QChar('0'));


        if(!QDir(filepath).exists() && (i < 999))
        {
            QDir().mkdir(filepath);
            break;
        }
        if(i > 999)
        {
            qWarning() << "all foldernames occupied";
            break;
        }
    }


    qInfo() << m_logName + "getMeasurement: " + filepath;

    for(int i = 0; i < 8; i++)
    {
        m_imageList.at(i)->save(filepath
                                  + QString("IMG%1_%2.png")
                                  .arg(i,3,10, QChar('0')));
    }

    imageSum.save(filepath + "sum.png");

////    qInfo() << m_logName + "arrayGetSensor Sensor: " << dataInList << "Source: 0x" << QString::number(m_sourceMask, 16);
////    drawGraph(dataInList, m_sourceMask);
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
