/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed 15. Feb 20:47:17 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      31,   26,   11,   11, 0x0a,
      63,   11,   11,   11, 0x08,
      82,   11,   11,   11, 0x08,
     100,   11,   11,   11, 0x08,
     125,   11,   11,   11, 0x08,
     150,   11,   11,   11, 0x08,
     181,   11,   11,   11, 0x08,
     206,   11,   11,   11, 0x08,
     228,   11,   11,   11, 0x08,
     249,   11,   11,   11, 0x08,
     280,  274,   11,   11, 0x08,
     313,   11,   11,   11, 0x08,
     338,   11,   11,   11, 0x08,
     362,   11,   11,   11, 0x08,
     382,   11,   11,   11, 0x08,
     405,  274,   11,   11, 0x08,
     439,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0dataArrival()\0sAux\0"
    "on_btn_connect_clicked(QString)\0"
    "updateScreenInfo()\0sendTempTimeOut()\0"
    "on_btn_refresh_clicked()\0"
    "on_btnSendData_clicked()\0"
    "on_txtSendData_returnPressed()\0"
    "on_btnCleanLog_clicked()\0on_btnRiego_clicked()\0"
    "on_pshTest_clicked()\0on_bntConexion_clicked()\0"
    "index\0on_tabWidget_currentChanged(int)\0"
    "on_btnActivate_clicked()\0"
    "on_table_item_changed()\0on_btnNew_clicked()\0"
    "on_btnDelete_clicked()\0"
    "on_tableView_clicked(QModelIndex)\0"
    "on_btnDelete_2_clicked()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: dataArrival(); break;
        case 1: on_btn_connect_clicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: updateScreenInfo(); break;
        case 3: sendTempTimeOut(); break;
        case 4: on_btn_refresh_clicked(); break;
        case 5: on_btnSendData_clicked(); break;
        case 6: on_txtSendData_returnPressed(); break;
        case 7: on_btnCleanLog_clicked(); break;
        case 8: on_btnRiego_clicked(); break;
        case 9: on_pshTest_clicked(); break;
        case 10: on_bntConexion_clicked(); break;
        case 11: on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: on_btnActivate_clicked(); break;
        case 13: on_table_item_changed(); break;
        case 14: on_btnNew_clicked(); break;
        case 15: on_btnDelete_clicked(); break;
        case 16: on_tableView_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 17: on_btnDelete_2_clicked(); break;
        default: ;
        }
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
