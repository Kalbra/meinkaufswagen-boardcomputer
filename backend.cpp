#include "backend.h"


BackEnd::BackEnd(QMLBridge *qml_bridge, QString port_name) : qml_bridge(qml_bridge){
    serial_engine = new SerialEngine(qml_bridge, lap_engine, port_name);
    serial_engine->moveToThread(&serialThread);
    serialThread.start();


    SignalViewEngine *engine_temp = new SignalViewEngine(qml_bridge, ENGINE_TEMP);
    SignalViewEngine *oil_temp = new SignalViewEngine(qml_bridge, OIL_TEMP);
    SignalViewEngine *battery_status = new SignalViewEngine(qml_bridge, BATTERY_STATUS);
    SignalViewEngine *serial_status = new SignalViewEngine(qml_bridge, SERIAL_STATUS);

    engine_temp->error();
    //battery_status->waring();
    //oil_temp->waring();
    serial_status->error();

    //Sets the display to the main field
    qml_bridge->setDisplayField(0);

    //Setting the placeholders at the fields
    Reset();
}

/*
void BackEnd::updateDisplay(Packet value){
    qml_bridge->setSpeed(QString::number(value.current_speed, 'f', 1));
    qml_bridge->setTotal_distance(QString(QString::number(value.total_distance, 'f', 2) + "km"));
    qml_bridge->setBattery_charge(QString(QString::number(value.battery_charge, 'f', 2) + "V"));
}*/

void BackEnd::SwitchMenuButton(){
    display_id += 1;
    if(display_id >= 2){
        display_id = 0;
    }
    qml_bridge->setDisplayField(display_id);
}

void BackEnd::LapTrigger(){
    lap_engine->NewLap();
}

void BackEnd::LightTrigger(){
    if(light_on){
        qml_bridge->setLight_off();
        light_on = false;
    }
    else {
        qml_bridge->setLight_on();
        light_on = true;
    }
}

void BackEnd::GasPoti(uint level){
    qDebug() << level;
}

void BackEnd::Reset(){
    lap_engine->reset();
    serial_engine->reset();

    //The lap time will update in lapengine updateLapField()
    qml_bridge->setSpeed("-- --");
    qml_bridge->setAverage_speed("-- --");
    qml_bridge->setTotal_distance("-- --");
    qml_bridge->setCruise_control("-- --");
    qml_bridge->setEngine_temp("-- --");
    qml_bridge->setOil_temp("-- --");
    qml_bridge->setBattery_charge("-- --");
    qml_bridge->setTotal_time("-- --");
    qml_bridge->setRPM("-- --");
}
