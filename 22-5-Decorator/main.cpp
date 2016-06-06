#include "hwlib.hpp"

class pin_out_all : public hwlib::pin_out
{
private:
	hwlib::pin_out * list[ 4 ];

public:

	pin_out_all(
	    hwlib::pin_out & p0,
	    hwlib::pin_out & p1 = hwlib::pin_out_dummy,
	    hwlib::pin_out & p2 = hwlib::pin_out_dummy,
	    hwlib::pin_out & p3 = hwlib::pin_out_dummy
	):
		list { &p0, &p1, &p2, &p3 }
	{}

	void set( bool v ) {
		for( auto p  : list ) {
			p->set( v );
		}
	}
};

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

class pin_out_invert : public hwlib::pin_out
{
	hwlib::pin_out &pin;
public:
	pin_out_invert(hwlib::pin_out &pin):pin(pin) {}
	void set(bool v) {
		pin.set(!v);
	}
};

int main()
{
	HC chip;

	hwlib::target::pin_out led1 = hwlib::target::pin_out(hwlib::target::pins::d47);
	hwlib::target::pin_out led2 = hwlib::target::pin_out(hwlib::target::pins::d49);
	hwlib::target::pin_out led3 = hwlib::target::pin_out(hwlib::target::pins::d51);
	hwlib::target::pin_out led4 = hwlib::target::pin_out(hwlib::target::pins::d53);

	pin_out_all leds1 = pin_out_all(led1,led2,led3,led4);
	pin_out_all leds2 = pin_out_all(chip.Reg.p4,chip.Reg.p5,chip.Reg.p6,chip.Reg.p7);

	pin_out_invert ledsinv1 = pin_out_invert(leds1);
	pin_out_invert ledsinv2 = pin_out_invert(leds2);
	
	hwlib::port_out_from_pins k(ledsinv1, ledsinv2);

	hwlib::kitt(k);
}
