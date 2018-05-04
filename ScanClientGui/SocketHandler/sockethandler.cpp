#include "sockethandler.h"
#include <QtNetwork>

SocketHandler::SocketHandler()
{
    m_logName = "SocketHandler : ";
    qInfo() << m_logName + "starting";

    m_isSocketReady = false;
}

QString SocketHandler::handleRetreiveIpAddress()
{
    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

    qInfo() << m_logName + "handleRetreiveIpAddress: "  << ipAddress;
    return(ipAddress);
}

quint64 SocketHandler::handleSendData(QTcpSocket *tcpSocket, QByteArray &byteArray)
{
    QByteArray block;
    QDataStream dataStreamOut(&block, QIODevice::WriteOnly);
    dataStreamOut.setVersion(QDataStream::Qt_4_0);

    dataStreamOut << byteArray;

    quint64 sendDataSize = tcpSocket->write(block);

    qInfo() << m_logName + "handleSendData: " <<QString("Set: %1 bytes to %2")
                 .arg(sendDataSize).arg(tcpSocket->peerAddress().toString());

    return sendDataSize;
}

bool SocketHandler::handleReceiveData(QTcpSocket *tcpSocket)
{
        QDataStream m_dataStreamIn;
        m_dataStreamIn.setDevice(tcpSocket);
        m_dataStreamIn.setVersion(QDataStream::Qt_4_0);

        m_dataStreamIn.startTransaction();

        QByteArray byteArray;
        m_dataStreamIn >> byteArray;                

        if(!m_dataStreamIn.commitTransaction())
        {
               qWarning() << m_logName + "handleReceiveData: commitTransaction FAILED";
               return(false);
        }
        else
        {
            m_mutex.lock();
            if(m_dataInBufferList.size() > 10)
            {
                qWarning() << m_logName + "handleReceiveData: BUFFER OVERFLOW";
                m_dataInBufferList.removeLast();
            }
            m_dataInBufferList.prepend(byteArray);
            m_mutex.unlock();

            qInfo() << m_logName + "handleReceiveData: " + QString("received %1 bytes from %2")
                         .arg(byteArray.size()).arg(tcpSocket->peerAddress().toString());
            return(true);
        }
}

bool SocketHandler::getReceivedData(QByteArray &byteArray)
{
    if(m_dataInBufferList.size() > 0)
    {
        byteArray = m_dataInBufferList.last();

        m_mutex.lock();
        m_dataInBufferList.removeLast();
        m_mutex.unlock();
        return true;
    }
    else
    {
        qWarning() << m_logName + "getReceivedData: BUFFER EMPTY";
        return false;
    }

}

bool SocketHandler::hanldeSocketState(QAbstractSocket::SocketState socketState)
{
    QString socketStateString;

    m_isSocketReady = false;

    switch (socketState)
    {
    case QAbstractSocket::UnconnectedState:
        socketStateString.append("disconnected");
        break;
    case QAbstractSocket::HostLookupState:
        socketStateString.append("lookup state");
        break;
    case QAbstractSocket::ConnectingState:
    {
        socketStateString.append("connecting");
        break;
    }
    case QAbstractSocket::ConnectedState:
        socketStateString.append("connected");
        m_isSocketReady = true;
        break;
    case QAbstractSocket::BoundState:
        socketStateString.append("bounding");
        break;
    case QAbstractSocket::ClosingState:
        socketStateString.append("closing");
        break;
    case QAbstractSocket::ListeningState:
        socketStateString.append("listening");
        break;
    default:
        socketStateString.append("unknown");
    }

    m_socketState = socketStateString;
    qInfo() << m_logName + "hanldeSocketState: " + m_socketState;

    return m_isSocketReady;
}

QString SocketHandler::getSocketState()
{
    return m_socketState;
}

