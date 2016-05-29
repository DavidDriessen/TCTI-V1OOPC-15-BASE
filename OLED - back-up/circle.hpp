#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "hwlib.hpp"

#include "drawable.hpp"

class circle : public drawable {
protected:
   int radius;
public:
   circle( hwlib::window & w, const hwlib::location & midpoint, int radius ):
      drawable( w, midpoint - hwlib::location( radius, radius ), hwlib::location( radius, radius ) * 2 ),
      radius( radius )
   {}
   void draw() override;
};

#endif // CIRCLE_HPP
