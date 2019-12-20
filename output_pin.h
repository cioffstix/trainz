#pragma once

#include "pin.h"

class output_pin {
public:
    output_pin(pin_id);

    void init();

    void turn_on();
    void turn_off();
private:
    int pin_;
};
