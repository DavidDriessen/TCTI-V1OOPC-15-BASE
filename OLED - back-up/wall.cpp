//
// Created by david on 5/21/2016.
//

#include "wall.hpp"

wall::wall(hwlib::window & w, const hwlib::location &start, const hwlib::location &end, hwlib::location bounce, bool filled, bool toggle) :
        rectangle(w, start, end, bounce),
        start(start),
        end(end),
        filled(filled),
        toggle(toggle){

}

void wall::draw() {
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

void wall::update() {
    if(toggle){
        filled = !filled;
    }
}





