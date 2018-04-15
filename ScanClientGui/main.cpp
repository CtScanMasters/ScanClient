#include "scanclientgui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ScanClientGui w;
    w.show();


    return a.exec();
}
