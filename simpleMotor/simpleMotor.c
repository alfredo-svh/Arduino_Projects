#include <avr/io.h>
#include <util/delay.h>

int main (void)
{
    /* set pins 0-3 of PORTB for output */
    DDRB = 0b00001111;

    while(1) {

		/* both motors forward for 2 seconds */
        PORTB = 0b00000101;
        _delay_ms(2000);
    
		/* both motors stop for 2 seconds */
        PORTB = 0b00000000;
        _delay_ms(2000);

		/* both motors backward for 2 seconds */
        PORTB = 0b00001010;
        _delay_ms(2000);

		/* both motors stop for 2 seconds */
        PORTB = 0b00000000;
        _delay_ms(2000);

    }
}
