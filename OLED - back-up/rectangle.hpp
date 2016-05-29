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
    rectangle(hwlib::window & w, const hwlib::location &start, const hwlib::location &end, hwlib::location bounce = hwlib::location(-1, -1));

    void draw() override;
};


#endif // RECTANGLE_HPP
