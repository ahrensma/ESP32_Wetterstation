/**
 * @file aqi.cpp
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#include "aqi.h"

//-----------------------------------------------------------------------------
void calcAQI_PM25(AQI_DATA* aqi_data)
{
  // Define AQI breakpoints for each range
  if (aqi_data->pm25 >= 0.0 && aqi_data->pm25 <= 12.0) {
    aqi_data->aqi_idx = 1; // Good
    aqi_data->aqi_val = (aqi_data->pm25 / 12.0) * 50;
  } else if (aqi_data->pm25 > 12.0 && aqi_data->pm25 <= 35.4) {
    aqi_data->aqi_idx = 2; // Moderate
    aqi_data->aqi_val = 51 + ((aqi_data->pm25 - 12.1) / (35.4 - 12.1)) * (100 - 51);
  } else if (aqi_data->pm25 > 35.4 && aqi_data->pm25 <= 55.4) {
    aqi_data->aqi_idx = 3; // Unhealthy for sensitive groups
    aqi_data->aqi_val = 101 + ((aqi_data->pm25 - 35.5) / (55.4 - 35.5)) * (150 - 101);
  } else if (aqi_data->pm25 > 55.4 && aqi_data->pm25 <= 150.4) {
    aqi_data->aqi_idx = 4; // Unhealthy
    aqi_data->aqi_val = 151 + ((aqi_data->pm25 - 55.5) / (150.4 - 55.5)) * (200 - 151);
  } else if (aqi_data->pm25 > 150.4 && aqi_data->pm25 <= 250.4) {
    aqi_data->aqi_idx = 5; // Very Unhealthy
    aqi_data->aqi_val = 201 + ((aqi_data->pm25 - 150.5) / (250.4 - 150.5)) * (300 - 201);
  } else if (aqi_data->pm25 > 250.4 && aqi_data->pm25 <= 350.4) {
    aqi_data->aqi_idx = 6; // Hazardous
    aqi_data->aqi_val = 301 + ((aqi_data->pm25 - 250.5) / (350.4 - 250.5)) * (400 - 301);
  } else if (aqi_data->pm25 > 350.4 && aqi_data->pm25 <= 500.4) {
    aqi_data->aqi_idx = 7; // Hazardous (extreme)
    aqi_data->aqi_val = 401 + ((aqi_data->pm25 - 350.5) / (500.4 - 350.5)) * (500 - 401);
  } else {
    aqi_data->aqi_idx = -999;
    aqi_data->aqi_val = -999;
  }
}

//-----------------------------------------------------------------------------
void calcAQI_PM10(AQI_DATA* aqi_data)
{
  // Define AQI breakpoints for each range
  if (aqi_data->pm10 >= 0 && aqi_data->pm10 <= 54) {
    aqi_data->aqi_idx = 1; // Good
    aqi_data->aqi_val = (aqi_data->pm10 / 54.0) * 50;
  } else if (aqi_data->pm10 > 54 && aqi_data->pm10 <= 154) {
    aqi_data->aqi_idx = 2; // Moderate
    aqi_data->aqi_val = 51 + ((aqi_data->pm10 - 55) / (154 - 55)) * (100 - 51);
  } else if (aqi_data->pm10 > 154 && aqi_data->pm10 <= 254) {
    aqi_data->aqi_idx = 3; // Unhealthy for sensitive groups
    aqi_data->aqi_val = 101 + ((aqi_data->pm10 - 155) / (254 - 155)) * (150 - 101);
  } else if (aqi_data->pm10 > 254 && aqi_data->pm10 <= 354) {
    aqi_data->aqi_idx = 4; // Unhealthy
    aqi_data->aqi_val = 151 + ((aqi_data->pm10 - 255) / (354 - 255)) * (200 - 151);
  } else if (aqi_data->pm10 > 354 && aqi_data->pm10 <= 424) {
    aqi_data->aqi_idx = 5; // Very Unhealthy
    aqi_data->aqi_val = 201 + ((aqi_data->pm10 - 355) / (424 - 355)) * (300 - 201);
  } else if (aqi_data->pm10 > 424 && aqi_data->pm10 <= 504) {
    aqi_data->aqi_idx = 6; // Hazardous
    aqi_data->aqi_val = 301 + ((aqi_data->pm10 - 425) / (504 - 425)) * (400 - 301);
  } else if (aqi_data->pm10 > 504 && aqi_data->pm10 <= 604) {
    aqi_data->aqi_idx = 7; // Hazardous (extreme)
    aqi_data->aqi_val = 401 + ((aqi_data->pm10 - 505) / (604 - 505)) * (500 - 401);
  } else {
    aqi_data->aqi_idx = -999;
    aqi_data->aqi_val = -999;
  }
}