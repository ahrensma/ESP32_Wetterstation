/**
 * @file dev_bme680.h
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#ifndef _DEV_BME680_H
#define _DEV_BME680_H

#include <Adafruit_BME680.h>

/**
 * @struct BME680_DATA
 * @param bool status
 * @param float temperature
 * @param float pressure
 * @param float humidity
 * @param float airquality
 */
struct BME680_DATA
{
  bool status;
  float temperature;
  float pressure;
  float humidity;
  float airquality;
};

/**
 * @brief Init BME680
 *
 */
void initBME680();

/**
 * @brief Get BME680 values
 * @param bme680_data
 *
 */
void getBME680Values(BME680_DATA *bme680_data);

#endif /* _DEV_BME680_H */