    #ifndef DBMANAGER_H
#define DBMANAGER_H

/*LEEME: esta clase maneja la parte de bajo nivel de la base de datos.

Constructores:
    dbManager: setea el directorio de trabajo, y abre la base de datos.
Miembros publicos:
    setUpModel: setea el modelo que va a manejar los cambios en la base
                de datos, (ver MVC, modelo-vista-controlador para mas info)
    deleteDb: borra de manera definitiva la DB

*/


#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDir>
#include <QTableView>
#include <QSqlTableModel>
#include <QDebug>
#include <QStringList>

#include "delegate.h"

#define DB_DEBUG


class dbManager : public QObject
{
    Q_OBJECT
public:
    explicit dbManager(QObject *parent);
    dbManager();
    ~dbManager();
    QSqlError lastError();
    bool deleteDb();


protected:
    void setUpModel(QString tableName, QString sql);
    QSqlTableModel *myTableModel;
    QSqlError myLastError; //ugh
    QSqlDatabase db;




signals:

public slots:

};

#endif // DBMANAGER_H
