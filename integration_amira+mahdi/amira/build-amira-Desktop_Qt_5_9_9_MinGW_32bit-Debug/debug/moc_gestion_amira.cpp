/****************************************************************************
** Meta object code from reading C++ file 'gestion_amira.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../amira/gestion_amira.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gestion_amira.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_gestion_amira_t {
    QByteArrayData data[17];
    char stringdata0[324];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gestion_amira_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gestion_amira_t qt_meta_stringdata_gestion_amira = {
    {
QT_MOC_LITERAL(0, 0, 13), // "gestion_amira"
QT_MOC_LITERAL(1, 14, 8), // "sendMail"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "mailSent"
QT_MOC_LITERAL(4, 33, 6), // "browse"
QT_MOC_LITERAL(5, 40, 27), // "on_tableau_sponsors_clicked"
QT_MOC_LITERAL(6, 68, 5), // "index"
QT_MOC_LITERAL(7, 74, 33), // "on_tableau_sponsors_doubleCli..."
QT_MOC_LITERAL(8, 108, 30), // "on_actionadd_sponsor_triggered"
QT_MOC_LITERAL(9, 139, 33), // "on_actiondelete_sponsor_trigg..."
QT_MOC_LITERAL(10, 173, 30), // "on_sel_col_currentIndexChanged"
QT_MOC_LITERAL(11, 204, 19), // "on_rech_textChanged"
QT_MOC_LITERAL(12, 224, 4), // "arg1"
QT_MOC_LITERAL(13, 229, 23), // "on_export_excel_clicked"
QT_MOC_LITERAL(14, 253, 24), // "on_actionstats_triggered"
QT_MOC_LITERAL(15, 278, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(16, 300, 23) // "on_pushButton_2_clicked"

    },
    "gestion_amira\0sendMail\0\0mailSent\0"
    "browse\0on_tableau_sponsors_clicked\0"
    "index\0on_tableau_sponsors_doubleClicked\0"
    "on_actionadd_sponsor_triggered\0"
    "on_actiondelete_sponsor_triggered\0"
    "on_sel_col_currentIndexChanged\0"
    "on_rech_textChanged\0arg1\0"
    "on_export_excel_clicked\0"
    "on_actionstats_triggered\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gestion_amira[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    1,   80,    2, 0x08 /* Private */,
       4,    0,   83,    2, 0x08 /* Private */,
       5,    1,   84,    2, 0x08 /* Private */,
       7,    1,   87,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    1,   92,    2, 0x08 /* Private */,
      11,    1,   95,    2, 0x08 /* Private */,
      13,    0,   98,    2, 0x08 /* Private */,
      14,    0,   99,    2, 0x08 /* Private */,
      15,    0,  100,    2, 0x08 /* Private */,
      16,    0,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void gestion_amira::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        gestion_amira *_t = static_cast<gestion_amira *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendMail(); break;
        case 1: _t->mailSent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->browse(); break;
        case 3: _t->on_tableau_sponsors_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->on_tableau_sponsors_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_actionadd_sponsor_triggered(); break;
        case 6: _t->on_actiondelete_sponsor_triggered(); break;
        case 7: _t->on_sel_col_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_rech_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_export_excel_clicked(); break;
        case 10: _t->on_actionstats_triggered(); break;
        case 11: _t->on_pushButton_clicked(); break;
        case 12: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject gestion_amira::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_gestion_amira.data,
      qt_meta_data_gestion_amira,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *gestion_amira::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gestion_amira::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_gestion_amira.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int gestion_amira::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
