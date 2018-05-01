#include "scanclientgui.h"
#include <QApplication>
#include "MessageLogger/messagelogger.h"

void msgHandler(QtMsgType type, const QMessageLogContext &, const QString & str)
{
    MessageLogger::getInstance()->messageHandler(type, str);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ScanClientGui w;

    MessageLogger *messageLogger = MessageLogger::getInstance();
    qInstallMessageHandler(msgHandler);

    w.show();

    return a.exec();
}
