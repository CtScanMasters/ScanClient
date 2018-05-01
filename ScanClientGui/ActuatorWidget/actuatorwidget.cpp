#include "actuatorwidget.h"
#include <QDebug>

ActuatorWidget::ActuatorWidget(QWidget *parent) :
    QWidget(parent)
{
    m_logName = "ActuatorWidget : ";

    qInfo() << m_logName + "creating widget";

    m_jogForwardButton = new QPushButton(this);
    m_jogBackButton = new QPushButton(this);
    m_homeButton = new QPushButton(this);
    m_statusLabel = new QLabel(this);
    m_positionLabel = new QLabel(this);
    m_statusLineEdit = new QLineEdit(this);
    m_positionLineEdit = new QLineEdit(this);
    m_mainGridlayout = new QGridLayout(this);

    m_jogForwardButton->setText(">");
    m_jogForwardButton->setToolTip("jog forward");
    m_jogBackButton->setText("<");
    m_jogBackButton->setToolTip("jog backward");
    m_homeButton->setText("HOME");
    m_homeButton->setToolTip("Initialize acuator axis");
    m_statusLabel->setText("Status: ");
    m_positionLabel->setText("Position: ");
    m_statusLineEdit->setReadOnly(true);
    m_statusLineEdit->setPlaceholderText("unkown");
    m_positionLineEdit->setReadOnly(true);
    m_positionLineEdit->setPlaceholderText("unkown");

    m_mainGridlayout->addWidget(m_statusLabel, 0, 0, 1, 1);
    m_mainGridlayout->addWidget(m_statusLineEdit, 0, 1, 1, 4);
    m_mainGridlayout->addWidget(m_positionLabel, 1, 0, 2, 1);
    m_mainGridlayout->addWidget(m_positionLineEdit, 1, 1, 2, 4);
    m_mainGridlayout->addWidget(m_jogBackButton, 3, 0, 1, 2);
    m_mainGridlayout->addWidget(m_homeButton, 3, 2, 1, 1);
    m_mainGridlayout->addWidget(m_jogForwardButton, 3, 3, 1, 2);


    connect(m_jogForwardButton, SIGNAL(clicked(bool)), this, SLOT(jogForward()));
    connect(m_jogBackButton, SIGNAL(clicked(bool)), this, SLOT(jogBack()));
    connect(m_homeButton, SIGNAL(clicked(bool)), this, SLOT(homeActuator()));

    setLayout(m_mainGridlayout);

}

ActuatorWidget::~ActuatorWidget()
{

}

void ActuatorWidget::jogForward()
{
    qInfo() << m_logName + "jogForward";
    emit jogForwardSignal();
}

void ActuatorWidget::jogBack()
{
    qInfo() << m_logName + "jogBack";
    emit jogBackSignal();
}

void ActuatorWidget::homeActuator()
{
    qInfo() << m_logName + "homeActuator";
    emit homeActuatorSignal();
}

void ActuatorWidget::setPosition(quint64 position)
{
    qInfo() << m_logName + "setPosition :" << position;
    m_positionLineEdit->setText(QString::number(position));
}

void ActuatorWidget::setStatus(QString status)
{
    qInfo() << m_logName + "status changed: " + status;
    m_statusLineEdit->setText(status);
}
