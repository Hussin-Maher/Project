#include "pwm.h"
#include "common_macros.h"
#include "gpio.h"
#include "avr/io.h" /* To use the IO Ports Registers */
void PWM_Timer0_Start(uint8 duty_cycle) {
	TCNT0 = 0;
	GPIO_setupPinDirection(PWM_PORT_ID, PWM_PIN_ID, PIN_OUTPUT);
	TCCR0 = (1 << WGM00) | (1 << COM01) | (1 << CS01) | (1 << WGM01);
	OCR0 = ((255) * (duty_cycle / 100));
}
