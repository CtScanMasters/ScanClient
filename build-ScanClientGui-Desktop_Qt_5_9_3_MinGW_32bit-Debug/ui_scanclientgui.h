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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScanClientGui
{
public:
    QWidget *centralWidget;

    void setupUi(QMainWindow *ScanClientGui)
    {
        if (ScanClientGui->objectName().isEmpty())
            ScanClientGui->setObjectName(QStringLiteral("ScanClientGui"));
        ScanClientGui->resize(400, 300);
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
"QPushButton{\n"
"	border: 1px solid rgb(0, 0, 0);\n"
"	border-radius: 5px;\n"
"	background-color:qlineargradient(spread:pad, x1:0.307, y1:0.715545, x2:0, y2:1, stop:0 rgba(145, 51, 143, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	color: white;\n"
""
                        "	min-height: 18px;\n"
"\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	border: 1px solid rgb(255, 255, 255);\n"
"	background-color:rgb(111, 111, 111);\n"
"}\n"
"\n"
"QProgressBar:horizontal {\n"
"	border: 1px white;\n"
"	border-radius: 5px;\n"
"	background: rgb(81, 81, 81);\n"
"	padding: 1px;\n"
"\n"
"}\n"
"\n"
"QProgressBar::chunk:horizontal {\n"
"	background: qlineargradient(spread:pad, x1:0.3405, y1:0.761, x2:0, y2:1, stop:0 rgba(167, 120, 166, 255), stop:1 rgba(255, 255, 255, 255));\n"
"	border-radius: 5px;\n"
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
"    border: 1px solid black;\n"
"	width: 100px;\n"
"	"
                        "border-radius: 5px;\n"
"	border: 1px solid rgb(255, 255, 255);\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background: qlineargradient(spread:pad, x1:0.3405, y1:0.761, x2:0, y2:1, stop:0 rgba(167, 88, 165, 255), stop:1 rgba(255, 255, 255, 255));\n"
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
"\n"
"QTabBar::tab:bottom:selected {\n"
""
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
        ScanClientGui->setCentralWidget(centralWidget);

        retranslateUi(ScanClientGui);

        QMetaObject::connectSlotsByName(ScanClientGui);
    } // setupUi

    void retranslateUi(QMainWindow *ScanClientGui)
    {
        ScanClientGui->setWindowTitle(QApplication::translate("ScanClientGui", "ScanClientGui", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ScanClientGui: public Ui_ScanClientGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANCLIENTGUI_H
