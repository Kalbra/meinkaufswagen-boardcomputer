#include "serialengine.h"

SerialEngine::SerialEngine(QMLBridge *qml_bridge, LapEngine *lap_engine, QString port_name, SignalViewEngine *serial_status, InformationEngine *information_engine) : qml_bridge(qml_bridge), lap_engine(lap_engine), information_engine(information_engine){
    serial.setPortName(port_name);
    serial.setBaudRate(QSerialPort::Baud115200);

    if(!serial.open(QIODevice::ReadOnly)){
        serial_status->error();
        qDebug() << serial.errorString();
    }

    connect(&serial, &QSerialPort::errorOccurred, this, [&]{
       serial_status->error();
    });
    connect(&serial, &QSerialPort::readyRead, this, &SerialEngine::dataEvaluate);


    qDebug() << "dspof";
    //Test
    RPMCalc(1243);
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
            qml_bridge->setSpeed(QString(QString::number(speed, 'f', 1)));

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
        case BREAK_EVENT: {
            break;
        }
        case INFO_EVENT_BATTERY_CHARGE: {
            information_engine->setBatteryCharge(datas);
            qDebug() << "lksdf";
            break;
        }
        case INFO_EVENT_ENGINE_TEMP: {
            information_engine->setEngineTemp(datas);
            break;
        }
        case INFO_EVENT_GENERATOR_CURRENT: {
            information_engine->setGeneratorCurrent(datas);
            break;
        }
        case INFO_EVENT_USED_CURRENT: {
            information_engine->setUsedCurrend(datas);
            break;
        }
        default:
            qDebug() << "Cant decode the serial data";
    }
}

void SerialEngine::RPMCalc(int rpm){
    qDebug() << (rpm - MIN_RPM) * (799 - 494) / (MAX_RPM - MIN_RPM) + 494;
    qml_bridge->setRPMProgressbar((rpm - MIN_RPM) * (799 - 494) / (MAX_RPM - MIN_RPM) + 494);
}

void SerialEngine::reset(){
    total_speed_triggers = 0;
}
