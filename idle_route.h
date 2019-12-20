#pragma once

#include "route.h"

class idle_route : public route {
public:
    idle_route(pin_layout const &);
    route_status update(unsigned long);
};