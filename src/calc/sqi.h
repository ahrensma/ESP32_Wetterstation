/**
 * @file sqi.h
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#ifndef _SQI_H
#define _SQI_H

/**
 *
 * @link
 * https://github.com/indilib/indi-3rdparty/tree/master/indi-duino/devices/Firmwares/weatherradio
 *
 * @link https://github.com/marcocipriani01/SimpleSQM
 *
 * @link https://stargazerslounge.com/topic/366438-diy-sky-quality-meter/
 *
 * Istil et al. “Night Sky Photometry with Sky Quality Meter.” (2005).
 *
 */

/**
 * @struct SQI_DATA
 * @param bool status
 * @param float inputval
 * @param float sqi_freq
 * @param float sqi_norm
 */
struct SQI_DATA {
  bool status;
  float inputval;
  float sqi_freq;
  float sqi_norm;
};

/**
 * @brief
 *
 * @param sqm_data
 */
void calcSQI_FREQ(SQI_DATA* sqm_data);

/**
 * @brief
 *
 * @param sqm_data
 */
void calcSQI_NORM(SQI_DATA* sqm_data);

#endif // _SQM_H
