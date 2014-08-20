#ifndef PERFIL_H
#define PERFIL_H
#include <QString>
//#include "viewmanager.h"

class perfil
{
public:
    perfil();
    //set
    void setId(int num);
    void setNombre(QString nombre);
    void setTemp(QString temp);
    void setDias(QString dias);
    void setHoras(QString horas);
    void setMins(QString mins);

    //get
    QString getTimeString();
    int getId();
    QString getNombre();
    QString getTemp();
    QString getDias();
    QString getHoras();
    QString getMins();
//    friend viewManager::activateProfile();

private:
    int mSid;
    QString mNombre;
    QString mTemp;
    QString mDias;
    QString mHoras;
    QString mMins;

};

#endif // PERFIL_H
