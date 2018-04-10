#include "tcpclient.h"
#include <QNetworkInterface>
#include <QDebug>

TcpClient::TcpClient(QString ipAddress, quint64 port)
:   QObject(), SocketHandler()

{
    m_tcpSocket = new QTcpSocket(this);
    m_reconnectTimer = new QTimer(this);

    m_hostIpAddress = QHostAddress(ipAddress);
    m_hostPort = port;

    m_myIp = QHostAddress(handleRetreiveIpAddress());

    debugMessage("Starting");


    autoReconnectTime = 5000;

    connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(m_reconnectTimer, SIGNAL(timeout()), this, SLOT(connectToHost()));
    connect(m_tcpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this, SLOT(displaySocketState(QAbstractSocket::SocketState)));

    debugMessage(QString("CLIENT IP: %1 READY").arg(m_myIp.toString()));
    connectToHost();

}

void TcpClient::connectToHost()
{
    m_tcpSocket->connectToHost(m_hostIpAddress, m_hostPort);
}

void TcpClient::disconnectFromHost()
{
    m_tcpSocket->disconnect();
}

void TcpClient::sendData(QByteArray byteArray)
{
    handleSendData(m_tcpSocket, byteArray);
}

void TcpClient::readData()
{
    if(handleReceiveData(m_tcpSocket))
    {
        newDataAvailable();
    }
}

void TcpClient::displaySocketState(QAbstractSocket::SocketState socketState)
{
    if(!hanldeSocketState(socketState))
    {
        if(!m_reconnectTimer->isActive())
            m_reconnectTimer->start(autoReconnectTime);
    }
    else
    {
        m_reconnectTimer->stop();
    }
}

void TcpClient::newDataAvailable()
{
    emit newDataAvailableSignal();
}
