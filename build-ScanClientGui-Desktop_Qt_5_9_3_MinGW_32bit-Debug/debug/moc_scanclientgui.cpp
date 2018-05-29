/****************************************************************************
** Meta object code from reading C++ file 'scanclientgui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ScanClientGui/scanclientgui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scanclientgui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ScanClientGui_t {
    QByteArrayData data[28];
    char stringdata0[354];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScanClientGui_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScanClientGui_t qt_meta_stringdata_ScanClientGui = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ScanClientGui"
QT_MOC_LITERAL(1, 14, 14), // "commandHandler"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 7), // "command"
QT_MOC_LITERAL(4, 38, 9), // "scanStart"
QT_MOC_LITERAL(5, 48, 8), // "scanStop"
QT_MOC_LITERAL(6, 57, 15), // "setScanProgress"
QT_MOC_LITERAL(7, 73, 11), // "getScanData"
QT_MOC_LITERAL(8, 85, 18), // "actuatorJogForward"
QT_MOC_LITERAL(9, 104, 15), // "actuatorJogBack"
QT_MOC_LITERAL(10, 120, 16), // "actuatorPosition"
QT_MOC_LITERAL(11, 137, 12), // "actuatorHome"
QT_MOC_LITERAL(12, 150, 12), // "sendNotReady"
QT_MOC_LITERAL(13, 163, 9), // "sendReady"
QT_MOC_LITERAL(14, 173, 11), // "newScanData"
QT_MOC_LITERAL(15, 185, 12), // "dataDelivery"
QT_MOC_LITERAL(16, 198, 7), // "dataEnd"
QT_MOC_LITERAL(17, 206, 11), // "prepareData"
QT_MOC_LITERAL(18, 218, 10), // "tcpConnect"
QT_MOC_LITERAL(19, 229, 13), // "tcpDisconnect"
QT_MOC_LITERAL(20, 243, 14), // "tcpStateChange"
QT_MOC_LITERAL(21, 258, 11), // "tcpSendData"
QT_MOC_LITERAL(22, 270, 11), // "tcpReadData"
QT_MOC_LITERAL(23, 282, 18), // "arraySetSourceMask"
QT_MOC_LITERAL(24, 301, 10), // "sourceMask"
QT_MOC_LITERAL(25, 312, 14), // "arraySetSource"
QT_MOC_LITERAL(26, 327, 14), // "arrayGetSensor"
QT_MOC_LITERAL(27, 342, 11) // "processData"

    },
    "ScanClientGui\0commandHandler\0\0command\0"
    "scanStart\0scanStop\0setScanProgress\0"
    "getScanData\0actuatorJogForward\0"
    "actuatorJogBack\0actuatorPosition\0"
    "actuatorHome\0sendNotReady\0sendReady\0"
    "newScanData\0dataDelivery\0dataEnd\0"
    "prepareData\0tcpConnect\0tcpDisconnect\0"
    "tcpStateChange\0tcpSendData\0tcpReadData\0"
    "arraySetSourceMask\0sourceMask\0"
    "arraySetSource\0arrayGetSensor\0processData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScanClientGui[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  134,    2, 0x08 /* Private */,
       4,    0,  137,    2, 0x08 /* Private */,
       5,    0,  138,    2, 0x08 /* Private */,
       6,    0,  139,    2, 0x08 /* Private */,
       7,    0,  140,    2, 0x08 /* Private */,
       8,    0,  141,    2, 0x08 /* Private */,
       9,    0,  142,    2, 0x08 /* Private */,
      10,    0,  143,    2, 0x08 /* Private */,
      11,    0,  144,    2, 0x08 /* Private */,
      12,    0,  145,    2, 0x08 /* Private */,
      13,    0,  146,    2, 0x08 /* Private */,
      14,    0,  147,    2, 0x08 /* Private */,
      15,    0,  148,    2, 0x08 /* Private */,
      16,    0,  149,    2, 0x08 /* Private */,
      17,    0,  150,    2, 0x08 /* Private */,
      18,    0,  151,    2, 0x08 /* Private */,
      19,    0,  152,    2, 0x08 /* Private */,
      20,    0,  153,    2, 0x08 /* Private */,
      21,    0,  154,    2, 0x08 /* Private */,
      22,    0,  155,    2, 0x08 /* Private */,
      23,    1,  156,    2, 0x08 /* Private */,
      25,    0,  159,    2, 0x08 /* Private */,
      26,    0,  160,    2, 0x08 /* Private */,
      27,    0,  161,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::UShort,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ScanClientGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScanClientGui *_t = static_cast<ScanClientGui *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->commandHandler((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 1: _t->scanStart(); break;
        case 2: _t->scanStop(); break;
        case 3: _t->setScanProgress(); break;
        case 4: _t->getScanData(); break;
        case 5: _t->actuatorJogForward(); break;
        case 6: _t->actuatorJogBack(); break;
        case 7: _t->actuatorPosition(); break;
        case 8: _t->actuatorHome(); break;
        case 9: _t->sendNotReady(); break;
        case 10: _t->sendReady(); break;
        case 11: _t->newScanData(); break;
        case 12: _t->dataDelivery(); break;
        case 13: _t->dataEnd(); break;
        case 14: _t->prepareData(); break;
        case 15: _t->tcpConnect(); break;
        case 16: _t->tcpDisconnect(); break;
        case 17: _t->tcpStateChange(); break;
        case 18: _t->tcpSendData(); break;
        case 19: _t->tcpReadData(); break;
        case 20: _t->arraySetSourceMask((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 21: _t->arraySetSource(); break;
        case 22: _t->arrayGetSensor(); break;
        case 23: _t->processData(); break;
        default: ;
        }
    }
}

const QMetaObject ScanClientGui::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ScanClientGui.data,
      qt_meta_data_ScanClientGui,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ScanClientGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScanClientGui::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScanClientGui.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ScanClientGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 24;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
