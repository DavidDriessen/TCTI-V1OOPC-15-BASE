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
    wall(hwlib::window &w, const hwlib::location &start, const hwlib::location &end, hwlib::location bounce,
         bool filled, bool toggle = false) :
            rectangle(w, start, end, bounce),
            start(start),
            end(end),
            filled(filled),
            toggle(toggle) {

    }


    void draw() {
        rectangle::draw();
        if (filled) {
            for (hwlib::location temp = start; temp.y < end.y; temp.y++) {
                temp.x = start.x;
                for (; temp.x < end.x; temp.x++) {
                    w.write(temp);
                }
            }
        }
    }

    void update() {
        if (toggle) {
            filled = !filled;
        }
    }
};


#endif //INC_17_1_DIKKERE_MUREN_WALL_H
