#ifndef CRUISECONTROL_H
#define CRUISECONTROL_H

#include <QObject>
#include <QDebug>
#include "qmlbridge.h"

class CruiseControl : public QObject
{
    Q_OBJECT
public:
    CruiseControl(QMLBridge *qml_bridge);
    void evaluateGas(uint level);

    void reset();

signals:

public slots:
    void setOnOff(){on_off = !on_off; updateField();}

    void TargetSpeedUp(){target_speed += 1; updateField();}
    //TODO: Not to go into negativ
    void TargetSpeedDown(){target_speed -= 1; updateField();}

private:
    QMLBridge *qml_bridge;
    void updateField();

    bool on_off;
    double target_speed;
};

#endif // CRUISECONTROL_H
