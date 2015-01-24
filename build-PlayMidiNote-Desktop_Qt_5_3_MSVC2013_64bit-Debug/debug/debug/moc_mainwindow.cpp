/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PlayMidiNote/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata[373];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 17),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 7),
QT_MOC_LITERAL(4, 38, 17),
QT_MOC_LITERAL(5, 56, 17),
QT_MOC_LITERAL(6, 74, 17),
QT_MOC_LITERAL(7, 92, 17),
QT_MOC_LITERAL(8, 110, 17),
QT_MOC_LITERAL(9, 128, 17),
QT_MOC_LITERAL(10, 146, 17),
QT_MOC_LITERAL(11, 164, 17),
QT_MOC_LITERAL(12, 182, 18),
QT_MOC_LITERAL(13, 201, 18),
QT_MOC_LITERAL(14, 220, 18),
QT_MOC_LITERAL(15, 239, 22),
QT_MOC_LITERAL(16, 262, 5),
QT_MOC_LITERAL(17, 268, 25),
QT_MOC_LITERAL(18, 294, 27),
QT_MOC_LITERAL(19, 322, 4),
QT_MOC_LITERAL(20, 327, 21),
QT_MOC_LITERAL(21, 349, 23)
    },
    "MainWindow\0on_note_1_clicked\0\0checked\0"
    "on_note_2_clicked\0on_note_3_clicked\0"
    "on_note_4_clicked\0on_note_5_clicked\0"
    "on_note_6_clicked\0on_note_7_clicked\0"
    "on_note_8_clicked\0on_note_9_clicked\0"
    "on_note_10_clicked\0on_note_11_clicked\0"
    "on_note_12_clicked\0on_volume_valueChanged\0"
    "value\0on_pitchbend_valueChanged\0"
    "on_midichannel_valueChanged\0arg1\0"
    "on_comboBox_activated\0on_program_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x08 /* Private */,
       4,    1,  102,    2, 0x08 /* Private */,
       5,    1,  105,    2, 0x08 /* Private */,
       6,    1,  108,    2, 0x08 /* Private */,
       7,    1,  111,    2, 0x08 /* Private */,
       8,    1,  114,    2, 0x08 /* Private */,
       9,    1,  117,    2, 0x08 /* Private */,
      10,    1,  120,    2, 0x08 /* Private */,
      11,    1,  123,    2, 0x08 /* Private */,
      12,    1,  126,    2, 0x08 /* Private */,
      13,    1,  129,    2, 0x08 /* Private */,
      14,    1,  132,    2, 0x08 /* Private */,
      15,    1,  135,    2, 0x08 /* Private */,
      17,    1,  138,    2, 0x08 /* Private */,
      18,    1,  141,    2, 0x08 /* Private */,
      20,    1,  144,    2, 0x08 /* Private */,
      21,    1,  147,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::Int,   19,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_note_1_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_note_2_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_note_3_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_note_4_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_note_5_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_note_6_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_note_7_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_note_8_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_note_9_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_note_10_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_note_11_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_note_12_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_volume_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_pitchbend_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_midichannel_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_comboBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->on_program_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
