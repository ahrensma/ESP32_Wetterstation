/**
 * @file aqi.h
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#ifndef _AQI_H
#define _AQI_H

/**
 * @details
 *
 *  @link
 https://document.airnow.gov/technical-assistance-document-for-the-reporting-of-daily-air-quailty.pdf
 *  @link
 https://www.airnow.gov/sites/default/files/2020-05/aqi-technical-assistance-document-sept2018.pdf

 */

/**
 * @struct AQI_DATA
 * @param bool status
 * @param float pm25
 * @param float pm10
 * @param float aqi_val
 * @param int aqi_idx
 */
struct AQI_DATA {
  bool status;
  float pm25;
  float pm10;
  float aqi_val;
  int aqi_idx;
};

/**
 * @brief Calculate the AQI
 *
 *  * PM₂.₅ (µg/m³) AQI Breakpoints
 *
 * | **AQI Range** | **PM₂.₅ (µg/m³)** |
 * |---------------|---------------------|
 * | 0 - 50        | 0.0 - 12.0          |
 * | 51 - 100      | 12.1 - 35.4         |
 * | 101 - 150     | 35.5 - 55.4         |
 * | 151 - 200     | 55.5 - 150.4        |
 * | 201 - 300     | 150.5 - 250.4       |
 * | 301 - 400     | 250.5 - 350.4       |
 * | 401 - 500     | 350.5 - 500.4       |
 *
 */
void calcAQI_PM25(AQI_DATA* aqi_data);

/**
 * @brief Calculate the AQI
 *
 * PM₁₀ (µg/m³) AQI Breakpoints
 *
 * | **AQI Range** | **PM₁₀ (µg/m³)** |
 * |---------------|-------------------|
 * | 0 - 50        | 0 - 54            |
 * | 51 - 100      | 55 - 154          |
 * | 101 - 150     | 155 - 254         |
 * | 151 - 200     | 255 - 354         |
 * | 201 - 300     | 355 - 424         |
 * | 301 - 400     | 425 - 504         |
 * | 401 - 500     | 505 - 604         |
 *
 */
void calcAQI_PM10(AQI_DATA* aqi_data);

#endif /* _AQI_H */
