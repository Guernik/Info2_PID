#include "createprofform.h"
#include "ui_createprofform.h"
#include "mainwindow.h"

#include "qextserialenumerator.h"
#include "qextserialport.h"
#include "qextserialport_global.h"
#include "qwineventnotifier_p.h"
#include <QDebug>

class MainWindow;
extern QextSerialPort *m_port;

createProfForm::createProfForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createProfForm)
{
    ui->setupUi(this);
    ui->lbl_estado->setText("<b>INACTIVA<\b>");
    ui->lbl_estado->setStyleSheet("color: red");


}

createProfForm::~createProfForm()
{
    delete ui;
}

void createProfForm::on_btn_connect_clicked()
{
    //Obtenemos el nombre del puerto
    QString sPort;
    int i = ui->combo_puertos->currentIndex();
    if (i != -1 && ui->combo_puertos->itemText(i) == ui->combo_puertos->currentText())
            sPort = ui->combo_puertos->itemData(i).toString();
    else
            sPort = ui->combo_puertos->currentText();

    mw->on_btn_connect_clicked(sPort);
    updateConnectionLabels();

}


void createProfForm::enumerarPuertos()
{
        ui->combo_puertos->clear();

        QList<QextPortInfo> ports = QextSerialEnumerator::getPorts();

        for (int i = 0; i < ports.size(); i++)
        {

        #ifdef Q_OS_WIN
                ui->combo_puertos->addItem(ports.at(i).friendName, ports.at(i).portName);
        #elif (defined Q_OS_UNIX)
                ui->combo_puertos->addItem(ports.at(i).friendName, ports.at(i).physName);
        #endif

                /*qDebug() << "port name:" << ports.at(i).portName;
                qDebug() << "friendly name:" << ports.at(i).friendName;
                qDebug() << "physical name:" << ports.at(i).physName;
                qDebug() << "enumerator name:" << ports.at(i).enumName;
                qDebug() << "vendor ID:" << QString::number(ports.at(i).vendorID, 16);
                qDebug() << "product ID:" << QString::number(ports.at(i).productID, 16);*/
        }
}



void createProfForm::updateConnectionLabels()
{
    if (!commManager::staticConnectedFlag)
    {
        ui->lbl_estado->setText("<b>INACTIVA<\b>");
        ui->lbl_estado->setStyleSheet("color: red");

    }
    else
    {
        ui->lbl_estado->setText("ACTIVA");
        ui->lbl_estado->setStyleSheet("color: green");
    }
    qDebug() << commManager::staticConnectedFlag;
}

void createProfForm::on_btn_refresh_clicked()
{
    enumerarPuertos();
}
