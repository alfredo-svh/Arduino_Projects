#include <avr/io.h>
#include <util/delay.h>
 
#define BLINK_DELAY_MS 500
 
int main (void)
{
	/* set pin 5 of PORTB for output*/
	DDRB = 0b00100000;

	while(1) {
		/* set pin 5 high to turn led on */
		PORTB = 0b00100000;
		_delay_ms(BLINK_DELAY_MS);
			   
		/* set pin 5 low to turn led off */
		PORTB = 0b00000000;
		_delay_ms(BLINK_DELAY_MS);
	}
}
