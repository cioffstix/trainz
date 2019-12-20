#pragma once

#include "pin.h"

class input_pin {
public:
    input_pin(pin_id);

    void init();

    pin_state update();
private:
    pin_id pin_;
    pin_state state_;
};