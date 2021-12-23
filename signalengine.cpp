#include "signalengine.h"

SignalViewEngine::SignalViewEngine(QMLBridge *qml_bridge, uint8_t signal_type) : qml_bridge(qml_bridge), signal_type(signal_type){
    //Init the timer to tick this will generate an animation of blick
    QTimer *timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &SignalViewEngine::tick);
    timer->start(500);
}

void SignalViewEngine::tick(){
    //Sets the color to black to make a blink effect
    if(on_off){
        color = "black";
        on_off = false;
    }
    //Sets the color for the right mode like error(red) and warning(yellow)
    else {
        switch (raisetype) {
            case ERROR:
                color = "red";
                break;
            case WARNING:
                color = "#feef09"; // = yellow
                break;
            case CLEAR:
                color = "black";
                break;
            }
        on_off = true;
    }

    //Sets the color the right window
    switch (signal_type) {
        case ENGINE_TEMP:
            qml_bridge->setEngine_temp_color(color);
            break;
        case OIL_TEMP:
            qml_bridge->setOil_temp_color(color);
            break;
        case BATTERY_STATUS:
            qml_bridge->setBattery_status_color(color);
            break;
        case SERIAL_STATUS:
            qml_bridge->setSerial_status_color(color);
            break;
        }
}
