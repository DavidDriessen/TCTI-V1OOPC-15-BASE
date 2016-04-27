//
// Created by david on 4/14/2016.
//

#include "grafiek.hpp"
#include "filled_rectangle.hpp"

void grafiek::print(int size, int *lines) {

    if ((size * 2) > width) {
        return;
    }

    for (int i = 0; i < size; i++) {
        if (lines[i] > height) { return; }
    }

    filled_rectangle *pillar[size];

    rand.print();
    for (int i = 0; i < size; i++) {
        pillar[i] = new filled_rectangle(w,
                                         (xStart + ((width / size) * i) + (width / size / 2)),
                                         (yStart + height),
                                         (xStart + (width / size) * (i + 1)),
                                         (yStart + height - lines[i]));
        pillar[i]->print();
    }

}

