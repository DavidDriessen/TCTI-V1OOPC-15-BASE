#include "../hwlib/hwlib-due.hpp"
#include "hwlib.hpp"

struct HC
{
    hwlib::target::pin_out dc;
    hwlib::target::pin_out stcp;
    hwlib::target::pin_out shcp;
    hwlib::target::pin_in miso;
    hwlib::spi_bus_bit_banged_sclk_mosi_miso SPI;
    hwlib::hc595 Reg;

    HC() :
            dc(hwlib::target::pins::d2),
            stcp(hwlib::target::pins::d3),
            shcp(hwlib::target::pins::d4),
            miso(hwlib::target::pins::d5),
            SPI(shcp, dc, miso),
            Reg(SPI, stcp){ }
};

void kitt(hwlib::hc595 &reg, int ms = 80) {
    for (; ;) {
        for (unsigned int i = 0; i < 8; ++i) {
            reg.set(0x01 << i);
            hwlib::wait_ms(ms);
        }
        for (unsigned int i = 0; i < 8; ++i) {
            reg.set(0x80 >> i);
            hwlib::wait_ms(ms);
        }
    }
}

int main(void) {
    HC spi;

    ::kitt(spi.Reg);
}

