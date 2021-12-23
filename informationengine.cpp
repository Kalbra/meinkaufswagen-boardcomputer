#include "informationengine.h"

InformationEngine::InformationEngine(QMLBridge *qml_bridge): qml_bridge(qml_bridge){

}

void InformationEngine::setBatteryCharge(QByteArray data){
    qml_bridge->setBattery_charge(QString(QString::number(dataToDouble(data), 'f', 2) + " V"));
}

void InformationEngine::setEngineTemp(QByteArray data){
    qml_bridge->setEngine_temp(QString(QString::number(dataToDouble(data), 'f', 2) + " C°"));
}

void InformationEngine::setGeneratorCurrent(QByteArray data){
    qml_bridge->setGenerator_current(QString(QString::number(dataToDouble(data), 'f', 2) + " W"));
}

void InformationEngine::setUsedCurrend(QByteArray data){
    qml_bridge->setUsed_current(QString(QString::number(dataToDouble(data), 'f', 2) + " W"));
}


double InformationEngine::dataToDouble(QByteArray data){
    data.remove(0, 1);

    char tmp[8];
    strncpy(tmp, data.data(), 8);

    return atof(tmp);
}
