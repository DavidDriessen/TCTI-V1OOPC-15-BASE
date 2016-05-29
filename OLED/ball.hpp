#ifndef BALL_HPP
#define BALL_HPP

#include "hwlib.hpp"
#include "circle.hpp"

class ball : public circle {
private:
    hwlib::location speed;
public:
    ball(hwlib::window &w, const hwlib::location &midpoint, int radius, hwlib::location speed) :
            circle(w, midpoint, radius),
            speed(speed) { }

    void update() override {
        location.x += speed.x;
        location.y += speed.y;
    }

    void interact(drawable &other) override {
        if (this != &other) {
            if (overlaps(other)) {
                speed.x *= other.bounce.x;
                speed.y *= other.bounce.y;
            }
        }
    }
};

#endif // BALL_HPP
