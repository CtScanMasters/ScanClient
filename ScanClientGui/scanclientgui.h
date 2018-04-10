#ifndef SCANCLIENTGUI_H
#define SCANCLIENTGUI_H

#include <QMainWindow>
#include <QTabWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QList>

#include "3DScatterWidget/scatterwidget.h"
#include "ActuatorWidget/actuatorwidget.h"
#include "ArrayWidget/arraywidget.h"
#include "FileHandlerWidget/filehandlerwidget.h"
#include "ScanWidget/scanwidget.h"
#include "TcpClientWidget/tcpclientwidget.h"


namespace Ui {
class ScanClientGui;
}

class ScanClientGui : public QMainWindow
{
    Q_OBJECT

public:
    explicit ScanClientGui(QWidget *parent = 0);
    ~ScanClientGui();

private:
    Ui::ScanClientGui *ui;
    QTabWidget *m_tabWidget;
    QGroupBox *m_fileHandlerBox;
    QGroupBox *m_scanBox;
    QGroupBox *m_connectionBox;
    QGroupBox *m_actuatorBox;
    QPushButton *m_exitButton;

    ScatterWidget *m_scatterWidget;
    ActuatorWidget *m_actuatorWidget;
    FileHandlerWidget *m_fileHandlerWidget;
    ScanWidget *m_scanWidget;
    QList<ArrayWidget *> *m_arrayWidgetList;

    void buildGui();



};

#endif // SCANCLIENTGUI_H
