/****************************************************************************
** Meta object code from reading C++ file 'xvideoui.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../XVideoEdit/src/xvideoui.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xvideoui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_XVideoUI_t {
    uint offsetsAndSizes[12];
    char stringdata0[9];
    char stringdata1[5];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[13];
    char stringdata5[2];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_XVideoUI_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_XVideoUI_t qt_meta_stringdata_XVideoUI = {
    {
        QT_MOC_LITERAL(0, 8),  // "XVideoUI"
        QT_MOC_LITERAL(9, 4),  // "Open"
        QT_MOC_LITERAL(14, 0),  // ""
        QT_MOC_LITERAL(15, 10),  // "timerEvent"
        QT_MOC_LITERAL(26, 12),  // "QTimerEvent*"
        QT_MOC_LITERAL(39, 1)   // "e"
    },
    "XVideoUI",
    "Open",
    "",
    "timerEvent",
    "QTimerEvent*",
    "e"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_XVideoUI[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x0a,    1 /* Public */,
       3,    1,   27,    2, 0x0a,    2 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

Q_CONSTINIT const QMetaObject XVideoUI::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_XVideoUI.offsetsAndSizes,
    qt_meta_data_XVideoUI,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_XVideoUI_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<XVideoUI, std::true_type>,
        // method 'Open'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'timerEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTimerEvent *, std::false_type>
    >,
    nullptr
} };

void XVideoUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<XVideoUI *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Open(); break;
        case 1: _t->timerEvent((*reinterpret_cast< std::add_pointer_t<QTimerEvent*>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *XVideoUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XVideoUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_XVideoUI.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int XVideoUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
