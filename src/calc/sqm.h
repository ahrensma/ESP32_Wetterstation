/**
 * @file sqm.h
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#ifndef _SQM_H
#define _SQM_H

/**
 *
 * @link https://github.com/indilib/indi-3rdparty/tree/master/indi-duino/devices/Firmwares/weatherradio
 *
 * @link https://github.com/marcocipriani01/SimpleSQM
 *
 * @link https://stargazerslounge.com/topic/366438-diy-sky-quality-meter/
 *
 * Istil et al. “Night Sky Photometry with Sky Quality Meter.” (2005).
 *
 */

/**
 * @struct SQM_DATA
 * @param bool status
 * @param float aqi
 */
struct SQM_DATA
{
    bool status;
    float sqm;
};

void calcSQM(SQM_DATA *sqm_data);

#endif // _SQM_H
