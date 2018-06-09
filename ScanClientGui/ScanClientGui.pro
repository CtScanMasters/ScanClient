#-------------------------------------------------
#
# Project created by QtCreator 2018-04-10T19:03:15
#
#-------------------------------------------------

QT       += core gui
QT       += datavisualization
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ScanClientGui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        scanclientgui.cpp \
    3DScatterWidget/scatterwidget.cpp \
    ActuatorWidget/actuatorwidget.cpp \
    ArrayWidget/arraywidget.cpp \
    FileHandlerWidget/filehandlerwidget.cpp \
    ScanWidget/scanwidget.cpp \
    SocketHandler/sockethandler.cpp \
    TcpClient/tcpclient.cpp \
    TcpClientWidget/tcpclientwidget.cpp \
    MessageLogger/messagelogger.cpp \
    ImageCalculator/imagecalculator.cpp \
    ImageCalculator/imageprocessor.cpp \
    ImageCalculator/imageprocessmanager.cpp \
    ImageCalculator/imageprocesstask.cpp \
    FileHandlerWidget/imageviewerwidget.cpp

HEADERS += \
        scanclientgui.h \
    3DScatterWidget/scatterwidget.h \
    ActuatorWidget/actuatorwidget.h \
    ArrayWidget/arraywidget.h \
    FileHandlerWidget/filehandlerwidget.h \
    ScanWidget/scanwidget.h \
    SocketHandler/sockethandler.h \
    TcpClient/tcpclient.h \
    TcpClientWidget/tcpclientwidget.h \
    MessageLogger/messagelogger.h \
    ImageCalculator/imagecalculator.h \
    commandlist.h \
    ImageCalculator/imageprocessor.h \
    ImageCalculator/imageprocessmanager.h \
    ImageCalculator/imageprocesstask.h \
    FileHandlerWidget/imageviewerwidget.h

FORMS += \
        scanclientgui.ui \
    FileHandlerWidget/imageviewerwidget.ui

DISTFILES += \
    Stylesheet/StylesheetCt.txt \
    Stylesheet/ScanMaster pic.png

RESOURCES += \
    Stylesheet/resource_file.qrc
