#include "adc.h"
#include "gpio.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include "avr/io.h"

void ADC_init(const ADC_ConfigType *Config_Ptr) {
	ADMUX = 0;
	ADCSRA = (1 << ADEN);
	switch (Config_Ptr->prescaler) {
	case (0):
		break;
	case (1):
		ADCSRA |= (1 << ADPS0);
		break;
	case (2):
		ADCSRA |= (1 << ADPS1);
		break;
	case (3):
		ADCSRA |= (1 << ADPS1) | (1 << ADPS0);
		break;
	case (4):
		ADCSRA |= (1 << ADPS2);
		break;
	case (5):
		ADCSRA |= (1 << ADPS0) | (1 << ADPS2);
		break;
	case (6):
		ADCSRA |= (1 << ADPS2) | (1 << ADPS1);
		break;
	case (7):
		ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
		break;
	}
	switch (Config_Ptr->ref_volt) {
	case 0:
		break;
	case (1):
		ADMUX |= (1 << REFS0);
		break;
	case (2):
		break;
	case (3):
		ADMUX |= (1 << REFS0) | (1 << REFS1);
		break;
	}
}
uint16 ADC_readChannel(uint8 channel_num) {
	channel_num &= 0x07;
	ADMUX &= 0xE0;
	ADMUX |= channel_num;
	SET_BIT(ADCSRA, ADSC);
	while (BIT_IS_CLEAR(ADCSRA, ADIF))
		;
	SET_BIT(ADCSRA, ADIF);
	return ADC;
}
