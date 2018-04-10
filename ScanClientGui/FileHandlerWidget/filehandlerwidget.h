#ifndef FILEHANDLERWIDGET_H
#define FILEHANDLERWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>



class FileHandlerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FileHandlerWidget(QWidget *parent = 0);
    ~FileHandlerWidget();

private:
    QPushButton *m_loadSettingsButton;
    QPushButton *m_loadScanButton;
    QPushButton *m_editSettingsButton;
    QGridLayout *m_mainGridLayout;

private slots:
    void loadSettings();
    void loadScan();
    void editSettings();

signals:
    void loadSettingsSignal();
    void loadScanSignal();
    void editSettingsSignal();


};

#endif // FILEHANDLERWIDGET_H
