#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"
#include "common_macros.h"

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   5

typedef struct {
	uint8 ref_volt;
	uint8 prescaler;
} ADC_ConfigType;

void ADC_init(const ADC_ConfigType *Config_Ptr);
uint16 ADC_readChannel(uint8 channel_num);

#endif
