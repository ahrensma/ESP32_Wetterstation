/**
 * @file dev_MDWS.cpp
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#include <math.h>

#include "dev_MDWS.h"

#include "calibration.h"

//-----------------------------------------------------------------------------
void initMDWS() { ; }

//-----------------------------------------------------------------------------
void getMDWSValues(MDWS_DATA* mdws_data)
{

  mdws_data->temperature = ((float)mdws_data->rawdata_temp - ZeroVoltage) / .0195;

  mdws_data->windmph = pow(
      (((mdws_data->rawdata_wind - ZeroWind) / (3.038517 * pow(mdws_data->temperature, 0.115157)))
          / 0.0872878),
      3.009364);

  mdws_data->windms = mdws_data->windmph * 0.44704;
  mdws_data->windBF = 0.836 * pow(mdws_data->windms, 3 / 2);
}
