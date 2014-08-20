#include "commmanager.h"

bool commManager::staticConnectedFlag;

commManager::commManager(QObject *parent) :
    QObject(parent)
{
    m_port = NULL;
    profileToSend = NULL;
}

commManager::commManager (QString sPort)
{
    m_port = NULL;
    profileToSend = NULL;
    mbFlagTimeOut = false;
    profileToSend = new perfil;
    m_port = new QextSerialPort(sPort, QextSerialPort::EventDriven);


    m_port->setBaudRate(BAUD9600);		//9600 baud
    m_port->setFlowControl(FLOW_OFF);           //Sin control de flujo
    m_port->setParity(PAR_NONE);		//Sin paridad
    m_port->setDataBits(DATA_8);		//8 bits de datos
    m_port->setStopBits(STOP_1);		//1 bit de stop

    if (m_port->open(QIODevice::ReadWrite) == true)	//Abrimos el puerto en modo lectura-escritura
    {
            QObject::connect(m_port, SIGNAL(readyRead()), this, SLOT(dataArrival()));
            mPortInitialized = true;
    }
    else
    {
        closePort();
    }

    sendTimer = new QTimer(this);
    connect(sendTimer,SIGNAL(timeout()),this,SLOT(sendTimeOut()));

}


void commManager::dataArrival()
{
    QByteArray tmpArray;
    static bool recvFlag;

    qDebug() << "dataArrival: Managed data arrival!";

    int cantBytes = m_port->bytesAvailable();
    tmpArray.resize(cantBytes);

    if (m_port != NULL)
    {
        //TODO: verificar que `read` saca lo leido del buffer.
        //(en caso de que no sea asi, leo todos los bytes y listo...)
        //Guardo en un array byte a byte lo que el puerto recivio.
        /*
        for (int i = 0; i < cantBytes; i++)
        {
            tmpArray[i] = m_port->read(1); //Leo 1 byte del puerto.
            qDebug() << "dataArrival: for-iteracion: " << i << " cantBytes: " << cantBytes << " current byte: " << tmpArray[i];
        }
        */

        m_port->read(tmpArray.data(),cantBytes);

        //******Si acabo de recibir el inicio de un comando.....*************
        if (tmpArray[0] == CMD_INICIO_TOKEN) //comienzo del comando
        {
            recStr.clear();
//            recStr.fromAscii(tmpArray.data());
            recStr = QString(tmpArray.constData());

            recvFlag = true; //Estoy reciviendo un comando valido.
            qDebug() << "dataArrival: Reciviendo token de inicio: " << recStr << " Raw: " << tmpArray.data();
            qDebug() << "recvFlag: " << recvFlag;

        }
        else
            //Puede que el comando llegue partido, o puede que llegue un error(comando sin el
            //token correspondiente)....
        {
            if (recvFlag)
            {
                recStr.append(QString(tmpArray.constData()));
                qDebug() << "dataArrival: Reciviendo comando partido: " << recStr;
            }
            //Este caso seria si me llega un comando sin un token.
            else
            {
                qDebug() << "dataArrival: error desconocido.";
            }
        }
        if (tmpArray[cantBytes-1] == CMD_FIN_TOKEN) //final del comando
        {
            recvFlag = false;
            qDebug() << "Recivido fin del comando: " << recStr;
            execCommands(parseCommand());
            //recStr.clear();
        }
    }
    else
    {
        qDebug() << "dataHannibal: Error Horrendo.";
    }    
}


void commManager::closePort()
{
    if (m_port != NULL)
    {
        m_port->close();
        delete m_port;
        m_port = NULL;
    }
}

bool commManager::sendData(QString data)
{
    QByteArray sendBytes = data.toAscii();

#if RS232_DEBUG
    qDebug() << "sendData: RS232OUTPUT: " << sendBytes.data();
#else
    if ((data != "") && (isPortConnected()))
    {
        m_port->write(sendBytes);
        qDebug() << "sendData: puerto conectado, escribiendo: sendBytes: " << sendBytes << ", data: " << data;
        return true;
    }
    else
    {
        qDebug() << "sendData: WARNING! estoy en el else! ";
        return false;
    }
#endif
}




bool commManager::isPortConnected()
{
    if (!mPortInitialized)
    {
        /**Puede ocurrir que esta clase haya sido inicializada pero el
        puerto serie aun no*/
        return false;
    }
    if (m_port != NULL)
    {

        if (m_port->isOpen())
        {
            qDebug() << "isPortConnected: isOpen->true";
            staticConnectedFlag = true;
            return TRUE;
        }
        else
        {
            qDebug() << "updateConLabels isOpen->false";
            staticConnectedFlag = false;
            return FALSE;
        }
    }
    else
    {
        //MUY poco probable: (si estoy adentro de este slot,
        //es porque ya inicialice el m_port).
        qDebug() << "ERROR CRITICO!!!!!!!! ESTO NO DEBERIA PASAR!!!";
    }

    return FALSE;
}

