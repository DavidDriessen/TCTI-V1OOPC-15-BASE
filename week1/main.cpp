#include "window.hpp"
#include "grafiek.hpp"

int main(int argc, char **argv) {
    window w(228, 264, 2);

    int g[4] = {30, 50, 60, 20};

    grafiek grafiek1(w, 20, 10, 100, 100);
    grafiek1.print(4, g);

    return 0;
}
