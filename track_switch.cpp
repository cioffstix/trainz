#include "track_switch.h"
#include "Arduino.h"

// track_switch definition
track_switch::track_switch(pin_id inner_pin, pin_id outter_pin) : 
    inner_(inner_pin),
    outter_(outter_pin)
{
}

void track_switch::init() {
}

void track_switch::inner() {
}
void track_switch::outter() {
}
