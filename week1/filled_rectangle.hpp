// example:
// declaration of a rectangle object that is contains four line objects

#ifndef FILLED_RECTANGLE_HPP
#define FILLED_RECTANGLE_HPP

#include "window.hpp"

class filled_rectangle {
private:
    int start_x;
    int start_y;
    int end_x;
    int end_y;
    window &w;
public:
    filled_rectangle(window &w, int start_x, int start_y, int end_x, int end_y) :
            start_x(start_x),
            start_y(start_y),
            end_x(end_x),
            end_y(end_y),
            w(w) { }

    void print();
    void printLinned();
};


#endif // FILLED_RECTANGLE_HPP
