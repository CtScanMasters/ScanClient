#include "tcpclient.h"
#include <QNetworkInterface>
#include <QDebug>

TcpClient::TcpClient()
:   QObject(), SocketHandler()

{
    m_tcpSocket = new QTcpSocket(this);
    m_reconnectTimer = new QTimer(this);

    m_hostIpAddress.clear();
    m_hostPort = 0;

    m_myIp = QHostAddress(handleRetreiveIpAddress());

    debugMessage("Starting");

    m_autoReconnectTime = 5000;

    connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(m_tcpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this, SLOT(displaySocketState(QAbstractSocket::SocketState)));

    debugMessage(QString("CLIENT IP: %1 READY").arg(m_myIp.toString()));
    connectToHost();

}

void TcpClient::connectToHost()
{
    if(!m_hostIpAddress.toIPv4Address() || !m_hostPort)
    {
        debugMessage("No IP or Port set!");
    }
    else
    {
        m_tcpSocket->connectToHost(m_hostIpAddress, m_hostPort);
        //m_reconnectTimer->start(m_autoReconnectTime);
    }
}

void TcpClient::disconnectFromHost()
{
    m_tcpSocket->disconnectFromHost();
    m_reconnectTimer->stop();
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
        {
            //m_reconnectTimer->start(m_autoReconnectTime);
        }
    }
    else
    {
        m_reconnectTimer->stop();
    }

    emit socketStateChangedSignal();
}

void TcpClient::newDataAvailable()
{
    emit newDataAvailableSignal();
}

void TcpClient::setHostIpAddress(QString ipAddress)
{
    m_hostIpAddress = QHostAddress(ipAddress);
}

void TcpClient::setHostPort(quint64 port)
{
    m_hostPort = port;
}
