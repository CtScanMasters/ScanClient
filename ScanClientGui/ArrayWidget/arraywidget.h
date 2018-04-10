#ifndef ARRAYWIDGET_H
#define ARRAYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QGroupBox>
#include <QGridLayout>
#include <QList>
#include <QLineEdit>


class ArrayWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ArrayWidget(QWidget *parent = 0);
    ~ArrayWidget();
    void setNumber(quint16 number);
    void setButtonStyle();
    void setBarMaxValue(quint8 barNumber, quint64 maxValue);
    void setBarValue(quint8 barNumber, quint64 value);


private:
    QList<QPushButton* > m_pushButtonList;
    QList<QProgressBar* > m_progressBarList;
    QList<QLineEdit* > m_lineEditList;

    QGridLayout *m_mainGridLayout;
    QLabel *m_arrayTitleLabel;
    QPushButton *m_controlAllButton;
    QWidget *m_widgetContainer;
    quint16 m_arrayNumber;
    quint8 m_sourceBitmask;
    quint8 m_ArraySize;

    QColor buttonStatusColor;
    QString buttonColorSheet;

    void emitSourceSetSignal();

private slots:
    void getPushButtonSignal();

signals:
    void sourceSetSignal(quint8 sourceBitmask);


};

#endif // ARRAYWIDGET_H
