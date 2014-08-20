#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H

/*LEEME: esta clase, heredada de dbManager, se encarga de la parte de de "alto nivel"
         del manejo de la DB.
Constructor: setea el delegate que va a manejar la validacion de los campos.
             (Para mas info buscar en la documentacion del QT, "delegate").
Miembros publicos:
            updateTableView: refresca la tabla  para reflejar los cambios que se hayan hecho
                             en la DB.
            newRow: crea una nueva fila en la DB, es decir, un nuevo perfil para una planta.
            deleteRow: borra la fila en la que el usuario haya hecho click.


*/

#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QTableView>
#include <QSqlQuery>
#include <QDebug>
#include <QFile>
#include <QDir>
#include "delegate.h"
#include "dbmanager.h"
#include "perfil.h"



class viewManager : public dbManager
{
    Q_OBJECT
public:
    //Constructores
    explicit viewManager(QObject *parent = 0);
    viewManager (QTableView *table);
    //Delegate del tableView
    lineEditDelegate delegate;
    //Refresca la tabla
    void updateTableView();
    //Borra una fila (en este caso seria un perfil de una planta)
    int deleteRow();
    //Agrega una nueva fila.
    bool newRow();
    //struct que contiene los datos del perfil activo.
    perfil *perfilActivo;
    //Setea el perfil activo a la fila que el usuario tenga seleccionada.
    perfil *activateProfile();

private:
    //Referencia a la QTableView mostrada en el formulario
    QTableView *innerTable;

    struct datosPerfil *mDatosPerfil;



signals:

public slots:

};

#endif // VIEWMANAGER_H
