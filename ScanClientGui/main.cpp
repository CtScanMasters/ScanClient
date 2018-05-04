#include "scanclientgui.h"
#include <QApplication>
#include "MessageLogger/messagelogger.h"

#include <QDateTime>
#include <QFile>

// Smart pointer to log file
QScopedPointer<QFile>   m_logFile;

void msgHandler(QtMsgType type, const QMessageLogContext &, const QString & str)
{
    QString messageString;

    QDateTime dateTime;
    dateTime = QDateTime::currentDateTime();

    messageString.append(dateTime.toString("yyyy-MM-dd hh:mm:ss:zzz"));
    messageString.append("  ");

    switch (type) {
    case QtDebugMsg:
        messageString.append(QString("DEBUG : %1").arg(str));
        break;
    case QtWarningMsg:
        messageString.append(QString("WARNING : %1").arg(str));
        break;
    case QtCriticalMsg:
        messageString.append(QString("CRITICAL : %1").arg(str));
        break;
    case QtInfoMsg:
        messageString.append(QString("INFO : %1").arg(str));
        break;
    case QtFatalMsg:
        messageString.append(QString("FATAL : %1").arg(str));
        abort();
    }

    QTextStream out(m_logFile.data());
    out << messageString << endl;
    out.flush();

    MessageLogger::getInstance()->messageHandler(messageString);
}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    MessageLogger *messageLogger = MessageLogger::getInstance();
    m_logFile.reset(new QFile("SCANLOG.log"));
    m_logFile.data()->open(QFile::WriteOnly|QFile::Truncate);
    m_logFile.data()->close();
    m_logFile.data()->open(QFile::Append | QFile::Text);
    qInstallMessageHandler(msgHandler);

    qInfo() << "------------BUILD APPLICATION CT SCANMASTER-------------";

    ScanClientGui w;
    w.show();

    return a.exec();
}
