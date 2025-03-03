/**
 * @file dev_bme680.h
 * @author Martin Ahrens
 * @date 2025_Q1
 *
 */

#include "dev_bme680.h"

Adafruit_BME680 bme;

//-----------------------------------------------------------------------------
void initBME680()
{
  if (bme.begin() == false) {
    Serial.println(F("BME680 not detected ..."));
    while (1)
      ;
  }

  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
  bme.setGasHeater(320, 150);
}

//-----------------------------------------------------------------------------
float calcAQI_GAS(float val)
{
  int res = -999;
  // Define AQI breakpoints for each range
  if (val >= 0.0 && val <= 12.0) {
    res = 1; // Good
  } else if (val > 12.0 && val <= 35.4) {
    res = 2; // Moderate
  } else if (val > 35.4 && val <= 55.4) {
    res = 3; // Unhealthy for sensitive groups
  } else if (val > 55.4 && val <= 150.4) {
    res = 4; // Unhealthy
  } else if (val > 150.4 && val <= 250.4) {
    res = 5; // Very Unhealthy
  } else if (val > 250.4 && val <= 350.4) {
    res = 6; // Hazardous
  } else if (val > 350.4 && val <= 500.4) {
    res = 7; // Hazardous (extreme)
  } else {
    res = -999;
  }

  return res;
}

//-----------------------------------------------------------------------------
void getBME680Values(BME680_DATA* bme680_data)
{
  if (!bme.performReading()) {
    bme680_data->status = false;
    bme680_data->temperature = -999;
    bme680_data->pressure = -999;
    bme680_data->humidity = -999;
    bme680_data->airquality = -999;
  } else {
    bme680_data->status = true;
    bme680_data->temperature = bme.temperature;
    bme680_data->pressure = bme.pressure / 100.0;
    bme680_data->humidity = bme.humidity;
    bme680_data->airquality = calcAQI_GAS(bme.gas_resistance / 1000.0);
  }
}
