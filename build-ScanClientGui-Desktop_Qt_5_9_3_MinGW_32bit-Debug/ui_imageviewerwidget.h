/********************************************************************************
** Form generated from reading UI file 'imageviewerwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEVIEWERWIDGET_H
#define UI_IMAGEVIEWERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageViewerWidget
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButtonOpen;
    QPushButton *pushButtonNext;
    QPushButton *pushButtonPrevious;
    QSpacerItem *horizontalSpacer;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLabel *labelImage1;
    QLabel *labelImage2;
    QLabel *labelImage3;
    QLabel *labelImage4;
    QLabel *labelImage5;
    QLabel *labelImage6;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *labelFilePath;
    QLabel *labelScans;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *ImageViewerWidget)
    {
        if (ImageViewerWidget->objectName().isEmpty())
            ImageViewerWidget->setObjectName(QStringLiteral("ImageViewerWidget"));
        ImageViewerWidget->resize(1299, 922);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ImageViewerWidget->sizePolicy().hasHeightForWidth());
        ImageViewerWidget->setSizePolicy(sizePolicy);
        ImageViewerWidget->setMaximumSize(QSize(16777215, 16777215));
        layoutWidget = new QWidget(ImageViewerWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 360, 27));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonOpen = new QPushButton(layoutWidget);
        pushButtonOpen->setObjectName(QStringLiteral("pushButtonOpen"));
        pushButtonOpen->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(pushButtonOpen, 0, 0, 1, 1);

        pushButtonNext = new QPushButton(layoutWidget);
        pushButtonNext->setObjectName(QStringLiteral("pushButtonNext"));
        pushButtonNext->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(pushButtonNext, 0, 2, 1, 1);

        pushButtonPrevious = new QPushButton(layoutWidget);
        pushButtonPrevious->setObjectName(QStringLiteral("pushButtonPrevious"));
        pushButtonPrevious->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(pushButtonPrevious, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 4, 1, 1);

        layoutWidget1 = new QWidget(ImageViewerWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 120, 1166, 776));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        labelImage1 = new QLabel(layoutWidget1);
        labelImage1->setObjectName(QStringLiteral("labelImage1"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelImage1->sizePolicy().hasHeightForWidth());
        labelImage1->setSizePolicy(sizePolicy1);
        labelImage1->setMaximumSize(QSize(400, 400));

        gridLayout_2->addWidget(labelImage1, 0, 0, 1, 1);

        labelImage2 = new QLabel(layoutWidget1);
        labelImage2->setObjectName(QStringLiteral("labelImage2"));
        sizePolicy1.setHeightForWidth(labelImage2->sizePolicy().hasHeightForWidth());
        labelImage2->setSizePolicy(sizePolicy1);
        labelImage2->setMaximumSize(QSize(400, 400));

        gridLayout_2->addWidget(labelImage2, 0, 1, 1, 1);

        labelImage3 = new QLabel(layoutWidget1);
        labelImage3->setObjectName(QStringLiteral("labelImage3"));
        sizePolicy1.setHeightForWidth(labelImage3->sizePolicy().hasHeightForWidth());
        labelImage3->setSizePolicy(sizePolicy1);
        labelImage3->setMaximumSize(QSize(400, 400));

        gridLayout_2->addWidget(labelImage3, 0, 2, 1, 1);

        labelImage4 = new QLabel(layoutWidget1);
        labelImage4->setObjectName(QStringLiteral("labelImage4"));
        sizePolicy1.setHeightForWidth(labelImage4->sizePolicy().hasHeightForWidth());
        labelImage4->setSizePolicy(sizePolicy1);
        labelImage4->setMaximumSize(QSize(400, 400));

        gridLayout_2->addWidget(labelImage4, 1, 0, 1, 1);

        labelImage5 = new QLabel(layoutWidget1);
        labelImage5->setObjectName(QStringLiteral("labelImage5"));
        sizePolicy1.setHeightForWidth(labelImage5->sizePolicy().hasHeightForWidth());
        labelImage5->setSizePolicy(sizePolicy1);
        labelImage5->setMaximumSize(QSize(400, 400));

        gridLayout_2->addWidget(labelImage5, 1, 1, 1, 1);

        labelImage6 = new QLabel(layoutWidget1);
        labelImage6->setObjectName(QStringLiteral("labelImage6"));
        sizePolicy1.setHeightForWidth(labelImage6->sizePolicy().hasHeightForWidth());
        labelImage6->setSizePolicy(sizePolicy1);
        labelImage6->setMaximumSize(QSize(400, 400));

        gridLayout_2->addWidget(labelImage6, 1, 2, 1, 1);

        widget = new QWidget(ImageViewerWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(9, 42, 811, 60));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelFilePath = new QLabel(widget);
        labelFilePath->setObjectName(QStringLiteral("labelFilePath"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelFilePath->sizePolicy().hasHeightForWidth());
        labelFilePath->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(labelFilePath);

        labelScans = new QLabel(widget);
        labelScans->setObjectName(QStringLiteral("labelScans"));

        verticalLayout->addWidget(labelScans);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);


        retranslateUi(ImageViewerWidget);

        QMetaObject::connectSlotsByName(ImageViewerWidget);
    } // setupUi

    void retranslateUi(QWidget *ImageViewerWidget)
    {
        ImageViewerWidget->setWindowTitle(QApplication::translate("ImageViewerWidget", "Form", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButtonOpen->setToolTip(QApplication::translate("ImageViewerWidget", "open image folder", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonOpen->setText(QApplication::translate("ImageViewerWidget", "Open folder", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButtonNext->setToolTip(QApplication::translate("ImageViewerWidget", "next image (hold to scroll)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonNext->setText(QApplication::translate("ImageViewerWidget", "Next", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButtonPrevious->setToolTip(QApplication::translate("ImageViewerWidget", "previous image (hold to scroll)", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonPrevious->setText(QApplication::translate("ImageViewerWidget", "Previous", Q_NULLPTR));
        labelImage1->setText(QApplication::translate("ImageViewerWidget", "<html><head/><body><p><img src=\":/ScanMaster pic.png\"/></p></body></html>", Q_NULLPTR));
        labelImage2->setText(QApplication::translate("ImageViewerWidget", "<html><head/><body><p><img src=\":/ScanMaster pic.png\"/></p></body></html>", Q_NULLPTR));
        labelImage3->setText(QApplication::translate("ImageViewerWidget", "<html><head/><body><p><img src=\":/ScanMaster pic.png\"/></p></body></html>", Q_NULLPTR));
        labelImage4->setText(QApplication::translate("ImageViewerWidget", "<html><head/><body><p><img src=\":/ScanMaster pic.png\"/></p></body></html>", Q_NULLPTR));
        labelImage5->setText(QApplication::translate("ImageViewerWidget", "<html><head/><body><p><img src=\":/ScanMaster pic.png\"/></p></body></html>", Q_NULLPTR));
        labelImage6->setText(QApplication::translate("ImageViewerWidget", "<html><head/><body><p><img src=\":/ScanMaster pic.png\"/></p></body></html>", Q_NULLPTR));
        labelFilePath->setText(QApplication::translate("ImageViewerWidget", "Folder: -", Q_NULLPTR));
        labelScans->setText(QApplication::translate("ImageViewerWidget", "Scans: -", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ImageViewerWidget: public Ui_ImageViewerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEVIEWERWIDGET_H
