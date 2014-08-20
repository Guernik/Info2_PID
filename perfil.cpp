#include "perfil.h"

perfil::perfil()
{
    //cargo la estructura con valores de error por defecto.
    mSid=-1;
    mNombre="error";
    mTemp="00";
    mDias="00";
    mHoras="00";
    mMins="00";
}

void perfil::setId(int num)
{
    mSid = num;
}

void perfil::setNombre(QString nombre)
{
    mNombre = nombre;
}

void perfil::setTemp(QString temp)
{
    mTemp = temp;
}

void perfil::setDias(QString dias)
{
    mDias = dias;
    //Si el usuario ingresó "n", lo convierto a "0n" (necesario para armar el comando del puerto serie).
    //Nota: la validacion se hace en delegate.cpp
    if (mDias.size() == 1)
    {
        mDias.insert(0,"0");
    }



}

void perfil::setHoras(QString horas)
{
    mHoras = horas;
    //Si el usuario ingresó "n", lo convierto a "0n" (necesario para armar el comando del puerto serie).
    //Nota: la validacion se hace en delegate.cpp
    if (mHoras.size() == 1)
    {
        mHoras.insert(0,"0");
    }

}

void perfil::setMins(QString mins)
{
    mMins = mins;
    //Si el usuario ingresó "n", lo convierto a "0n" (necesario para armar el comando del puerto serie).
    //Nota: la validacion se hace en delegate.cpp
    if (mMins.size() == 1)
    {
        mMins.insert(0,"0");
    }
}

/*********************************************/
int perfil::getId()
{
    return mSid;
}

QString perfil::getNombre()
{
    return mNombre;
}

QString perfil::getTemp()
{
    return mTemp;
}

QString perfil::getDias()
{
    return mDias;
}

QString perfil::getHoras()
{
    return mHoras;
}

QString perfil::getMins()
{
    return mMins;
}

QString perfil::getTimeString()
{
    QString ret;
    ret.append(mDias);
    ret.append(mHoras);
    ret.append(mMins);
    return ret;
}




