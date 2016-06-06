#include "hwlib.hpp"

int main()
{
	hwlib::target::pin_out led1 = hwlib::target::pin_out(hwlib::target::pins::d47);
	hwlib::target::pin_out led2 = hwlib::target::pin_out(hwlib::target::pins::d49);
	hwlib::target::pin_out led3 = hwlib::target::pin_out(hwlib::target::pins::d51);
	hwlib::target::pin_out led4 = hwlib::target::pin_out(hwlib::target::pins::d53);

	bool direction = 0;
	byte leds = 0b0011;

	while(1) {
		led1.set(((leds & 0b0001)?1:0));
		led2.set(((leds & 0b0010)?1:0));
		led3.set(((leds & 0b0100)?1:0));
		led4.set(((leds & 0b1000)?1:0));

		if(direction) {
			leds = leds >> 1;
		} else {
			leds = leds << 1;
		}
		if(leds == 0b0011) {
			direction = 0;
		} else if(leds == 0b1100) {
			direction = 1;
		}
		hwlib::wait_ms(80);
	}
}
