/*
 * dc_motor.h
 *
 *  Created on: May 27, 2022
 *      Author: hussi
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "std_types.h"
#include "common_macros.h"
#include "pwm.h"

#define DC_MOTOR_PORT_ID		PORTB_ID
#define DC_MOTOR_IN1_PIN_ID		PIN0_ID
#define DC_MOTOR_IN2_PIN_ID		PIN1_ID
void DcMotor_Rotate(uint8 state,uint8 speed);
void DcMotor_Init();

#endif /* DC_MOTOR_H_ */
