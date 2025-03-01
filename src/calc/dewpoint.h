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
 */
struct DEWPOINT_DATA
{
  bool status;
  float temp;
  float humi;
  float dewpoint;
};

/**
 *
 * https://craftofcoding.wordpress.com/wp-content/uploads/2018/06/prac_dewpoint.pdf
 *
 */
void calcDEWPOINT(DEWPOINT_DATA *dewpoint_data);

#endif /* _DEWPOINT_H */