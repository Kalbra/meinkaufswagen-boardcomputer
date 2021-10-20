#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QPushButton>
#include <QString>
#include <QTimer>
#include <QQmlProperty>
#include <QSerialPort>
#include <QDebug>
#include <qqml.h>
#include "lapengine.h"


//The data packet
struct Packet{
    double current_speed;
    double total_distance;
    double battery_charge;

    bool break_trigger;
    bool lap_trigger;
};


class BackEnd : public QObject
{
    Q_OBJECT

    //Display signals
    Q_PROPERTY(QString engine_temp_color MEMBER engine_temp_color NOTIFY engine_temp_colorChanged)
    Q_PROPERTY(QString oil_temp_color MEMBER oil_temp_color NOTIFY oil_temp_colorChanged)
    Q_PROPERTY(QString battery_status_color MEMBER battery_status_color NOTIFY battery_status_colorChanged)
    Q_PROPERTY(QString serial_status_color MEMBER serial_status_color NOTIFY serial_status_colorChanged)

    //Speed
    Q_PROPERTY(QString speed_string MEMBER speed_string NOTIFY speed_stringChanged)
    //Average speed
    Q_PROPERTY(QString average_speed MEMBER average_speed NOTIFY average_speedChanged)
    //Cruise control
    Q_PROPERTY(QString cruise_control MEMBER cruise_control NOTIFY cruise_controlChanged)
    //Total distance
    Q_PROPERTY(QString total_distance MEMBER total_distance NOTIFY total_distanceChanged)
    //Lap time
    Q_PROPERTY(QString lap_time MEMBER lap_time NOTIFY lap_timeChanged)
    //Cruse control color
    Q_PROPERTY(QString cruse_control_color MEMBER cruse_control_color NOTIFY cruse_control_colorChanged)
    //Battery charge
    Q_PROPERTY(QString battery_charge MEMBER battery_charge NOTIFY battery_chargeChanged)


public:
    BackEnd(QString port_name); 

    //Display signals
    QString engine_temp_color;
    QString oil_temp_color;
    QString battery_status_color;
    QString serial_status_color;
    void setEngine_temp_color(QString value){engine_temp_color = value; emit engine_temp_colorChanged();}
    void setOil_temp_color(QString value){oil_temp_color = value; emit oil_temp_colorChanged();}
    void setBattery_status_color(QString value){battery_status_color = value; emit battery_status_colorChanged();}
    void setSerial_status_color(QString value){serial_status_color = value; emit serial_status_colorChanged();}

    //Speed
    QString speed_string;
    void setSpeed(QString value){speed_string = value; emit speed_stringChanged();}
    //Average speed
    QString average_speed;
    void setAverage_speed(QString value){average_speed = value; emit average_speedChanged();}
    //Cruise control
    QString cruise_control;
    void setCruise_control(QString value){cruise_control = value; emit cruise_controlChanged();}
    //Total distance
    QString total_distance;
    void setTotal_distance(QString value){total_distance = value; emit total_distanceChanged();}
    //Lap time
    QString lap_time;
    void setLap_time(QString value){lap_time = value; emit lap_timeChanged();}
    //Battery charge
    QString battery_charge;
    void setBattery_charge(QString value){battery_charge = value; emit battery_chargeChanged();}

    //Cruise control color on/off
    QString cruse_control_color;
    void setCruse_control_on(){cruse_control_color = "blue"; emit cruse_control_colorChanged();}
    void setCruse_control_off(){cruse_control_color = "white"; emit cruse_control_colorChanged();}

    //Update display
    void updateDisplay(Packet value);




signals:
    //Display signals
    void engine_temp_colorChanged();
    void oil_temp_colorChanged();
    void battery_status_colorChanged();
    void serial_status_colorChanged();

    //Speed
    void speed_stringChanged();
    //Average speed
    void average_speedChanged();
    //Cruise control
    void cruise_controlChanged();
    //Total distance
    void total_distanceChanged();
    //Lap time
    void lap_timeChanged();
    //Cruse control color
    void cruse_control_colorChanged();
    //Battery charge
    void battery_chargeChanged();


private slots:
    void SerialRead();

public slots:
    //void GasPoti(float value);
    //void CruiseControlTriggerButton();
    //void CruiseControlUpButton();
    //void CruiseControlDownButton();
    //void IgnoreTriggerButton();
    void SwitchMenuButton();
    void LapTrigger();

protected:

private:
    QSerialPort serial;

    LapEngine lap_engine;

};

#endif // BACKEND_H
