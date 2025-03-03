/**
 * @file dev_MDWS.h
 * @author Martin Ahrens
 * @date 2025_Q1
 *
 * @brief See detailed documentation under
 * @link
 * https://moderndevice.com/blogs/documentation/calibrating-the-rev-p-wind-sensor-from-a-new-regression
 *
 * Calculation:
 * Temp_C = ((float)Volts - ZeroVoltage) / .0195;
 * WS_MPH = (((Volts – ZeroWind_V) / (3.038517 * (Temp_C ^ 0.115157 ))) / 0.087288 ) ^ 3.009364
 *
 */

#ifndef _DEV_MDWS_H
#define _DEV_MDWS_H

/**
 * @struct MDWS_DATA
 * @param bool status
 * @param float rawdata_wind
 * @param float rawdata_temp
 * @param float windMHP
 * @param float windms
 * @param float windBF
 * @param float temperature
 */
struct MDWS_DATA {
  bool status;
  float rawdata_wind;
  float rawdata_temp;
  float windmph;
  float windms;
  float windBF;
  float temperature;
};

/**
 * @brief Init MDWS
 *
 * Nothing to do, because the analog values are comming from the ADS105.
 *
 */
void initMDWS();

/**
 * @brief Get HM330X values
 *
 * @param hm330x_data
 */
void getMDWSValues(MDWS_DATA* mdws_data);

#endif /* _DEV_MDWS_H */