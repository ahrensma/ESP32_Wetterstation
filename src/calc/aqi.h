/**
 * @file aqi.h
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#ifndef _AQI_H
#define _AQI_H

/**
 * @details
 * | Range        | Quality                          | Color  |
 * |--------------|----------------------------------|--------|
 * | 0 to 50      | Good                             | Green  |
 * | 51 to 100    | Moderate                         | Yellow |
 * | 101 to 150   | Unhealthy for Sensitive Groups   | Orange |
 * | 151 to 200   | Unhealthy                        | Red    |
 * | 201 to 300   | Very Unhealthy                   | Purple |
 * | 301+         | Hazardous                        | Maroon |
 *
 *  @link https://document.airnow.gov/technical-assistance-document-for-the-reporting-of-daily-air-quailty.pdf
 *
 */

/**
 * @struct AQI_DATA
 * @param bool status
 * @param float aqi
 */
struct AQI_DATA
{
    bool status;
    float aqi;
};

/**
 * @brief Calculate the AQI
 *
 */
void calcAQI(AQI_DATA *aqi_data);

#endif /* _AQI_H */
