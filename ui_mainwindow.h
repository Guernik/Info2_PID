/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed 15. Feb 18:14:13 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableView>
#include <QtGui/QTextBrowser>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QLabel *lbl_active_2;
    QLabel *lbl_active_3;
    QLabel *lbl_active_4;
    QLabel *lblTemp;
    QLabel *lblTranscurrido;
    QLabel *lblTiempoTotal;
    QLabel *lblEstadoProceso;
    QLabel *lbl_active_8;
    QGroupBox *groupBox_4;
    QLabel *lbl_active_5;
    QLabel *lbl_active_6;
    QLabel *lbl_active_7;
    QLabel *lblNombre;
    QLabel *lblProfTemp;
    QLabel *lblProfTime;
    QWidget *tab_3;
    QGroupBox *groupBox_11;
    QLabel *lbl_active;
    QLabel *lblActiveProfile_2;
    QTableView *tableView;
    QPushButton *btnCleanLog;
    QLabel *label_3;
    QLabel *lblComm;
    QGroupBox *groupBox_12;
    QPushButton *btnActivate;
    QPushButton *btnNew;
    QPushButton *btnDelete;
    QLabel *lblProfHelp;
    QPushButton *bntConexion;
    QWidget *tab_2;
    QPushButton *btnSendData;
    QGroupBox *groupBox_2;
    QTextBrowser *txtLog;
    QLineEdit *txtSendData;
    QGroupBox *groupBox_3;
    QTextEdit *txtHistorial;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(579, 515);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 10, 561, 446));
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabsClosable(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 20, 411, 191));
        lbl_active_2 = new QLabel(groupBox);
        lbl_active_2->setObjectName(QString::fromUtf8("lbl_active_2"));
        lbl_active_2->setGeometry(QRect(30, 30, 121, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Black"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        lbl_active_2->setFont(font);
        lbl_active_3 = new QLabel(groupBox);
        lbl_active_3->setObjectName(QString::fromUtf8("lbl_active_3"));
        lbl_active_3->setGeometry(QRect(30, 66, 171, 20));
        lbl_active_3->setFont(font);
        lbl_active_4 = new QLabel(groupBox);
        lbl_active_4->setObjectName(QString::fromUtf8("lbl_active_4"));
        lbl_active_4->setGeometry(QRect(30, 110, 151, 16));
        lbl_active_4->setFont(font);
        lblTemp = new QLabel(groupBox);
        lblTemp->setObjectName(QString::fromUtf8("lblTemp"));
        lblTemp->setGeometry(QRect(200, 30, 70, 16));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        lblTemp->setPalette(palette);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        lblTemp->setFont(font1);
        lblTemp->setMargin(0);
        lblTranscurrido = new QLabel(groupBox);
        lblTranscurrido->setObjectName(QString::fromUtf8("lblTranscurrido"));
        lblTranscurrido->setGeometry(QRect(200, 70, 200, 16));
        QPalette palette1;
        QBrush brush2(QColor(0, 213, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        lblTranscurrido->setPalette(palette1);
        lblTranscurrido->setFont(font1);
        lblTranscurrido->setMargin(0);
        lblTiempoTotal = new QLabel(groupBox);
        lblTiempoTotal->setObjectName(QString::fromUtf8("lblTiempoTotal"));
        lblTiempoTotal->setGeometry(QRect(200, 110, 200, 16));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        lblTiempoTotal->setPalette(palette2);
        lblTiempoTotal->setFont(font1);
        lblTiempoTotal->setMargin(0);
        lblEstadoProceso = new QLabel(groupBox);
        lblEstadoProceso->setObjectName(QString::fromUtf8("lblEstadoProceso"));
        lblEstadoProceso->setGeometry(QRect(200, 150, 200, 16));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        lblEstadoProceso->setPalette(palette3);
        lblEstadoProceso->setFont(font1);
        lblEstadoProceso->setMargin(0);
        lbl_active_8 = new QLabel(groupBox);
        lbl_active_8->setObjectName(QString::fromUtf8("lbl_active_8"));
        lbl_active_8->setGeometry(QRect(30, 150, 151, 16));
        lbl_active_8->setFont(font);
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(30, 230, 411, 191));
        lbl_active_5 = new QLabel(groupBox_4);
        lbl_active_5->setObjectName(QString::fromUtf8("lbl_active_5"));
        lbl_active_5->setGeometry(QRect(30, 30, 121, 16));
        lbl_active_5->setFont(font);
        lbl_active_6 = new QLabel(groupBox_4);
        lbl_active_6->setObjectName(QString::fromUtf8("lbl_active_6"));
        lbl_active_6->setGeometry(QRect(30, 70, 121, 16));
        lbl_active_6->setFont(font);
        lbl_active_7 = new QLabel(groupBox_4);
        lbl_active_7->setObjectName(QString::fromUtf8("lbl_active_7"));
        lbl_active_7->setGeometry(QRect(30, 110, 121, 16));
        lbl_active_7->setFont(font);
        lblNombre = new QLabel(groupBox_4);
        lblNombre->setObjectName(QString::fromUtf8("lblNombre"));
        lblNombre->setGeometry(QRect(197, 30, 70, 16));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        lblNombre->setPalette(palette4);
        lblNombre->setFont(font1);
        lblNombre->setMargin(0);
        lblProfTemp = new QLabel(groupBox_4);
        lblProfTemp->setObjectName(QString::fromUtf8("lblProfTemp"));
        lblProfTemp->setGeometry(QRect(197, 70, 200, 16));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        lblProfTemp->setPalette(palette5);
        lblProfTemp->setFont(font1);
        lblProfTemp->setMargin(0);
        lblProfTime = new QLabel(groupBox_4);
        lblProfTime->setObjectName(QString::fromUtf8("lblProfTime"));
        lblProfTime->setGeometry(QRect(197, 110, 200, 16));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        lblProfTime->setPalette(palette6);
        lblProfTime->setFont(font1);
        lblProfTime->setMargin(0);
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        groupBox_11 = new QGroupBox(tab_3);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        groupBox_11->setGeometry(QRect(0, 10, 531, 331));
        lbl_active = new QLabel(groupBox_11);
        lbl_active->setObjectName(QString::fromUtf8("lbl_active"));
        lbl_active->setGeometry(QRect(15, 10, 121, 16));
        lbl_active->setFont(font);
        lblActiveProfile_2 = new QLabel(groupBox_11);
        lblActiveProfile_2->setObjectName(QString::fromUtf8("lblActiveProfile_2"));
        lblActiveProfile_2->setGeometry(QRect(155, 10, 201, 16));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        lblActiveProfile_2->setPalette(palette7);
        lblActiveProfile_2->setFont(font1);
        lblActiveProfile_2->setMargin(0);
        tableView = new QTableView(groupBox_11);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 30, 511, 291));
        tableView->setGridStyle(Qt::DashLine);
        btnCleanLog = new QPushButton(groupBox_11);
        btnCleanLog->setObjectName(QString::fromUtf8("btnCleanLog"));
        btnCleanLog->setGeometry(QRect(30, 610, 231, 23));
        QFont font2;
        font2.setPointSize(10);
        btnCleanLog->setFont(font2);
        label_3 = new QLabel(groupBox_11);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(280, 10, 121, 16));
        label_3->setFont(font);
        lblComm = new QLabel(groupBox_11);
        lblComm->setObjectName(QString::fromUtf8("lblComm"));
        lblComm->setGeometry(QRect(420, 10, 111, 16));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        lblComm->setPalette(palette8);
        lblComm->setFont(font1);
        lblComm->setMargin(0);
        groupBox_12 = new QGroupBox(tab_3);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        groupBox_12->setGeometry(QRect(10, 350, 521, 61));
        btnActivate = new QPushButton(groupBox_12);
        btnActivate->setObjectName(QString::fromUtf8("btnActivate"));
        btnActivate->setGeometry(QRect(10, 10, 101, 20));
        QFont font3;
        font3.setBold(true);
        font3.setWeight(75);
        btnActivate->setFont(font3);
        btnNew = new QPushButton(groupBox_12);
        btnNew->setObjectName(QString::fromUtf8("btnNew"));
        btnNew->setGeometry(QRect(10, 30, 101, 20));
        btnNew->setFont(font3);
        btnDelete = new QPushButton(groupBox_12);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
        btnDelete->setGeometry(QRect(120, 10, 101, 20));
        btnDelete->setFont(font3);
        lblProfHelp = new QLabel(groupBox_12);
        lblProfHelp->setObjectName(QString::fromUtf8("lblProfHelp"));
        lblProfHelp->setEnabled(true);
        lblProfHelp->setGeometry(QRect(230, 30, 251, 31));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        lblProfHelp->setPalette(palette9);
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        font4.setPointSize(9);
        font4.setBold(true);
        font4.setWeight(75);
        lblProfHelp->setFont(font4);
        bntConexion = new QPushButton(groupBox_12);
        bntConexion->setObjectName(QString::fromUtf8("bntConexion"));
        bntConexion->setGeometry(QRect(120, 30, 100, 20));
        bntConexion->setFont(font3);
        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        btnSendData = new QPushButton(tab_2);
        btnSendData->setObjectName(QString::fromUtf8("btnSendData"));
        btnSendData->setGeometry(QRect(160, 330, 75, 23));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 241, 311));
        txtLog = new QTextBrowser(groupBox_2);
        txtLog->setObjectName(QString::fromUtf8("txtLog"));
        txtLog->setGeometry(QRect(10, 20, 221, 281));
        txtSendData = new QLineEdit(tab_2);
        txtSendData->setObjectName(QString::fromUtf8("txtSendData"));
        txtSendData->setGeometry(QRect(30, 330, 113, 20));
        tabWidget->addTab(tab_2, QString());
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(560, 400, 521, 121));
        txtHistorial = new QTextEdit(groupBox_3);
        txtHistorial->setObjectName(QString::fromUtf8("txtHistorial"));
        txtHistorial->setGeometry(QRect(10, 20, 501, 91));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 579, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(txtLog, txtSendData);
        QWidget::setTabOrder(txtSendData, btnSendData);
        QWidget::setTabOrder(btnSendData, tabWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "INFORMACION", 0, QApplication::UnicodeUTF8));
        lbl_active_2->setText(QApplication::translate("MainWindow", "Temp. Actual:", 0, QApplication::UnicodeUTF8));
        lbl_active_3->setText(QApplication::translate("MainWindow", "Tiempo transcurrido:", 0, QApplication::UnicodeUTF8));
        lbl_active_4->setText(QApplication::translate("MainWindow", "Tiempo total:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        lblTemp->setStatusTip(QApplication::translate("MainWindow", "Muestra el estado de la conexion serie.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        lblTemp->setText(QApplication::translate("MainWindow", "INACTIVA", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        lblTranscurrido->setStatusTip(QApplication::translate("MainWindow", "Muestra el perfil activo.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        lblTranscurrido->setText(QApplication::translate("MainWindow", "0 dias, 0 horas, 0 minutos.", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        lblTiempoTotal->setStatusTip(QApplication::translate("MainWindow", "Muestra el perfil activo.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        lblTiempoTotal->setText(QApplication::translate("MainWindow", "0 dias, 0 horas, 0 minutos.", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        lblEstadoProceso->setStatusTip(QApplication::translate("MainWindow", "Muestra el perfil activo.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        lblEstadoProceso->setText(QApplication::translate("MainWindow", "Apagado.", 0, QApplication::UnicodeUTF8));
        lbl_active_8->setText(QApplication::translate("MainWindow", "Estado:", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "PERFIL SELECCIONADO", 0, QApplication::UnicodeUTF8));
        lbl_active_5->setText(QApplication::translate("MainWindow", "Nombre:", 0, QApplication::UnicodeUTF8));
        lbl_active_6->setText(QApplication::translate("MainWindow", "Temperatura:", 0, QApplication::UnicodeUTF8));
        lbl_active_7->setText(QApplication::translate("MainWindow", "Tiempo:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        lblNombre->setStatusTip(QApplication::translate("MainWindow", "Muestra el estado de la conexion serie.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        lblNombre->setText(QApplication::translate("MainWindow", "- - - - - - - - - - - - -", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        lblProfTemp->setStatusTip(QApplication::translate("MainWindow", "Muestra el perfil activo.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        lblProfTemp->setText(QApplication::translate("MainWindow", "- - - - - C", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        lblProfTime->setStatusTip(QApplication::translate("MainWindow", "Muestra el perfil activo.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        lblProfTime->setText(QApplication::translate("MainWindow", "0 dias, 0 horas, o minutos.", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Info.", 0, QApplication::UnicodeUTF8));
        groupBox_11->setTitle(QString());
        lbl_active->setText(QApplication::translate("MainWindow", "PERFIL ACTIVO:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        lblActiveProfile_2->setStatusTip(QApplication::translate("MainWindow", "Muestra el perfil activo.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        lblActiveProfile_2->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        btnCleanLog->setStatusTip(QApplication::translate("MainWindow", "Limpia el historial de comandos.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        btnCleanLog->setText(QApplication::translate("MainWindow", "Limpiar", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Conexion:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        lblComm->setStatusTip(QApplication::translate("MainWindow", "Muestra el estado de la conexion serie.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        lblComm->setText(QApplication::translate("MainWindow", "INACTIVA", 0, QApplication::UnicodeUTF8));
        groupBox_12->setTitle(QString());
        btnActivate->setText(QApplication::translate("MainWindow", "ACTIVAR PERFIL", 0, QApplication::UnicodeUTF8));
        btnNew->setText(QApplication::translate("MainWindow", "Nuevo Perfil", 0, QApplication::UnicodeUTF8));
        btnDelete->setText(QApplication::translate("MainWindow", "Borrar Perfil", 0, QApplication::UnicodeUTF8));
        lblProfHelp->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        bntConexion->setStatusTip(QApplication::translate("MainWindow", "Abre la ventana de conexion.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        bntConexion->setText(QApplication::translate("MainWindow", "Conexion", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Admin. de Perfiles", 0, QApplication::UnicodeUTF8));
        btnSendData->setText(QApplication::translate("MainWindow", "Enviar", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Datos Recibidos", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Historial", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        txtHistorial->setStatusTip(QApplication::translate("MainWindow", "Historial de comandos y mensajes de la aplicaci\303\263n.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
