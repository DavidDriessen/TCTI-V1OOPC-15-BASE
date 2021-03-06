//
// Created by david on 5/21/2016.
//

#include "wall.hpp"

wall::wall(window &w, const vector &start, const vector &end, bool filled, bool toggle) :
        rectangle(w, start, end),
        start(start),
        end(end),
        filled(filled),
        toggle(toggle){

}

void wall::draw() {
    rectangle::draw();

    if (filled) {
        for (vector temp = start; temp.y < end.y; temp.y++) {
            temp.x = start.x;
            for (; temp.x < end.x; temp.x++) {
                w.draw(temp);
            }
        }
    }
}

void wall::update() {
    if(toggle){
        filled = !filled;
    }
}





