#include "idle_route.h"

idle_route::idle_route(pin_layout const & pins) : route(pins) {}

route_status idle_route::update(unsigned long) {
    return route_status::stopped;
}