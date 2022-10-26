/*
 * sensorsData.h
 *
 *  Created on: 28-Feb-2022
 *      Author: 27779
 */

#ifndef APPLICATION_CODE_SENSORSDATA_H_
#define APPLICATION_CODE_SENSORSDATA_H_
#include "stdio.h"
#include "stdint.h"

#include "stdbool.h"
#define ENABLE_SENSORS_SERIAL_PRINTS 1

#define TRI_LED_R PORT1.PODR.BIT.B7
#define TRI_LED_G PORTA.PODR.BIT.B5
#define TRI_LED_B PORTA.PODR.BIT.B7

#define LED_ON 0
#define LED_OFF 1
/** ICM20948 values */
typedef struct icm20948_axis_data_t {
    float     xaxis;
    float     yaxis;
    float     zaxis;
} st_icm20948_axis_data_t;

typedef struct icm20948_data_t {
	st_icm20948_axis_data_t      accel;       ///< Accelerometer
	st_icm20948_axis_data_t      gyro;        ///< Gyroscope
	st_icm20948_axis_data_t      mag;         ///<Magentometer
} st_icm20948_data_t;

typedef struct zmod4410_data_t {
    float     iaq;       ///< iaq
    float     ec02;       ///< eco2
    float     tvoc;       ///< tvoc
    float     etoh;       ///< tvoc
} st_zmod4410_data_t;

/** Sensor and LED values */
typedef struct sensorsHS_t {

    float                  temperature; ///< Temperature
    float                  humidity;    ///< Humidity
} st_sensorsHS_t;

typedef struct sensorsICP_t {

    float                  temperatureicp; ///< Temperature
    float                  pressureicp;    ///< Pressure
} st_sensorsICP_t;

typedef struct sensorsZmod4410_t
{
	st_zmod4410_data_t  zmod4410Data;
}st_sensorsZmod4410_t;

typedef struct sensorsZmod4510_t
{
	float  zmod410_oaq;
}st_sensorsZmod4510_t;

typedef struct sensorsOB_t {

	uint16_t 	ob_spo2;  ///< spo2
	uint16_t 	ob_hr;    ///< Heart rate
	uint16_t 	ob_rr;
	float 		ob_pi;
} st_sensorsOB_t;

//extern uint8_t uart_printBuf[60];
#endif /* APPLICATION_CODE_SENSORSDATA_H_ */
