#include "hwlib.hpp"

int main()
{
	hwlib::target::pin_out led1 = hwlib::target::pin_out(hwlib::target::pins::d47);
	hwlib::target::pin_out led2 = hwlib::target::pin_out(hwlib::target::pins::d49);
	hwlib::target::pin_out led3 = hwlib::target::pin_out(hwlib::target::pins::d51);
	hwlib::target::pin_out led4 = hwlib::target::pin_out(hwlib::target::pins::d53);

	hwlib::target::pin_in btn1 = hwlib::target::pin_in(hwlib::target::pins::d22);
	hwlib::target::pin_in btn2 = hwlib::target::pin_in(hwlib::target::pins::d24);

	byte leds = 0b0000;
	bool err = false;

	while(1) {
		led1.set(((leds & 0b0001)?1:0));
		led2.set(((leds & 0b0010)?1:0));
		led3.set(((leds & 0b0100)?1:0));
		led4.set(((leds & 0b1000)?1:0));

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
