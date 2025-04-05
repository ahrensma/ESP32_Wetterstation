/**
 * @file dewpoint.h
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#include "dewpoint.h"
#include <math.h>

// TODO: Add a second source (url, sensor) and calculate the dew point-dependent ventilation display

//-----------------------------------------------------------------------------
double SDD(double T)
{
  double a, b;
  if (T >= 0) {
    a = 7.5;
    b = 237.3;
  } else {
    a = 7.6;
    b = 240.7;
  }
  return 6.1078 * pow(10, (a * T) / (b + T));
}

//-----------------------------------------------------------------------------
double DD(double r, double T) { return (r / 100.0) * SDD(T); }

//-----------------------------------------------------------------------------
double rel(double T, double TD) { return 100.0 * SDD(TD) / SDD(T); }

//-----------------------------------------------------------------------------
double TD(double r, double T)
{
  double a = (T >= 0) ? 7.5 : 7.6;
  double b = (T >= 0) ? 237.3 : 240.7;
  double v = log10(DD(r, T) / 6.1078);
  return (b * v) / (a - v);
}

//-----------------------------------------------------------------------------
double AF(double r, double TK) { return pow(10, 5) * MW / R_STAR * DD(r, TK - 273.15) / TK; }

//-----------------------------------------------------------------------------

void calcDEWPOINT(DEWPOINT_DATA* dewpoint_data)
{
  double TK = dewpoint_data->temp + 273.15;
  dewpoint_data->dewpoint = TD(dewpoint_data->humi, dewpoint_data->temp);
  dewpoint_data->absHumi = AF(dewpoint_data->humi, TK);
}