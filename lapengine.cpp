#include "lapengine.h"

LapEngine::LapEngine() {
    NewLap();
}

void LapEngine::NewLap(){
    lap_times.append(QDateTime::currentDateTime());
}

void LapEngine::updateLapDisplay(BackEnd *backend){
    qint64 delta1 = lap_times[0].msecsTo(lap_times[1]);
    qint64 delta2 = lap_times[1].msecsTo(lap_times[2]);
    qint64 delta3 = lap_times[2].msecsTo(lap_times[3]);
    qint64 delta4 = lap_times[3].msecsTo(lap_times[4]);
    qint64 delta5 = lap_times[4].msecsTo(lap_times[5]);
    qint64 delta6 = lap_times[5].msecsTo(lap_times[6]);



    qDebug() << delta1;
}
