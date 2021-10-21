#include "serialengine.h"

SerialEngine::SerialEngine(QString port_name){
    serial.setPortName(port_name);
    serial.setBaudRate(QSerialPort::Baud115200);

    if(!serial.open(QIODevice::ReadOnly)){
        qDebug() << serial.errorString();
    }

    connect(&serial, &QSerialPort::readyRead, this, &SerialEngine::dataEvaluate);
}

void SerialEngine::dataEvaluate(){
    QByteArray datas = serial.readAll();
    qDebug() << datas;
}

void SerialEngine::speed_trigger(){

}
