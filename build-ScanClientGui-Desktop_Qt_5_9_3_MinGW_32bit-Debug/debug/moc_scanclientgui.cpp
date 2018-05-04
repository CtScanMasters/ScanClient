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
    QByteArrayData data[24];
    char stringdata0[312];
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
QT_MOC_LITERAL(14, 173, 10), // "tcpConnect"
QT_MOC_LITERAL(15, 184, 13), // "tcpDisconnect"
QT_MOC_LITERAL(16, 198, 14), // "tcpStateChange"
QT_MOC_LITERAL(17, 213, 11), // "tcpSendData"
QT_MOC_LITERAL(18, 225, 11), // "tcpReadData"
QT_MOC_LITERAL(19, 237, 18), // "arraySetSourceMask"
QT_MOC_LITERAL(20, 256, 10), // "sourceMask"
QT_MOC_LITERAL(21, 267, 14), // "arraySetSource"
QT_MOC_LITERAL(22, 282, 14), // "arrayGetSensor"
QT_MOC_LITERAL(23, 297, 14) // "getMeasurement"

    },
    "ScanClientGui\0commandHandler\0\0command\0"
    "scanStart\0scanStop\0setScanProgress\0"
    "getScanData\0actuatorJogForward\0"
    "actuatorJogBack\0actuatorPosition\0"
    "actuatorHome\0sendNotReady\0sendReady\0"
    "tcpConnect\0tcpDisconnect\0tcpStateChange\0"
    "tcpSendData\0tcpReadData\0arraySetSourceMask\0"
    "sourceMask\0arraySetSource\0arrayGetSensor\0"
    "getMeasurement"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScanClientGui[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  114,    2, 0x08 /* Private */,
       4,    0,  117,    2, 0x08 /* Private */,
       5,    0,  118,    2, 0x08 /* Private */,
       6,    0,  119,    2, 0x08 /* Private */,
       7,    0,  120,    2, 0x08 /* Private */,
       8,    0,  121,    2, 0x08 /* Private */,
       9,    0,  122,    2, 0x08 /* Private */,
      10,    0,  123,    2, 0x08 /* Private */,
      11,    0,  124,    2, 0x08 /* Private */,
      12,    0,  125,    2, 0x08 /* Private */,
      13,    0,  126,    2, 0x08 /* Private */,
      14,    0,  127,    2, 0x08 /* Private */,
      15,    0,  128,    2, 0x08 /* Private */,
      16,    0,  129,    2, 0x08 /* Private */,
      17,    0,  130,    2, 0x08 /* Private */,
      18,    0,  131,    2, 0x08 /* Private */,
      19,    1,  132,    2, 0x08 /* Private */,
      21,    0,  135,    2, 0x08 /* Private */,
      22,    0,  136,    2, 0x08 /* Private */,
      23,    0,  137,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::UChar,   20,
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
        case 11: _t->tcpConnect(); break;
        case 12: _t->tcpDisconnect(); break;
        case 13: _t->tcpStateChange(); break;
        case 14: _t->tcpSendData(); break;
        case 15: _t->tcpReadData(); break;
        case 16: _t->arraySetSourceMask((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 17: _t->arraySetSource(); break;
        case 18: _t->arrayGetSensor(); break;
        case 19: _t->getMeasurement(); break;
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
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
