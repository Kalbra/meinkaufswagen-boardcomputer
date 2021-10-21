#include "lapengine.h"

LapEngine::LapEngine(QMLBridge *qml_bridge) : qml_bridge(qml_bridge) {
    reset();
    updateLapField();

    QTimer *timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &LapEngine::updateLapField);
    timer->start();

}

void LapEngine::NewLap(){
    lap_times.insert(lap_times.begin(), QDateTime::currentDateTime());
    updateLapDisplay();
}

void LapEngine::updateLapDisplay(){
    qint64 lap1 = lap_times[0].toMSecsSinceEpoch() - lap_times[1].toMSecsSinceEpoch();
    qint64 lap2 = lap_times[1].toMSecsSinceEpoch() - lap_times[2].toMSecsSinceEpoch();
    qint64 lap3 = lap_times[2].toMSecsSinceEpoch() - lap_times[3].toMSecsSinceEpoch();
    qint64 lap4 = lap_times[3].toMSecsSinceEpoch() - lap_times[4].toMSecsSinceEpoch();
    qint64 lap5 = lap_times[4].toMSecsSinceEpoch() - lap_times[5].toMSecsSinceEpoch();
    qint64 lap6 = lap_times[5].toMSecsSinceEpoch() - lap_times[6].toMSecsSinceEpoch();
    qint64 lap7 = lap_times[6].toMSecsSinceEpoch() - lap_times[7].toMSecsSinceEpoch();

    qint64 delta1 = lap1 - lap2;
    qint64 delta2 = lap2 - lap3;
    qint64 delta3 = lap3 - lap4;
    qint64 delta4 = lap4 - lap5;
    qint64 delta5 = lap5 - lap6;
    qint64 delta6 = lap6 - lap7;


    //Delta 1
    if(delta1 > 0){
        qml_bridge->setDeltaColor1("red");
        qml_bridge->setDelta1(QString("+ " + QString::number((float)std::abs(delta1) / 1000)));
    }
    else if(delta1 < 0){
        qml_bridge->setDeltaColor1("#00ff22");
        qml_bridge->setDelta1(QString("- " + QString::number((float)std::abs(delta1) / 1000)));
    }
    else {
        qml_bridge->setDeltaColor1("white");
        qml_bridge->setDelta1("-- --");
    }
    //Delta 2
    if(delta2 > 0){
        qml_bridge->setDeltaColor2("red");
        qml_bridge->setDelta2(QString("+ " + QString::number((float)std::abs(delta2) / 1000)));
    }
    else if(delta2 < 0){
        qml_bridge->setDeltaColor2("#00ff22");
        qml_bridge->setDelta2(QString("- " + QString::number((float)std::abs(delta2) / 1000)));
    }
    else {
        qml_bridge->setDeltaColor2("white");
        qml_bridge->setDelta2("-- --");
    }
    //Delta 3
    if(delta3 > 0){
        qml_bridge->setDeltaColor3("red");
        qml_bridge->setDelta3(QString("+ " + QString::number((float)std::abs(delta3) / 1000)));
    }
    else if(delta3 < 0){
        qml_bridge->setDeltaColor3("#00ff22");
        qml_bridge->setDelta3(QString("- " + QString::number((float)std::abs(delta3) / 1000)));
    }
    else {
        qml_bridge->setDeltaColor3("white");
        qml_bridge->setDelta3("-- --");
    }
    //Delta 4
    if(delta4 > 0){
        qml_bridge->setDeltaColor4("red");
        qml_bridge->setDelta4(QString("+ " + QString::number((float)std::abs(delta4) / 1000)));
    }
    else if(delta4 < 0){
        qml_bridge->setDeltaColor4("#00ff22");
        qml_bridge->setDelta4(QString("- " + QString::number((float)std::abs(delta4) / 1000)));
    }
    else {
        qml_bridge->setDeltaColor4("white");
        qml_bridge->setDelta4("-- --");
    }
    //Delta 5
    if(delta5 > 0){
        qml_bridge->setDeltaColor5("red");
        qml_bridge->setDelta5(QString("+ " + QString::number((float)std::abs(delta5) / 1000)));
    }
    else if(delta5 < 0){
        qml_bridge->setDeltaColor5("#00ff22");
        qml_bridge->setDelta5(QString("- " + QString::number((float)std::abs(delta5) / 1000)));
    }
    else {
        qml_bridge->setDeltaColor5("white");
        qml_bridge->setDelta5("-- --");
    }
    //Delta 6
    if(delta6 > 0){
        qml_bridge->setDeltaColor6("red");
        qml_bridge->setDelta6(QString("+ " + QString::number((float)std::abs(delta6) / 1000)));
    }
    else if(delta6 < 0){
        qml_bridge->setDeltaColor6("#00ff22");
        qml_bridge->setDelta6(QString("- " + QString::number((float)std::abs(delta6) / 1000)));
    }
    else {
        qml_bridge->setDeltaColor6("white");
        qml_bridge->setDelta6("-- --");
    }
}

//Update the left bottom field which shows the current lap time
void LapEngine::updateLapField(){
    qint64 current_lap = QDateTime::currentDateTime().toMSecsSinceEpoch() - lap_times[0].toMSecsSinceEpoch();

    qml_bridge->setLap_time(QString(QTime::fromMSecsSinceStartOfDay(current_lap).toString("mm:ss:zzz")));
}

void LapEngine::reset(){
    lap_times.clear();

    for(uint8_t i = 0; i <= 7; i++){
        lap_times.append(QDateTime());
    }
    updateLapDisplay();
}
