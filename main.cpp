#include <QtGui/QApplication>
#include <qextserialport.h>
#include "mainwindow.h"
#include "createprofform.h"
#include <QObject>

//QextSerialPort *m_port;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    createProfForm z;
    z.mw = &w;
    w.formConex = &z;

    w.show();

    return a.exec();
}
