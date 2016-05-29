//
// Created by david on 5/21/2016.
//

#ifndef INC_17_1_DIKKERE_MUREN_WALL_H
#define INC_17_1_DIKKERE_MUREN_WALL_H

#include "hwlib.hpp"
#include "rectangle.hpp"

class wall : public rectangle {
    hwlib::location start;
    hwlib::location end;
    bool filled;
    bool toggle;
public:
    wall(hwlib::window & w, const hwlib::location &start, const hwlib::location &end, hwlib::location bounce, bool filled, bool toggle = false);

    void draw();

    void update();
};


#endif //INC_17_1_DIKKERE_MUREN_WALL_H
