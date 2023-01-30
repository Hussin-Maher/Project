#include "Lm35_sensor.h"
#include "adc.h"
#include "std_types.h"
#include "common_macros.h"

uint8 LM35_GetTempreture() {
	uint8 temp_value=0;
	uint16 adc_value=0;
	adc_value= ADC_readChannel(Lm35_sensor_channel_num);
	temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));
	return temp_value;
}
