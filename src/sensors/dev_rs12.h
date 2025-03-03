/**
 * @file dev_rs12.h
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#ifndef _DEV_RS12_H
#define _DEV_RS12_h

/**
 * @struct RS12_DATA
 * @param bool status
 */
struct RS12_DATA {
  bool status;
};

/**
 * @brief Init RS12
 *
 */
void initRS12();

/**
 * @brief Get RS12 values
 * @param rs12_data
 *
 */
void getRS12Values(RS12_DATA* rs12_data);

#endif /* _DEV_RS12_h */