/**
 * @file sqi.cpp
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#include "sqi.h"
#include <math.h>

//-----------------------------------------------------------------------------
void calcSQI_FREQ(SQI_DATA* sqm_data)
{
  /* Device constant */
  const float A = 19.0;

  sqm_data->sqi_freq
      = A - 2.5 * log10(sqm_data->inputval); // Frequency to magnitudes/arcSecond2 formula
}

//-----------------------------------------------------------------------------
void calcSQI_NORM(SQI_DATA* sqm_data)
{

  /* SQM limits (16 to 22 mag/arcsec²) */
  const double m_min = 16.0;
  const double m_max = 22.0;

  float m = sqm_data->inputval;

  if (m < m_min)
    m = m_min; // Ensuring value stays within the range
  if (m > m_max)
    m = m_max;

  sqm_data->sqi_norm = 100.0 * (m - m_min) / (m_max - m_min);
}