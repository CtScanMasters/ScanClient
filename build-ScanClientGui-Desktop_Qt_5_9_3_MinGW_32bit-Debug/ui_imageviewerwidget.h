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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageViewerWidget
{
public:
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QLabel *labelFilePath;
    QGridLayout *gridLayout;
    QPushButton *pushButtonOpen;
    QPushButton *pushButtonNext;
    QPushButton *pushButtonPrevious;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QLabel *labelImage1;
    QLabel *labelImage2;
    QLabel *labelImage3;
    QLabel *labelImage4;
    QLabel *labelScans;

    void setupUi(QWidget *ImageViewerWidget)
    {
        if (ImageViewerWidget->objectName().isEmpty())
            ImageViewerWidget->setObjectName(QStringLiteral("ImageViewerWidget"));
        ImageViewerWidget->resize(883, 922);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ImageViewerWidget->sizePolicy().hasHeightForWidth());
        ImageViewerWidget->setSizePolicy(sizePolicy);
        ImageViewerWidget->setMaximumSize(QSize(16777215, 16777215));
        widget = new QWidget(ImageViewerWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(9, 9, 866, 889));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        labelFilePath = new QLabel(widget);
        labelFilePath->setObjectName(QStringLiteral("labelFilePath"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelFilePath->sizePolicy().hasHeightForWidth());
        labelFilePath->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(labelFilePath, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButtonOpen = new QPushButton(widget);
        pushButtonOpen->setObjectName(QStringLiteral("pushButtonOpen"));
        pushButtonOpen->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(pushButtonOpen, 0, 0, 1, 1);

        pushButtonNext = new QPushButton(widget);
        pushButtonNext->setObjectName(QStringLiteral("pushButtonNext"));
        pushButtonNext->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(pushButtonNext, 0, 2, 1, 1);

        pushButtonPrevious = new QPushButton(widget);
        pushButtonPrevious->setObjectName(QStringLiteral("pushButtonPrevious"));
        pushButtonPrevious->setMinimumSize(QSize(100, 25));

        gridLayout->addWidget(pushButtonPrevious, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 4, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 3, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 3, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 2, 0, 1, 1);

        labelImage1 = new QLabel(widget);
        labelImage1->setObjectName(QStringLiteral("labelImage1"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelImage1->sizePolicy().hasHeightForWidth());
        labelImage1->setSizePolicy(sizePolicy2);
        labelImage1->setMaximumSize(QSize(400, 400));

        gridLayout_2->addWidget(labelImage1, 0, 0, 1, 1);

        labelImage2 = new QLabel(widget);
        labelImage2->setObjectName(QStringLiteral("labelImage2"));
        sizePolicy2.setHeightForWidth(labelImage2->sizePolicy().hasHeightForWidth());
        labelImage2->setSizePolicy(sizePolicy2);
        labelImage2->setMaximumSize(QSize(400, 400));

        gridLayout_2->addWidget(labelImage2, 0, 3, 1, 1);

        labelImage3 = new QLabel(widget);
        labelImage3->setObjectName(QStringLiteral("labelImage3"));
        sizePolicy2.setHeightForWidth(labelImage3->sizePolicy().hasHeightForWidth());
        labelImage3->setSizePolicy(sizePolicy2);
        labelImage3->setMaximumSize(QSize(400, 400));

        gridLayout_2->addWidget(labelImage3, 3, 0, 1, 1);

        labelImage4 = new QLabel(widget);
        labelImage4->setObjectName(QStringLiteral("labelImage4"));
        sizePolicy2.setHeightForWidth(labelImage4->sizePolicy().hasHeightForWidth());
        labelImage4->setSizePolicy(sizePolicy2);
        labelImage4->setMaximumSize(QSize(400, 400));

        gridLayout_2->addWidget(labelImage4, 3, 3, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 3, 0, 1, 1);

        labelScans = new QLabel(widget);
        labelScans->setObjectName(QStringLiteral("labelScans"));

        gridLayout_3->addWidget(labelScans, 2, 0, 1, 1);


        retranslateUi(ImageViewerWidget);

        QMetaObject::connectSlotsByName(ImageViewerWidget);
    } // setupUi

    void retranslateUi(QWidget *ImageViewerWidget)
    {
        ImageViewerWidget->setWindowTitle(QApplication::translate("ImageViewerWidget", "Form", Q_NULLPTR));
        labelFilePath->setText(QApplication::translate("ImageViewerWidget", "Folder: -", Q_NULLPTR));
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
        labelScans->setText(QApplication::translate("ImageViewerWidget", "Scans: -", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ImageViewerWidget: public Ui_ImageViewerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEVIEWERWIDGET_H