bool commManager::isOpen()
{
    if (m_port != NULL)
    {
        return m_port->isOpen();
    }
    return FALSE;
}

char commManager::parseCommand()
{
    //elimina el $
    recStr.remove(0,1);
    recStr.chop(1); //elimina el #
    qDebug() << "commManager: parseCommand: auxStr = " << recStr;

    return recStr.at(0).toAscii();
}

void commManager::execCommands(char cmd)
{
    switch (cmd)
    {
    case RECV_TEMP_SENSOR:
         recStr.remove(0,3); //"n000251" --> 251
         MainWindow::setRealTemp(recStr.toInt());
         break;
    case RECV_TEMP_SETEADA:
         recStr.remove(0,3);
         MainWindow::setTempSeteada(recStr.toInt());
         break;
    case RECV_TIEMPO_TRANSCURRIDO:
         recStr.remove(0,1);
         MainWindow::setTiempoTranscurrido(recStr);
         break;
    case RECV_TIEMPO_SETEADO:
         recStr.remove(0,1);
         MainWindow::setTiempoSeteado(recStr);
         break;
    case RECV_ESTADO_PROCESO:
         recStr.remove(0,6); //"n000001" --> 1
         MainWindow::setEstadoProceso(recStr.toInt());
         break;
    }
    recStr.clear();
}


bool commManager::waitForACK(int ms /*=1200*/)
{
    waitingAck = true;
    QTimer::singleShot(ms,this,SLOT(ackTimeOut()));
    qDebug() << "waitForACK: ms = " << ms;
    return TRUE;
}



void commManager::sendProfileData(perfil *data)
{
    int j;
    profileToSend = data;

    sendData(formatCmd(profileToSend->getTemp(),CMD_SET_TEMP));
    //sendTimer->start(1500);

    while (!mbFlagTimeOut)
    {
        QApplication::processEvents();
    }

    mbFlagTimeOut = false;
    sendData(formatCmd(profileToSend->getTimeString(),CMD_SET_TIEMPO));

//    commandQueue.enqueue(formatCmd(profileToSend->getTemp(),CMD_SET_TEMP));
//    commandQueue.enqueue(formatCmd(profileToSend->getTimeString(),CMD_SET_TIEMPO));
//    dispatchAllCommands();
}

void commManager::sendProfileData()
{


    sendData(formatCmd(profileToSend->getTemp(),CMD_SET_TEMP));
    sendData(formatCmd(profileToSend->getTimeString(),CMD_SET_TIEMPO));
}


//Metodo que agrega los caracteres especiales a los comandos, segun corresponda.
//(ver la tabla de excel).
QString commManager::formatCmd(QString data ,cmdEnum e)
{
    QString ret;
    ret.append(data);

    switch (e)
    {
        case CMD_PEDIR_TEMP:
            ret = "$000201#";
            break;
        case CMD_SET_TEMP:
            if(ret.size() == 2)
            {
                ret.insert(0,"$30000");
            }
            else if (ret.size() == 1)
            {
                ret.insert(0,"$300000");
            }
            else
            {
                ret.insert(0,"$3000");
            }
            ret.append('#');
            qDebug() << "formatCmd: CMD_SET_TEMP: " << ret;
            break;
        case CMD_PING:
            ret = "$000234#";
            break;
        case CMD_SET_TIEMPO:
            ret.insert(0,"$4");
            ret.append('#');
            qDebug() << "formatCmd: CMD_SET_TIEMPO: " << ret;
            break;
        case CMD_PONG:
            break;
        case CMD_ACK:
            break; //para que no salte el warning molesto...
    }
    return ret;

}

void commManager::dispatchAllCommands()
{
    QString saveSize = QString::number(commandQueue.size());
    while (commandQueue.size() != 0)
    {
        sendData(commandQueue.dequeue());
    }
    qDebug() << "dispatchAllCommands(): all (" + saveSize + ") CMDS dispatched! ";
}


void commManager::dispatchNextCmd()
{
    if (commandQueue.size() == 0)
    {
        qDebug() << "dispatchNextCmd: All cmds dispatched OK";
        return;
    }
    sendData(commandQueue.dequeue());
    waitForACK();

}

void commManager::sendTimeOut()
{
    mbFlagTimeOut = true;
    sendTimer->stop();
    qDebug() << "----sendTimeOut----";
}




