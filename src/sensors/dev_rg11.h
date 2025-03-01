/**
 * @file dev_rg11.h
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#ifndef _DEV_RG11_H
#define _DEV_RG11_h

// https://partofthething.com/thoughts/connecting-a-hydreon-infrared-rain-sensor-to-a-esp8266-or-arduino-or-raspberry-pi/

/**
 * @struct RG11_DATA
 * @param bool status
 */
struct RG11_DATA
{
  bool status;
};

/**
 * @brief Init RG11
 *
 */
void initRG11();

/**
 * @brief Get RG11 values
 * @param rg11_data
 *
 */
void getRG11Values(RG11_DATA *rg11_data);

#endif /* _DEV_RG11_h */