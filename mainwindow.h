#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMap>
#include <qextserialport.h>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QProcess>
#include "createprofform.h"
#include "viewmanager.h"
#include "commmanager.h"



class createProfForm;

#define RECV_TEMP_SENSOR             '1'
#define RECV_TEMP_SETEADA            '3'
#define RECV_TIEMPO_TRANSCURRIDO     '2'
#define RECV_TIEMPO_SETEADO          '4'
#define RECV_ESTADO_PROCESO          '5'

#define ESTADO_APAGADO      '0'
#define ESTADO_CALENTANDO   '1'
#define ESTADO_ENCENDIDO    '2'
#define ESTADO_ENFRIANDO    '3'


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /***Miembros estaticos que interactuaran con la clase commManager***/
    static void setRealTemp(int temp);
    static void setTempSeteada(int temp);
    static void setTiempoTranscurrido(QString tiempo);
    static void setTiempoSeteado(QString tiempo);
    static void setEstadoProceso(int estado);

    //Miembro publico estatico, unico para todas las instancias de esta clase.
    static int iRealTemp;
    static int iTempSeteada;
    static QString strTiempoTranscurrido;
    static QString strTiempoSeteado;
    static int iEstadoProceso;
    static bool bRefreshStatus;
    static int iRefreshWhat;

    void EnumerarPuertos();
    void closePort();
    bool isPortConnected();
    void processDataArrival(QByteArray bArray);
    void updateConnectionLabels();
    void sendCommand(QString strCmd);
    //QextSerialPort *m_port;

    createProfForm *formConex;
    QByteArray m_datos_recibidos;

    commManager *managedComm;


public slots:
    void dataArrival();

    void on_btn_connect_clicked(QString sAux);


private slots:
    void updateScreenInfo();
    void sendTempTimeOut();

    void on_btn_refresh_clicked();

    void on_btnSendData_clicked();

    void on_txtSendData_returnPressed();

    void on_btnCleanLog_clicked();

    void on_btnRiego_clicked();

    void on_pshTest_clicked();

    void on_bntConexion_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_btnActivate_clicked();

    void on_table_item_changed();

    void on_btnNew_clicked();

    void on_btnDelete_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_btnDelete_2_clicked();

    void on_btnStartProcess_clicked();

private:
    Ui::MainWindow *ui;
    viewManager *managedView;
    createProfForm  *myNewCreateForm;
    //QMap<int,QString> activeProfileMap;
    QSqlDatabase db;
    QSqlTableModel *myTableModel;
    void updateTableView ();
    bool rowValidation(QTableView *table);
    QMap <int,QString> processStatus;
    //QextSerialPort *m_port;

};

#endif // MAINWINDOW_H



