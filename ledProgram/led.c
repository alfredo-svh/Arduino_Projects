#include <avr/io.h>
#include <util/delay.h>
#define USART_BAUDRATE 9600
#define UBRR_VALUE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)
#define BLINK_DELAY_MS 500

void USART0Init(void);
uint8_t USART0ReceiveByte();

uint8_t incomingByte;


int main (void)
{
	/* set pin 5 of PORTB for output*/
	DDRB |= _BV(DDB5);

    //Initialize USART0
    USART0Init();

	while(1) {
        // Receive data
        incomingByte = USART0ReceiveByte();

		if (incomingByte == '1')
			PORTB = 0b00100000;
		else if (incomingByte == '0')
			PORTB = 0b00000000;
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
