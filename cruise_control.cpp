#include "cruise_control.h"

CruiseControl::CruiseControl(QMLBridge *qml_bridge) : qml_bridge(qml_bridge){
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

void CruiseControl::evaluateGas(uint level){
    if(on_off) {
        //dlskjf
    }
    else {
        qDebug() << level;
    }
}

void CruiseControl::reset(){
    on_off = false;
    target_speed = 20;

    updateField();
}
