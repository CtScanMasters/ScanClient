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
    TcpClient(QString ipAddress, quint64 port);
    void sendData(QByteArray byteArray);
    void disconnectFromHost();
    void newDataAvailable();

private:

    QTcpSocket *m_tcpSocket;
    QTimer *m_reconnectTimer;
    quint64 autoReconnectTime;
    QHostAddress m_hostIpAddress;
    quint64 m_hostPort;
    QHostAddress m_myIp;
    QString m_myName;
    QTimer sendTimer;

private slots:
    void readData();
    void connectToHost();
    void displaySocketState(QAbstractSocket::SocketState socketState);

signals:
    void newDataAvailableSignal();


};

#endif // TCPCLIENT_H
