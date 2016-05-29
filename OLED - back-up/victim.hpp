//
// Created by david on 5/21/2016.
//

#ifndef INC_17_3_VERDWIJNEN_VICTIM_H
#define INC_17_3_VERDWIJNEN_VICTIM_H

#include "hwlib.hpp"
#include "rectangle.hpp"

class victim : public drawable{
    void drawLine(hwlib::location start, hwlib::location stop);
public:
    victim(hwlib::window & w, const hwlib::location &start, const hwlib::location &end);
    void draw() override ;
    void interact(drawable &other) override;

};


#endif //INC_17_3_VERDWIJNEN_VICTIM_H
