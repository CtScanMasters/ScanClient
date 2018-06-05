/****************************************************************************
** Meta object code from reading C++ file 'imageprocessmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ScanClientGui/ImageCalculator/imageprocessmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageprocessmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ImageProcessManager_t {
    QByteArrayData data[6];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageProcessManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageProcessManager_t qt_meta_stringdata_ImageProcessManager = {
    {
QT_MOC_LITERAL(0, 0, 19), // "ImageProcessManager"
QT_MOC_LITERAL(1, 20, 15), // "startProcessing"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 14), // "processingDone"
QT_MOC_LITERAL(4, 52, 18), // "finishedProcessing"
QT_MOC_LITERAL(5, 71, 10) // "scanNumber"

    },
    "ImageProcessManager\0startProcessing\0"
    "\0processingDone\0finishedProcessing\0"
    "scanNumber"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageProcessManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       3,    0,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UShort,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::UShort,    5,

       0        // eod
};

void ImageProcessManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageProcessManager *_t = static_cast<ImageProcessManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startProcessing((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 1: _t->processingDone(); break;
        case 2: _t->finishedProcessing((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ImageProcessManager::*_t)(quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImageProcessManager::startProcessing)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ImageProcessManager::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImageProcessManager::processingDone)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ImageProcessManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ImageProcessManager.data,
      qt_meta_data_ImageProcessManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ImageProcessManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageProcessManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ImageProcessManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ImageProcessManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ImageProcessManager::startProcessing(quint16 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ImageProcessManager::processingDone()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
