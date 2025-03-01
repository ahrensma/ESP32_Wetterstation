/**
 * @file dev_tsl2591.h
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#ifndef _DEV_TSL2591_H
#define _DEV_TSL2591_H

#include <Adafruit_TSL2591.h>

/**
 * @struct TSL2591_DATA
 * @param bool status
 * @param int vis
 * @param int nir
 * @param int lux
 */
struct TSL2591_DATA
{
  bool status;
  int vis;
  int nir;
  int lux;
};

/**
 * @brief Init TSL2591
 *
 */
void initTSL2591();

/**
 * @brief Get TSL2591 values
 * @param tsl2591_data
 *
 */
void getTSL2591Values(TSL2591_DATA *tsl2591_data);

#endif /* _DEV_TSL2591_H */