#ifndef SOCKETHANDLER_H
#define SOCKETHANDLER_H

#include <QTcpSocket>
#include <QMutex>


class SocketHandler
{

private:
    QList<QByteArray> m_dataInBufferList;
    QMutex m_mutex;

    QString m_socketState;

protected:    
    quint64 handleSendData(QTcpSocket *tcpSocket, QByteArray &byteArray);
    bool handleReceiveData(QTcpSocket *tcpSocket);
    bool hanldeSocketState(QAbstractSocket::SocketState socketState);
    void debugMessage(QString message);


public:
    SocketHandler();
    void getReceivedData(QByteArray &byteArray);
    QString getSocketState();
    QString handleRetreiveIpAddress();


};

#endif // SOCKETHANDLER_H
