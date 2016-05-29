#ifndef BALL_HPP
#define BALL_HPP

#include "hwlib.hpp"

#include "circle.hpp"

class ball : public circle {
private:
   hwlib::location speed;
public:
   ball( hwlib::window & w, const hwlib::location & midpoint, int radius, hwlib::location speed );
   void update() override;
   void interact( drawable & other ) override;
};

#endif // BALL_HPP
