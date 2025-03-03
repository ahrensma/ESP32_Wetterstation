/**
 * @file dev_tsl2591.cpp
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#include "dev_tsl2591.h"

Adafruit_TSL2591 tsl = Adafruit_TSL2591(2591);

//-----------------------------------------------------------------------------
void initTSL2591()
{

  if (tsl.begin() == false) {
    Serial.println(F("TSL2591 not detected ..."));
    while (1)
      ;
  }

  tsl.setGain(TSL2591_GAIN_MED);
  tsl.setTiming(TSL2591_INTEGRATIONTIME_100MS);
  tsl2591Gain_t gain = tsl.getGain();
}

//-----------------------------------------------------------------------------
void getTSL2591Values(TSL2591_DATA* tsl2591_data)
{

  uint32_t lum = tsl.getFullLuminosity();
  uint16_t ir, full;
  ir = lum >> 16;
  full = lum & 0xFFFF;

  tsl2591_data->nir = ir;
  tsl2591_data->vis = full - ir;
  tsl2591_data->lux = tsl.calculateLux(full, ir);
}
