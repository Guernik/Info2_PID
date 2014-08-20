#include "dbmanager.h"
#include "viewmanager.h"
#include <QString>
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


class viewManager;

viewManager::viewManager(QObject *parent) :
    dbManager(parent)
{

}

viewManager::viewManager(QTableView *table)
{
    qDebug() << "Hola! Soy el contructor de viewManager(QTableView)!";
    innerTable = table;
    //Sseteo la clase que va a controlar las celdas de la tableView.
    //Esto es para poder validar la entrada del usuario.
    innerTable->setItemDelegate(&delegate);
    perfilActivo = NULL;
    perfilActivo = new perfil;


}



perfil* viewManager::activateProfile()
{
    QSqlQuery query(db);




    if (!query.exec("SELECT `id`,`nombre`,`temp`,`days`,`hours`,`mins` FROM `perfiles`"))
    {
        //Devuelvo el perfil activo por defecto (condicion de error).
        qDebug() << "viewManager::activateProfile: error con el select principal.";
        return perfilActivo;
    }
    if (innerTable->currentIndex().row() == -1)
    {
        //Devuelvo el perfil activo por defecto (condicion de error).
        return perfilActivo;
    }

    //de todas las filas, me quedo con la que el usuario haya seleccionado en la vista (la tabla).
    query.seek(innerTable->currentIndex().row());

    perfilActivo->setId(        query.value(0).toInt());
    perfilActivo->setNombre(    query.value(1).toString());
    perfilActivo->setTemp(      query.value(2).toString());
    perfilActivo->setDias(      query.value(3).toString());
    perfilActivo->setHoras(     query.value(4).toString());
    perfilActivo->setMins(      query.value(5).toString());

#ifdef DB_DEBUG
    qDebug() << "setId: "     << query.value(0).toInt();
    qDebug() << "setNombre: " << query.value(1).toString();
    qDebug() << "setTemp: "   << query.value(2).toString();
    qDebug() << "setDias: "   << query.value(3).toString();
    qDebug() << "setHoras: "  << query.value(4).toString();
    qDebug() << "setMins: "   << query.value(5).toString();
#endif
    return perfilActivo;
}


void viewManager::updateTableView()
{
   setUpModel("perfiles","id>0");
   myTableModel->setHeaderData(1,Qt::Horizontal,"Nombre");
   myTableModel->setHeaderData(2,Qt::Horizontal,"Temperatura [°C]");
   myTableModel->setHeaderData(3,Qt::Horizontal,"Dias");
   myTableModel->setHeaderData(4,Qt::Horizontal,"Horas");
   myTableModel->setHeaderData(5,Qt::Horizontal,"Minutos");


   //y finalmente vinculo el modelo a la QTableView
   innerTable->setModel(myTableModel);

   innerTable->show();
   //Oculto la columna de ID ya que no me interesa.
   //(el id es unico para cada perfil creada, no es importante para el usuario).
   innerTable->hideColumn(0);
}

bool viewManager::newRow()
{
    //Declaro una query asociada a la base de datos abierta (db).
    QSqlQuery query(db);
    //Ejecuto la sentencia correspondiente para crear una nueva fila.
    if (!query.exec("INSERT INTO `perfiles` (`nombre`,`temp`,`days`,`hours`,`mins`) VALUES (\"Nuevo Perfil\",25,0,2,0)") )
    {
        qDebug() << query.lastError();
        myLastError = query.lastError();
        return FALSE;
    }
    //Actualizo la vista para reflejar los cambios.
    updateTableView();


    return TRUE;
}

int viewManager::deleteRow()
{
    QSqlQuery query(db);
    QSqlQuery auxQuery(db);

    QString queryStr;
    //deleteRow es el row que vamos a borrar (tiene que estar seleccionado por el usuario).
    //El codigo cliente debe validar que no devuelva -1 (ninguna row seleccionada).
    int deleteRow = innerTable->currentIndex().row();
    QString deleteID;;


    //Hago un select para tener a disposicion todas las filas.
    if (!auxQuery.exec("SELECT `id`,`nombre`,`temp`,`days`,`hours`,`mins` FROM `perfiles`"))
    {
        qDebug() << query.lastError();
        myLastError = auxQuery.lastError();
        return -1;
    }

    //Selecciono la fila que se debe borrar.
    auxQuery.seek(deleteRow);
    //Tomo el ID unico de la planta que vamos a borrar (columna 0).
    deleteID = auxQuery.value(0).toString();

    qDebug() << "deleteRow: "  << deleteRow;
    qDebug() <<"deleteID: "    << deleteID;

    //Armo la sentencia SQL para borrar la fila correspondiente.
    queryStr = "DELETE FROM `perfiles` WHERE `id` = " ;
    queryStr += deleteID;
    qDebug() << "queryStr: " <<queryStr;

    //Seteo la sentencia.
    query.prepare(queryStr);

    //Ejecuto la sentencia SQL.
    if (!query.exec())
    {
        qDebug() << query.lastError();
        //Si devolvio error, lo guardo en la variable local para que el codigo cliente lo pueda ver.
        myLastError = query.lastError();
        return 0;
    }

    //Finalmente actualizo la vista (es decir la QTableView)
    updateTableView();
    return 1;


}






