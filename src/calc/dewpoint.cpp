/**
 * @file dewpoint.h
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#include <math.h>
#include "dewpoint.h"

//-----------------------------------------------------------------------------
void calcDEWPOINT(DEWPOINT_DATA *dewpoint_data)
{
  float gamma = (17.27 * dewpoint_data->temp) / (237.7 + dewpoint_data->temp) + log(dewpoint_data->humi);
  dewpoint_data->dewpoint = (237.7 * gamma) / (17.27 - gamma);
}
