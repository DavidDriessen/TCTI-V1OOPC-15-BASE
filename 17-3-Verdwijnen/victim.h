//
// Created by david on 5/21/2016.
//

#ifndef INC_17_3_VERDWIJNEN_VICTIM_H
#define INC_17_3_VERDWIJNEN_VICTIM_H

#include "window.hpp"
#include "rectangle.hpp"

class victim : public drawable{
    void drawLine(vector start, vector stop);
public:
    victim(window &w, const vector &start, const vector &end);
    void draw() override ;
    void interact(drawable &other) override;

};


#endif //INC_17_3_VERDWIJNEN_VICTIM_H
