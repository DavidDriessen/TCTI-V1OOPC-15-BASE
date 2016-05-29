// example:
// definition of the functions of a rectangle object

#include "rectangle.hpp"

rectangle::rectangle(hwlib::window & w, const hwlib::location &start, const hwlib::location &end, hwlib::location bounce) :
        drawable(w, start, end - start, bounce),
        end(end),
        left(w, hwlib::location(start.x, start.y), hwlib::location(start.x, end.y)),
        right(w, hwlib::location(end.x, start.y), hwlib::location(end.x, end.y)),
        top(w, hwlib::location(start.x, start.y), hwlib::location(end.x, start.y)),
        bottom(w, hwlib::location(start.x, end.y), hwlib::location(end.x, end.y)) { }

void rectangle::draw() {
    left.draw();
    right.draw();
    top.draw();
    bottom.draw();
}

