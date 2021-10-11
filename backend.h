#ifndef BACKEND_H
#define BACKEND_H

#define ENGINE_TEMP    0x00
#define OIL_TEMP       0x01
#define BATTERY_STATUS 0x02
#define SERIAL_STATUS  0x03

#define CLEAR          0x00
#define ERROR          0x01
#define WARNING        0x02

#include <QObject>
#include <QString>
#include <QTimer>
#include <QQmlProperty>
#include <QSerialPort>
#include <QDebug>
#include <qqml.h>

class BackEnd : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int engine_temp_signal MEMBER engine_temp_signal NOTIFY engine_temp_signalChanged)
    Q_PROPERTY(int oil_temp_signal MEMBER oil_temp_signal NOTIFY oil_temp_signalChanged)
    Q_PROPERTY(int battery_status_signal MEMBER battery_status_signal NOTIFY battery_status_signalChanged)
    Q_PROPERTY(int serial_status_signal MEMBER serial_status_signal NOTIFY serial_status_signalChanged)


public:
    BackEnd(QObject *QmlRoot, QString port_name);

    void SignalLoop(QObject *signal_object, QString *signal_type_string);
    void SetDisplaySignal(uint8_t signal, uint8_t signal_type);

signals:
    void engine_temp_signalChanged();
    void oil_temp_signalChanged();
    void battery_status_signalChanged();
    void serial_status_signalChanged();

private slots:
    void SerialRead();

private:
    QObject *qmlroot;

    QSerialPort serial;

    //If the signal stops or not
    bool trigger_signal;

    // This shows the qml if a waring or error should raise. 0 = No raise; 1 = Warning; 2 = Error
    int engine_temp_signal;
    int oil_temp_signal;
    int battery_status_signal;
    int serial_status_signal;



};

#endif // BACKEND_H
