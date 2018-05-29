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
#include <QtWidgets/QSlider>
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
    QGridLayout *gridLayout_2;
    QLabel *titleLabel;
    QSpacerItem *horizontalSpacer_3;
    QTabWidget *tabWidget;
    QWidget *scanImaging;
    QGridLayout *gridLayout_10;
    QSlider *verticalSlider;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_11;
    QLabel *imagingWidget;
    QWidget *scanData;
    QGridLayout *gridLayout_7;
    QGroupBox *scanPlot;
    QGridLayout *gridLayout_8;
    ScatterWidget *scatterPlot;
    QWidget *arrayControl;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QGroupBox *tcpBox;
    QGridLayout *gridLayout_6;
    TcpClientWidget *tcpControlWidget;
    QGroupBox *fileHandlerBox;
    QGridLayout *gridLayout_3;
    FileHandlerWidget *fileHandlerWidget;
    QGroupBox *actuatorBox;
    QGridLayout *gridLayout_5;
    ActuatorWidget *actuatorControlWidget;
    QGroupBox *scanBox;
    QGridLayout *gridLayout_4;
    ScanWidget *scanControlWidget;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_9;
    QLabel *label;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QMainWindow *ScanClientGui)
    {
        if (ScanClientGui->objectName().isEmpty())
            ScanClientGui->setObjectName(QStringLiteral("ScanClientGui"));
        ScanClientGui->resize(1800, 900);
        ScanClientGui->setStyleSheet(QLatin1String("QMainWindow{\n"
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
        centralWidget = new QWidget(ScanClientGui);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        titleLabel = new QLabel(centralWidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(titleLabel, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 1, 1, 2);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        scanImaging = new QWidget();
        scanImaging->setObjectName(QStringLiteral("scanImaging"));
        gridLayout_10 = new QGridLayout(scanImaging);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        verticalSlider = new QSlider(scanImaging);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setMinimum(1);
        verticalSlider->setMaximum(255);
        verticalSlider->setSingleStep(8);
        verticalSlider->setPageStep(16);
        verticalSlider->setValue(64);
        verticalSlider->setSliderPosition(64);
        verticalSlider->setOrientation(Qt::Vertical);

        gridLayout_10->addWidget(verticalSlider, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(scanImaging);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_11 = new QGridLayout(groupBox_3);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        imagingWidget = new QLabel(groupBox_3);
        imagingWidget->setObjectName(QStringLiteral("imagingWidget"));
        imagingWidget->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(imagingWidget, 0, 0, 1, 1);


        gridLayout_10->addWidget(groupBox_3, 0, 0, 1, 1);

        tabWidget->addTab(scanImaging, QString());
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

        gridLayout_2->addWidget(tabWidget, 1, 0, 1, 3);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(600, 0));
        groupBox_2->setMaximumSize(QSize(500, 16777215));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tcpBox = new QGroupBox(groupBox_2);
        tcpBox->setObjectName(QStringLiteral("tcpBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tcpBox->sizePolicy().hasHeightForWidth());
        tcpBox->setSizePolicy(sizePolicy1);
        gridLayout_6 = new QGridLayout(tcpBox);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        tcpControlWidget = new TcpClientWidget(tcpBox);
        tcpControlWidget->setObjectName(QStringLiteral("tcpControlWidget"));

        gridLayout_6->addWidget(tcpControlWidget, 0, 0, 1, 1);


        gridLayout->addWidget(tcpBox, 0, 0, 1, 1);

        fileHandlerBox = new QGroupBox(groupBox_2);
        fileHandlerBox->setObjectName(QStringLiteral("fileHandlerBox"));
        sizePolicy1.setHeightForWidth(fileHandlerBox->sizePolicy().hasHeightForWidth());
        fileHandlerBox->setSizePolicy(sizePolicy1);
        gridLayout_3 = new QGridLayout(fileHandlerBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        fileHandlerWidget = new FileHandlerWidget(fileHandlerBox);
        fileHandlerWidget->setObjectName(QStringLiteral("fileHandlerWidget"));

        gridLayout_3->addWidget(fileHandlerWidget, 0, 0, 1, 1);


        gridLayout->addWidget(fileHandlerBox, 0, 1, 1, 1);

        actuatorBox = new QGroupBox(groupBox_2);
        actuatorBox->setObjectName(QStringLiteral("actuatorBox"));
        sizePolicy1.setHeightForWidth(actuatorBox->sizePolicy().hasHeightForWidth());
        actuatorBox->setSizePolicy(sizePolicy1);
        gridLayout_5 = new QGridLayout(actuatorBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        actuatorControlWidget = new ActuatorWidget(actuatorBox);
        actuatorControlWidget->setObjectName(QStringLiteral("actuatorControlWidget"));

        gridLayout_5->addWidget(actuatorControlWidget, 0, 0, 1, 1);


        gridLayout->addWidget(actuatorBox, 1, 0, 1, 1);

        scanBox = new QGroupBox(groupBox_2);
        scanBox->setObjectName(QStringLiteral("scanBox"));
        sizePolicy1.setHeightForWidth(scanBox->sizePolicy().hasHeightForWidth());
        scanBox->setSizePolicy(sizePolicy1);
        gridLayout_4 = new QGridLayout(scanBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        scanControlWidget = new ScanWidget(scanBox);
        scanControlWidget->setObjectName(QStringLiteral("scanControlWidget"));

        gridLayout_4->addWidget(scanControlWidget, 0, 0, 1, 1);


        gridLayout->addWidget(scanBox, 1, 1, 1, 1);

        groupBox = new QGroupBox(groupBox_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        groupBox->setMinimumSize(QSize(500, 0));
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
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_9->addWidget(label, 1, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(groupBox);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setMinimumSize(QSize(500, 0));

        gridLayout_9->addWidget(plainTextEdit, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 2, 0, 1, 2);


        gridLayout_2->addWidget(groupBox_2, 1, 3, 1, 5);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy3);
        pushButton->setMinimumSize(QSize(30, 20));
        pushButton->setMaximumSize(QSize(50, 16777215));

        gridLayout_2->addWidget(pushButton, 0, 7, 1, 1);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(30, 20));
        pushButton_2->setMaximumSize(QSize(50, 16777215));

        gridLayout_2->addWidget(pushButton_2, 0, 6, 1, 1);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(30, 20));
        pushButton_3->setMaximumSize(QSize(50, 16777215));

        gridLayout_2->addWidget(pushButton_3, 0, 5, 1, 1);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(30, 20));
        pushButton_4->setMaximumSize(QSize(50, 16777215));

        gridLayout_2->addWidget(pushButton_4, 0, 4, 1, 1);

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
        titleLabel->setText(QApplication::translate("ScanClientGui", "IR ScanMasterPi", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("ScanClientGui", "Scan image", Q_NULLPTR));
        imagingWidget->setText(QApplication::translate("ScanClientGui", "<html><head/><body><p><img src=\":/ScanMaster pic.png\"/></p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(scanImaging), QApplication::translate("ScanClientGui", "Scan Imaging", Q_NULLPTR));
        scanPlot->setTitle(QApplication::translate("ScanClientGui", "3D Scan plot", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(scanData), QApplication::translate("ScanClientGui", "Scan data", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(arrayControl), QApplication::translate("ScanClientGui", "Array control", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        tcpBox->setTitle(QApplication::translate("ScanClientGui", "Connection", Q_NULLPTR));
        fileHandlerBox->setTitle(QApplication::translate("ScanClientGui", "File handler", Q_NULLPTR));
        actuatorBox->setTitle(QApplication::translate("ScanClientGui", "Actuator control", Q_NULLPTR));
        scanBox->setTitle(QApplication::translate("ScanClientGui", "Scan control", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ScanClientGui", "Log", Q_NULLPTR));
        label->setText(QApplication::translate("ScanClientGui", "by CT ScanMasters 2018", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ScanClientGui", "X", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("ScanClientGui", "-", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("ScanClientGui", "<>", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("ScanClientGui", "><", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ScanClientGui: public Ui_ScanClientGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANCLIENTGUI_H
