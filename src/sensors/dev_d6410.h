/**
 * @file dev_d6410.h
 * @author Martin Ahrens
 * @date 2025_Q1
 *
 * @link https://github.com/wrybread
 * @cite https://github.com/wrybread/weewx-ArduinoWeatherStation
 *
 */

#ifndef _DEV_D6410_H
#define _DEV_D6410_H

#include <WString.h>
#include <math.h>
#include <Arduino.h> // neccessary for map()

#include "calibration.h"

#define SLICEDURATION 5000

/**
 * @struct D6410_DATA
 * @param bool status
 * @param float ISRFreq
 * @param float windSpeed_ms
 * @param float windSpeed_kmh
 * @param float windDIR
 * @param String windDirection
 */
struct D6410_DATA
{
  bool status;
  float ISRFreq;
  float windSpeed_ms;
  float windSpeed_kmh;
  float windDIR;
  String windDirection;
};

/**
 * @brief Get D6410 Values
 *
 */
void initD6410();

/**
 * @brief Get D6410 Values
 *
 * Windspeed in m/s
 *
 */
String calculateWindDirection(float irsfreq);

/**
 * @brief Get D6410 Values
 *
 * Black     Wind speed open drain to ground
 * Red       Ground
 * Green     Wind direction pot wiper (20KΩ potentiometer)
 * Yellow    Pot supply voltage

 * Wind Speed Translation Formula
 *      1600 rev/hr = 1 mph
 *      V = P(2.25/T) (V = speed in mph, P = no. of pulses per sample period T = sample period in seconds)
 * Wind Direction Translation
 *      Variable resistance 0 - 20KΩ; 10KΩ = south, 180°
 *
 * @param d6410_data
 */
void getD6410Values(D6410_DATA *d6410_data);

#endif /* _DEV_D6410_H */