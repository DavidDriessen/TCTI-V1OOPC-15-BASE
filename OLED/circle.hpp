#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "hwlib.hpp"

#include "drawable.hpp"

class circle : public drawable {
protected:
    int radius;
public:
    circle(hwlib::window &w, const hwlib::location &midpoint, int radius) :
            drawable(w, midpoint - hwlib::location(radius, radius), hwlib::location(radius, radius) * 2),
            radius(radius) { }

    void draw() override {

        // don't draw anything when the size would be 0
        if (radius < 1) {
            return;
        }

        // http://en.wikipedia.org/wiki/Midpoint_circle_algorithm

        int fx = 1 - radius;
        int ddFx = 1;
        int ddFy = -2 * radius;
        int x = 0;
        int y = radius;
        hwlib::location midpoint = location + hwlib::location(radius, radius);

        // top and bottom
        w.write(hwlib::location(midpoint.x + 0, midpoint.y + radius));
        w.write(hwlib::location(midpoint.x + 0, midpoint.y - radius));

        // left and right
        w.write(hwlib::location(midpoint.x + radius, midpoint.y + 0));
        w.write(hwlib::location(midpoint.x + radius, midpoint.y - 0));

        while (x < y) {

            // calculate next outer circle point
            if (fx >= 0) {
                y--;
                ddFy += 2;
                fx += ddFy;
            }
            x++;
            ddFx += 2;
            fx += ddFx;

            w.write(hwlib::location(midpoint.x + x, midpoint.y + y));
            w.write(hwlib::location(midpoint.x - x, midpoint.y + y));
            w.write(hwlib::location(midpoint.x + x, midpoint.y - y));
            w.write(hwlib::location(midpoint.x - x, midpoint.y - y));
            w.write(hwlib::location(midpoint.x + y, midpoint.y + x));
            w.write(hwlib::location(midpoint.x - y, midpoint.y + x));
            w.write(hwlib::location(midpoint.x + y, midpoint.y - x));
            w.write(hwlib::location(midpoint.x - y, midpoint.y - x));
        }
    }
};

#endif // CIRCLE_HPP
