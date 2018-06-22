#ifndef SCANCLIENTGUI_H
#define SCANCLIENTGUI_H

#include <QMainWindow>
#include <QTabWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QList>
#include <QLayout>

#include "3DScatterWidget/scatterwidget.h"
#include "ActuatorWidget/actuatorwidget.h"
#include "ArrayWidget/arraywidget.h"
#include "FileHandlerWidget/filehandlerwidget.h"
#include "ScanWidget/scanwidget.h"
#include "TcpClientWidget/tcpclientwidget.h"
#include "TcpClient/tcpclient.h"
#include "MessageLogger/messagelogger.h"
#include "ImageCalculator/imagecalculator.h"
#include "ImageCalculator/imageprocessmanager.h"
#include "commandlist.h"


namespace Ui {
class ScanClientGui;
}

class ScanClientGui : public QMainWindow
{
    Q_OBJECT

public:
    explicit ScanClientGui(QWidget *parent = 0);
    ~ScanClientGui();

private:
    Ui::ScanClientGui *ui;

    enum COMMANDLIST
    {
        COMMAND_SCAN_START,
        COMMAND_SCAN_STOP,
        COMMAND_SCAN_SET_PROGRESS,
        COMMAND_SCAN_GET_DATA,
        COMMAND_SCAN_NEW_DATA,
        COMMAND_SCAN_DATA_DELIVERY,
        COMMAND_SCAN_DATA_END,
        COMMAND_ACTUATOR_FORWARD,
        COMMAND_ACTUATOR_BACKWARD,
        COMMAND_ACTUATOR_POSITION,
        COMMAND_ACTUATOR_HOME,
        COMMAND_ACTUATOR_STOP,
        COMMAND_SENSOR_VALUE,
        COMMAND_SOURCE_VALUE,
        COMMAND_READY,
        COMMAND_NOT_READY

    };


    QString m_logName;

    QList<ArrayWidget *> m_arrayWidgetList;
    QGroupBox *m_arrayBox1;
    QGridLayout *m_arrayBoxGridLayout1;
    QGridLayout *m_arrayTabGridLayout;
    quint8 m_arrayCount;
    quint8 m_sourceMask;

    TcpClient *m_tcpClient;
    bool m_tcpIsConnected;
    bool m_iamBusy;
    bool m_dataAvailable;
    bool m_isScanStopped;
    bool m_dataEnd;
    bool m_actuatorIsmoving;
    QByteArray m_bufferOut;
    QByteArray m_bufferIn;

    quint8 m_numberOfscans;
    quint8 m_scanDistance;
    quint8 m_numberOfScansPerArray;
    quint8 m_scanDataOffset;
    quint8 m_scanDataSize;

    QVector<QByteArray> m_dataBufferInList;
    QVector<QVector<quint16>> m_scanDataList;

    ImageProcessManager *m_imageProcessManager;

    MessageLogger *m_dataLogger;

    void buildMainGui();
    void buildArrayTab();
    void buildTcpClient();
    void buildActuatorControl();
    void actuatorStatusChange();

    void drawGraph(QList<uint16_t> sensorValueList, quint8 source);
    quint16 m_imageWidth;

private slots:
    void commandHandler(quint16 command);
    void scanStart();
    void scanStop();
    void setScanProgress();
    void getScanData();
    void actuatorJogForward();
    void actuatorJogBack();
    void actuatorPosition();
    void actuatorHome();
    void actuatorStop();
    void sendNotReady();
    void sendReady();
    void newScanData();
    void dataDelivery();
    void dataEnd();
    void prepareData();

    void updateImageProcessStatus(quint16 imageNumber);
    void imageProcessingDone(QString filepath);


    void tcpConnect();
    void tcpDisconnect();
    void tcpStateChange();
    void tcpSendData();
    void tcpReadData();
    void tcpConnectTimeOut();

    void arraySetSource();
    void processData();





};

#endif // SCANCLIENTGUI_H
