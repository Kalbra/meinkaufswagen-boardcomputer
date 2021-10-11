#ifndef SIGNALVIEWENGINE_H
#define SIGNALVIEWENGINE_H

#define CLEAR          0x00
#define ERROR          0x01
#define WARNING        0x02

#include <QObject>
#include <QTimer>

class SignalViewEngine : public QObject
{
    Q_OBJECT
public:
    SignalViewEngine(QObject* qmlroot, QString qml_object_name, bool *ignore);

    void error(){raisetype = ERROR;}
    void waring(){raisetype = WARNING;}
    void clear(){raisetype = CLEAR;}

signals:

public slots:

private:
    QTimer *timer = new QTimer(this);

    uint8_t raisetype;
};

#endif // SIGNALVIEWENGINE_H
