/**
 * @file dev_ads1015.h
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#ifndef _DEV_ADS1015_H
#define _DEV_ADS1015_H

#include <Adafruit_ADS1X15.h>

/**
 * @struct ADS1015_DATA
 * @param bool status
 * @param float ai0
 * @param float ai1
 * @param float ai2
 * @param float ai3
 */
struct ADS1015_DATA {
  bool status;
  float ai0;
  float ai1;
  float ai2;
  float ai3;
};

/**
 * @brief Init ADS1015
 *
 */
void initADS1015();

/**
 * @brief Get ADS1015 values
 *
 * @details
 * The ADC input range (or gain) can be changed via the following
 * functions, but be careful never to exceed VDD +0.3V max, or to
 * exceed the upper and lower limits if you adjust the input range!
 * Setting these values incorrectly may destroy your ADC!
 *                                                                ADS1015  ADS1115
 *                                                                -------  -------
 * ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
 * ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
 * ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
 * ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
 * ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
 * ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV
 */
void getADS105Values(ADS1015_DATA* ads1015_data);

#endif /* _DEV_ADS1015_H */