#ifndef TCPCLIENTWIDGET_H
#define TCPCLIENTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QRegExpValidator>
#include <QLineEdit>

class TcpClientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TcpClientWidget(QWidget *parent = 0);
    ~TcpClientWidget();


    void setClientIpAddress(QString ipAddress);
    void setStatus(QString status);
    QString getHostIpAddress();
    QString getHostPort();

private:
    QLabel *m_clientIpLabel;
    QLabel *m_hostIpLabel;
    QLabel *m_hostPortLabel;
    QLabel *m_statusLabel;
    QLineEdit *m_hostIpLineEdit;
    QLineEdit *m_hostPortLineEdit;
    QLineEdit *m_clienIpLineEdit;
    QPushButton *m_connectButton;
    QPushButton *m_disconnectButton;
    QLineEdit *m_statusLineEdit;
    QGridLayout *m_mainGridLayout;

    QRegExpValidator *ipValidator;
    QValidator *portValidator;



public slots:
    void connectToHost();
    void disconnectFromHost();
    void setConnected(bool status);

signals:
    void connectToHostSignal();
    void disconnectFromHostSignal();

};

#endif // TCPCLIENTWIDGET_H
