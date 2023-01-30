/*
 * lm35_sensor.h
 *
 *  Created on: May 28, 2022
 *      Author: hussi
 */

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_
#define Lm35_sensor_channel_num		2
#include  "std_types.h"

#define SENSOR_CHANNEL_ID         2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150



uint8 LM35_GetTempreture();


#endif /* LM35_SENSOR_H_ */
