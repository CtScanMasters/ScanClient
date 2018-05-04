#ifndef MESSAGELOGGER_H
#define MESSAGELOGGER_H

#include <QPlainTextEdit>
#include <QFile>

class MessageLogger
{
private:

    static MessageLogger* instance;
    MessageLogger();
    QPlainTextEdit *m_textEditor;
    bool m_textEditorEnabled;

public:
    static MessageLogger* getInstance();
    void messageHandler(QString string);
    void setTextEdit(QPlainTextEdit *textEditor);
};

#endif // MESSAGELOGGER_H
