#include "output_pin.h"
#include <stdint.h>

class shift_register {
public:
    shift_register(pin_id, pin_id, pin_id);

    void init();

    void set(uint8_t);
private:
    output_pin data_;
    output_pin clock_;
    output_pin latch_;
};
