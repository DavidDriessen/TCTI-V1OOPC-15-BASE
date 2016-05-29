#include "../hwlib/hwlib-due.hpp"
#include "hwlib.hpp"
#include "wall.hpp"
#include "ball.hpp"
#include "victim.hpp"

int main() {
    auto scl = hwlib::target::pin_oc(hwlib::target::pins::scl);
    auto sda = hwlib::target::pin_oc(hwlib::target::pins::sda);
    hwlib::i2c_bus_bit_banged_scl_sda i2c(scl,sda);
    hwlib::glcd_oled screen(i2c);
    screen.clear();

    wall top(screen, hwlib::location(0, 0), hwlib::location(127, 4), hwlib::location(1,-1), true);
    wall right(screen, hwlib::location(123, 0), hwlib::location(127, 63), hwlib::location(-1,1), true);
    wall bottom(screen, hwlib::location(0, 59), hwlib::location(127, 63), hwlib::location(1,-1), true);
    wall left(screen, hwlib::location(0, 0), hwlib::location(4, 63), hwlib::location(-1,1), true);
    ball b(screen, hwlib::location(50, 20), 9, hwlib::location(5, 2));
    victim man(screen, hwlib::location(50, 40), hwlib::location(60, 58));

    drawable *objects[] = {&b, &top, &left, &right, &bottom, &man};

    for (; ;) {
        screen.clear();
        for (auto &p : objects) {
            p->draw();
        }
        hwlib::wait_ms(200);
        for (auto &p : objects) {
            p->update();
        }
        for (auto &p : objects) {
            for (auto &other : objects) {
                p->interact(*other);
            }
        }
    }
}

