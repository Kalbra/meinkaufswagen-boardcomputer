#include "backend.h"


BackEnd::BackEnd(QMLBridge *qml_bridge) : qml_bridge(qml_bridge){
    SignalViewEngine *engine_temp = new SignalViewEngine(qml_bridge, ENGINE_TEMP);
    SignalViewEngine *oil_temp = new SignalViewEngine(qml_bridge, OIL_TEMP);
    SignalViewEngine *battery_status = new SignalViewEngine(qml_bridge, BATTERY_STATUS);
    SignalViewEngine *serial_status = new SignalViewEngine(qml_bridge, SERIAL_STATUS);

    InformationEngine *information_engine = new InformationEngine(qml_bridge, engine_temp, battery_status);

    serial_engine = new SerialEngine(qml_bridge, lap_engine, serial_status, information_engine);
    serial_engine->moveToThread(&serialThread);
    serialThread.start();

    cruise_control = new CruiseControl(qml_bridge, serial_engine);

    //Sets the display to the main field
    qml_bridge->setDisplayField(0);

    //Setting the placeholders at the fields
    Reset();
}

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
        serial_engine->sendLightOff();
        qml_bridge->setLight_off();
        light_on = false;
    }
    else {
        serial_engine->sendLightOn();
        qml_bridge->setLight_on();
        light_on = true;
    }
}

void BackEnd::TalkTrigger(){
    if(talk_on){
        serial_engine->sendTalkOff();
        qml_bridge->setTalk_off();
        talk_on = false;
    }
    else {
        serial_engine->sendTalkOn();
        qml_bridge->setTalk_on();
        talk_on = true;
    }
}


void BackEnd::GasPoti(uint16_t level){
    cruise_control->evaluateGas(level);
}

void BackEnd::CruiseControlUpButton(){
    cruise_control->TargetSpeedUp();
}

void BackEnd::CruiseControlDownButton(){
    cruise_control->TargetSpeedDown();
}

void BackEnd::CruiseControlTriggerButton(){
    cruise_control->setOnOff();
}

void BackEnd::Reset(){
    lap_engine->reset();
    serial_engine->reset();
    cruise_control->reset();

    //The lap time will update in lapengine updateLapField()
    //Cruise control will update in cruise_control
    qml_bridge->setSpeed("-- --");
    qml_bridge->setAverage_speed("-- --");
    qml_bridge->setTotal_distance("-- --");
    qml_bridge->setEngine_temp("-- --");
    qml_bridge->setOil_temp("-- --");
    qml_bridge->setBattery_charge("-- --");
    qml_bridge->setTotal_time("-- --");
    qml_bridge->setRPM("-- --");
    qml_bridge->setGenerator_current("-- --");
    qml_bridge->setUsed_current("-- --");
    qml_bridge->setRPMProgressbar(495);
}
