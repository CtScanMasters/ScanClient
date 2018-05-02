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
    QByteArrayData data[13];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScanClientGui_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScanClientGui_t qt_meta_stringdata_ScanClientGui = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ScanClientGui"
QT_MOC_LITERAL(1, 14, 10), // "tcpConnect"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 13), // "tcpDisconnect"
QT_MOC_LITERAL(4, 40, 14), // "tcpStateChange"
QT_MOC_LITERAL(5, 55, 11), // "tcpSendData"
QT_MOC_LITERAL(6, 67, 14), // "arraySetSource"
QT_MOC_LITERAL(7, 82, 10), // "sourceMask"
QT_MOC_LITERAL(8, 93, 14), // "arrayGetSensor"
QT_MOC_LITERAL(9, 108, 14), // "getMeasurement"
QT_MOC_LITERAL(10, 123, 18), // "actuatorJogForward"
QT_MOC_LITERAL(11, 142, 15), // "actuatorJogBack"
QT_MOC_LITERAL(12, 158, 12) // "actuatorHome"

    },
    "ScanClientGui\0tcpConnect\0\0tcpDisconnect\0"
    "tcpStateChange\0tcpSendData\0arraySetSource\0"
    "sourceMask\0arrayGetSensor\0getMeasurement\0"
    "actuatorJogForward\0actuatorJogBack\0"
    "actuatorHome"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScanClientGui[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    1,   68,    2, 0x08 /* Private */,
       8,    0,   71,    2, 0x08 /* Private */,
       9,    0,   72,    2, 0x08 /* Private */,
      10,    0,   73,    2, 0x08 /* Private */,
      11,    0,   74,    2, 0x08 /* Private */,
      12,    0,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar,    7,
    QMetaType::Void,
    QMetaType::Void,
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
        case 0: _t->tcpConnect(); break;
        case 1: _t->tcpDisconnect(); break;
        case 2: _t->tcpStateChange(); break;
        case 3: _t->tcpSendData(); break;
        case 4: _t->arraySetSource((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 5: _t->arrayGetSensor(); break;
        case 6: _t->getMeasurement(); break;
        case 7: _t->actuatorJogForward(); break;
        case 8: _t->actuatorJogBack(); break;
        case 9: _t->actuatorHome(); break;
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
