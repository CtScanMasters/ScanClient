#include "messagelogger.h"

#include <QDebug>
#include <QDateTime>

MessageLogger* MessageLogger::instance = 0;

MessageLogger::MessageLogger()
{
    m_textEditorEnabled = false;
}

MessageLogger* MessageLogger::getInstance()
{
    if (instance == 0)
    {
        instance = new MessageLogger();
        instance->clearLogFile();
    }

    return instance;
}


void MessageLogger::messageHandler(QtMsgType type, const QString &str)
{
    //const char * msg = str.toStdString().c_str();

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

    QTextStream ts(&m_logFile);
    ts << messageString << endl;

    if(m_textEditorEnabled)
    {
        m_textEditor->appendPlainText(messageString);
    }
}

void MessageLogger::setTextEdit(QPlainTextEdit *textEditor)
{
    m_textEditor = textEditor;
    m_textEditorEnabled = true;
}

void MessageLogger::clearLogFile()
{
    m_logFile.setFileName("SCANLOG.log");
    m_logFile.open(QFile::WriteOnly|QFile::Truncate);
    m_logFile.close();
    m_logFile.open(QIODevice::WriteOnly | QIODevice::Append);

}
