/****************************************************************************
** Meta object code from reading C++ file 'xvideothread.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/xvideothread.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xvideothread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSXVideoThreadENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSXVideoThreadENDCLASS = QtMocHelpers::stringData(
    "XVideoThread",
    "ViewImage1",
    "",
    "cv::Mat",
    "mat",
    "ViewImage2",
    "ViewDst",
    "SaveEnd"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSXVideoThreadENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[13];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[4];
    char stringdata5[11];
    char stringdata6[8];
    char stringdata7[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSXVideoThreadENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSXVideoThreadENDCLASS_t qt_meta_stringdata_CLASSXVideoThreadENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "XVideoThread"
        QT_MOC_LITERAL(13, 10),  // "ViewImage1"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 7),  // "cv::Mat"
        QT_MOC_LITERAL(33, 3),  // "mat"
        QT_MOC_LITERAL(37, 10),  // "ViewImage2"
        QT_MOC_LITERAL(48, 7),  // "ViewDst"
        QT_MOC_LITERAL(56, 7)   // "SaveEnd"
    },
    "XVideoThread",
    "ViewImage1",
    "",
    "cv::Mat",
    "mat",
    "ViewImage2",
    "ViewDst",
    "SaveEnd"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSXVideoThreadENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    1 /* Public */,
       5,    1,   41,    2, 0x06,    3 /* Public */,
       6,    1,   44,    2, 0x06,    5 /* Public */,
       7,    0,   47,    2, 0x06,    7 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject XVideoThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_CLASSXVideoThreadENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSXVideoThreadENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSXVideoThreadENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<XVideoThread, std::true_type>,
        // method 'ViewImage1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<cv::Mat, std::false_type>,
        // method 'ViewImage2'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<cv::Mat, std::false_type>,
        // method 'ViewDst'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<cv::Mat, std::false_type>,
        // method 'SaveEnd'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void XVideoThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<XVideoThread *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ViewImage1((*reinterpret_cast< std::add_pointer_t<cv::Mat>>(_a[1]))); break;
        case 1: _t->ViewImage2((*reinterpret_cast< std::add_pointer_t<cv::Mat>>(_a[1]))); break;
        case 2: _t->ViewDst((*reinterpret_cast< std::add_pointer_t<cv::Mat>>(_a[1]))); break;
        case 3: _t->SaveEnd(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (XVideoThread::*)(cv::Mat );
            if (_t _q_method = &XVideoThread::ViewImage1; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (XVideoThread::*)(cv::Mat );
            if (_t _q_method = &XVideoThread::ViewImage2; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (XVideoThread::*)(cv::Mat );
            if (_t _q_method = &XVideoThread::ViewDst; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (XVideoThread::*)();
            if (_t _q_method = &XVideoThread::SaveEnd; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *XVideoThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XVideoThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSXVideoThreadENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int XVideoThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void XVideoThread::ViewImage1(cv::Mat _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void XVideoThread::ViewImage2(cv::Mat _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void XVideoThread::ViewDst(cv::Mat _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void XVideoThread::SaveEnd()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
