// example:
// declaration of a rectangle object that is contains four line objects

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "hwlib.hpp"
#include "drawable.hpp"

#include "line.hpp"

class rectangle : public drawable {
protected:
    hwlib::location end;
    line left;
    line right;
    line top;
    line bottom;
public:
    rectangle(hwlib::window &w, const hwlib::location &start, const hwlib::location &end,
              hwlib::location bounce = hwlib::location(-1, -1)) :
            drawable(w, start, end - start, bounce),
            end(end),
            left(w, hwlib::location(start.x, start.y), hwlib::location(start.x, end.y)),
            right(w, hwlib::location(end.x, start.y), hwlib::location(end.x, end.y)),
            top(w, hwlib::location(start.x, start.y), hwlib::location(end.x, start.y)),
            bottom(w, hwlib::location(start.x, end.y), hwlib::location(end.x, end.y)) { }

    void draw() override {
        left.draw();
        right.draw();
        top.draw();
        bottom.draw();
    }
};


#endif // RECTANGLE_HPP
