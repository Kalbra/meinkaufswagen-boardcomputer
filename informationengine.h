#ifndef INFORMATIONENGINE_H
#define INFORMATIONENGINE_H

#include <QObject>
#include "qmlbridge.h"

class InformationEngine : public QObject
{
    Q_OBJECT

public:
    InformationEngine(QMLBridge *qml_bridge);

    void setBatteryCharge(QByteArray data);
    void setEngineTemp(QByteArray data);
    void setGeneratorCurrent(QByteArray data);
    void setUsedCurrend(QByteArray data);

private:
    QMLBridge *qml_bridge;

};

#endif // INFORMATIONENGINE_H
