#ifndef LAPENGINE_H
#define LAPENGINE_H

#include <QObject>
#include <QDateTime>
#include <QTime>
#include <QTimer>
#include <QDebug>
#include <cmath>
#include "qmlbridge.h"


class LapEngine : public QObject
{
    Q_OBJECT

public:
    LapEngine(QMLBridge *qml_bridge);
    void NewLap();
    void updateLapDisplay();
    void updateLapField();
    void reset();

    qint64 total_time;

private:
    QMLBridge *qml_bridge;

    QVector<QDateTime> lap_times;

    qint64 start_time;

};

#endif // LAPENGINE_H
