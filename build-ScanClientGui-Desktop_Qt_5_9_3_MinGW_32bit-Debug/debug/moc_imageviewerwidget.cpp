/****************************************************************************
** Meta object code from reading C++ file 'imageviewerwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ScanClientGui/FileHandlerWidget/imageviewerwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageviewerwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ImageViewerWidget_t {
    QByteArrayData data[11];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageViewerWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageViewerWidget_t qt_meta_stringdata_ImageViewerWidget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ImageViewerWidget"
QT_MOC_LITERAL(1, 18, 10), // "openFolder"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 4), // "next"
QT_MOC_LITERAL(4, 35, 8), // "previous"
QT_MOC_LITERAL(5, 44, 13), // "getImageNames"
QT_MOC_LITERAL(6, 58, 8), // "getImage"
QT_MOC_LITERAL(7, 67, 8), // "iterator"
QT_MOC_LITERAL(8, 76, 9), // "setImages"
QT_MOC_LITERAL(9, 86, 16), // "startTimerScroll"
QT_MOC_LITERAL(10, 103, 15) // "stopTimerScroll"

    },
    "ImageViewerWidget\0openFolder\0\0next\0"
    "previous\0getImageNames\0getImage\0"
    "iterator\0setImages\0startTimerScroll\0"
    "stopTimerScroll"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageViewerWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    1,   58,    2, 0x0a /* Public */,
       8,    0,   61,    2, 0x0a /* Public */,
       9,    0,   62,    2, 0x0a /* Public */,
      10,    0,   63,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QImage, QMetaType::UInt,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ImageViewerWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageViewerWidget *_t = static_cast<ImageViewerWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openFolder(); break;
        case 1: _t->next(); break;
        case 2: _t->previous(); break;
        case 3: _t->getImageNames(); break;
        case 4: { QImage _r = _t->getImage((*reinterpret_cast< quint32(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->setImages(); break;
        case 6: _t->startTimerScroll(); break;
        case 7: _t->stopTimerScroll(); break;
        default: ;
        }
    }
}

const QMetaObject ImageViewerWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ImageViewerWidget.data,
      qt_meta_data_ImageViewerWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ImageViewerWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageViewerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ImageViewerWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ImageViewerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
