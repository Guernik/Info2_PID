#include "dbmanager.h"
/*LEEME: esta clase maneja la parte de bajo nivel de la base de datos.

Constructores:
    dbManager: setea el directorio de trabajo, y abre la base de datos.
Miembros publicos:
    setUpModel: setea el modelo que va a manejar los cambios en la base
                de datos, (ver MVC, modelo-vista-controlador para mas info)
    deleteDb: borra de manera definitiva la DB

*/

dbManager::dbManager(QObject *parent) : QObject(parent)
{
}

dbManager::dbManager()
{
    qDebug() << "Hola! Soy el contructor de dbManager()!";
    //Seteo el directorio de trabajo al home del usuario (en windows, C:\users\<usuario>
    QDir::setCurrent(QDir::homePath());
    //Creo la coneccion a la base de datos, con el driver de SQLITE3.
    db = QSqlDatabase::addDatabase("QSQLITE","managedDbConnection");
    //Seteo el nombre de la base de datos. (Ya que estamos en SQLITE sera el nombre del archivo)
    db.setDatabaseName("my.db.sqlite");
    //Abrimos la db (aha!)
    db.open();

    /**El archivo de la db se crea en el paso anterior, pero aun debemos crear la tabla.*/
    QSqlQuery query(db);
    QStringList tableList(db.tables(QSql::Tables));
    if (tableList.size() == 0)
    {
        query.exec("CREATE TABLE perfiles (id integer primary key autoincrement, nombre char, temp integer, days integer, hours integer, mins integer)");
    }

}



void dbManager::setUpModel(QString tableName, QString sql)
{
    myTableModel = new QSqlTableModel(this,db);
    myTableModel->setTable(tableName);

    //Seteo la sentencia SQL a ejecutar.
    myTableModel->setFilter(sql);
    //Ejecuto la sentencia anterior.
    myTableModel->select();
    //El modelo se actualizara ni bien el usuario modifique una celda.
    myTableModel->setEditStrategy(QSqlTableModel::OnFieldChange);
}



dbManager::~dbManager()
{
    db.close();
}


bool dbManager::deleteDb()
{
    //Close db
    db.close();
    //Borra irremediablemente la base de datos.
    return QFile::remove("my.db.sqlite");
}


QSqlError dbManager::lastError()
{
    //Devuelvo el ultimo error que haya ocurrido.
    //(Se puede consultar con QSqlError::Text())
    return myLastError;
}










