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

// #include <cmath> // For log10 function
// #include <iostream>
// #include <vector>

// using namespace std;

// // Function to compute A for a single measurement
// double calculateA(double sqm, double frequency) { return sqm + 2.5 * log10(frequency); }

// int main()
// {
//   int numMeasurements;
//   cout << "Enter the number of measurements: ";
//   cin >> numMeasurements;

//   vector<double> aValues;
//   double sqm, frequency, sumA = 0.0;

//   for (int i = 0; i < numMeasurements; i++) {
//     cout << "\nMeasurement " << (i + 1) << ":" << endl;
//     cout << "Enter reference SQM value (mag/arcsec²): ";
//     cin >> sqm;
//     cout << "Enter measured frequency (counts/sec): ";
//     cin >> frequency;

//     double A = calculateA(sqm, frequency);
//     aValues.push_back(A);
//     sumA += A;
//   }

//   double averageA = sumA / numMeasurements;

//   cout << "\nCalibration constant A values: ";
//   for (double A : aValues) {
//     cout << A << " ";
//   }
//   cout << "\nAverage Calibration constant A: " << averageA << endl;

//   return 0;
// }
