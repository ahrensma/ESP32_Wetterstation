/**
 * @file dev_scd41.h
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#ifndef _DEV_SCD41_H
#define _DEV_SCD41_H

#include "SparkFun_SCD4x_Arduino_Library.h"

/**
 * @struct SCD41_DATA
 * @param bool status
 * @param float co2
 * @param float temperature
 * @param float humidity
 */
struct SCD41_DATA {
  bool status;
  float co2;
  float temperature;
  float humidity;
};

/**
 * @brief Init SCD41
 *
 */
void initSCD41();

/**
 * @brief Get SCD41 values
 * @param scd41_data
 *
 */
void getSCD41Values(SCD41_DATA* scd41_data);

#endif /* _DEV_SCD41_H */