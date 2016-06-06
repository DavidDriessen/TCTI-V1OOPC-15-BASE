#include "hwlib.hpp"


struct HC {
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
		Reg(SPI, stcp) { }
};

int main()
{
	HC chip;

	hwlib::target::pin_out led1 = hwlib::target::pin_out(hwlib::target::pins::d47);
	hwlib::target::pin_out led2 = hwlib::target::pin_out(hwlib::target::pins::d49);
	hwlib::target::pin_out led3 = hwlib::target::pin_out(hwlib::target::pins::d51);
	hwlib::target::pin_out led4 = hwlib::target::pin_out(hwlib::target::pins::d53);

	hwlib::target::pin_in btn1 = hwlib::target::pin_in(hwlib::target::pins::d22);
	hwlib::target::pin_in btn2 = hwlib::target::pin_in(hwlib::target::pins::d24);

	byte leds = 0b00000000;
	byte last = leds;
	bool err = false;

	while(1) {
		if(leds != last) {
			led1.set(((leds & 0b0001)?1:0));
			led2.set(((leds & 0b0010)?1:0));
			led3.set(((leds & 0b0100)?1:0));
			led4.set(((leds & 0b1000)?1:0));
			chip.Reg.set(leds & 0b11110000);
			last = leds;
		}

		if(btn1.get() && !err) {
			leds = leds << 1;
			leds = leds + 0b0001;
			err = true;
			hwlib::wait_ms(80);
		} else if(btn2.get() && !err) {
			leds = leds >> 1;
			err = true;
			hwlib::wait_ms(80);
		} else if(!btn1.get() && !btn1.get() && err) {
			err = false;
			hwlib::wait_ms(80);
		}
	}
}
