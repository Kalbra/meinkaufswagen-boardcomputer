#ifndef LAPENGINE_H
#define LAPENGINE_H

#include <QObject>
#include <QDateTime>
#include <QDebug>
#include "backend.h"

struct

class LapEngine : public QObject
{
    Q_OBJECT

public:
    LapEngine();
    void NewLap();
    void updateLapDisplay(BackEnd *backend);

private:

    QVector<QDateTime> lap_times;
};

#endif // LAPENGINE_H
