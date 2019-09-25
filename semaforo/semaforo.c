#include <avr/io.h>
#include <util/delay.h>
 
#define DELAY_BIG 10000
#define DELAY_MED 6000
#define DELAY_SMALL 2000
#define DELAY_BLINK 200
 
int main (void)
{
    /* set pins 0-6 of PORTB for output */
    DDRB = 0b00111111;

	int i;

    while(1) {
        /* green traffic light and red crossing light on */
        PORTB = 0b00110001;
        _delay_ms(DELAY_BIG);
    
        /* yellow traffic light on */
        PORTB = 0b00110010;
        _delay_ms(DELAY_SMALL);

		/* red traffic light on */
		PORTB = 0b00110100;
		_delay_ms(DELAY_SMALL);

		/* green crossing light on */
		PORTB = 0b00101100;
		_delay_ms(DELAY_MED);

		/* crossing light flashes red */
		for(i=0;i<5;i++){
			PORTB = 0b00110100;
			_delay_ms(DELAY_BLINK);
			PORTB = 0b00000100;
			_delay_ms(DELAY_BLINK);
		}

	}
}
