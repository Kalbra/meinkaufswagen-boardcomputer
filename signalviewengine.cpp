#include "signalviewengine.h"

SignalViewEngine::SignalViewEngine(QObject* qmlroot, QString qml_object_name, bool *ignore){
    QObject *signal_object = qmlroot->findChild<QObject*>(qml_object_name);
    bool on_off = true;

    connect(timer, &QTimer::timeout, this, [&]{
        if(signal_object){

            if(on_off){
                signal_object->setProperty("color", "black");
                on_off = false;
            }
            else {
                switch (raisetype) {
                    case ERROR:
                        signal_object->setProperty("color", "red");
                        break;
                    case WARNING:
                        signal_object->setProperty("color", "#feef09");
                        break;
                    case CLEAR:
                        signal_object->setProperty("color", "black");
                        break;
                }
            }
        }
    });
}
