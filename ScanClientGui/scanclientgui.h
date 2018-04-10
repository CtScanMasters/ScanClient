#ifndef SCANCLIENTGUI_H
#define SCANCLIENTGUI_H

#include <QMainWindow>
#include <QTabWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QList>
#include <QLayout>

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

    QList<ArrayWidget *> m_arrayWidgetList;
    QGroupBox *m_arrayBox1;
    QGridLayout *m_arrayBoxGridLayout1;
    QGridLayout *m_arrayTabGridLayout;
    quint8 m_arrayCount;

};

#endif // SCANCLIENTGUI_H
