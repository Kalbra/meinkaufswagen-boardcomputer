#include "signalviewengine.h"

SignalViewEngine::SignalViewEngine(BackEnd* backend_, uint8_t signal_type_){
    backend = backend_;
    signal_type = signal_type_;

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
            backend->setEngine_temp_color(color);
            break;
        case OIL_TEMP:
            backend->setOil_temp_color(color);
            break;
        case BATTERY_STATUS:
            backend->setBattery_status_color(color);
            break;
        case SERIAL_STATUS:
            backend->setSerial_status_color(color);
            break;
        }
}
