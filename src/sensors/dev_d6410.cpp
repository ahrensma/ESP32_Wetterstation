/**
 * @file dev_d6410.cpp
 * @author Martin Ahrens
 * @date 2025_Q1
 *
 * @brief Davis Instruments Anemometer 6410
 *
 */

#include "dev_d6410.h"

//-----------------------------------------------------------------------------
void initD6410() { ; }

//-----------------------------------------------------------------------------
String calculateWindDirection(float windDir)
{

  String windCompassDirection;
  int windDirection; // translated 0 - 360 direction
  int windCalDirection; // converted value with offset applied

  windDirection = map(windDir, 0, 1023, 0, 360);
  windCalDirection = windDirection + VaneOffset;

  if (windCalDirection > 360)
    windCalDirection = windCalDirection - 360;
  if (windCalDirection < 0)
    windCalDirection = windCalDirection + 360;

  // get the compass direction for convenience
  if (windCalDirection < 22)
    windCompassDirection = "N";
  else if (windCalDirection < 67)
    windCompassDirection = "NE";
  else if (windCalDirection < 112)
    windCompassDirection = "E";
  else if (windCalDirection < 157)
    windCompassDirection = "SE";
  else if (windCalDirection < 212)
    windCompassDirection = "S";
  else if (windCalDirection < 247)
    windCompassDirection = "SW";
  else if (windCalDirection < 292)
    windCompassDirection = "W";
  else if (windCalDirection < 337)
    windCompassDirection = "NW";
  else
    windCompassDirection = "N";

  return windCompassDirection;
}

//-----------------------------------------------------------------------------
void getD6410Values(D6410_DATA* d6410_data)
{

  d6410_data->windDirection = calculateWindDirection(d6410_data->windDIR);
}
