#ifndef COMMMANAGER_H
#define COMMMANAGER_H

#include <QObject>
#include <QDebug>
#include <QMap>
#include <QQueue>
#include <QTimer>
#include <QTimerEvent>
#include <QVariant>
#include <QApplication>
#include <qextserialport.h>
#include <perfil.h>



#define CMD_INICIO_TOKEN '$' //!< Encabezado del mensaje.
#define CMD_FIN_TOKEN '#' //!< Conclusion del mensaje.


//DEBI: lo importante esta aca:
//Comando para que la placa me envie la temperatura del sensor
#define SEND_PEDIR_TEMP_SENSOR       "$000201#"

/*El tiempo transcurrido se supone que me lo manda automacticamente
 *El estado tambien me lo manda automacticamente
 */

#define RECV_TEMP_SENSOR             '1'
#define RECV_TEMP_SETEADA            '3'
#define RECV_TIEMPO_TRANSCURRIDO     '2'
#define RECV_TIEMPO_SETEADO          '4'
#define RECV_ESTADO_PROCESO          '5'

#define ESTADO_APAGADO      '0'
#define ESTADO_CALENTANDO   '1'
#define ESTADO_ENCENDIDO    '2'
#define ESTADO_ENFRIANDO    '3'


#define RS232_DEBUG 1



class commManager : public QObject
{
    Q_OBJECT
public:
    explicit commManager(QObject *parent = 0);
    commManager(QString sPort);

    static bool staticConnectedFlag;
    static bool getConnectedFlag();

    void closePort();
    bool sendData(QString data);
    bool isPortConnected();
    bool isOpen();
    void sendProfileData(perfil *data);
    bool waitForACK(int ms = 1200);
    enum cmdEnum{
        CMD_PEDIR_TEMP  = 1,
        CMD_SET_TEMP    = 2,
        CMD_PING        = 3,
        CMD_SET_TIEMPO  = 5,
        CMD_PONG        = 234,
        CMD_ACK         = 235

    }mCmds;

private slots:
    void dataArrival();
    void sendTimeOut();
private:
    void execCommands(char cmd);
    void sendProfileData();
    void dispatchAllCommands();
    char parseCommand();

    bool mbFlagTimeOut;

    QString formatCmd(QString data, cmdEnum e);
//    QMap <QString,QString> commandMap;
    QTimer *sendTimer;
    QString recStr;
    int recInt;
    QByteArray recBytes;
    bool ackRecivedOk;
    int reintentos;
    bool ackFail;
    bool waitingAck;
    bool mPortInitialized;
    QextSerialPort *m_port;
    perfil *profileToSend;
    QQueue<QString> commandQueue;  //Gracias a Dios existe esta cosa!!!
    void dispatchNextCmd();







signals:

public slots:

};


#include "mainwindow.h"
#endif // COMMMANAGER_H
