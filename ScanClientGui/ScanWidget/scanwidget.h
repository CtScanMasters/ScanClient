#ifndef SCANWIDGET_H
#define SCANWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QGridLayout>
#include <QLineEdit>
#include <QSpinBox>

class ScanWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ScanWidget(QWidget *parent = 0);
    ~ScanWidget();
    void setStatus(QString status, quint8 progress);
    void setEnabled(bool status);
    void isScanning(bool status);
    quint8 getNumberOfScans();

private:
    QString m_logName;
    QPushButton *m_startScanButton;
    QPushButton *m_stopScanButton;
    QLabel *m_statusLabel;
    QLabel *m_NumberOfScansLabel;
    QLineEdit *m_scanLineEdit;
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
