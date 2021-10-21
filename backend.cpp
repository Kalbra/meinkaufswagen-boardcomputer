#include "backend.h"


BackEnd::BackEnd(QMLBridge *qml_bridge, QString port_name) : qml_bridge(qml_bridge){
    serial_engine = new SerialEngine(qml_bridge, port_name);
    serial_engine->moveToThread(&serialThread);
    serialThread.start();

    //QObject::connect(&serial, &QSerialPort::readyRead, SerialRead);

    SignalViewEngine *engine_temp = new SignalViewEngine(qml_bridge, ENGINE_TEMP);
    SignalViewEngine *oil_temp = new SignalViewEngine(qml_bridge, OIL_TEMP);
    SignalViewEngine *battery_status = new SignalViewEngine(qml_bridge, BATTERY_STATUS);
    SignalViewEngine *serial_status = new SignalViewEngine(qml_bridge, SERIAL_STATUS);

    engine_temp->error();
    //battery_status->waring();
    //oil_temp->waring();
    serial_status->error();

    Packet test;
    test.current_speed = 32.1122;
    test.battery_charge = 42.1222;
    test.total_distance = 33.1;

    updateDisplay(test);
}


void BackEnd::updateDisplay(Packet value){
    qml_bridge->setSpeed(QString::number(value.current_speed, 'f', 1));
    qml_bridge->setTotal_distance(QString(QString::number(value.total_distance, 'f', 2) + "km"));
    qml_bridge->setBattery_charge(QString(QString::number(value.battery_charge, 'f', 2) + "V"));
}

void BackEnd::SwitchMenuButton(){

}

void BackEnd::LapTrigger(){
    lap_engine->NewLap();
}

void BackEnd::Reset(){
    lap_engine->reset();
    serial_engine->reset();
}
