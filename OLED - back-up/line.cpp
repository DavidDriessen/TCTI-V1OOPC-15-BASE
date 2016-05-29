// example:
// definition of the functions of a line class 
// you are not expected to understand how line::print works

#include "line.hpp"
#include "stdlib.h"

void line::draw() {
    hwlib::location start = location;
    hwlib::location stop = end;
    int dx = abs(stop.x - start.x), sx = start.x < stop.x ? 1 : -1;
    int dy = abs(stop.y - start.y), sy = start.y < stop.y ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2, e2;

    for (; ;) {
        w.write(start);
        if (start == stop) break;
        e2 = err;
        if (e2 > -dx) {
            err -= dy;
            start.x += sx;
        }
        if (e2 < dy) {
            err += dx;
            start.y += sy;
        }
    }
}
