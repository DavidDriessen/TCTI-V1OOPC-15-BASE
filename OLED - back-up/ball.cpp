#include "ball.hpp"
#include <iostream>

void ball::update() {
    location.x += speed.x;
    location.y += speed.y;
}

ball::ball(hwlib::window & w, const hwlib::location &midpoint, int radius, hwlib::location speed) :
        circle(w, midpoint, radius),
        speed(speed) { }

void ball::interact(drawable &other) {
    if (this != &other) {
        if (overlaps(other)) {
            speed.x *= other.bounce.x;
            speed.y *= other.bounce.y;
        }
    }
}