#ifndef SCANWIDGET_H
#define SCANWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QGridLayout>
#include <QLineEdit>

class ScanWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ScanWidget(QWidget *parent = 0);
    ~ScanWidget();
    void setStatus(QString status, quint8 progress);

private:
    QString m_logName;
    QPushButton *m_startScanButton;
    QPushButton *m_stopScanButton;
    QLabel *m_statusLabel;
    QProgressBar *m_progressBar;
    QGridLayout *m_mainGridLayout;
    QLineEdit *m_statusLineEdit;


private slots:
    void startScan();
    void stopScan();

signals:
    void startScanSignal();
    void stopScanSignal();

};

#endif // SCANWIDGET_H
