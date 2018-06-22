#ifndef MESSAGELOGGER_H
#define MESSAGELOGGER_H

#include <QPlainTextEdit>
#include <QFile>

class MessageLogger
{
private:

    static MessageLogger* instance;
    MessageLogger();
    QTextEdit *m_textEditor;
    bool m_textEditorEnabled;

public:
    static MessageLogger* getInstance();
    void messageHandler(QString string);
    void setTextEdit(QTextEdit *textEditor);
};

#endif // MESSAGELOGGER_H
