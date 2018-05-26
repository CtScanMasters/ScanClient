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
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_8;
    QLabel *titleLabel;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_9;
    QPlainTextEdit *plainTextEdit;
    QSpacerItem *horizontalSpacer_7;
    QTabWidget *tabWidget;
    QWidget *general;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QGroupBox *fileHandlerBox;
    QGridLayout *gridLayout_3;
    FileHandlerWidget *fileHandlerWidget;
    QGroupBox *actuatorBox;
    QGridLayout *gridLayout_5;
    ActuatorWidget *actuatorControlWidget;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QWidget *scanData;
    QGridLayout *gridLayout_7;
    QGroupBox *scanPlot;
    QGridLayout *gridLayout_8;
    ScatterWidget *scatterPlot;
    QWidget *scanImaging;
    QGridLayout *gridLayout_10;
    QLabel *imagingWidget;
    QSlider *verticalSlider;
    QWidget *arrayControl;
    QGroupBox *scanBox;
    QGridLayout *gridLayout_4;
    ScanWidget *scanControlWidget;
    QGroupBox *tcpBox;
    QGridLayout *gridLayout_6;
    TcpClientWidget *tcpControlWidget;

    void setupUi(QMainWindow *ScanClientGui)
    {
        if (ScanClientGui->objectName().isEmpty())
            ScanClientGui->setObjectName(QStringLiteral("ScanClientGui"));
        ScanClientGui->resize(1402, 692);
        ScanClientGui->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(ScanClientGui);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(30, 20));

        gridLayout->addWidget(pushButton, 0, 13, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 0, 8, 1, 1);

        titleLabel = new QLabel(centralWidget);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(titleLabel, 0, 5, 1, 1);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(30, 20));

        gridLayout->addWidget(pushButton_4, 0, 10, 1, 1);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(30, 20));

        gridLayout->addWidget(pushButton_3, 0, 11, 1, 1);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(30, 20));

        gridLayout->addWidget(pushButton_2, 0, 12, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
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


        gridLayout->addWidget(groupBox, 3, 8, 1, 6);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 0, 9, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        general = new QWidget();
        general->setObjectName(QStringLiteral("general"));
        gridLayout_2 = new QGridLayout(general);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(general);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label, 7, 2, 1, 1);

        fileHandlerBox = new QGroupBox(general);
        fileHandlerBox->setObjectName(QStringLiteral("fileHandlerBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(fileHandlerBox->sizePolicy().hasHeightForWidth());
        fileHandlerBox->setSizePolicy(sizePolicy2);
        gridLayout_3 = new QGridLayout(fileHandlerBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        fileHandlerWidget = new FileHandlerWidget(fileHandlerBox);
        fileHandlerWidget->setObjectName(QStringLiteral("fileHandlerWidget"));

        gridLayout_3->addWidget(fileHandlerWidget, 0, 0, 1, 1);


        gridLayout_2->addWidget(fileHandlerBox, 2, 0, 1, 1);

        actuatorBox = new QGroupBox(general);
        actuatorBox->setObjectName(QStringLiteral("actuatorBox"));
        sizePolicy2.setHeightForWidth(actuatorBox->sizePolicy().hasHeightForWidth());
        actuatorBox->setSizePolicy(sizePolicy2);
        gridLayout_5 = new QGridLayout(actuatorBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        actuatorControlWidget = new ActuatorWidget(actuatorBox);
        actuatorControlWidget->setObjectName(QStringLiteral("actuatorControlWidget"));

        gridLayout_5->addWidget(actuatorControlWidget, 0, 0, 1, 1);


        gridLayout_2->addWidget(actuatorBox, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 7, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 1, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 2, 2, 1, 1);

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
        scanImaging = new QWidget();
        scanImaging->setObjectName(QStringLiteral("scanImaging"));
        gridLayout_10 = new QGridLayout(scanImaging);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        imagingWidget = new QLabel(scanImaging);
        imagingWidget->setObjectName(QStringLiteral("imagingWidget"));
        imagingWidget->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(imagingWidget, 0, 0, 1, 1);

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

        tabWidget->addTab(scanImaging, QString());
        arrayControl = new QWidget();
        arrayControl->setObjectName(QStringLiteral("arrayControl"));
        tabWidget->addTab(arrayControl, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 3, 8);

        scanBox = new QGroupBox(centralWidget);
        scanBox->setObjectName(QStringLiteral("scanBox"));
        sizePolicy2.setHeightForWidth(scanBox->sizePolicy().hasHeightForWidth());
        scanBox->setSizePolicy(sizePolicy2);
        gridLayout_4 = new QGridLayout(scanBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        scanControlWidget = new ScanWidget(scanBox);
        scanControlWidget->setObjectName(QStringLiteral("scanControlWidget"));

        gridLayout_4->addWidget(scanControlWidget, 0, 0, 1, 1);


        gridLayout->addWidget(scanBox, 2, 9, 1, 1);

        tcpBox = new QGroupBox(centralWidget);
        tcpBox->setObjectName(QStringLiteral("tcpBox"));
        sizePolicy2.setHeightForWidth(tcpBox->sizePolicy().hasHeightForWidth());
        tcpBox->setSizePolicy(sizePolicy2);
        gridLayout_6 = new QGridLayout(tcpBox);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        tcpControlWidget = new TcpClientWidget(tcpBox);
        tcpControlWidget->setObjectName(QStringLiteral("tcpControlWidget"));

        gridLayout_6->addWidget(tcpControlWidget, 0, 0, 1, 1);


        gridLayout->addWidget(tcpBox, 2, 8, 1, 1);

        ScanClientGui->setCentralWidget(centralWidget);

        retranslateUi(ScanClientGui);
        QObject::connect(pushButton, SIGNAL(clicked(bool)), ScanClientGui, SLOT(close()));
        QObject::connect(pushButton_2, SIGNAL(clicked(bool)), ScanClientGui, SLOT(showMinimized()));
        QObject::connect(pushButton_3, SIGNAL(clicked(bool)), ScanClientGui, SLOT(showFullScreen()));
        QObject::connect(pushButton_4, SIGNAL(clicked(bool)), ScanClientGui, SLOT(showNormal()));

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(ScanClientGui);
    } // setupUi

    void retranslateUi(QMainWindow *ScanClientGui)
    {
        ScanClientGui->setWindowTitle(QApplication::translate("ScanClientGui", "ScanClientGui", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ScanClientGui", "X", Q_NULLPTR));
        titleLabel->setText(QApplication::translate("ScanClientGui", "IR ScanMasterPi", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("ScanClientGui", "><", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("ScanClientGui", "<>", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("ScanClientGui", "-", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ScanClientGui", "Log", Q_NULLPTR));
        label->setText(QApplication::translate("ScanClientGui", "by CT ScanMasters 2018", Q_NULLPTR));
        fileHandlerBox->setTitle(QApplication::translate("ScanClientGui", "File handler", Q_NULLPTR));
        actuatorBox->setTitle(QApplication::translate("ScanClientGui", "Actuator control", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(general), QApplication::translate("ScanClientGui", "General", Q_NULLPTR));
        scanPlot->setTitle(QApplication::translate("ScanClientGui", "3D Scan plot", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(scanData), QApplication::translate("ScanClientGui", "Scan data", Q_NULLPTR));
        imagingWidget->setText(QApplication::translate("ScanClientGui", "IMAGE", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(scanImaging), QApplication::translate("ScanClientGui", "Scan Imaging", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(arrayControl), QApplication::translate("ScanClientGui", "Array control", Q_NULLPTR));
        scanBox->setTitle(QApplication::translate("ScanClientGui", "Scan control", Q_NULLPTR));
        tcpBox->setTitle(QApplication::translate("ScanClientGui", "Connection", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ScanClientGui: public Ui_ScanClientGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANCLIENTGUI_H
