#ifndef SERIALENGINE_H
#define SERIALENGINE_H

#include <QObject>
#include <QThread>
#include <QSerialPort>
#include <QDebug>

class SerialEngine : public QObject
{
    Q_OBJECT
    QThread serialThread;

public:
    SerialEngine(QString port_name);

public slots:

private slots:
    void dataEvaluate();

signals:

private:
    QSerialPort serial;


    void speed_trigger();

};

#endif // SERIALENGINE_H
