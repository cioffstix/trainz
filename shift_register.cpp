#include "shift_register.h"
#include "Arduino.h"

shift_register::shift_register(pin_id data, pin_id clock, pin_id latch) :
    data_(data), clock_(clock), latch_(latch)
{
}

void shift_register::init() {
    data_.turn_off();
    clock_.turn_off();
    latch_.turn_off();
}

void shift_register::set(uint8_t val) {
    for (int i = 0; i < 8; i++) {
        (val&(1<<i))?data_.turn_on():data_.turn_off();
        clock_.turn_on();
        clock_.turn_off();
    }
    latch_.turn_on();
    data_.turn_off();
    latch_.turn_off();
}
