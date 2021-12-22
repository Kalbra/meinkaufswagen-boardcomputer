#ifndef SERIALENGINE_H
#define SERIALENGINE_H

#include <QObject>
#include <QThread>
#include <QSerialPort>
#include <chrono>
#include <QDebug>
#include "lapengine.h"
#include "qmlbridge.h"
#include "informationengine.h"

#define WHEEL_CIRCUMFERENCE 20//IN CM
#define SERIAL_TIME_OFFSET -0.01
#define MAX_RPM 1000
#define MIN_RPM 3000

#define SPEED_EVENT                  0
#define LAP_EVENT                    1
#define BREAK_EVENT                  2
#define INFO_EVENT_BATTERY_CHARGE    3
#define INFO_EVENT_ENGINE_TEMP       4
#define INFO_EVENT_GENERATOR_CURRENT 5
#define INFO_EVENT_USED_CURRENT      6

using namespace std::chrono;

class SerialEngine : public QObject
{
    Q_OBJECT
    QThread serialThread;

public:
    SerialEngine(QMLBridge *qml_bridge, LapEngine *lap_engine, QString port_name);
    void reset();

public slots:

private slots:
    void dataEvaluate();

signals:

private:
    QSerialPort serial;
    QMLBridge *qml_bridge;
    LapEngine *lap_engine;
    InformationEngine *information_engine;
    uint64_t total_speed_triggers = 0;

    high_resolution_clock::time_point last_speed_trigger = high_resolution_clock::now();
    void RPMCalc(int rpm);
};

#endif // SERIALENGINE_H
