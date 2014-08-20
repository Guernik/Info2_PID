#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qextserialenumerator.h"
#include "qextserialport.h"
#include "qextserialport_global.h"
#include "qwineventnotifier_p.h"
#include "dbmanager.h"
#include "viewmanager.h"
#include "perfil.h"
#include "delegate.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QTimer>





bool bManualModeEnabled = false;
int gRecvRealTemp;
QextSerialPort *m_port;
lineEditDelegate delegate;

/***Declaro los miembros estáticos, de otro modo no los puedo usar*/
bool MainWindow::bRefreshStatus;
int  MainWindow::iRealTemp;
int  MainWindow::iTempSeteada;
int  MainWindow::iEstadoProceso;
QString MainWindow::strTiempoSeteado;
QString MainWindow::strTiempoTranscurrido;
int MainWindow::iRefreshWhat;

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->groupBox_3->hide();




    QDir::setCurrent(QDir::homePath());
    db = QSqlDatabase::addDatabase("QSQLITE","myConnection");
    db.setDatabaseName("my.db.sqlite");
    db.open();
    qDebug() << "db creada (supuestamente), " << db.isOpen() << ". lastError: " << db.lastError().text();


    managedView = new viewManager(ui->tableView);
    managedView->updateTableView();

    if (managedComm != NULL && managedComm->isOpen())
    {
        managedComm->closePort();
        delete managedComm;
        managedComm = NULL;
    }

    ui->lblProfHelp->setVisible(FALSE);



    QTimer *refreshTimer = new QTimer(this);
    connect(refreshTimer,SIGNAL(timeout()),this,SLOT(updateScreenInfo()));
    refreshTimer->start(5000);

    QTimer *sendTempTimer = new QTimer(this);
    connect(sendTempTimer,SIGNAL(timeout()),this,SLOT(sendTempTimeOut()));
    sendTempTimer->start(1000);

    processStatus[ESTADO_ENFRIANDO]  = "Enfriando...";
    processStatus[ESTADO_CALENTANDO] = "Calentando...";
    processStatus[ESTADO_ENCENDIDO] = "Encendido";
    processStatus[ESTADO_APAGADO] = "Apagado.";
}

void MainWindow::updateScreenInfo()
{
    QString diasTranscurridos;
    QString horasTranscurridas;
    QString minutosTranscurridos;

    QString diasSeteados;
    QString horasSeteadas;
    QString minutosSeteados;

    if (iRefreshWhat != 0)
    {


        diasTranscurridos    =  strTiempoTranscurrido.mid(0,2);
        horasTranscurridas   =  strTiempoTranscurrido.mid(2,2);
        minutosTranscurridos =  strTiempoTranscurrido.mid(4,2);

        diasSeteados    = strTiempoSeteado.mid(0,2);
        horasSeteadas   = strTiempoSeteado.mid(2,2);
        minutosSeteados = strTiempoSeteado.mid(4,2);

        //Armo los strings para mostrar en los labels.
        diasTranscurridos.append(" dias, " + horasTranscurridas + " horas, " + minutosTranscurridos + " minutos.");
        diasSeteados.append(" dias, " + horasSeteadas + " horas, " + minutosSeteados + " minutos.");

        switch (iRefreshWhat)
        {
        case RECV_TEMP_SENSOR:
            ui->lblTemp->setText(QString::number(iRealTemp));
            break;
        case RECV_TEMP_SETEADA:
            ui->lblProfTemp->setText(QString::number(iTempSeteada));
            break;
        case RECV_TIEMPO_TRANSCURRIDO:
            ui->lblTranscurrido->setText(diasTranscurridos);
            break;
        case RECV_TIEMPO_SETEADO:
            ui->lblTiempoTotal->setText(diasSeteados);
            break;
        case RECV_ESTADO_PROCESO:
            ui->lblEstadoProceso->setText(processStatus[iEstadoProceso]); //processStatus es un QMap
            qDebug() << "RECV_ESTADO_PROCESO: " << iEstadoProceso;
            break;
        }
        iRefreshWhat = 0;

        qDebug() << "--------[TIMEOUT.... refrescando]--------";
    }
        qDebug() << "[TIMEOUT.... sin refresco]";
}

