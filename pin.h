#pragma once

using pin_id = int;

enum class pin_state {
    unknown = -1,
    still_low,
    still_high,
    newly_low,
    newly_high
};
