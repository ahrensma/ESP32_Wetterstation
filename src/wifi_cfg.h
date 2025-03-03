/**
 * @file wifi_cfg.h
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#ifndef _WIFI_CFG_H
#define _WIFI_CFG_H

#include <WString.h>
#include <WiFi.h>

/* The following values are from https://www.intuitibits.com/2016/03/23/dbm-to-percent-conversion/
 */
const int8_t signal_dBM[] = { -100, -99, -98, -97, -96, -95, -94, -93, -92, -91, -90, -89, -88, -87,
  -86, -85, -84, -83, -82, -81, -80, -79, -78, -77, -76, -75, -74, -73, -72, -71, -70, -69, -68,
  -67, -66, -65, -64, -63, -62, -61, -60, -59, -58, -57, -56, -55, -54, -53, -52, -51, -50, -49,
  -48, -47, -46, -45, -44, -43, -42, -41, -40, -39, -38, -37, -36, -35, -34, -33, -32, -31, -30,
  -29, -28, -27, -26, -25, -24, -23, -22, -21, -20, -19, -18, -17, -16, -15, -14, -13, -12, -11,
  -10, -9, -8, -7, -6, -5, -4, -3, -2, -1 };
const uint8_t signal_percent[] = { 0, 0, 0, 0, 0, 0, 4, 6, 8, 11, 13, 15, 17, 19, 21, 23, 26, 28,
  30, 32, 34, 35, 37, 39, 41, 43, 45, 46, 48, 50, 52, 53, 55, 56, 58, 59, 61, 62, 64, 65, 67, 68,
  69, 71, 72, 73, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 90, 91, 92, 93,
  93, 94, 95, 95, 96, 96, 97, 97, 98, 98, 99, 99, 99, 100, 100, 100, 100, 100, 100, 100, 100, 100,
  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100 };

/**
 * @struct WIFI_DATA
 * @param bool status
 * @param String IPAddress
 * @param int WifiSignal
 */
struct WIFI_DATA {
  bool status;
  String IPAddress;
  int WifiSignal;
};

/**
 * @brief
 * @param ssid
 * @param password
 */
void initWiFi(const char* ssid, const char* password);

/**
 * @brief  Function to calculate the WiFi strength
 *
 * For more information see https://www.intuitibits.com/2016/03/23/dbm-to-percent-conversion/
 * Calculation:  percent = 100*(1-(P_dBm_max - P_dBm)/(P_dBm_max - P_dBm_min))
 *
 * @param wifi_data
 */
void CalcWiFiStrength(WIFI_DATA* wifi_data);

#endif /* _WIFI_CFG_H */