#ifndef MESSAGELOGGER_H
#define MESSAGELOGGER_H

#include <QPlainTextEdit>

class MessageLogger
{
private:

    static MessageLogger* instance;
    MessageLogger();
    QPlainTextEdit *m_textEditor;
    bool m_textEditorEnabled;
    QFile m_logFile;

public:
    static MessageLogger* getInstance();
    void messageHandler(QtMsgType type, const QString & str);
    void setTextEdit(QPlainTextEdit *textEditor);
    void clearLogFile();
};

#endif // MESSAGELOGGER_H
