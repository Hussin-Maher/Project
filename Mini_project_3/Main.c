#include <avr/io.h>
#include "lcd.h"
#include "Lm35_sensor.h"
#include "common_macros.h"
#include "std_types.h"
#include "adc.h"
#include "dc_motor.h"
int main() {
	DcMotor_Init();
	uint8 temp = 0;
	ADC_ConfigType Temp_config;
	Temp_config.ref_volt = 2;
	Temp_config.prescaler = 3;
	ADC_init(&Temp_config);
	LCD_init();
	DcMotor_Init();
	LCD_displayString("fan is off");
	LCD_moveCursor(1, 0);
	LCD_displayString("Temp =    C");
	while (1) {
		DcMotor_Rotate(2, 25);
		temp = LM35_GetTempreture();
		LCD_moveCursor(1, 7);
		LCD_intgerToString(temp);
		if (temp < 30) {
			DcMotor_Rotate(0, 0);
		} else if (temp >= 30 || temp <= 60) {
			LCD_moveCursor(0, 8);
			LCD_displayString("on");
			DcMotor_Rotate(1, 64);
		} else if (temp >= 60 || temp <= 90) {
			LCD_moveCursor(0, 8);
			LCD_displayString("on");
			DcMotor_Rotate(1, 128);
		} else if (temp >= 90 || temp <= 120) {
			LCD_moveCursor(0, 8);
			LCD_displayString("on");
			DcMotor_Rotate(1, 192);
		} else if (temp >= 120) {
			LCD_moveCursor(0, 8);
			LCD_displayString("on");
			DcMotor_Rotate(1, 255);
		}
	}
}
