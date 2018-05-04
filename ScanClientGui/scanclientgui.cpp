#include "scanclientgui.h"
#include "ui_scanclientgui.h"
#include <QDebug>
#include <QDir>
#include <QDateTime>
#include "ImageCalculator/imagecalculator.h"
#include "commandlist.h"

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

void ScanClientGui::commandHandler(quint16 command)
{
    switch(command)
    {
    case COMMAND_SCAN_START:
        scanStart();
        break;
    case COMMAND_SCAN_STOP:
        scanStop();
        break;
    case COMMAND_SCAN_SET_PROGRESS:
        setScanProgress();
        break;
    case COMMAND_SCAN_GET_DATA:
        getScanData();
        break;
    case COMMAND_ACTUATOR_FORWARD:
        actuatorJogForward();
        break;
    case COMMAND_ACTUATOR_BACKWARD:
        actuatorJogBack();
        break;
    case COMMAND_ACTUATOR_POSITION:
        actuatorPosition();
        break;
    case COMMAND_ACTUATOR_HOME:
        actuatorHome();
        break;
    case COMMAND_SENSOR_VALUE:
        arrayGetSensor();
        break;
    case COMMAND_SOURCE_VALUE:
        arraySetSource();
        break;
    case COMMAND_READY:
        sendReady();
        break;
    case COMMAND_NOT_READY:
        sendNotReady();
        break;
    default:
        qWarning() << m_logName + "RECEIVED UNKOWN COMMAND";
    }
}

void ScanClientGui::scanStart()
{

}

void ScanClientGui::scanStop()
{

}

void ScanClientGui::setScanProgress()
{

}

void ScanClientGui::getScanData()
{
    getMeasurement();
    commandHandler(COMMAND_READY);
    qInfo() << m_logName + "COMMAND_SCAN_GET_DATA";
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

void ScanClientGui::actuatorPosition()
{

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

void ScanClientGui::arraySetSource()
{

}

void ScanClientGui::sendReady()
{
    m_dataBufferOut.append(QString::number(COMMAND_READY,10));
    m_tcpClient->sendData(m_dataBufferOut);

    qInfo() << m_logName + "COMMAND_READY";
}

void ScanClientGui::sendNotReady()
{

}

void ScanClientGui::buildMainGui()
{
    qInfo() << "------------STARTING CT SCANMASTER 2018 V1.0------------";

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

    connect(m_arrayWidgetList.at(0), SIGNAL(sourceSetSignalMask(quint8)), this, SLOT(arraySetSourceMask(quint8)));
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

void ScanClientGui::tcpReadData()
{
    m_dataBufferInList.clear();
    QByteArray dataBufferIn;
    m_tcpClient->getReceivedData(dataBufferIn);
    QDataStream dataInStream(&dataBufferIn, QIODevice::ReadWrite);
    dataInStream >> m_dataBufferInList;
    qInfo() << m_logName + "tcpReadData: " << m_dataBufferInList;
    commandHandler(m_dataBufferInList.at(0));
}

void ScanClientGui::buildActuatorControl()
{
    qInfo() << m_logName + "buildActuatorControl";

    connect(ui->actuatorControlWidget, SIGNAL(jogBackSignal()), this, SLOT(actuatorJogBack()));
    connect(ui->actuatorControlWidget, SIGNAL(jogForwardSignal()), this, SLOT(actuatorJogForward()));
    connect(ui->actuatorControlWidget, SIGNAL(homeActuatorSignal()), this, SLOT(actuatorHome()));
}

void ScanClientGui::arraySetSourceMask(quint8 sourceMask)
{
    qInfo() << m_logName + "arraySetSource";

    m_sourceMask = sourceMask;

    QByteArray dataOutArray;
    QDataStream dataOutStream(&dataOutArray, QIODevice::ReadWrite);
    dataOutStream << m_sourceMask;
    m_tcpClient->sendData(dataOutArray);

//    ui->plainTextEdit->appendPlainText(QString("Source mask: %1").arg(QString::number(sourceMask,2)));
}



void ScanClientGui::getMeasurement()
{   

    QTime time;
    time.start();
    qWarning() << "*************************START*****************************************";

    QByteArray dataInArray;
    m_tcpClient->getReceivedData(dataInArray);

    QList<quint16> sensorIntensity;
    QDataStream dataInStream(&dataInArray, QIODevice::ReadWrite);
    dataInStream >> sensorIntensity;

    const quint16 imageWidth = 512;
    quint8 numberOfSensors = 8;

    ImageCalculator imageCalculator;
    imageCalculator.setDimensions(numberOfSensors, imageWidth, 60, 120);

    QList<QImage* > imageList0;

    for(int i = 0; i < 8; i++)
    {
        QImage image(imageWidth, imageWidth, QImage::Format_Grayscale8);
        imageList0.append(new QImage(imageWidth, imageWidth, QImage::Format_Grayscale8));
        imageList0.at(i)->fill(qRgb(0,0,0));
    }

    QImage imageSum(imageWidth  + (imageWidth / 4), imageWidth + (imageWidth / 4), QImage::Format_Grayscale8);
    imageSum.fill(qRgb(0,0,0));


    quint8 sourceMask = 0x01;
    for(int i = 0; i < 8; i++)
    {
        QList<quint16> list;
        for(int j = 0; j < 8; j++)
        {
            list.append((quint16)((double)((sensorIntensity.at((i * 8) + j)) / ui->verticalSlider->value()) + 0.5 ));
        }
        //qInfo() << m_logName + "getMeasurement: " << sensorIntensity << list;
        imageCalculator.calculateBeam(list, sourceMask << i, *imageList0.at(i));

    }

    for(int i = 0; i < 8; i++)
    {
        imageCalculator.mergeImages(*imageList0.at(i), 0.0, imageSum);
    }

// Use to check image offset
//    for(int i = 0; i < 8; i++)
//    {
//        imageCalculator.mergeImages(*imageList0.at(i), 45.0, imageSum);
//    }

    //imageSum.invertPixels();

    QPixmap pixMapSum = QPixmap::fromImage(imageSum);

    ui->imagingWidget->setPixmap(pixMapSum.scaledToHeight(this->height() - 200));
//    ui->imagingWidget->setPixmap(pixMapSum);

//    QString filepath;

//    for(int i = 0; i < 1000; i++)
//    {
//        filepath = QCoreApplication::applicationDirPath()
//                            + QString("/IMG%1/")
//                                .arg(i,3,10, QChar('0'));


//        if(!QDir(filepath).exists() && (i < 999))
//        {
//            QDir().mkdir(filepath);
//            break;
//        }
//        if(i > 999)
//        {
//            qWarning() << "all foldernames occupied";
//            break;
//        }
//    }


//    qInfo() << m_logName + "getMeasurement: " + filepath;

//    for(int i = 0; i < 8; i++)
//    {
//        imageList0.at(i)->save(filepath
//                                  + QString("IMG%1_%2.png")
//                                  .arg(i,3,10, QChar('0')));
//    }

//    imageSum.save(filepath + "sum.png");


    for(int i = 0; i < imageList0.size(); i++)
    {
        delete imageList0.at(i);
    }

qWarning() << "*************************STOP*****************************************";
qWarning() << time.elapsed();
qWarning() << "*************************STOP*****************************************";
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



