#pragma once

#include "pin_layout.h"

enum class train_route {
    unknown,
    idle,
    j_inner,
    j_outter,
    n_inner,
    n_outter,
    n_j_inners
};

enum class route_status {
    unknown,
    starting,
    running,
    stopping,
    stopped,
    transitioning,
};

class route {
public:
    route(pin_layout const & pins) : pins_(pins) {}
    virtual ~route() {}
    virtual route_status update(unsigned long) = 0;
private:
    pin_layout pins_;
};
