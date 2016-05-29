#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <ostream>
#include "hwlib.hpp"


class drawable {
protected:
    hwlib::window & w;
    hwlib::location location;
    hwlib::location size;
public:
    hwlib::location bounce;

    drawable(hwlib::window & w, const hwlib::location &location, const hwlib::location &size, hwlib::location bounce = hwlib::location(1, 1));

    bool overlaps(const drawable &other);

    virtual void draw() = 0;

    virtual void update() { }

    virtual void interact(drawable &other) { }

    hwlib::ostream &print(hwlib::ostream &out) const;
};

hwlib::ostream &operator<<(hwlib::ostream &lhs, const drawable &rhs);

#endif // DRAWABLE_HPP
