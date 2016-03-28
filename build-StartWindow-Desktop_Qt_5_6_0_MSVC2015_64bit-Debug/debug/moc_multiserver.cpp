/****************************************************************************
** Meta object code from reading C++ file 'multiserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UI/multiserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'multiserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MultiServer_t {
    QByteArrayData data[13];
    char stringdata0[251];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MultiServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MultiServer_t qt_meta_stringdata_MultiServer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MultiServer"
QT_MOC_LITERAL(1, 12, 24), // "on_pushButton_4_released"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 27), // "on_buttonStopAudio_released"
QT_MOC_LITERAL(4, 66, 28), // "on_buttonPauseAudio_released"
QT_MOC_LITERAL(5, 95, 30), // "on_sliderSound_actionTriggered"
QT_MOC_LITERAL(6, 126, 6), // "action"
QT_MOC_LITERAL(7, 133, 26), // "on_QueueAddButton_released"
QT_MOC_LITERAL(8, 160, 29), // "on_QueueRemoveButton_released"
QT_MOC_LITERAL(9, 190, 12), // "playNextSong"
QT_MOC_LITERAL(10, 203, 15), // "updateStatusBar"
QT_MOC_LITERAL(11, 219, 3), // "msg"
QT_MOC_LITERAL(12, 223, 27) // "on_SendAudioButton_released"

    },
    "MultiServer\0on_pushButton_4_released\0"
    "\0on_buttonStopAudio_released\0"
    "on_buttonPauseAudio_released\0"
    "on_sliderSound_actionTriggered\0action\0"
    "on_QueueAddButton_released\0"
    "on_QueueRemoveButton_released\0"
    "playNextSong\0updateStatusBar\0msg\0"
    "on_SendAudioButton_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MultiServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    1,   62,    2, 0x08 /* Private */,
       7,    0,   65,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    1,   68,    2, 0x08 /* Private */,
      12,    0,   71,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,

       0        // eod
};

void MultiServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MultiServer *_t = static_cast<MultiServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_4_released(); break;
        case 1: _t->on_buttonStopAudio_released(); break;
        case 2: _t->on_buttonPauseAudio_released(); break;
        case 3: _t->on_sliderSound_actionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_QueueAddButton_released(); break;
        case 5: _t->on_QueueRemoveButton_released(); break;
        case 6: _t->playNextSong(); break;
        case 7: _t->updateStatusBar((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->on_SendAudioButton_released(); break;
        default: ;
        }
    }
}

const QMetaObject MultiServer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MultiServer.data,
      qt_meta_data_MultiServer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MultiServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MultiServer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MultiServer.stringdata0))
        return static_cast<void*>(const_cast< MultiServer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MultiServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
