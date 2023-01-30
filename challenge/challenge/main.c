#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
unsigned char counter = 0;
unsigned char ticks = 0;
ISR(TIMER0_OVF_vect) {
	ticks++;
	if(ticks==123)
	{
		counter++;
		TIFR |= (1 << TOV0);
		ticks=0;
	}
}
void Timer0_init() {
	TCCR0 |= (1 << CS02) | (1 << FOC0);
	TCNT0 = 0x00;
	TIMSK |= (1 << TOIE0);
}
void main() {
	Timer0_init();
	SREG |= (1 << 7);
	DDRC |= (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3);
	PORTC = 0x00;
	while (1) {
		if (counter == 10) {
			PORTC = (PORTC & 0xF0) | (counter & 0x0f);
			counter = 0;
		} else {
			PORTC = (PORTC & 0xF0) | (counter & 0x0f);
		}
	}
}
