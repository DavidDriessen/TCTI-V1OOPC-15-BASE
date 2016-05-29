#ifndef LINE_HPP
#define LINE_HPP

#include "hwlib.hpp"

#include "drawable.hpp"

class line : public drawable {
public:
    hwlib::location end;
   line( hwlib::window & w, const hwlib::location & location, const hwlib::location & end ):
      drawable( w, location, end - location ),
      end( end )
   {}
   void draw() override;
};

#endif // LINE_HPP
