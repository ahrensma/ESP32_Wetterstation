/**
 * @file dev_scd41.cpp
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#include "dev_scd41.h"

SCD4x scd41;

//-----------------------------------------------------------------------------
void initSCD41()
{
  if (scd41.begin() == false) {
    Serial.println(F("SCD41 not detected ..."));
    while (1)
      ;
  }
}

//-----------------------------------------------------------------------------
void getSCD41Values(SCD41_DATA* scd41_data)
{

  scd41_data->co2 = scd41.getCO2();
  scd41_data->temperature = scd41.getTemperature();
  scd41_data->humidity = scd41.getHumidity();
}
