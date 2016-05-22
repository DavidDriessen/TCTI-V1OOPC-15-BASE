//
// Created by david on 5/21/2016.
//

#ifndef INC_17_1_DIKKERE_MUREN_WALL_H
#define INC_17_1_DIKKERE_MUREN_WALL_H

#include "window.hpp"
#include "rectangle.hpp"

class wall : public rectangle {
    bool filled;
    bool toggle;
    vector start;
    vector end;
public:
    wall(window &w, const vector &start, const vector &end, vector bounce, bool filled, bool toggle = false);

    void draw();

    void update();
};


#endif //INC_17_1_DIKKERE_MUREN_WALL_H
