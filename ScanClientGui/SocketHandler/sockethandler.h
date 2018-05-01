#ifndef SOCKETHANDLER_H
#define SOCKETHANDLER_H

#include <QTcpSocket>
#include <QMutex>


class SocketHandler
{

private:
    QList<QByteArray> m_dataInBufferList;
    QMutex m_mutex;
    QString m_logName;


protected:    
    quint64 handleSendData(QTcpSocket *tcpSocket, QByteArray &byteArray);
    bool handleReceiveData(QTcpSocket *tcpSocket);
    bool hanldeSocketState(QAbstractSocket::SocketState socketState);
    QString m_socketState;
    bool m_isSocketReady;

public:
    SocketHandler();
    void getReceivedData(QByteArray &byteArray);
    QString getSocketState();
    QString handleRetreiveIpAddress();


};

#endif // SOCKETHANDLER_H
