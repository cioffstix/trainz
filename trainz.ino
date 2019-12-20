#include "pin_layout.h"
#include "idle_route.h"
#include "busy_route.h"
#include "Arduino.h"

namespace pin {
    // outputs
    const pin_id whistle = 0;

    const pin_id power_shift_data = 0;
    const pin_id power_shift_clock = 0;
    const pin_id power_shift_latch = 0;
    
    const pin_id back_left_switch_inner = 0;
    const pin_id back_left_switch_outter = 0;
    const pin_id back_right_switch_inner = 0;
    const pin_id back_right_switch_outter = 0;

    const pin_id front_left_switch_inner = 0;
    const pin_id front_left_switch_outter = 0;
    const pin_id front_right_switch_inner = 0;
    const pin_id front_right_switch_outter = 0;

    // inputs
    const pin_id red_button = 0;
    const pin_id blue_button = 0;
    const pin_id green_button = 0;

    const pin_id back_rail_sensor = 0;
    const pin_id front_rail_sensor = 0;
    const pin_id mid_back_rail_sensor = 0;
    const pin_id mid_front_rail_sensor = 0;
}


static pin_layout pins = {
    output_pin(pin::whistle),
    shift_register(pin::power_shift_data, pin::power_shift_clock, pin::power_shift_latch),
    track_switch(pin::back_left_switch_inner, pin::back_left_switch_outter),
    track_switch(pin::back_right_switch_inner, pin::back_right_switch_outter),
    track_switch(pin::front_left_switch_inner, pin::front_left_switch_outter),
    track_switch(pin::front_right_switch_inner, pin::front_right_switch_outter),
    input_pin(pin::red_button),
    input_pin(pin::blue_button),
    input_pin(pin::green_button),
    input_pin(pin::back_rail_sensor),
    input_pin(pin::front_rail_sensor),
    input_pin(pin::mid_back_rail_sensor),
    input_pin(pin::mid_front_rail_sensor),
};

idle_route rt_idle(pins);

route* routes[] = {
    nullptr,
    &rt_idle
};

route* active_route = nullptr;

void setup() {
    pins.whistle.init();
    
    pins.pwr_shift.init();
    
    pins.sw_back_left.init();
    pins.sw_back_right.init();
    pins.sw_front_left.init();
    pins.sw_front_right.init();

    pins.btn_red.init();
    pins.btn_blue.init();
    pins.btn_green.init();

    pins.snsr_back_rail.init();
    pins.snsr_front_rail.init();
    pins.snsr_mid_back_rail.init();
    pins.snsr_mid_front_rail.init();

    active_route = routes[1];
}

unsigned long lastMS = 0;
void loop() {
    auto ms = millis();
    auto dT = ms - lastMS;
    lastMS = ms;

    active_route->update(dT);
}
