/**
 * @file dewpoint.h
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#include "dewpoint.h"
#include <math.h>

// TODO: Add a second source (url, sensor) and calculate the dew point-dependent ventilation display

// Bezeichnungen:
// r = relative Luftfeuchte
// T = Temperatur in °C
// TK = Temperatur in Kelvin (TK = T + 273.15)
// TD = Taupunkttemperatur in °C
// DD = Dampfdruck in hPa
// SDD = Sättigungsdampfdruck in hPa

// Parameter:
// a = 7.5, b = 237.3 für T >= 0
// a = 7.6, b = 240.7 für T < 0 über Wasser (Taupunkt)
// a = 9.5, b = 265.5 für T < 0 über Eis (Frostpunkt)

// R* = 8314.3 J/(kmol*K) (universelle Gaskonstante)
// mw = 18.016 kg/kmol (Molekulargewicht des Wasserdampfes)
// AF = absolute Feuchte in g Wasserdampf pro m3 Luft

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
double DD(double r, double T)
{
  double DD = (r / 100.0) * SDD(T);
  return DD;
}

//-----------------------------------------------------------------------------
double rel(double T, double TD)
{
  double rel = 100.0 * SDD(TD) / SDD(T);
  return rel;
}

//-----------------------------------------------------------------------------
double TD(double r, double T)
{
  double a = (T >= 0) ? 7.5 : 7.6;
  double b = (T >= 0) ? 237.3 : 240.7;
  double v = log10(DD(r, T) / 6.1078);
  double TD = (b * v) / (a - v);
  return TD;
}

//-----------------------------------------------------------------------------
double AF(double r, double TK)
{
  double AF = pow(10, 5) * MW / R_STAR * DD(r, TK - 273.15) / TK;
  return AF;
}

//-----------------------------------------------------------------------------

void calcDEWPOINT(DEWPOINT_DATA* dewpoint_data)
{
  double TK = dewpoint_data->temp + 273.15;
  dewpoint_data->dewpoint = TD(dewpoint_data->humi, dewpoint_data->temp);
  dewpoint_data->absHumi = AF(dewpoint_data->humi, TK);
}