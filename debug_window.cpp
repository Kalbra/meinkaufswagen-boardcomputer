#include "debug_window.h"


Debug::Debug(BackEnd *backend): backend(backend){
    this->setWindowTitle("Debug Window");

    QWidget *window = new QWidget(this);

    QPushButton *switch_menu = new QPushButton("Switch Menu");
    QPushButton *ignore = new QPushButton("Ignore");
    QPushButton *cruise_control_trigger = new QPushButton("Cruise Control Trigger");
    QPushButton *cruise_control_high = new QPushButton("Cruise Control High");
    QPushButton *cruise_control_low = new QPushButton("Cruise Control Low");
    QPushButton *lap_trigger = new QPushButton("Lap Trigger");
    QPushButton *light_tigger = new QPushButton("Light Trigger");
    QPushButton *reset_tigger = new QPushButton("Reset");
    gas_input = new QLineEdit("");
    QPushButton *enter_gas = new QPushButton("Enter GAS");

    QHBoxLayout *layout = new QHBoxLayout(window);
    layout->addWidget(switch_menu);
    layout->addWidget(ignore);
    layout->addWidget(cruise_control_trigger);
    layout->addWidget(cruise_control_high);
    layout->addWidget(cruise_control_low);
    layout->addWidget(lap_trigger);
    layout->addWidget(light_tigger);
    layout->addWidget(reset_tigger);
    layout->addWidget(gas_input);
    layout->addWidget(enter_gas);

    connect(switch_menu, &QPushButton::clicked, backend, &BackEnd::SwitchMenuButton);
    connect(lap_trigger, &QPushButton::clicked, backend, &BackEnd::LapTrigger);
    connect(reset_tigger, &QPushButton::clicked, backend, &BackEnd::Reset);
    connect(light_tigger, &QPushButton::clicked, backend, &BackEnd::LightTrigger);
    connect(enter_gas, &QPushButton::clicked, this, &Debug::enterGas);
    connect(cruise_control_high, &QPushButton::clicked, backend, &BackEnd::CruiseControlUpButton);
    connect(cruise_control_low, &QPushButton::clicked, backend, &BackEnd::CruiseControlDownButton);
    connect(cruise_control_trigger, &QPushButton::clicked, backend, &BackEnd::CruiseControlTriggerButton);

    window->show();
}

void Debug::enterGas(){


    //LOOK HERE



    backend->GasPoti(gas_input->text().toUInt());
}
