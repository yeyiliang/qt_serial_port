/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[15];
    char stringdata0[285];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 16), // "SwitchSerialPort"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 13), // "fillPortsInfo"
QT_MOC_LITERAL(4, 39, 8), // "readData"
QT_MOC_LITERAL(5, 48, 30), // "on_clearShowDataButton_clicked"
QT_MOC_LITERAL(6, 79, 28), // "on_SendMessageButton_clicked"
QT_MOC_LITERAL(7, 108, 33), // "on_clearSendMessageButton_cli..."
QT_MOC_LITERAL(8, 142, 33), // "on_sendMessagelineEdit_textEd..."
QT_MOC_LITERAL(9, 176, 4), // "arg1"
QT_MOC_LITERAL(10, 181, 25), // "checkCustomBaudRatePolicy"
QT_MOC_LITERAL(11, 207, 3), // "idx"
QT_MOC_LITERAL(12, 211, 27), // "on_getDevicesButton_clicked"
QT_MOC_LITERAL(13, 239, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(14, 261, 23) // "on_pushButton_2_clicked"

    },
    "Widget\0SwitchSerialPort\0\0fillPortsInfo\0"
    "readData\0on_clearShowDataButton_clicked\0"
    "on_SendMessageButton_clicked\0"
    "on_clearSendMessageButton_clicked\0"
    "on_sendMessagelineEdit_textEdited\0"
    "arg1\0checkCustomBaudRatePolicy\0idx\0"
    "on_getDevicesButton_clicked\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    1,   75,    2, 0x08 /* Private */,
      10,    1,   78,    2, 0x08 /* Private */,
      12,    0,   81,    2, 0x08 /* Private */,
      13,    0,   82,    2, 0x08 /* Private */,
      14,    0,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Widget *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SwitchSerialPort(); break;
        case 1: _t->fillPortsInfo(); break;
        case 2: _t->readData(); break;
        case 3: _t->on_clearShowDataButton_clicked(); break;
        case 4: _t->on_SendMessageButton_clicked(); break;
        case 5: _t->on_clearSendMessageButton_clicked(); break;
        case 6: _t->on_sendMessagelineEdit_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->checkCustomBaudRatePolicy((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_getDevicesButton_clicked(); break;
        case 9: _t->on_pushButton_clicked(); break;
        case 10: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget.data,
      qt_meta_data_Widget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
