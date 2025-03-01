/**
 * @file dev_hm330x.h
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#ifndef _DEV_HM330X_H
#define _DEV_HM330X_H

#include <Tomoto_HM330X.h>

/**
 * @struct HM330X_DATA
 * @param bool status
 * @param int PM1
 * @param int PM25
 * @param int PM10
 */
struct HM330X_DATA
{
  bool status;
  int PM1;
  int PM25;
  int PM10;
};

/**
 * @brief Init HM330X
 *
 */
void initHM330X();

/**
 * @brief Get HM330X values
 * @param hm330x_data
 */
void getHM330XValues(HM330X_DATA *hm330x_data);

#endif /* _DEV_HM330X_H */