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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "3DScatterWidget\scatterwidget.h"
#include "ActuatorWidget\actuatorwidget.h"
#include "FileHandlerWidget\filehandlerwidget.h"
#include "ScanWidget\scanwidget.h"
#include "TcpClientWidget\tcpclientwidget.h"

QT_BEGIN_NAMESPACE

class Ui_ScanClientGui
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QTabWidget *tabWidget;
    QWidget *general;
    QGridLayout *gridLayout_2;
    QGroupBox *actuatorBox;
    QGridLayout *gridLayout_5;
    ActuatorWidget *actuatorControlWidget;
    QLabel *label;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;
    QGroupBox *tcpBox;
    QGridLayout *gridLayout_6;
    TcpClientWidget *tcpControlWidget;
    QGroupBox *scanBox;
    QGridLayout *gridLayout_4;
    ScanWidget *scanControlWidget;
    QGroupBox *fileHandlerBox;
    QGridLayout *gridLayout_3;
    FileHandlerWidget *fileHandlerWidget;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_6;
    QWidget *scanData;
    QGridLayout *gridLayout_7;
    QGroupBox *scanPlot;
    QGridLayout *gridLayout_8;
    ScatterWidget *scatterPlot;
    QWidget *arrayControl;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_8;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_9;
    QPlainTextEdit *plainTextEdit;
    QSpacerItem *horizontalSpacer_3;
    QLabel *titleLabel;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_10;

    void setupUi(QMainWindow *ScanClientGui)
    {
        if (ScanClientGui->objectName().isEmpty())
            ScanClientGui->setObjectName(QStringLiteral("ScanClientGui"));
        ScanClientGui->resize(1402, 692);
        ScanClientGui->setStyleSheet(QLatin1String("QMainWindow{\n"
"	background-color:qradialgradient(spread:reflect, cx:0.519, cy:0.540437, radius:0.442, fx:0.215, fy:0.848256, stop:0.808096 rgba(0, 0, 0, 255), stop:1 rgba(138, 0, 137, 255));\n"
"}\n"
"\n"
"QGroupBox {\n"
"	background-color: rgb(0, 0, 0);\n"
"	margin-top: 2em;\n"
"	border-radius: 5px;\n"
"	border: 1px solid rgb(255, 255, 255);\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"	background-color: transparent;\n"
"	color:rgb(255, 255, 255);\n"
"	padding-top: -20px;\n"
"	margin-top: -1em;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"\n"
"}\n"
"\n"
"QLineEdit{\n"
"    qproperty-alignment: AlignCenter;\n"
"	border-radius: 5px;\n"
"	font-size: 12px;\n"
"	font-weight: bold;\n"
"}\n"
"\n"
"QLabel{\n"
"	color: rgb(255, 255, 255);\n"
"	font-size: 14px;\n"
"}\n"
"\n"
"QPushButton{\n"
"\n"
"	border: 1px solid rgb(0, 0, 0);\n"
"	border-radius: 5px;\n"
"	background-color:qlineargradient(spread:pad, x1:1, y1:0.346591, x2:0, y2:1, stop:0.455056 rgba(141, 22, 158, 255), stop:0.983146 rgba(169, 169, 169, 255));\n"
""
                        "	color: white;\n"
"	min-height: 18px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border: 1px solid rgb(255, 255, 255);\n"
"	background-color:rgb(111, 111, 111);\n"
"}\n"
"\n"
"QProgressBar::chunk:horizontal {\n"
"	background: qlineargradient(spread:pad, x1:1, y1:0.346591, x2:0, y2:1, stop:0.0730337 rgba(103, 16, 115, 255), stop:0.983146 rgba(169, 169, 169, 255));\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QProgressBar:horizontal {\n"
"	border: 1px white;\n"
"	border-radius: 5px;\n"
"	background: rgb(100, 100, 100);\n"
"	padding: 1px;\n"
"\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"	border-radius: 5px;\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:1 rgba(0, 0, 0, 0));\n"
"	padding: 1px;\n"
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
"    border: 1px solid bl"
                        "ack;\n"
"	width: 100px;\n"
"	border-radius: 5px;\n"
"	border: 1px solid rgb(255, 255, 255);\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background: qlineargradient(spread:pad, x1:1, y1:0.346591, x2:0, y2:1, stop:0.455056 rgba(141, 22, 158, 255), stop:0.983146 rgba(169, 169, 169, 255));\n"
"	color: rgb(255,255,255);\n"
"	font-weight: bold;\n"
"	border-radius: 5px;\n"
"	border: 1px solid rgb(255, 255, 255);\n"
"}\n"
"\n"
"QTabBar::tab:!selected {\n"
"    background: rgb(133, 114, 143);\n"
"	color: silver;\n"
"	border-radius: 5px;\n"
"	border: 1px solid rgb(255, 255, 255);\n"
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
"QTabBar::tab:top:selected {\n"
"    border-bottom-color: none;\n"
"}\n"
""
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
"}"));
        centralWidget = new QWidget(ScanClientGui);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(30, 20));

        gridLayout->addWidget(pushButton_2, 0, 8, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        general = new QWidget();
        general->setObjectName(QStringLiteral("general"));
        gridLayout_2 = new QGridLayout(general);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        actuatorBox = new QGroupBox(general);
        actuatorBox->setObjectName(QStringLiteral("actuatorBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(actuatorBox->sizePolicy().hasHeightForWidth());
        actuatorBox->setSizePolicy(sizePolicy);
        gridLayout_5 = new QGridLayout(actuatorBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        actuatorControlWidget = new ActuatorWidget(actuatorBox);
        actuatorControlWidget->setObjectName(QStringLiteral("actuatorControlWidget"));

        gridLayout_5->addWidget(actuatorControlWidget, 0, 0, 1, 1);


        gridLayout_2->addWidget(actuatorBox, 0, 2, 1, 1);

        label = new QLabel(general);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label, 7, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 6, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 5, 1, 1, 1);

        tcpBox = new QGroupBox(general);
        tcpBox->setObjectName(QStringLiteral("tcpBox"));
        sizePolicy.setHeightForWidth(tcpBox->sizePolicy().hasHeightForWidth());
        tcpBox->setSizePolicy(sizePolicy);
        gridLayout_6 = new QGridLayout(tcpBox);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        tcpControlWidget = new TcpClientWidget(tcpBox);
        tcpControlWidget->setObjectName(QStringLiteral("tcpControlWidget"));

        gridLayout_6->addWidget(tcpControlWidget, 0, 0, 1, 1);


        gridLayout_2->addWidget(tcpBox, 0, 1, 1, 1);

        scanBox = new QGroupBox(general);
        scanBox->setObjectName(QStringLiteral("scanBox"));
        sizePolicy.setHeightForWidth(scanBox->sizePolicy().hasHeightForWidth());
        scanBox->setSizePolicy(sizePolicy);
        gridLayout_4 = new QGridLayout(scanBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        scanControlWidget = new ScanWidget(scanBox);
        scanControlWidget->setObjectName(QStringLiteral("scanControlWidget"));

        gridLayout_4->addWidget(scanControlWidget, 0, 0, 1, 1);


        gridLayout_2->addWidget(scanBox, 2, 1, 1, 1);

        fileHandlerBox = new QGroupBox(general);
        fileHandlerBox->setObjectName(QStringLiteral("fileHandlerBox"));
        sizePolicy.setHeightForWidth(fileHandlerBox->sizePolicy().hasHeightForWidth());
        fileHandlerBox->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(fileHandlerBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        fileHandlerWidget = new FileHandlerWidget(fileHandlerBox);
        fileHandlerWidget->setObjectName(QStringLiteral("fileHandlerWidget"));

        gridLayout_3->addWidget(fileHandlerWidget, 0, 0, 1, 1);


        gridLayout_2->addWidget(fileHandlerBox, 2, 2, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 6, 3, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 0, 3, 1, 1);

        tabWidget->addTab(general, QString());
        scanData = new QWidget();
        scanData->setObjectName(QStringLiteral("scanData"));
        gridLayout_7 = new QGridLayout(scanData);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        scanPlot = new QGroupBox(scanData);
        scanPlot->setObjectName(QStringLiteral("scanPlot"));
        gridLayout_8 = new QGridLayout(scanPlot);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        scatterPlot = new ScatterWidget(scanPlot);
        scatterPlot->setObjectName(QStringLiteral("scatterPlot"));

        gridLayout_8->addWidget(scatterPlot, 0, 0, 1, 1);


        gridLayout_7->addWidget(scanPlot, 0, 0, 1, 1);

        tabWidget->addTab(scanData, QString());
        arrayControl = new QWidget();
        arrayControl->setObjectName(QStringLiteral("arrayControl"));
        tabWidget->addTab(arrayControl, QString());

        gridLayout->addWidget(tabWidget, 2, 0, 1, 5);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMinimumSize(QSize(30, 20));

        gridLayout->addWidget(pushButton, 0, 9, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(448, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 0, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 0, 5, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        groupBox->setMinimumSize(QSize(600, 0));
        groupBox->setMaximumSize(QSize(300, 16777215));
        gridLayout_9 = new QGridLayout(groupBox);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        plainTextEdit = new QPlainTextEdit(groupBox);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setMinimumSize(QSize(500, 0));

        gridLayout_9->addWidget(plainTextEdit, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 2, 5, 1, 5);

        horizontalSpacer_3 = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        titleLabel = new QLabel(centralWidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(titleLabel, 0, 2, 1, 1);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(30, 20));

        gridLayout->addWidget(pushButton_4, 0, 6, 1, 1);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(30, 20));

        gridLayout->addWidget(pushButton_3, 0, 7, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 1, 5, 1, 1);

        ScanClientGui->setCentralWidget(centralWidget);

        retranslateUi(ScanClientGui);
        QObject::connect(pushButton, SIGNAL(clicked(bool)), ScanClientGui, SLOT(close()));
        QObject::connect(pushButton_2, SIGNAL(clicked(bool)), ScanClientGui, SLOT(showMinimized()));
        QObject::connect(pushButton_3, SIGNAL(clicked(bool)), ScanClientGui, SLOT(showFullScreen()));
        QObject::connect(pushButton_4, SIGNAL(clicked(bool)), ScanClientGui, SLOT(showNormal()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ScanClientGui);
    } // setupUi

    void retranslateUi(QMainWindow *ScanClientGui)
    {
        ScanClientGui->setWindowTitle(QApplication::translate("ScanClientGui", "ScanClientGui", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("ScanClientGui", "-", Q_NULLPTR));
        actuatorBox->setTitle(QApplication::translate("ScanClientGui", "Actuator control", Q_NULLPTR));
        label->setText(QApplication::translate("ScanClientGui", "by CT ScanMasters 2018", Q_NULLPTR));
        tcpBox->setTitle(QApplication::translate("ScanClientGui", "Connection", Q_NULLPTR));
        scanBox->setTitle(QApplication::translate("ScanClientGui", "Scan control", Q_NULLPTR));
        fileHandlerBox->setTitle(QApplication::translate("ScanClientGui", "File handler", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(general), QApplication::translate("ScanClientGui", "General", Q_NULLPTR));
        scanPlot->setTitle(QApplication::translate("ScanClientGui", "3D Scan plot", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(scanData), QApplication::translate("ScanClientGui", "Scan data", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(arrayControl), QApplication::translate("ScanClientGui", "Array control", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ScanClientGui", "X", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ScanClientGui", "Log", Q_NULLPTR));
        titleLabel->setText(QApplication::translate("ScanClientGui", "IR ScanMasterPi", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("ScanClientGui", "><", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("ScanClientGui", "<>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ScanClientGui: public Ui_ScanClientGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANCLIENTGUI_H
