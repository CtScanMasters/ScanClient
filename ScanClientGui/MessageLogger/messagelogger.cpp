#include "messagelogger.h"

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

    }

    return instance;
}


void MessageLogger::messageHandler(QString string)
{
    if(m_textEditorEnabled)
    {
        m_textEditor->append(string);
    }
}

void MessageLogger::setTextEdit(QTextEdit *textEditor)
{
    m_textEditor = textEditor;
    m_textEditorEnabled = true;
}


