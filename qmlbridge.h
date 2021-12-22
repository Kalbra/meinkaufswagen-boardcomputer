#ifndef QMLBRIDGE_H
#define QMLBRIDGE_H

#include <QObject>
#include <QDebug>

class QMLBridge : public QObject
{
    Q_OBJECT

    //Display signals
    Q_PROPERTY(QString engine_temp_color MEMBER engine_temp_color NOTIFY engine_temp_colorChanged)
    Q_PROPERTY(QString oil_temp_color MEMBER oil_temp_color NOTIFY oil_temp_colorChanged)
    Q_PROPERTY(QString battery_status_color MEMBER battery_status_color NOTIFY battery_status_colorChanged)
    Q_PROPERTY(QString serial_status_color MEMBER serial_status_color NOTIFY serial_status_colorChanged)

    //Setting display
    Q_PROPERTY(uint display_id MEMBER display_id NOTIFY setting_displayChanged)

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
    //Light color
    Q_PROPERTY(QString light_color MEMBER light_color NOTIFY light_colorChanged)
    //RPM progressbar
    Q_PROPERTY(int rpm_progressbar MEMBER rpm_progressbar NOTIFY rpm_progressbarChanged)
    //Engine temp
    Q_PROPERTY(QString engine_temp MEMBER engine_temp NOTIFY engine_tempChanged)
    //Oil temp
    Q_PROPERTY(QString oil_temp MEMBER oil_temp NOTIFY oil_tempChanged)
    //Total time
    Q_PROPERTY(QString total_time MEMBER total_time NOTIFY total_timeChanged)
    //RPM
    Q_PROPERTY(QString rpm MEMBER rpm NOTIFY rpmChanged)
    //Generator current
    Q_PROPERTY(QString generator_current MEMBER generator_current NOTIFY generator_currentChanged)
    //Used current
    Q_PROPERTY(QString used_current MEMBER used_current NOTIFY used_currentChanged)

    //Lap display
    Q_PROPERTY(QString delta1 MEMBER delta1 NOTIFY lap_displayChanged)
    Q_PROPERTY(QString delta2 MEMBER delta2 NOTIFY lap_displayChanged)
    Q_PROPERTY(QString delta3 MEMBER delta3 NOTIFY lap_displayChanged)
    Q_PROPERTY(QString delta4 MEMBER delta4 NOTIFY lap_displayChanged)
    Q_PROPERTY(QString delta5 MEMBER delta5 NOTIFY lap_displayChanged)
    Q_PROPERTY(QString delta6 MEMBER delta6 NOTIFY lap_displayChanged)
    //Lap display color
    Q_PROPERTY(QString delta1_color MEMBER delta1_color NOTIFY lap_displayChanged)
    Q_PROPERTY(QString delta2_color MEMBER delta2_color NOTIFY lap_displayChanged)
    Q_PROPERTY(QString delta3_color MEMBER delta3_color NOTIFY lap_displayChanged)
    Q_PROPERTY(QString delta4_color MEMBER delta4_color NOTIFY lap_displayChanged)
    Q_PROPERTY(QString delta5_color MEMBER delta5_color NOTIFY lap_displayChanged)
    Q_PROPERTY(QString delta6_color MEMBER delta6_color NOTIFY lap_displayChanged)

public:
    QMLBridge(){}

    //Display signals
    QString engine_temp_color;
    QString oil_temp_color;
    QString battery_status_color;
    QString serial_status_color;
    void setEngine_temp_color(QString value){engine_temp_color = value; emit engine_temp_colorChanged();}
    void setOil_temp_color(QString value){oil_temp_color = value; emit oil_temp_colorChanged();}
    void setBattery_status_color(QString value){battery_status_color = value; emit battery_status_colorChanged();}
    void setSerial_status_color(QString value){serial_status_color = value; emit serial_status_colorChanged();}

    //Setting display
    uint display_id;
    void setDisplayField(uint value){display_id = value; emit setting_displayChanged();}

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
    //RPM progressbar
    int rpm_progressbar;
    void setRPMProgressbar(int value){rpm_progressbar = value; emit rpm_progressbarChanged();}
    //Engine temp
    QString engine_temp;
    void setEngine_temp(QString value){engine_temp = value; emit engine_tempChanged();}
    //Oil temp
    QString oil_temp;
    void setOil_temp(QString value){oil_temp = value; emit oil_tempChanged();}
    //Total time
    QString total_time;
    void setTotal_time(QString value){total_time = value; emit total_timeChanged();}
    //RPM
    QString rpm;
    void setRPM(QString value){rpm = value; emit rpmChanged();}
    //Generator current
    QString generator_current;
    void setGenerator_current(QString value){generator_current = value; emit generator_currentChanged();}
    //Used current
    QString used_current;
    void setUsed_current(QString value){used_current = value; emit used_currentChanged();}


    //Cruise control color on/off
    QString cruse_control_color;
    void setCruse_control_on(){cruse_control_color = "blue"; emit cruse_control_colorChanged();}
    void setCruse_control_off(){cruse_control_color = "white"; emit cruse_control_colorChanged();}

    //Light color on/off
    QString light_color;
    void setLight_on(){light_color = "#00ff22"; emit light_colorChanged();}
    void setLight_off(){light_color = "black"; emit light_colorChanged();}

    //Lap display
    QString delta1;
    QString delta2;
    QString delta3;
    QString delta4;
    QString delta5;
    QString delta6;
    void setDelta1(QString value){delta1 = value; emit lap_displayChanged();}
    void setDelta2(QString value){delta2 = value; emit lap_displayChanged();}
    void setDelta3(QString value){delta3 = value; emit lap_displayChanged();}
    void setDelta4(QString value){delta4 = value; emit lap_displayChanged();}
    void setDelta5(QString value){delta5 = value; emit lap_displayChanged();}
    void setDelta6(QString value){delta6 = value; emit lap_displayChanged();}
    //Color
    QString delta1_color;
    QString delta2_color;
    QString delta3_color;
    QString delta4_color;
    QString delta5_color;
    QString delta6_color;
    void setDeltaColor1(QString value){delta1_color = value; emit lap_displayChanged();}
    void setDeltaColor2(QString value){delta2_color = value; emit lap_displayChanged();}
    void setDeltaColor3(QString value){delta3_color = value; emit lap_displayChanged();}
    void setDeltaColor4(QString value){delta4_color = value; emit lap_displayChanged();}
    void setDeltaColor5(QString value){delta5_color = value; emit lap_displayChanged();}
    void setDeltaColor6(QString value){delta6_color = value; emit lap_displayChanged();}


signals:
    //Display signals
    void engine_temp_colorChanged();
    void oil_temp_colorChanged();
    void battery_status_colorChanged();
    void serial_status_colorChanged();

    //Setting display
    void setting_displayChanged();

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
    //Light color
    void light_colorChanged();
    //RPM progressbar
    void rpm_progressbarChanged();
    //Engine temp
    void engine_tempChanged();
    //Oil temp
    void oil_tempChanged();
    //Total time
    void total_timeChanged();
    //RPM
    void rpmChanged();
    //Generator current
    void generator_currentChanged();
    //Used current
    void used_currentChanged();


    //Lap display
    void lap_displayChanged();
    void delta1Changed();
};

#endif // QMLBRIDGE_H
