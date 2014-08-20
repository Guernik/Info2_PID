#ifndef CREATEPROFFORM_H
#define CREATEPROFFORM_H

#include <QWidget>
#include "mainwindow.h"
#include "commmanager.h"


class MainWindow;

namespace Ui {
    class createProfForm;
}

class createProfForm : public QWidget
{
    Q_OBJECT

public:
    explicit createProfForm(QWidget *parent = 0);
    ~createProfForm();
    void closePort();
    void enumerarPuertos();
    void updateConnectionLabels();
    MainWindow *mw;

    //Ui::createProfForm *ui;

private slots:
    void on_btn_connect_clicked();



    void on_btn_refresh_clicked();

private:
    Ui::createProfForm *ui;
};

#endif // CREATEPROFFORM_H
