//
// Created by david on 4/14/2016.
//

#ifndef INC_06_TEMPLATE_GRAFIEK_H
#define INC_06_TEMPLATE_GRAFIEK_H

#include "window.hpp"
#include "rectangle.hpp"

class grafiek {
private:
    int xStart, yStart, width, height;
    window w;
    rectangle rand;
public:
    grafiek(window &w, int xStart, int yStart, int with, int height) :
            rand(w, xStart, yStart, (xStart + width), (yStart + height)),
            xStart(xStart),
            yStart(yStart),
            width(with),
            height(height),
            w(w) { }

    void print(int size, int *lines);

};


#endif //INC_06_TEMPLATE_GRAFIEK_H
