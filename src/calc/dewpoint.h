/**
 * @file dewpoint.h
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#ifndef _DEWPOINT_H
#define _DEWPOINT_H

/**
 * @struct DEWPOINT_DATA
 * @param bool status
 * @param float temp
 * @param float humi
 * @param float dewpoint
 * @param float absHumi;
 */
struct DEWPOINT_DATA {
  bool status;
  float temp;
  float humi;
  float dewpoint;
  float absHumi;
};

const double R_STAR = 8314.3; // J/(kmol*K)
const double MW = 18.016; // kg/kmol

double SDD(double T);
double DD(double r, double T);
double relHumi(double T, double TD);
double TD(double r, double T);
double AF(double r, double TK);

/**
 *
 * https://www.wetterochs.de/wetter/feuchte.html
 *
 */
void calcDEWPOINT(DEWPOINT_DATA* dewpoint_data);

#endif /* _DEWPOINT_H */