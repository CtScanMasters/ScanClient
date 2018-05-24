#include "scanclientgui.h"
#include "ui_scanclientgui.h"
#include <QDebug>
#include <QDir>
#include <QDateTime>
#include <QThread>
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
    m_iamBusy = false;
    m_dataAvailable = false;
    m_isScanStopped = true;
    m_dataEnd = true;
    m_sourceMask = 0; 

    buildMainGui();

    doCalculatorStuff();
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
    case COMMAND_SCAN_NEW_DATA:
        newScanData();
        break;
    case COMMAND_SCAN_DATA_DELIVERY:
        dataDelivery();
        break;
    case COMMAND_SCAN_DATA_END:
        dataEnd();
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
    qDebug() << m_logName + "send start scan";

    m_bufferOut.clear();
    m_bufferIn.clear();
    m_dataBufferInList.clear();
    m_isScanStopped = false;
    m_dataEnd = false;
    m_bufferOut.append(COMMAND_SCAN_START);
    tcpSendData();
}

void ScanClientGui::scanStop()
{
    qDebug() << m_logName + "send stop scan";
    m_bufferOut.append(COMMAND_SCAN_STOP);
    m_isScanStopped = true;
    m_iamBusy = false;
    tcpSendData();
}

void ScanClientGui::setScanProgress()
{

}

void ScanClientGui::getScanData()
{          
    if(!m_isScanStopped)
    {
        qDebug() << m_logName + "get scan data";
        m_iamBusy = false;
        m_bufferOut.append(COMMAND_SCAN_GET_DATA);
        tcpSendData();        
    }
    else
    {
        qDebug() << m_logName + "scan was stopped";
    }
}

void ScanClientGui::newScanData()
{
    m_dataAvailable = true;
    qDebug() << m_logName + "new scan data";

    if(!m_iamBusy)
    {
        qDebug() << m_logName + "new scan data handle";
        m_dataAvailable = false;
        m_iamBusy = true;
        getScanData();
    }
}

void ScanClientGui::dataDelivery()
{
    if(!m_dataEnd)
    {
        qDebug() << "Scandata: " << m_bufferIn.size();
        m_dataBufferInList.append(m_bufferIn);

        commandHandler(COMMAND_SCAN_GET_DATA);
    }
    else
    {
        qDebug() << "No data available" << m_bufferIn;
    }
}

void ScanClientGui::dataEnd()
{
    m_dataEnd = true;
    qDebug() << "Received data: " << m_dataBufferInList.size();
    prepareData();
}

void ScanClientGui::actuatorJogBack()
{
//    m_dataBufferOut.append(0x01);
//    m_dataBufferOut.append(0x01);
//    tcpSendData();
}

void ScanClientGui::actuatorJogForward()
{
//    m_dataBufferOut.append(0x01);
//    m_dataBufferOut.append(0x02);
//    tcpSendData();
}

void ScanClientGui::actuatorHome()
{
//    m_dataBufferOut.append(0x01);
//    m_dataBufferOut.append(0x03);
//    tcpSendData();
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
//    m_dataBufferOut.append(QString::number(COMMAND_READY,10));
//    m_tcpClient->sendData(m_dataBufferOut);

//    qInfo() << m_logName + "COMMAND_READY";
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

    connect(ui->scanControlWidget, SIGNAL(startScanSignal()), this, SLOT(scanStart()));
    connect(ui->scanControlWidget, SIGNAL(stopScanSignal()), this, SLOT(scanStop()));
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
    connect(m_tcpClient, SIGNAL(newDataAvailableSignal()), this, SLOT(tcpReadData()));
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
        m_tcpClient->sendData(m_bufferOut);
        m_bufferOut.clear();
    }
    else
    {
        qWarning() << m_logName + "tcpSendData: NOT CONNECTED";
    }
}

void ScanClientGui::tcpReadData()
{
    m_bufferIn.clear();
    m_tcpClient->getReceivedData(m_bufferIn);
    //qInfo() << m_logName + "tcpReadData: " << m_bufferIn;
    commandHandler(m_bufferIn.at(0));
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

void ScanClientGui::doCalculatorStuff()
{
    imageWidth = 255;         //Image resolution
    imageWidthDivider = 2;    //Result image resolution
    numberOfSensors = 8;       //Sensor in array
    innerDiameter = 70;
    outerdiameter = 140;

    imageCalculator.setDimensions(numberOfSensors, imageWidth, innerDiameter, outerdiameter);
}

void ScanClientGui::prepareData()
{
    m_scanDataList.clear();

    for(int i = 0; i < m_dataBufferInList.size(); i++)
    {
        QList<quint16> dataList;

        for(int j = 1; j < m_dataBufferInList.at(i).size() - 1; j+=2)
        {
            quint16 data0 = 0;
            data0 = (m_dataBufferInList.at(i).at(j) << 8) | data0;
            data0 = m_dataBufferInList.at(i).at(j+1) | data0;
            dataList.append(data0);
        }
        m_scanDataList.append(dataList);
    }

    for(int i = 0; i < m_scanDataList.at(0).size(); i++)
    {
       //qDebug() << i << m_scanDataList.at(0).at(i);
    }


    processData(0,0);
}

void ScanClientGui::processData(quint16 scanNumber, quint16 arrayNumber)
{   
    qDebug() << "processdata: " << scanNumber << arrayNumber;
    quint8 m_numberOfScansPerArray = 8;

    QTime time;
    time.start();
    qWarning() << "*************************START*****************************************";

    QList<QImage* > imageList;
    for(int i = 0; i < m_numberOfScansPerArray; i++)
    {
        imageList.append(new QImage(imageWidth, imageWidth, QImage::Format_Grayscale8));
        imageList.at(i)->fill(qRgb(0,0,0));
    }

    QImage imageSum(imageWidth  + (imageWidth / imageWidthDivider), imageWidth + (imageWidth / imageWidthDivider), QImage::Format_Grayscale8);
    imageSum.fill(qRgb(0,0,0));

    for(int source = 0; source < m_numberOfScansPerArray; source++)
    {
        QList<quint16> list;
        for(int sensor = 2; sensor < 10; sensor++)
        {
            list.append((quint16)((double)((m_scanDataList.at(scanNumber).at((source * 10) + sensor)))));// / ui->verticalSlider->value()) + 0.5 ));
        }
        qDebug() << list;
        imageCalculator.calculateBeam(list, 0x0001 << m_scanDataList.at(scanNumber).at(source * 10 + 1), *imageList.at(source));

    }

    for(int i = 0; i < 8; i++)
    {
        imageCalculator.mergeImages(*imageList.at(i), 0.0, imageSum);
    }

// Use to check image offset
//    for(int i = 0; i < 8; i++)
//    {
//        imageCalculator.mergeImages(*imageList.at(i), 45.0, imageSum);
//    }

//    imageSum.invertPixels();

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
//        imageList.at(i)->save(filepath
//                                  + QString("IMG%1_%2.png")
//                                  .arg(i,3,10, QChar('0')));
//    }

//    imageSum.save(filepath + "sum.png");

    for(int i = 0; i < imageList.size(); i++)
    {
        delete imageList.at(i);
    }

qWarning() << "*************************TIME*****************************************";
qWarning() << time.elapsed();
qWarning() << "*************************STOP*****************************************";

    m_iamBusy = false;


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



