#include "informationengine.h"

InformationEngine::InformationEngine(QMLBridge *qml_bridge, SignalViewEngine *engine_temp, SignalViewEngine *battery_status) : qml_bridge(qml_bridge), engine_temp(engine_temp), battery_status(battery_status){

}

void InformationEngine::setBatteryCharge(QByteArray data){
    double d_data = dataToDouble(data);
    checkLimits(0, d_data, battery_status);
    qml_bridge->setBattery_charge(QString(QString::number(d_data, 'f', 2) + " V"));
}

void InformationEngine::setEngineTemp(QByteArray data){
    double d_data = dataToDouble(data);
    checkLimits(1, d_data, engine_temp);
    qml_bridge->setEngine_temp(QString(QString::number(dataToDouble(data), 'f', 2) + " C°"));
}

void InformationEngine::setGeneratorCurrent(QByteArray data){
    qml_bridge->setGenerator_current(QString(QString::number(dataToDouble(data), 'f', 2) + " W"));
}

void InformationEngine::setUsedCurrend(QByteArray data){
    qml_bridge->setUsed_current(QString(QString::number(dataToDouble(data), 'f', 2) + " W"));
}

/*    double d = 70.976;
    const unsigned char *ptr2 = (const unsigned char*)(&d);
    for (int i = 0; i < 8; ++i)
        fprintf(stderr, "%02x\n", ptr2[i]);
*/


double InformationEngine::dataToDouble(QByteArray data){
    data.remove(0, 1);

    double out;
    memcpy(&out, data.data(), sizeof out);

    return out;
}

void InformationEngine::checkLimits(uint8_t id, double data, SignalViewEngine *engine){
    if(data < limits[id][0]){
        engine->error();
    } else if (data > limits[id][1]){
        engine->error();
    } else {
        engine->clear();
    }
}
