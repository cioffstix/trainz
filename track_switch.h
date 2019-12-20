#pragma once

#include "output_pin.h"

class track_switch {
public:
    track_switch(pin_id, pin_id);

    void init();

    void inner();
    void outter();
private:
    output_pin inner_;
    output_pin outter_;
};
