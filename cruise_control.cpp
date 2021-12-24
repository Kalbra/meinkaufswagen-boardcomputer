#include "cruise_control.h"

CruiseControl::CruiseControl(QMLBridge *qml_bridge, SerialEngine *serial_engine) : qml_bridge(qml_bridge), serial_engine(serial_engine){
    reset();
}

void CruiseControl::updateField(){
    qml_bridge->setCruise_control(QString(QString::number(target_speed) + "km/h"));
    if(on_off){
        qml_bridge->setCruse_control_on();
    }
    else{
        qml_bridge->setCruse_control_off();
    }
}

void CruiseControl::evaluateGas(uint16_t level){
    if(on_off) {
        //dlskjf
    }
    else {
        serial_engine->sendGas(level);
    }
}

void CruiseControl::reset(){
    on_off = false;
    target_speed = 20;

    updateField();
}
