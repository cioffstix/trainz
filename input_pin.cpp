#include "input_pin.h"
#include "Arduino.h"

input_pin::input_pin(pin_id pid) : pin_(pid), state_(pin_state::unknown) {
}

void input_pin::init() {
    pinMode(pin_, INPUT);
    state_ = pin_state(digitalRead(pin_));
}

pin_state input_pin::update() {
    auto cv = pin_state(digitalRead(pin_));
    if (cv != state_) {
        auto ncv = pin_state(int(cv)+2);
        if (ncv == state_) {
            state_ = cv;
        } else {
            state_ = ncv;
        }
    }
    return state_;
}
