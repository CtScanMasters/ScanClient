#ifndef ACTUATORWIDGET_H
#define ACTUATORWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <Qlabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>

class ActuatorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ActuatorWidget(QWidget *parent = 0);
    ~ActuatorWidget();
    void setPosition(quint64 position);
    void setStatus(QString status);
    void setEnabled(bool status);

private:
    QString m_logName;
    QPushButton *m_jogForwardButton;
    QPushButton *m_jogBackButton;
    QPushButton *m_homeButton;
    QLabel *m_statusLabel;
    QLabel *m_positionLabel;
    QLineEdit *m_statusLineEdit;
    QLineEdit *m_positionLineEdit;
    QGridLayout *m_mainGridlayout;

private slots:
    void jogForward();
    void jogBack();
    void homeActuator();
    void stopMovement();


signals:
    void jogForwardSignal();
    void jogBackSignal();
    void homeActuatorSignal();
    void stopMovementSignal();

};

#endif // ACTUATORWIDGET_H
