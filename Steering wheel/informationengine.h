#ifndef INFORMATIONENGINE_H
#define INFORMATIONENGINE_H

#include <QObject>
#include "qmlbridge.h"
#include "signalviewengine.h"

class InformationEngine : public QObject
{
    Q_OBJECT

public:
    InformationEngine(QMLBridge *qml_bridge, SignalViewEngine *engine_temp, SignalViewEngine *battery_status);

    //Limits
    double limits[4][2] = {
            {10, 20},     //BatteryCharge
            {10, 20},     //EngineTemp
            {10, 20},     //GeneratorCurrent
            {10, 20},     //UsedCurrent
        };//MIN  MAX

    void setBatteryCharge(QByteArray data);
    void setEngineTemp(QByteArray data);
    void setGeneratorCurrent(QByteArray data);
    void setUsedCurrend(QByteArray data);

private:
    QMLBridge *qml_bridge;

    SignalViewEngine *engine_temp;
    SignalViewEngine *battery_status;

    double dataToDouble(QByteArray data);
    void checkLimits(uint8_t id, double data, SignalViewEngine *engine);

};

#endif // INFORMATIONENGINE_H
