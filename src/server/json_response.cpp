#include "json_response.h"

String getSensorsJson()
{
  String jsonResponse = "{";

  jsonResponse += "\"weather\":{";

  // Davis Anemometer (using D6410 sensor data)
  jsonResponse += "\"Davis Anemometer\":{";
  jsonResponse += "\"init\": true,";
  jsonResponse += "\"direction\": " + String(d6410_data.windDIR, 0) + ",";
  jsonResponse += "\"avg speed\": " + String(d6410_data.windSpeed_ms, 0) + ",";
  jsonResponse += "\"min speed\": 0,";
  jsonResponse += "\"max speed\": 0,";
  jsonResponse += "\"rotations\": 0";
  jsonResponse += "},";

  // RG11 Rain Sensor
  jsonResponse += "\"RG11 Rain Sensor\":{";
  jsonResponse += "\"init\": true,";
  jsonResponse += "\"mode\": \"drop detect\",";
  jsonResponse += "\"count\": 0,";
  jsonResponse += "\"drop freq\": 0";
  jsonResponse += "},";

  // BME680 sensor values
  jsonResponse += "\"BME680\":{";
  jsonResponse += "\"init\": true,";
  jsonResponse += "\"Temp\": " + String(bme680_data.temperature, 8) + ",";
  jsonResponse += "\"Hum\": " + String(bme680_data.humidity, 8) + ",";
  jsonResponse += "\"Pres\": " + String(bme680_data.pressure, 8) + ",";
  jsonResponse += "\"Air\": " + String(bme680_data.airquality, 8);
  jsonResponse += "},";

  // MLX90614 sensor values
  jsonResponse += "\"MLX90614\":{";
  jsonResponse += "\"init\": true,";
  jsonResponse += "\"T amb\": " + String(mlx90614_data.AmbiTemp, 8) + ",";
  jsonResponse += "\"T obj\": " + String(mlx90614_data.ObjTemp, 8);
  jsonResponse += "},";

  // TSL2591 sensor values
  jsonResponse += "\"TSL2591\":{";
  jsonResponse += "\"init\": true,";
  jsonResponse += "\"Lux\": " + String(tsl2591_data.lux, 8) + ",";
  jsonResponse += "\"Visible\": " + String(tsl2591_data.vis, 0) + ",";
  jsonResponse += "\"IR\": " + String(tsl2591_data.nir, 0) + ",";
  jsonResponse += "\"Gain\": 16,";
  jsonResponse += "\"Timing\": 0";
  jsonResponse += "},";

  // Water sensor (example placeholder)
  jsonResponse += "\"Water\":{";
  jsonResponse += "\"init\": true,";
  jsonResponse += "\"wetness\": 0";
  jsonResponse += "},";

  // ADS1015 sensor values
  jsonResponse += "\"ADS1015\":{";
  jsonResponse += "\"AO0\": " + String(ads1015_data.ai0, 1) + ",";
  jsonResponse += "\"AO1\": " + String(ads1015_data.ai1, 1) + ",";
  jsonResponse += "\"AO2\": " + String(ads1015_data.ai2, 1) + ",";
  jsonResponse += "\"AO3\": " + String(ads1015_data.ai3, 1);
  jsonResponse += "},";

  // SCD41 sensor values
  jsonResponse += "\"SCD41\":{";
  jsonResponse += "\"CO2\": " + String(scd41_data.co2, 0) + ",";
  jsonResponse += "\"Temp\": " + String(scd41_data.temperature, 1) + ",";
  jsonResponse += "\"Humi\": " + String(scd41_data.humidity, 1);
  jsonResponse += "},";

  // HM330x sensor values (particulate matter)
  jsonResponse += "\"HM330x\":{";
  jsonResponse += "\"PM1.0\": " + String(hm330x_data.PM1) + ",";
  jsonResponse += "\"PM2.5\": " + String(hm330x_data.PM25) + ",";
  jsonResponse += "\"PM10\": " + String(hm330x_data.PM10);
  jsonResponse += "},";

  // MDWS sensor for wind measurement (WindMS)
  jsonResponse += "\"MDWS\":{";
  jsonResponse += "\"WindMS\": " + String(mdws_data.windms);
  jsonResponse += "},";

  // Dew Point sensor value
  jsonResponse += "\"DewPoint\":{";
  jsonResponse += "\"DP\": " + String(dewpoint_indoor.dewpoint);
  jsonResponse += "},";

  // SQI sensor values
  jsonResponse += "\"SQI\":{";
  jsonResponse += "\"SQM_FREQ\": " + String(sqi_data.sqi_freq) + ",";
  jsonResponse += "\"SQM_NORM\": " + String(sqi_data.sqi_norm);
  jsonResponse += "},";

  // AQI sensor value
  jsonResponse += "\"AQI\":{";
  jsonResponse += "\"AQI\": " + String(aqi_data.aqi_idx);
  jsonResponse += "},";

  // WiFi signal strength
  jsonResponse += "\"WiFi\":{";
  jsonResponse += "\"WIFI\": " + String(wifi_data.WifiSignal);
  jsonResponse += "}";

  jsonResponse += "}}"; // Close the "weather" object and the root JSON object

  return jsonResponse;
}
