#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QDataStream>
#include <QTcpSocket>
#include <QHostAddress>
#include <QTimer>
#include "SocketHandler/sockethandler.h"

class TcpClient : public QObject, public SocketHandler
{
    Q_OBJECT

public:
    TcpClient();
    bool sendData(QByteArray byteArray);
    void disconnectFromHost();
    void newDataAvailable();
    void setHostIpAddress(QString ipAddress);
    void setHostPort(quint64 port);


private:
    QString m_logName;
    QTcpSocket *m_tcpSocket;
    QTimer *m_reconnectTimer;
    quint64 m_autoReconnectTime;
    QHostAddress m_hostIpAddress;
    quint64 m_hostPort;
    QHostAddress m_myIp;
    QString m_myName;

private slots:
    void readData();    
    void displaySocketState(QAbstractSocket::SocketState socketState);

public slots:
    void connectToHost();

signals:
    void newDataAvailableSignal();
    void socketStateChangedSignal();


};

#endif // TCPCLIENT_H
