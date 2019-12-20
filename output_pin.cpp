#include "output_pin.h"
#include "Arduino.h"

output_pin::output_pin(pin_id pin) : pin_(pin) {
}

void output_pin::init() {
    pinMode(pin_, OUTPUT);
    digitalWrite(pin_, 0);
}

void output_pin::turn_on() {
    digitalWrite(pin_, HIGH);
}

void output_pin::turn_off() {
    digitalWrite(pin_, LOW);
}