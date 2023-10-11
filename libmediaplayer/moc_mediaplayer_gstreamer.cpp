/****************************************************************************
** Meta object code from reading C++ file 'mediaplayer_gstreamer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mediaplayer_gstreamer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mediaplayer_gstreamer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MediaPlayer_GStreamer_t {
    QByteArrayData data[13];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MediaPlayer_GStreamer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MediaPlayer_GStreamer_t qt_meta_stringdata_MediaPlayer_GStreamer = {
    {
QT_MOC_LITERAL(0, 0, 21), // "MediaPlayer_GStreamer"
QT_MOC_LITERAL(1, 22, 6), // "loaded"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 8), // "finished"
QT_MOC_LITERAL(4, 39, 5), // "error"
QT_MOC_LITERAL(5, 45, 4), // "text"
QT_MOC_LITERAL(6, 50, 11), // "tagsChanged"
QT_MOC_LITERAL(7, 62, 6), // "artist"
QT_MOC_LITERAL(8, 69, 5), // "title"
QT_MOC_LITERAL(9, 75, 15), // "durationChanged"
QT_MOC_LITERAL(10, 91, 7), // "logging"
QT_MOC_LITERAL(11, 99, 8), // "facility"
QT_MOC_LITERAL(12, 108, 7) // "message"

    },
    "MediaPlayer_GStreamer\0loaded\0\0finished\0"
    "error\0text\0tagsChanged\0artist\0title\0"
    "durationChanged\0logging\0facility\0"
    "message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MediaPlayer_GStreamer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    1,   46,    2, 0x06 /* Public */,
       6,    2,   49,    2, 0x06 /* Public */,
       9,    0,   54,    2, 0x06 /* Public */,
      10,    2,   55,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    7,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,   12,

       0        // eod
};

void MediaPlayer_GStreamer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MediaPlayer_GStreamer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loaded(); break;
        case 1: _t->finished(); break;
        case 2: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->tagsChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->durationChanged(); break;
        case 5: _t->logging((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MediaPlayer_GStreamer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaPlayer_GStreamer::loaded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MediaPlayer_GStreamer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaPlayer_GStreamer::finished)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MediaPlayer_GStreamer::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaPlayer_GStreamer::error)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MediaPlayer_GStreamer::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaPlayer_GStreamer::tagsChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MediaPlayer_GStreamer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaPlayer_GStreamer::durationChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MediaPlayer_GStreamer::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaPlayer_GStreamer::logging)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MediaPlayer_GStreamer::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_MediaPlayer_GStreamer.data,
    qt_meta_data_MediaPlayer_GStreamer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MediaPlayer_GStreamer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MediaPlayer_GStreamer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MediaPlayer_GStreamer.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "MediaPlayer"))
        return static_cast< MediaPlayer*>(this);
    if (!strcmp(_clname, "MediaPlayer"))
        return static_cast< MediaPlayer*>(this);
    return QObject::qt_metacast(_clname);
}

int MediaPlayer_GStreamer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void MediaPlayer_GStreamer::loaded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MediaPlayer_GStreamer::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MediaPlayer_GStreamer::error(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MediaPlayer_GStreamer::tagsChanged(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MediaPlayer_GStreamer::durationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MediaPlayer_GStreamer::logging(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
