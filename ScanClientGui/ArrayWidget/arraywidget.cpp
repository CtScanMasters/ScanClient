#include "arraywidget.h"
#include <QDebug>

ArrayWidget::ArrayWidget(QWidget *parent) :
    QWidget(parent)
{

    m_mainGridLayout = new QGridLayout(this);
    m_arrayTitleLabel = new QLabel(this);
    m_controlAllButton = new QPushButton(this);
    m_sourceBitmask = 0b00000000;
    m_ArraySize = 8;

    for(int i = 0; i < m_ArraySize; i++)
    {
        m_pushButtonList.append(new QPushButton(this));
        m_pushButtonList.at(i)->setText(QString::number(i));
        m_pushButtonList.at(i)->setMaximumWidth(30);
        m_pushButtonList.at(i)->setStyleSheet(buttonColorSheet);
        m_pushButtonList.at(i)->setToolTip("toggle source");
        m_mainGridLayout->addWidget(m_pushButtonList.at(i), i+1, 0, 1, 1);
        connect(m_pushButtonList.at(i), SIGNAL(clicked(bool)), this, SLOT(getPushButtonSignal()));

        m_progressBarList.append(new QProgressBar(this));
        m_progressBarList.at(i)->setMaximum(3300);
        m_progressBarList.at(i)->setFormat("%v");
        m_progressBarList.at(i)->setTextVisible(false);
        m_mainGridLayout->addWidget(m_progressBarList.at(i), i+1, 2, 1, 4);

        m_lineEditList.append(new QLineEdit(this));
        m_lineEditList.at(i)->setMaximumWidth(70);
        m_lineEditList.at(i)->setMinimumWidth(70);
        m_lineEditList.at(i)->setAlignment(Qt::AlignRight);
        m_lineEditList.at(i)->setReadOnly(true);
        m_mainGridLayout->addWidget(m_lineEditList.at(i), i+1, 1, 1, 1);
    }

    for(int i = 0; i < m_ArraySize;  i++)
    {
        setBarValue(i, (i * (3300 / m_ArraySize)));
    }

    m_controlAllButton->setMaximumWidth(30);
    m_controlAllButton->setText("ALL");
    m_controlAllButton->setToolTip("toggle all sources");
    connect(m_controlAllButton, SIGNAL(clicked(bool)), this, SLOT(getPushButtonSignal()));

    m_mainGridLayout->addWidget(m_controlAllButton, 0, 0, 1, 1);
    m_mainGridLayout->addWidget(m_arrayTitleLabel, 0, 1, 1, 2);

    setButtonStyle();
    setNumber(0);   
    setLayout(m_mainGridLayout);

}

ArrayWidget::~ArrayWidget()
{

}

void ArrayWidget::setNumber(quint16 number)
{
    m_arrayNumber = number;
    m_arrayTitleLabel->setText(QString("Array %1").arg(m_arrayNumber));
}

void ArrayWidget::getPushButtonSignal()
{
    QPushButton *pushButton = (QPushButton *)sender();

    if(pushButton == m_controlAllButton)
    {
        if(m_sourceBitmask > 0)
        {
            m_sourceBitmask = 0b00000000;
            emitSourceSetSignal();
            return;
        }
        else
        {
            m_sourceBitmask = 0b11111111;
            emitSourceSetSignal();
            return;
        }
    }
    else
    {
        for(int i = 0; i < m_ArraySize; i++)
        {
            if(m_pushButtonList.at(i) == pushButton)
            {
                quint8 mask = 1 << i;
                m_sourceBitmask = m_sourceBitmask ^ mask;

                emitSourceSetSignal();
                return;
            }
        }
    }
}

void ArrayWidget::setButtonStyle()
{
    quint8 mask = 1;

    for(int i = 0; i < m_ArraySize; i++)
    {
        if((mask << i) & m_sourceBitmask)
        {
            buttonColorSheet = QString("background-color: qlineargradient(spread:pad, "
                                       "x1:0.307, y1:0.715545, "
                                       "x2:0, y2:1, "
                                       "stop:0 rgba(57, 144, 145, 255), "
                                       "stop:1 rgba(255, 255, 255, 255))");
        }
        else
        {
            buttonColorSheet = QString("background-color: qlineargradient(spread:pad, "
                                        "x1:1, y1:0.397727, "
                                        "x2:0, y2:0.630682, "
                                        "stop:0.784091 rgba(152, 0, 152, 255), "
                                        "stop:1 rgba(255, 255, 255, 255)");
        }

        m_pushButtonList.at(i)->setStyleSheet(buttonColorSheet);
    }
}

void ArrayWidget::setBarMaxValue(quint8 barNumber, quint64 maxValue)
{
    m_progressBarList.at(barNumber)->setMaximum(maxValue);

}

void ArrayWidget::setBarValue(quint8 barNumber, quint64 value)
{

   m_progressBarList.at(barNumber)->setValue(value);
   m_lineEditList.at(barNumber)->setText(QString("%1 mV").arg(value));
}

void ArrayWidget::emitSourceSetSignal()
{
    setButtonStyle();
    emit sourceSetSignal(m_sourceBitmask);
}
