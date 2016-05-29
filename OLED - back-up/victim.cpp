//
// Created by david on 5/21/2016.
//

#include "victim.hpp"
#include "stdlib.h"

victim::victim(hwlib::window & w, const hwlib::location &start, const hwlib::location &end) :
        drawable(w, start, end - start, hwlib::location(-1, -1)) { }

void victim::interact(drawable &other) {
    if (this != &other) {
        if (overlaps(other)) {
            location.x+=1;
            location.y+=1;
            size.x-=2;
            size.y-=2;

        }
    }
}

void victim::draw() {
    hwlib::location x = hwlib::location(size.x, 0);
    hwlib::location y = hwlib::location(0, size.y);
    drawLine(location, location + x);
    drawLine(location, location + y);
    drawLine(location + x, location + size);
    drawLine(location + y, location + size);

}

void victim::drawLine(hwlib::location start, hwlib::location stop) {
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











