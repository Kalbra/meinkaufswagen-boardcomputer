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
#include "cruise_control.h"

class BackEnd : public QObject
{
    Q_OBJECT
    QThread serialThread;

public:
    BackEnd(QMLBridge *qml_bridge);

    //Resets all date like total time or distance
    void Reset();

signals:


private slots:


public slots:
    void GasPoti(uint16_t value);
    void CruiseControlTriggerButton();
    void CruiseControlUpButton();
    void CruiseControlDownButton();
    //void IgnoreTriggerButton();
    void SwitchMenuButton();
    void LapTrigger();
    void LightTrigger();
    void TalkTrigger();

protected:

private:
    QMLBridge *qml_bridge;
    SerialEngine *serial_engine;
    CruiseControl *cruise_control;
    LapEngine *lap_engine = new LapEngine(qml_bridge);

    bool light_on = false;
    bool talk_on = false;
    uint display_id = 0;
};

#endif // BACKEND_H
