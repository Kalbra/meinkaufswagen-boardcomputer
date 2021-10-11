#include "backend.h"

BackEnd::BackEnd(QObject *QmlRoot, QString port_name){
    qmlroot = QmlRoot;

    qDebug() << qmlroot->findChild<QObject*>("engine_temp");

    serial.setPortName(port_name);
    serial.setBaudRate(QSerialPort::Baud115200);

    if(!serial.open(QIODevice::ReadOnly)){
        qDebug() << serial.errorString();
    }

    //QObject::connect(&serial, &QSerialPort::readyRead, SerialRead);

    SetDisplaySignal(0, 0);

}
void BackEnd::SignalLoop(QObject *signal_object, QString *signal_type_string){

}

void BackEnd::SetDisplaySignal(uint8_t signal, uint8_t signal_type){
    bool on_off = true;

    QObject *engine_temp = qmlroot->findChild<QObject*>("engine_temp");
    QObject *oil_temp = qmlroot->findChild<QObject*>("oil_temp");
    QObject *battery_status = qmlroot->findChild<QObject*>("battery_status");
    QObject *serial_status = qmlroot->findChild<QObject*>("serial_status");


    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [&]{

        if(engine_temp && oil_temp && battery_status && serial_status){
            QObject *signal_object;
            QString signal_type_string;

            switch (signal) {
                case ENGINE_TEMP:
                    signal_object = engine_temp;
                    break;
                case OIL_TEMP:
                    signal_object = oil_temp;
                    break;
                case BATTERY_STATUS:
                    signal_object = battery_status;
                    break;
                case SERIAL_STATUS:
                    signal_object = serial_status;
                    break;
                default:
                    return;
            }
            switch (signal_type) {
                case ERROR:
                    signal_type_string = "red";
                    break;
                case WARNING:
                    signal_type_string = "#feef09";
                    break;
                default:
                    return;
            }
            if(on_off or signal == CLEAR){
                signal_object->setProperty("color", "black");
                on_off = false;
            }
            else {
                signal_object->setProperty("color", signal_type_string);
                on_off = true;
            }
        }
    });

    timer->start(500);
}

void BackEnd::ClearDisplaySignal(uint8_t signal){

}

void BackEnd::SerialRead(){
    qDebug() << "New data available: " << serial.bytesAvailable();
    QByteArray datas = serial.readAll();
    qDebug() << datas;
}
