#include "backend.h"
#include "signalviewengine.h"

BackEnd::BackEnd(QString port_name){


    serial.setPortName(port_name);
    serial.setBaudRate(QSerialPort::Baud115200);

    if(!serial.open(QIODevice::ReadOnly)){
        qDebug() << serial.errorString();
    }

    //QObject::connect(&serial, &QSerialPort::readyRead, SerialRead);

    SignalViewEngine *engine_temp = new SignalViewEngine(this, ENGINE_TEMP);
    SignalViewEngine *oil_temp = new SignalViewEngine(this, OIL_TEMP);
    SignalViewEngine *battery_status = new SignalViewEngine(this, BATTERY_STATUS);
    SignalViewEngine *serial_status = new SignalViewEngine(this, SERIAL_STATUS);

    engine_temp->error();
    //battery_status->waring();
    //oil_temp->waring();
    serial_status->error();

    Packet test;
    test.current_speed = 32.1122;
    test.battery_charge = 42.1222;
    test.total_distance = 33.1;

    updateDisplay(test);


    lap_engine.NewLap();

}


void BackEnd::updateDisplay(Packet value){
    setSpeed(QString::number(value.current_speed, 'f', 1));
    setTotal_distance(QString(QString::number(value.total_distance, 'f', 2) + "km"));
    setBattery_charge(QString(QString::number(value.battery_charge, 'f', 2) + "V"));
}

void BackEnd::SwitchMenuButton(){

}

void BackEnd::LapTrigger(){
    //lap_engine.NewLap();
}


void BackEnd::SerialRead(){
    qDebug() << "New data available: " << serial.bytesAvailable();
    QByteArray datas = serial.readAll();
    qDebug() << datas;
}
