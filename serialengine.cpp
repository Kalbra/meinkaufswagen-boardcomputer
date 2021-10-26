#include "serialengine.h"

SerialEngine::SerialEngine(QMLBridge *qml_bridge, LapEngine *lap_engine, QString port_name) : qml_bridge(qml_bridge), lap_engine(lap_engine){
    serial.setPortName(port_name);
    serial.setBaudRate(QSerialPort::Baud115200);

    if(!serial.open(QIODevice::ReadOnly)){
        qDebug() << serial.errorString();
    }

    connect(&serial, &QSerialPort::readyRead, this, &SerialEngine::dataEvaluate);
}

void SerialEngine::dataEvaluate(){
    QByteArray datas = serial.readAll();

    switch (datas[0]) {
        case SPEED_EVENT: {
            //Delta caluclation
            high_resolution_clock::time_point now_trigger = high_resolution_clock::now();
            duration<double> delta = duration_cast<duration<double>>(now_trigger - last_speed_trigger);
            last_speed_trigger = now_trigger;

            //Speed calculation and inserting
            double speed = (((double)WHEEL_CIRCUMFERENCE / 100) / (delta.count()) + SERIAL_TIME_OFFSET) * 3.6;
            qml_bridge->setSpeed(QString::number(speed, 'f', 1));

            qDebug() << "Eich time:"<< delta.count();

            //Calculates the total distance
            double total_distance = ((double)WHEEL_CIRCUMFERENCE / 100000) * total_speed_triggers;
            total_speed_triggers += 1;
            qml_bridge->setTotal_distance(QString(QString::number(total_distance, 'f', 2) + "km"));

            break;
        }
        case LAP_EVENT: {
            lap_engine->NewLap();
            break;
        }
        case BREAK_EVENT:
            break;
        case INFO_EVENT:
            break;
        default:
            qDebug() << "Cant decode the serial data";
    }
}

void SerialEngine::reset(){
    total_speed_triggers = 0;
}
