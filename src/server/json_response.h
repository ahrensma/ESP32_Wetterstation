#ifndef JSON_RESPONSE_H
#define JSON_RESPONSE_H

#include "config.h"
#include <Arduino.h>

// You can either declare them as extern if they are global:
extern ADS1015_DATA ads1015_data;
extern BME680_DATA bme680_data;
extern D6410_DATA d6410_data;
extern HM330X_DATA hm330x_data;
extern MDWS_DATA mdws_data;
extern MLX90614_DATA mlx90614_data;
extern RG11_DATA rg11_data;
extern RS12_DATA rs12_data;
extern SCD41_DATA scd41_data;
extern SH1106_DATA sh1106_data;
extern TSL2591_DATA tsl2591_data;
extern WIFI_DATA wifi_data;
extern DEWPOINT_DATA dewpoint_indoor;
extern AQI_DATA aqi_data;
extern SQI_DATA sqi_data;

// Function prototype to generate the JSON response
String getSensorsJson();

#endif // JSON_RESPONSE_H
