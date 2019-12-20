#pragma once

#include "input_pin.h"
#include "output_pin.h"
#include "track_switch.h"
#include "shift_register.h"

struct pin_layout {
    output_pin whistle;
    
    shift_register pwr_shift;
    
    track_switch sw_back_left;
    track_switch sw_back_right;
    track_switch sw_front_left;
    track_switch sw_front_right;

    input_pin btn_red;
    input_pin btn_blue;
    input_pin btn_green;

    input_pin snsr_back_rail;
    input_pin snsr_front_rail;
    input_pin snsr_mid_back_rail;
    input_pin snsr_mid_front_rail;
};