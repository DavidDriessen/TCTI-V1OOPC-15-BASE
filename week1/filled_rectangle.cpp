// example:
// definition of the functions of a rectangle object

#include "filled_rectangle.hpp"

void filled_rectangle::print() {
    int xe = end_x, ye = end_y;
    int xdir = (start_x < xe) ? 1 : -1, ydir = (start_y < ye) ? 1 : -1;

    for (int ys = start_y; ys != ye; ys += ydir) {
        for (int xs = start_x; xs != xe; xs += xdir) {
            w.draw(xs, ys);
        }
    }
}

void filled_rectangle::printLinned() {
    int xe = end_x, ye = end_y;
    int dx = abs(xe - start_x), sx = start_x < xe ? 1 : -1;
    int dy = abs(ye - start_y), sy = start_y < ye ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2, e2 = 0;

    for (int ys = start_y; ys != ye; ys++) {
        for (int xs = start_x; xs != xe; xs++) {
            w.draw(xs, ys);
            e2 = err;
            if (e2 > -dx) {
                err -= dy;
                xs += sx;
            }
        }
        if (e2 < dy) {
            err += dx;
            ys += sy;
        }
    }
}