void MainWindow::sendTempTimeOut()
{
   static unsigned char pedirTiempo = 0;

   if(iEstadoProceso == ESTADO_ENCENDIDO)
   {
       if(pedirTiempo == 60)
       {
           managedComm->sendData("$000202#");
           pedirTiempo = 0;
       }
       else
       {
            managedComm->sendData("$000201#");
            pedirTiempo++;
       }
       //qDebug() << "---sendTempTimeOut---";
    }

}


MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_btnRiego_clicked()
{
//      managedComm->sendData();
}




void MainWindow::on_btn_connect_clicked(QString aux)
{
    managedComm = new commManager(aux);
    updateConnectionLabels();
}

void MainWindow::on_btn_refresh_clicked()
{
    //EnumerarPuertos();
}


void MainWindow::on_btnSendData_clicked()
{
    if (managedComm != NULL)
    {
        managedComm->sendData(ui->txtSendData->text());
    }
}



void MainWindow::on_txtSendData_returnPressed()
{
    on_btnSendData_clicked();
}





void MainWindow::on_btnCleanLog_clicked()
{
    ui->txtHistorial->clear();
}

void MainWindow::on_pshTest_clicked()
{

    ui->txtHistorial->append(QDir::currentPath());
    ui->txtHistorial->append("---");
    ui->txtHistorial->append(QDir::homePath());
    ui->txtHistorial->append("---");
    QDir::setCurrent(QDir::homePath());
}

void MainWindow::on_bntConexion_clicked()
{
    if (!formConex->isVisible())
    {
        formConex->show();
    }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if (index == 1)
    {
        managedView->updateTableView();
    }
}



void MainWindow::on_table_item_changed()
{
    qDebug() << "table item change";

}

void MainWindow::on_btnActivate_clicked()
{
    QString strTemp;
    QString strTimer;

    //Valido que el usuario haya realmente seleccionado alguna fila.
    if (!rowValidation(ui->tableView))
    {
        return;
    }

#ifndef RS232_DEBUG
    if (managedComm == NULL)
    {
        ui->lblProfHelp->setText("<- ERROR: Primero configure la conexión.");
        ui->lblProfHelp->setVisible(TRUE);
        return;
    }

    if (!managedComm->isPortConnected())
    {
        ui->lblProfHelp->setText("<- ERROR: Primero configure la conexión.");
        ui->lblProfHelp->setVisible(TRUE);
        return;
    }
#else
    if (managedComm != NULL && managedComm->isOpen())
    {
        managedComm->closePort();
        delete managedComm;
        managedComm = NULL;
    }
    managedComm = new commManager();
#endif


    ui->lblActiveProfile_2->setText(managedView->activateProfile()->getNombre());
    ui->lblNombre->setText(managedView->perfilActivo->getNombre());

    strTemp = managedView->perfilActivo->getTemp();
    ui->lblProfTemp->setText(strTemp + " °C");

    QString strDias = managedView->perfilActivo->getDias();
    QString strHoras = managedView->perfilActivo->getHoras();
    QString strMinutos = managedView->perfilActivo->getMins();
    strTimer =strDias + " dias, " + strHoras + " horas, " +strMinutos + " minutos.";
    ui->lblProfTime->setText(strTimer);

    managedComm->sendProfileData(managedView->perfilActivo);
}

void MainWindow::on_btnNew_clicked()
{
    //Intento crear la nueva fila.
    if (!managedView->newRow())
    {
        //Si da error lo muestro en pantalla.
        QMessageBox::critical(this,"Error en la base de datos.",managedView->lastError().text());

    }

}



