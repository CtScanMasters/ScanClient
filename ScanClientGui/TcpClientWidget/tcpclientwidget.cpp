#include "tcpclientwidget.h"


TcpClientWidget::TcpClientWidget(QWidget *parent) :
    QWidget(parent)
{
    m_clientIpLabel = new QLabel(this);
    m_hostIpLabel = new QLabel(this);
    m_hostPortLabel = new QLabel(this);
    m_statusLabel = new QLabel(this);
    m_statusLineEdit = new QLineEdit(this);
    m_hostIpLineEdit = new QLineEdit(this);
    m_clienIpLineEdit = new QLineEdit(this);
    m_hostPortLineEdit = new QLineEdit(this);
    m_connectButton = new QPushButton(this);
    m_disconnectButton = new QPushButton(this);
    m_mainGridLayout = new QGridLayout(this);


    m_clientIpLabel->setText("Client IP: ");
    m_hostIpLabel->setText("Host IP: ");
    m_hostPortLabel->setText("Host PORT:");
    m_statusLabel->setText("Status: ");
    m_connectButton->setText("Connect");
    m_connectButton->setToolTip("connect to host");
    m_disconnectButton->setText("Disconnect");
    m_disconnectButton->setToolTip("disconnect from host");
    m_statusLineEdit->setReadOnly(true);
    m_statusLineEdit->setPlaceholderText("unkown");
    m_clienIpLineEdit->setReadOnly(true);
    m_clienIpLineEdit->setPlaceholderText("xxx.xxx.xxx.xxx");

    m_hostIpLineEdit->setPlaceholderText("Host IP address xxx.xxx.xxx.xxx");
    m_hostPortLineEdit->setPlaceholderText("Host PORT number 1-99999");

    QString ipRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";
    QRegExp ipRegex ("^" + ipRange
                     + "\\." + ipRange
                     + "\\." + ipRange
                     + "\\." + ipRange + "$");
    ipValidator = new QRegExpValidator(ipRegex, this);
    m_hostIpLineEdit->setValidator(ipValidator);

    portValidator = new QIntValidator(1, 99999, this);
    m_hostPortLineEdit->setValidator(portValidator);

    m_mainGridLayout->addWidget(m_statusLabel, 0, 0, 1, 1);
    m_mainGridLayout->addWidget(m_statusLineEdit, 0, 1, 1, 3);
    m_mainGridLayout->addWidget(m_hostIpLabel, 1, 0, 1, 1);
    m_mainGridLayout->addWidget(m_hostIpLineEdit, 1, 1, 1, 3);
    m_mainGridLayout->addWidget(m_hostPortLabel, 2, 0, 1, 1);
    m_mainGridLayout->addWidget(m_hostPortLineEdit, 2, 1, 1, 3);
    m_mainGridLayout->addWidget(m_clientIpLabel, 3, 0, 1, 1);
    m_mainGridLayout->addWidget(m_clienIpLineEdit, 3, 1, 1, 3);
    m_mainGridLayout->addWidget(m_connectButton, 4, 0, 1, 2);
    m_mainGridLayout->addWidget(m_disconnectButton, 4, 2, 1, 2);

    setLayout(m_mainGridLayout);

    connect(m_connectButton, SIGNAL(clicked(bool)), this, SLOT(connectToHost()));
    connect(m_disconnectButton, SIGNAL(clicked(bool)), this, SLOT(disconnectFromHost()));

}

TcpClientWidget::~TcpClientWidget()
{

}

void TcpClientWidget::connectToHost()
{
    emit connectToHostSignal();
}

void TcpClientWidget::disconnectFromHost()
{
    emit disconnectFromHostSignal();
}

void TcpClientWidget::setClientIpAddress(QString ipAddress)
{
    QString string = "Client IP: ";
    string.append(ipAddress);
    m_clientIpLabel->setText(string);
}

void TcpClientWidget::setStatus(QString status)
{
    m_statusLineEdit->setText(status);
}

QString TcpClientWidget::getHostIpAddress()
{
    return(m_hostIpLineEdit->text());
}

QString TcpClientWidget::getHostPort()
{
    return(m_hostPortLineEdit->text());
}

