#include <avr/io.h>
#include <util/delay.h>
#define USART_BAUDRATE 9600
#define UBRR_VALUE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

void USART0Init(void);
uint8_t USART0ReceiveByte();

uint8_t incomingByte;


int main (void)
{
    /* set pins 0-3 of PORTB for output*/
    DDRB = 0b00001111;

    //Initialize USART0
    USART0Init();

    while(1) {
        // Receive data
        incomingByte = USART0ReceiveByte();

		/* stop */
        if (incomingByte == '0')
            PORTB = 0b00000000;

		/* move forward */
        else if (incomingByte == '1')
            PORTB = 0b00000101;

		/* move backward */
		else if (incomingByte == '2')
			PORTB = 0b00001010;

		/* turn right */
		else if (incomingByte == '3')
			PORTB = 0b00000100;

		/* turn left */
		else if (incomingByte == '4')
			PORTB = 0b00000001;
    }
}


void USART0Init(void)
{
    // Set baud rate
    UBRR0H = (uint8_t)(UBRR_VALUE>>8);
    UBRR0L = (uint8_t)UBRR_VALUE;
    // Set frame format to 8 data bits, no parity, 1 stop bit
    UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00);
    //enable reception
    UCSR0B |= (1<<RXEN0);
}

uint8_t USART0ReceiveByte()
{
    // Wait for byte to be received
    while(!(UCSR0A&(1<<RXC0))){};
    // Return received data
    return UDR0;
}
