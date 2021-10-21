#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QPushButton>
#include <QString>
#include <QTimer>
#include <QQmlProperty>
#include <QSerialPort>
#include <QThread>
#include <QDebug>
#include <qqml.h>
#include "lapengine.h"
#include "signalviewengine.h"
#include "qmlbridge.h"
#include "serialengine.h"

//The data packet
struct Packet{
    double current_speed;
    double total_distance;
    double battery_charge;

    bool break_trigger;
    bool lap_trigger;
};


class BackEnd : public QObject
{
    Q_OBJECT
    QThread serialThread;

public:
    BackEnd(QMLBridge *qml_bridge, QString port_name);

    //Update display
    void updateDisplay(Packet value);

    //Resets all date like total time or distance
    void Reset();

signals:


private slots:
    void SerialRead();

public slots:
    //void GasPoti(float value);
    //void CruiseControlTriggerButton();
    //void CruiseControlUpButton();
    //void CruiseControlDownButton();
    //void IgnoreTriggerButton();
    void SwitchMenuButton();
    void LapTrigger();

protected:

private:
    QMLBridge *qml_bridge;

    QSerialPort serial;

     LapEngine *lap_engine = new LapEngine(qml_bridge);

};

#endif // BACKEND_H
