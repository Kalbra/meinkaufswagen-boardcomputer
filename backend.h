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

class BackEnd : public QObject
{
    Q_OBJECT
    QThread serialThread;

public:
    BackEnd(QMLBridge *qml_bridge, QString port_name);

    //Resets all date like total time or distance
    void Reset();

signals:


private slots:


public slots:
    void GasPoti(uint value);
    //void CruiseControlTriggerButton();
    //void CruiseControlUpButton();
    //void CruiseControlDownButton();
    //void IgnoreTriggerButton();
    void SwitchMenuButton();
    void LapTrigger();

protected:

private:
    QMLBridge *qml_bridge;
    SerialEngine *serial_engine;
    LapEngine *lap_engine = new LapEngine(qml_bridge);

};

#endif // BACKEND_H
