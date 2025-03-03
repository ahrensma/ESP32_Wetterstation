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
struct BME680_DATA {
  bool status;
  float temperature;
  float pressure;
  float humidity;
  float airquality;
};

/**
 * @brief Init BME680
 */
void initBME680();

/**
 * @brief Calculates the air quality index
 * @param Raw airquiality value ( gas resistance [Ω] / 1000 ) from the BME680
 * @return Airquality index 1-7
 *
 * @link
 * https://www.bosch-sensortec.com/media/boschsensortec/downloads/datasheets/bst-bme680-ds001.pdf
 *
 * |   | **AQI Range** |
 * |---|---------------|
 * | 1 | 0 - 50        |
 * | 2 | 51 - 100      |
 * | 3 | 101 - 150     |
 * | 4 | 151 - 200     |
 * | 5 | 201 - 300     |
 * | 6 | 301 - 400     |
 * | 7 | 401 - 500     |
 *
 */
float calcAQI_GAS(float gasvalue);

/**
 * @brief Get BME680 values
 * @param bme680_data
 */
void getBME680Values(BME680_DATA* bme680_data);

#endif /* _DEV_BME680_H */