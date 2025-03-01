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
  if (bme.begin() == false)
  {
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
void getBME680Values(BME680_DATA *bme680_data)
{
  if (!bme.performReading())
  {
    bme680_data->status = false;
    bme680_data->temperature = -99;
    bme680_data->pressure = -99;
    bme680_data->humidity = -99;
    bme680_data->airquality = -99;
  }
  else
  {
    bme680_data->status = true;
    bme680_data->temperature = bme.temperature;
    bme680_data->pressure = bme.pressure / 100.0;
    bme680_data->humidity = bme.humidity;
    bme680_data->airquality = bme.gas_resistance / 1000.0;
  }
}
