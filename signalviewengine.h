#ifndef SIGNALVIEWENGINE_H
#define SIGNALVIEWENGINE_H

#define ENGINE_TEMP    0
#define OIL_TEMP       1
#define BATTERY_STATUS 2
#define SERIAL_STATUS  3

#define CLEAR          0
#define ERROR          1
#define WARNING        3

#include <QObject>
#include <QTimer>
#include <QVariant>
#include <QDebug>
#include <QQmlProperty>
#include <QQuickItem>
#include <qqml.h>
#include "backend.h"

class SignalViewEngine : public QObject
{
    Q_OBJECT

public:
    SignalViewEngine(BackEnd *backend, uint8_t signal_type);

    void error(){raisetype = ERROR;}
    void waring(){raisetype = WARNING;}
    void clear(){raisetype = CLEAR;}

    uint8_t signal_type;

//signals:

public slots:
    void tick();


private:
    uint8_t raisetype;

    bool on_off = true;
    QString color = "red";
    BackEnd *backend;
};

#endif // SIGNALVIEWENGINE_H
