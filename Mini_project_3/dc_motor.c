#include "dc_motor.h"
#include "gpio.h"
#include "common_macros.h"
#include "avr/io.h"
void DcMotor_Init() {
	GPIO_setupPinDirection(DC_MOTOR_PORT_ID, DC_MOTOR_IN1_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORT_ID, DC_MOTOR_IN2_PIN_ID, PIN_OUTPUT);
	GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_LOW);
}
void DcMotor_Rotate(uint8 state, uint8 speed) {
	switch (state) {
	case (0):
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_LOW);
		break;
	case (1):
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_HIGH);
		break;
	case (2):
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_IN2_PIN_ID, LOGIC_HIGH);
		break;
	}
	PWM_Timer0_Start(speed);
}
