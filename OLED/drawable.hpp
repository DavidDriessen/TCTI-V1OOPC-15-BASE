#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <ostream>
#include "hwlib.hpp"


class drawable {

    bool within(int x, int a, int b) {
        return (x >= a) && (x <= b);
    }

protected:
    hwlib::window &w;
    hwlib::location location;
    hwlib::location size;
public:
    hwlib::location bounce;

    drawable(hwlib::window &w, const hwlib::location &location, const hwlib::location &size,
             hwlib::location bounce = hwlib::location(1, 1)) :
            w(w),
            location(location),
            size(size),
            bounce(bounce) { }

    bool overlaps(const drawable &other) {

        bool x_overlap = within(
                location.x,
                other.location.x,
                other.location.x + other.size.x
        ) || within(
                other.location.x,
                location.x,
                location.x + size.x
        );

        bool y_overlap = within(
                location.y,
                other.location.y,
                other.location.y + other.size.y
        ) || within(
                other.location.y,
                location.y,
                location.y + size.y
        );

        return x_overlap && y_overlap;
    }

    virtual void draw() = 0;

    virtual void update() { }

    virtual void interact(drawable &other) { }

    hwlib::ostream &print(hwlib::ostream &out) const {
        return out << location << location + size;
    }
};

hwlib::ostream &operator<<(hwlib::ostream &lhs, const drawable &rhs) {
    return rhs.print(lhs);
}


#endif // DRAWABLE_HPP
