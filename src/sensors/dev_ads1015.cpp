/**
 * @file dev_ads1015.h
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#include "dev_ads1015.h"

Adafruit_ADS1015 ads;

//-----------------------------------------------------------------------------
void initADS1015()
{
  if (ads.begin() == false) {
    Serial.println(F("ADS1015 not detected ..."));
    while (1)
      ;
  }
}

//-----------------------------------------------------------------------------
void getADS105Values(ADS1015_DATA* ads1015_data)
{
  ads1015_data->ai0 = ads.computeVolts(ads.readADC_SingleEnded(0));
  ads1015_data->ai1 = ads.computeVolts(ads.readADC_SingleEnded(1));
  ads1015_data->ai2 = ads.computeVolts(ads.readADC_SingleEnded(2));
  ads1015_data->ai3 = ads.computeVolts(ads.readADC_SingleEnded(3));
}
