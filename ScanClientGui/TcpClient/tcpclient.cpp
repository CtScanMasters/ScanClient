#include "tcpclient.h"
#include <QNetworkInterface>
#include <QDebug>

TcpClient::TcpClient()
:   QObject(), SocketHandler()

{
    m_logName = "TcpClient : ";
    qInfo() << m_logName + "starting";

    m_tcpSocket = new QTcpSocket(this);
    m_reconnectTimer = new QTimer(this);

    m_hostIpAddress.clear();
    m_hostPort = 0;

    m_myIp = QHostAddress(handleRetreiveIpAddress());

    //m_autoReconnectTime = 5000;
    //qInfo() << m_logName + "m_autoReconnectTime: " << m_autoReconnectTime;

    connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(m_tcpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this, SLOT(displaySocketState(QAbstractSocket::SocketState)));


    qInfo() << m_logName + QString("CLIENT IP: %1 READY").arg(m_myIp.toString());


}

void TcpClient::connectToHost()
{
    if(!m_hostIpAddress.toIPv4Address() || !m_hostPort)
    {
        qWarning() << m_logName + "connectToHost: NO IP OR PORT SET";
    }
    else
    {
        m_tcpSocket->connectToHost(m_hostIpAddress, m_hostPort);
        //connect(m_reconnectTimer, SIGNAL(timeout()), this, SLOT(connectToHost()));
        //m_reconnectTimer->start(m_autoReconnectTime);
        qInfo() << m_logName + QString("connectToHost IP: %1 PORT: %2")
                                                   .arg(m_hostIpAddress.toString())
                                                   .arg(m_hostPort);
    }


}

void TcpClient::disconnectFromHost()
{
    m_tcpSocket->disconnectFromHost();
    //m_reconnectTimer->stop();
    //disconnect(m_reconnectTimer, SIGNAL(timeout()), this, SLOT(connectToHost()));
    qInfo() << m_logName + "disconnectFromHost";
}

bool TcpClient::sendData(QByteArray byteArray)
{
    if(!m_isSocketReady)
    {
        qWarning() << m_logName + "sendData: FAILED NOT CONNECTED";
        return false;
    }
    else
    {
        handleSendData(m_tcpSocket, byteArray);
        return true;
    }
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
    hanldeSocketState(socketState);

//    if(!m_isSocketReady)
//    {
//        if(!m_reconnectTimer->isActive())
//        {
//            m_reconnectTimer->start(m_autoReconnectTime);
//            qInfo() << m_logName + "displaySocketState: autoreconnect";
//        }
//    }
//    else
//    {
//        m_reconnectTimer->stop();
//    }

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
