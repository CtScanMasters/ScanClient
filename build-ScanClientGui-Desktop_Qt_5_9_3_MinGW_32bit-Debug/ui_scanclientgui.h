/********************************************************************************
** Form generated from reading UI file 'scanclientgui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANCLIENTGUI_H
#define UI_SCANCLIENTGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "ActuatorWidget\actuatorwidget.h"
#include "ScanWidget\scanwidget.h"
#include "TcpClientWidget\tcpclientwidget.h"
#include "filehandlerwidget/imageviewerwidget.h"

QT_BEGIN_NAMESPACE

class Ui_ScanClientGui
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QGroupBox *tcpBox;
    QGridLayout *gridLayout_6;
    TcpClientWidget *tcpControlWidget;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_11;
    ImageViewerWidget *imageViewerWidget;
    QLabel *label;
    QGroupBox *actuatorBox;
    QGridLayout *gridLayout_5;
    ActuatorWidget *actuatorControlWidget;
    QGroupBox *scanBox;
    QGridLayout *gridLayout_4;
    ScanWidget *scanControlWidget;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_9;
    QTextEdit *plainTextEdit;

    void setupUi(QMainWindow *ScanClientGui)
    {
        if (ScanClientGui->objectName().isEmpty())
            ScanClientGui->setObjectName(QStringLiteral("ScanClientGui"));
        ScanClientGui->resize(1800, 900);
        QIcon icon;
        icon.addFile(QStringLiteral(":/ScanMaster pic.png"), QSize(), QIcon::Normal, QIcon::Off);
        ScanClientGui->setWindowIcon(icon);
        ScanClientGui->setStyleSheet(QLatin1String("QMainWindow{\n"
"        background-color:qlineargradient(spread:reflect, x1:0, y1:0, x2:1, y2:0.988636, stop:0.619318 rgba(0, 0, 0, 255), stop:1 rgba(0, 92, 111, 255));\n"
"\n"
"}\n"
"\n"
"QGroupBox {\n"
"        background-color: transparent;\n"
"        margin-top: 2em;\n"
"        border-radius: 5px;\n"
"        border: 1px solid rgb(255, 255, 255);\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"        background-color: transparent;\n"
"        color:rgb(255, 255, 255);\n"
"        padding-top: -20px;\n"
"        margin-top: -1em;\n"
"        font-size: 18px;\n"
"        font-weight: bold;\n"
"\n"
"}\n"
"\n"
"QScrollBar{\n"
"	background-color:qlineargradient(spread:pad, x1:0.307, y1:0.715545, x2:0, y2:1, stop:0 rgba(0, 92, 111, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	width: 15px;\n"
"	\n"
"}\n"
"\n"
"QScrollBar::handle{\n"
"	min-height: 50px;\n"
"}\n"
"\n"
"QScrollBar::add-page{\n"
"	background:rgb(0,0,0);\n"
"}\n"
"\n"
"QScrollbar:sub-page{\n"
"	background:rgb(0,0,0);\n"
"}\n"
"\n"
"QScrollBar::add-line{\n"
""
                        "	background:rgb(0,0,0);\n"
"\n"
"}\n"
"\n"
"QScrollBar::sub-line{\n"
"	background:rgb(0,0,0);\n"
"\n"
"}\n"
"\n"
"\n"
"QLineEdit{\n"
"        qproperty-alignment: AlignCenter;\n"
"        border-radius: 5px;\n"
"        font-size: 12px;\n"
"        font-weight: bold;\n"
"}\n"
"\n"
"QLabel{\n"
"        color: rgb(255, 255, 255);\n"
"        font-size: 14px;\n"
"}\n"
"\n"
"QTextEdit{\n"
"	color:rgb(150,150,150);\n"
"	background-color:rgb(0,0,0);\n"
"	border: 1px;\n"
"	border-color:rgb(255,255,255);\n"
"}\n"
"\n"
"QPushButton{\n"
"\n"
"        border: 1px solid rgb(0, 0, 0);\n"
"        border-radius: 5px;\n"
"        background-color:qlineargradient(spread:pad, x1:0.307, y1:0.715545, x2:0, y2:1, stop:0 rgba(0, 92, 111, 255), stop:1 rgba(255, 255, 255, 255));\n"
"        color: white;\n"
"        min-height: 18px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"        border: 1px solid rgb(255, 255, 255);\n"
"        background-color:rgb(111, 111, 111);\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"        border: 1px soli"
                        "d rgb(255, 255, 255);\n"
"        background-color:rgb(111, 111, 111);\n"
"}\n"
"\n"
"QProgressBar::chunk:horizontal {\n"
"        background:qlineargradient(spread:pad, x1:0.307, y1:0.715545, x2:0, y2:1, stop:0 rgba(0, 92, 111, 255), stop:1 rgba(255, 255, 255, 255));\n"
"        border-radius: 5px;\n"
"}\n"
"\n"
"QProgressBar:horizontal {\n"
"        border: 2px white;\n"
"        border-radius: 5px;\n"
"        background: rgb(255, 255, 255);\n"
"        padding: 1px;\n"
"		color:rgb(255,255,255);\n"
"\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"        border-radius: 5px;\n"
"        background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"        padding: 1px;\n"
"\n"
"}\n"
"\n"
"QTabWidget::tab-bar:top {\n"
"    top: 1px;\n"
"}\n"
"\n"
"QTabWidget::tab-bar:bottom {\n"
"    bottom: 1px;\n"
"}\n"
"\n"
"QTabWidget::tab-bar:left {\n"
"    right: 1px;\n"
"}\n"
"\n"
"QTabWidget::tab-bar:right {\n"
"    left: 1px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    border: 1px solid black;\n"
" "
                        "       width: 100px;\n"
"        border-radius: 5px;\n"
"        border: 1px solid rgb(255, 255, 255);\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background: qlineargradient(spread:pad, x1:0.307, y1:0.715545, x2:0, y2:1, stop:0 rgba(0, 92, 111, 255), stop:1 rgba(255, 255, 255, 255));\n"
"        color: rgb(255,255,255);\n"
"        font-weight: bold;\n"
"        border-radius: 5px;\n"
"        border: 1px solid rgb(255, 255, 255);\n"
"}\n"
"\n"
"QTabBar::tab:!selected {\n"
"    background: rgb(133, 114, 143);\n"
"        color: silver;\n"
"        border-radius: 5px;\n"
"        border: 1px solid rgb(255, 255, 255);\n"
"}\n"
"\n"
"QTabBar::tab:!selected:hover {\n"
"    background: white;\n"
"}\n"
"\n"
"QTabBar::tab:top:!selected {\n"
"    margin-top: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:bottom:!selected {\n"
"    margin-bottom: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:top, QTabBar::tab:bottom {\n"
"    min-width: 8ex;\n"
"    margin-right: -1px;\n"
"    padding: 5px 10px 5px 10px;\n"
"}\n"
"\n"
"QTabBar::tab:top:selec"
                        "ted {\n"
"    border-bottom-color: none;\n"
"}\n"
"\n"
"QTabBar::tab:bottom:selected {\n"
"    border-top-color: none;\n"
"}\n"
"\n"
"QTabBar::tab:top:last, QTabBar::tab:bottom:last,\n"
"QTabBar::tab:top:only-one, QTabBar::tab:bottom:only-one {\n"
"    margin-right: 0;\n"
"}\n"
"\n"
"QTabBar::tab:left:!selected {\n"
"    margin-right: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:right:!selected {\n"
"    margin-left: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:left, QTabBar::tab:right {\n"
"    min-height: 8ex;\n"
"    margin-bottom: -1px;\n"
"    padding: 10px 5px 10px 5px;\n"
"}\n"
"\n"
"QTabBar::tab:left:selected {\n"
"    border-left-color: none;\n"
"}\n"
"\n"
"QTabBar::tab:right:selected {\n"
"    border-right-color: none;\n"
"}\n"
"\n"
"QTabBar::tab:left:last, QTabBar::tab:right:last,\n"
"QTabBar::tab:left:only-one, QTabBar::tab:right:only-one {\n"
"    margin-bottom: 0;\n"
"}\n"
""));
        centralWidget = new QWidget(ScanClientGui);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        titleLabel = new QLabel(centralWidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(titleLabel);

        horizontalSpacer = new QSpacerItem(768, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(30, 20));
        pushButton_4->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(30, 20));
        pushButton_3->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(30, 20));
        pushButton_2->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(30, 20));
        pushButton->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(pushButton);


        horizontalLayout_3->addLayout(horizontalLayout);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 2);

        tcpBox = new QGroupBox(centralWidget);
        tcpBox->setObjectName(QStringLiteral("tcpBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tcpBox->sizePolicy().hasHeightForWidth());
        tcpBox->setSizePolicy(sizePolicy1);
        tcpBox->setMinimumSize(QSize(300, 0));
        tcpBox->setMaximumSize(QSize(1600, 16777215));
        tcpBox->setStyleSheet(QLatin1String("QGroupBox {\n"
"        background-color: rgb(0, 0, 0);\n"
"        margin-top: 2em;\n"
"        border-radius: 5px;\n"
"        border: 1px solid rgb(255, 255, 255);\n"
"}"));
        gridLayout_6 = new QGridLayout(tcpBox);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        tcpControlWidget = new TcpClientWidget(tcpBox);
        tcpControlWidget->setObjectName(QStringLiteral("tcpControlWidget"));

        gridLayout_6->addWidget(tcpControlWidget, 0, 0, 1, 1);


        gridLayout->addWidget(tcpBox, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy2);
        groupBox_3->setMinimumSize(QSize(1300, 600));
        gridLayout_11 = new QGridLayout(groupBox_3);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        imageViewerWidget = new ImageViewerWidget(groupBox_3);
        imageViewerWidget->setObjectName(QStringLiteral("imageViewerWidget"));
        sizePolicy2.setHeightForWidth(imageViewerWidget->sizePolicy().hasHeightForWidth());
        imageViewerWidget->setSizePolicy(sizePolicy2);
        imageViewerWidget->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_11->addWidget(imageViewerWidget, 0, 0, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_11->addWidget(label, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox_3, 1, 1, 5, 1);

        actuatorBox = new QGroupBox(centralWidget);
        actuatorBox->setObjectName(QStringLiteral("actuatorBox"));
        sizePolicy1.setHeightForWidth(actuatorBox->sizePolicy().hasHeightForWidth());
        actuatorBox->setSizePolicy(sizePolicy1);
        actuatorBox->setMinimumSize(QSize(300, 0));
        actuatorBox->setMaximumSize(QSize(1600, 16777215));
        actuatorBox->setStyleSheet(QLatin1String("QGroupBox {\n"
"        background-color: rgb(0, 0, 0);\n"
"        margin-top: 2em;\n"
"        border-radius: 5px;\n"
"        border: 1px solid rgb(255, 255, 255);\n"
"}"));
        gridLayout_5 = new QGridLayout(actuatorBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        actuatorControlWidget = new ActuatorWidget(actuatorBox);
        actuatorControlWidget->setObjectName(QStringLiteral("actuatorControlWidget"));

        gridLayout_5->addWidget(actuatorControlWidget, 0, 0, 1, 1);


        gridLayout->addWidget(actuatorBox, 2, 0, 1, 1);

        scanBox = new QGroupBox(centralWidget);
        scanBox->setObjectName(QStringLiteral("scanBox"));
        sizePolicy1.setHeightForWidth(scanBox->sizePolicy().hasHeightForWidth());
        scanBox->setSizePolicy(sizePolicy1);
        scanBox->setMinimumSize(QSize(300, 0));
        scanBox->setMaximumSize(QSize(1000, 150));
        scanBox->setStyleSheet(QLatin1String("QGroupBox {\n"
"        background-color: rgb(0, 0, 0);\n"
"        margin-top: 2em;\n"
"        border-radius: 5px;\n"
"        border: 1px solid rgb(255, 255, 255);\n"
"}"));
        gridLayout_4 = new QGridLayout(scanBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        scanControlWidget = new ScanWidget(scanBox);
        scanControlWidget->setObjectName(QStringLiteral("scanControlWidget"));
        scanControlWidget->setMaximumSize(QSize(1600, 100));

        gridLayout_4->addWidget(scanControlWidget, 0, 0, 1, 1);


        gridLayout->addWidget(scanBox, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMinimumSize(QSize(450, 0));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        groupBox->setStyleSheet(QLatin1String("QMainWindow{\n"
"        background-color:qradialgradient(spread:reflect, cx:0.519, cy:0.540437, radius:0.442, fx:0.215, fy:0.848256, stop:0.808096 rgba(0, 0, 0, 255), stop:1 rgba(138, 0, 137, 255));\n"
"}\n"
"\n"
"QGroupBox {\n"
"        background-color: rgb(0, 0, 0);\n"
"        margin-top: 2em;\n"
"        border-radius: 5px;\n"
"        border: 1px solid rgb(255, 255, 255);\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"        background-color: transparent;\n"
"        color:rgb(255, 255, 255);\n"
"        padding-top: -20px;\n"
"        margin-top: -1em;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"\n"
"}\n"
"\n"
"QLineEdit{\n"
"    qproperty-alignment: AlignCenter;\n"
"        border-radius: 5px;\n"
"        font-size: 12px;\n"
"        font-weight: bold;\n"
"}\n"
"\n"
"QLabel{\n"
"        color: rgb(255, 255, 255);\n"
"        font-size: 14px;\n"
"}\n"
"\n"
"QPushButton{\n"
"\n"
"        border: 1px solid rgb(0, 0, 0);\n"
"        border-radius: 5px;\n"
"        background-color:qlineargradient(spre"
                        "ad:pad, x1:1, y1:0.346591, x2:0, y2:1, stop:0.455056 rgba(141, 22, 158, 255), stop:0.983146 rgba(169, 169, 169, 255));\n"
"        color: white;\n"
"        min-height: 18px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"        border: 1px solid rgb(255, 255, 255);\n"
"        background-color:rgb(111, 111, 111);\n"
"}\n"
"\n"
"QProgressBar::chunk:horizontal {\n"
"        background: qlineargradient(spread:pad, x1:1, y1:0.346591, x2:0, y2:1, stop:0.0730337 rgba(103, 16, 115, 255), stop:0.983146 rgba(169, 169, 169, 255));\n"
"        border-radius: 5px;\n"
"}\n"
"\n"
"QProgressBar:horizontal {\n"
"        border: 1px white;\n"
"        border-radius: 5px;\n"
"        background: rgb(100, 100, 100);\n"
"        padding: 1px;\n"
"\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"        border-radius: 5px;\n"
"        background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"        padding: 1px;\n"
"\n"
"}\n"
"\n"
"QTabWidget::tab-bar:top {\n"
"    top: 1px;\n"
"}\n"
"\n"
"QTabWidget::tab-ba"
                        "r:bottom {\n"
"    bottom: 1px;\n"
"}\n"
"\n"
"QTabWidget::tab-bar:left {\n"
"    right: 1px;\n"
"}\n"
"\n"
"QTabWidget::tab-bar:right {\n"
"    left: 1px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    border: 1px solid black;\n"
"        width: 100px;\n"
"        border-radius: 5px;\n"
"        border: 1px solid rgb(255, 255, 255);\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background: qlineargradient(spread:pad, x1:1, y1:0.346591, x2:0, y2:1, stop:0.455056 rgba(141, 22, 158, 255), stop:0.983146 rgba(169, 169, 169, 255));\n"
"        color: rgb(255,255,255);\n"
"        font-weight: bold;\n"
"        border-radius: 5px;\n"
"        border: 1px solid rgb(255, 255, 255);\n"
"}\n"
"\n"
"QTabBar::tab:!selected {\n"
"    background: rgb(133, 114, 143);\n"
"        color: silver;\n"
"        border-radius: 5px;\n"
"        border: 1px solid rgb(255, 255, 255);\n"
"}\n"
"\n"
"QTabBar::tab:!selected:hover {\n"
"    background: white;\n"
"}\n"
"\n"
"QTabBar::tab:top:!selected {\n"
"    margin-top: 3px;\n"
"}\n"
"\n"
"QTab"
                        "Bar::tab:bottom:!selected {\n"
"    margin-bottom: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:top, QTabBar::tab:bottom {\n"
"    min-width: 8ex;\n"
"    margin-right: -1px;\n"
"    padding: 5px 10px 5px 10px;\n"
"}\n"
"\n"
"QTabBar::tab:top:selected {\n"
"    border-bottom-color: none;\n"
"}\n"
"\n"
"QTabBar::tab:bottom:selected {\n"
"    border-top-color: none;\n"
"}\n"
"\n"
"QTabBar::tab:top:last, QTabBar::tab:bottom:last,\n"
"QTabBar::tab:top:only-one, QTabBar::tab:bottom:only-one {\n"
"    margin-right: 0;\n"
"}\n"
"\n"
"QTabBar::tab:left:!selected {\n"
"    margin-right: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:right:!selected {\n"
"    margin-left: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:left, QTabBar::tab:right {\n"
"    min-height: 8ex;\n"
"    margin-bottom: -1px;\n"
"    padding: 10px 5px 10px 5px;\n"
"}\n"
"\n"
"QTabBar::tab:left:selected {\n"
"    border-left-color: none;\n"
"}\n"
"\n"
"QTabBar::tab:right:selected {\n"
"    border-right-color: none;\n"
"}\n"
"\n"
"QTabBar::tab:left:last, QTabBar::tab:right:last,\n"
"QTabBa"
                        "r::tab:left:only-one, QTabBar::tab:right:only-one {\n"
"    margin-bottom: 0;\n"
"}\n"
""));
        gridLayout_9 = new QGridLayout(groupBox);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        plainTextEdit = new QTextEdit(groupBox);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        gridLayout_9->addWidget(plainTextEdit, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 5, 0, 1, 1);

        ScanClientGui->setCentralWidget(centralWidget);

        retranslateUi(ScanClientGui);
        QObject::connect(pushButton, SIGNAL(clicked(bool)), ScanClientGui, SLOT(close()));
        QObject::connect(pushButton_2, SIGNAL(clicked(bool)), ScanClientGui, SLOT(showMinimized()));
        QObject::connect(pushButton_3, SIGNAL(clicked(bool)), ScanClientGui, SLOT(showFullScreen()));
        QObject::connect(pushButton_4, SIGNAL(clicked(bool)), ScanClientGui, SLOT(showNormal()));

        QMetaObject::connectSlotsByName(ScanClientGui);
    } // setupUi

    void retranslateUi(QMainWindow *ScanClientGui)
    {
        ScanClientGui->setWindowTitle(QApplication::translate("ScanClientGui", "CT ScanMaster", Q_NULLPTR));
        label_2->setText(QApplication::translate("ScanClientGui", "<html><head/><body><p><img src=\":/ScanMaster pic SMALL.png\"/></p></body></html>", Q_NULLPTR));
        titleLabel->setText(QApplication::translate("ScanClientGui", "IR ScanMasterPi", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton_4->setToolTip(QApplication::translate("ScanClientGui", "exit fullscreen", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_4->setText(QApplication::translate("ScanClientGui", "><", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton_3->setToolTip(QApplication::translate("ScanClientGui", "full screen", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_3->setText(QApplication::translate("ScanClientGui", "<>", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("ScanClientGui", "minimalize", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_2->setText(QApplication::translate("ScanClientGui", "-", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("ScanClientGui", "close", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QApplication::translate("ScanClientGui", "X", Q_NULLPTR));
        tcpBox->setTitle(QApplication::translate("ScanClientGui", "Connection", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("ScanClientGui", "Image viewer", Q_NULLPTR));
        label->setText(QApplication::translate("ScanClientGui", "by CT ScanMasters 2018", Q_NULLPTR));
        actuatorBox->setTitle(QApplication::translate("ScanClientGui", "Actuator control", Q_NULLPTR));
        scanBox->setTitle(QApplication::translate("ScanClientGui", "Scan control", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ScanClientGui", "Log", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ScanClientGui: public Ui_ScanClientGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANCLIENTGUI_H