void MainWindow::on_btnDelete_clicked()
{    
    //Valido que el usuario haya realmente seleccionado alguna fila.
    if (!rowValidation(ui->tableView))
    {
        return;
    }
    //Si devolvio error, lo muestro en pantalla
    if (managedView->deleteRow())
    {
//        QMessageBox::critical(this,"Error en la base de datos.",managedView->lastError().text());
    }
}




void MainWindow::on_btnDelete_2_clicked()
{
    QStringList arguments;
    arguments << "/capture";
    QProcess::startDetached("WebCamImageSave.exe",arguments);
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
   ui->lblProfHelp->setVisible(FALSE);
}




bool MainWindow::rowValidation(QTableView *table)
{
    if (table->currentIndex().row() == -1)
    {
        ui->lblProfHelp->setVisible(TRUE);
        ui->lblProfHelp->setText("¡Primero seleccione un perfil de la lista!");
        return FALSE;
    }
    return TRUE;
}


void MainWindow::closePort()
{
        m_port->close();
        delete m_port;
        m_port = NULL;
}

bool MainWindow::isPortConnected()
{

    updateConnectionLabels();
    if (m_port->isOpen()) qDebug() << "updateConectionLabels: isOpen->true";
    else
        qDebug() << "updateConLabels isOpen->false";
    return (m_port && m_port->isOpen());
}

void MainWindow::sendCommand(QString strCmd)
{

    if( managedComm->isPortConnected())
    {
        QByteArray sendBytes = (strCmd).toAscii();
        m_port->write(sendBytes);
        qDebug("sendCommand: puerto conectado, escribiendo...");
    }
    else
    {
        ui->txtHistorial->append("<b><font color=red>Error: puerto no conectado!<\font><\b>");
        qDebug("sendCommand: puerto NO conectado.");
    }
}

/****************************************************************/
/*SLOT:dataArrival, recive los datos que llegan del puerto serie*/
/****************************************************************/
void MainWindow::dataArrival()
{
    QByteArray recBytes;
    int cantBytes = m_port->bytesAvailable();
    recBytes.resize(cantBytes);

    m_port->read(recBytes.data(),recBytes.size());
    processDataArrival(recBytes);
    qDebug() << "dataArrival, cantBytes:" << cantBytes << ". Data: " << recBytes;
}


void MainWindow::processDataArrival(QByteArray bArray)
{
    m_datos_recibidos += bArray;
    ui->txtLog->append(bArray);
}


void MainWindow::updateConnectionLabels()
{
    if (managedComm == NULL)
    {
        ui->lblComm->setText("INACTIVA");
        ui->lblComm->setStyleSheet("color: red");
        qDebug() << "form:main, NO conectado";
    }
    else if(managedComm->isOpen())
    {
        ui->lblComm->setText("ACTIVA");
        ui->lblComm->setStyleSheet("color: green");
        qDebug() << "form:main, conectado";
    }
}

void MainWindow::setRealTemp(int temp)
{
    iRealTemp = temp;
    iRefreshWhat = RECV_TEMP_SENSOR;

}

void MainWindow::setTempSeteada(int temp)
{
    iTempSeteada = temp;
    iRefreshWhat = RECV_TEMP_SETEADA;

}

void MainWindow::setTiempoTranscurrido(QString tiempo)
{
    strTiempoTranscurrido = tiempo;
    iRefreshWhat = RECV_TIEMPO_TRANSCURRIDO;

}

void MainWindow::setTiempoSeteado(QString tiempo)
{
    strTiempoSeteado = tiempo;
    iRefreshWhat = RECV_TIEMPO_SETEADO;

}

void MainWindow::setEstadoProceso(int estado)
{
    iEstadoProceso = estado;
    iRefreshWhat = RECV_ESTADO_PROCESO;
}




void MainWindow::on_btnStartProcess_clicked()
{
    ui->lblProfTemp->setVisible(false);
}
