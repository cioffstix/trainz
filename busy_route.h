#pragma once

#include "route.h"

class busy_route : public route {
public:
    busy_route(pin_layout const &);
};