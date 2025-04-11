/**
 * @file main.cpp
 * @author Martin Ahrens
 * @date 2025_Q2
 * @version 0.3
 *
 * @mainpage ESP Wetterstation
 *
 * @include README.md
 *
 */

#include "client/read_json.h"
#include "server/json_response.h" // Include the JSON helper file

#include "config.h"
#include "main.h"

//------------------------------------------------------------------------------
WiFiClient espClient;
AsyncWebServer server(80);
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 3600);

//------------------------------------------------------------------------------
TaskHandle_t SensorTask1;
TaskHandle_t SensorTask2;
TaskHandle_t SensorTask3;
TaskHandle_t SensorTask4;
TaskHandle_t SensorTask5;
TaskHandle_t SensorTask6;
TaskHandle_t SensorTask7;
TaskHandle_t SensorTask8;
TaskHandle_t SensorTask9;
TaskHandle_t SensorTask10;
TaskHandle_t SensorTask11;
TaskHandle_t SensorTask12;
TaskHandle_t SensorTask13;

//------------------------------------------------------------------------------
ADS1015_DATA ads1015_data;
BME680_DATA bme680_data;
D6410_DATA d6410_data;
HM330X_DATA hm330x_data;
MDWS_DATA mdws_data;
MLX90614_DATA mlx90614_data;
RG11_DATA rg11_data;
RS12_DATA rs12_data;
SCD41_DATA scd41_data;
SH1106_DATA sh1106_data;
TSL2591_DATA tsl2591_data;
WIFI_DATA wifi_data;

JSON_CLIENT_DATA json_client_data;

DEWPOINT_DATA dewpoint_data;
AQI_DATA aqi_data;
SQI_DATA sqi_data;

//------------------------------------------------------------------------------
/**
 * @brief Start OTA
 *
 */
void onOTAStart()
{
  // Log when OTA has started
  Serial.println("OTA update started!");
}

//------------------------------------------------------------------------------
/**
 * @brief Progress OTA
 *-
 */
void onOTAProgress(size_t current, size_t final)
{
  // Log every 1 second
  if (millis() - ota_progress_millis > 1000) {
    ota_progress_millis = millis();
    Serial.printf("OTA Progress Current: %u bytes, Final: %u bytes\n", current, final);
  }
}

//------------------------------------------------------------------------------
/**
 * @brief End OTA
 *
 */
void onOTAEnd(bool success)
{
  // Log when OTA has finished
  if (success) {
    Serial.println("OTA update finished successfully!");
  } else {
    Serial.println("There was an error during OTA update!");
  }
}

//------------------------------------------------------------------------------
/**
 * @brief Sensor task 1 -- ADA1015
 *
 */
void sensorTask1(void* parameter)
{
  while (true) {
    getADS105Values(&ads1015_data);

    if (SERIAL_OUTPUT == true) {
      Serial.printf("AO0      = %.1f V \n", ads1015_data.ai0);
      Serial.printf("AO1      = %.1f V \n", ads1015_data.ai1);
      Serial.printf("AO2      = %.1f V \n", ads1015_data.ai2);
      Serial.printf("AO3      = %.1f V \n", ads1015_data.ai3);
    }

    vTaskDelay(pdMS_TO_TICKS(task_delay));
  }
}

//------------------------------------------------------------------------------
/**
 * @brief Sensor task 2 -- BME680
 *
 */
void sensorTask2(void* parameter)
{
  while (true) {
    getBME680Values(&bme680_data);

    dewpoint_data.temp = bme680_data.temperature;
    dewpoint_data.humi = bme680_data.humidity;

    calcDEWPOINT(&dewpoint_data);

    if (bme680_data.status == false) {
      Serial.println("Failed to perform reading BME680.");
    }

    if (SERIAL_OUTPUT == true) {
      Serial.printf("Temp     = %.1f ºC   \n", bme680_data.temperature);
      Serial.printf("Humi     = %.1f %%   \n", bme680_data.humidity);
      Serial.printf("Pres     = %.1f mbar \n", bme680_data.pressure);
      Serial.printf("AQ       = %.1f AQI  \n", bme680_data.airquality);
      Serial.printf("Dewpoint = %.1f ºC   \n", dewpoint_data.dewpoint);
    }
    vTaskDelay(pdMS_TO_TICKS(task_delay));
  }
}

//------------------------------------------------------------------------------
/**
 * @brief ISR D6410
 *
 */
void IRAM_ATTR handle_ISR_D6410()
{
  pulseCount++; // Increment pulse count on each interrupt
}

//------------------------------------------------------------------------------
/**
 * @brief calculateWindSpeed
 *
 */
float calculateWindSpeed(float rpm)
{
  float windSpeedMS = rpm * anemometerFactor; // Convert RPM to wind speed in m/s
  return windSpeedMS;
}

//------------------------------------------------------------------------------
/**
 * @brief Sensor task 3 -- D6410
 *
 */
void sensorTask3(void* parameter)
{
  while (true) {
    unsigned long currentTime = millis();
    if (currentTime - lastTime >= 1000) { // Calculate RPM every second
      float rpm = (pulseCount / (float)pulsesPerRevolution) * 60.0;
      d6410_data.windSpeed_ms = calculateWindSpeed(rpm);
      d6410_data.windSpeed_kmh = d6410_data.windSpeed_ms * 3.6;

      pulseCount = 0; // Reset pulse count
      lastTime = currentTime;
    }

    d6410_data.windDIR = ads1015_data.ai3;

    getD6410Values(&d6410_data);

    if (SERIAL_OUTPUT == true) {
      Serial.printf("WindDIR  = %02d deg \n", d6410_data.windDIR);
      Serial.printf("WindSPD  = %02d ms  \n", d6410_data.windSpeed_ms);
      Serial.printf("WindDIR  = %02d kmh \n", d6410_data.windSpeed_kmh);
    }

    vTaskDelay(pdMS_TO_TICKS(task_delay));
  }
}

//------------------------------------------------------------------------------
/**
 * @brief Sensor task 4 -- HM330x
 *
 */
void sensorTask4(void* parameter)
{
  while (true) {
    getHM330XValues(&hm330x_data);
    aqi_data.pm25 = hm330x_data.PM25;
    calcAQI_PM25(&aqi_data);

    if (SERIAL_OUTPUT == true) {
      Serial.printf("PM1.0    = %02d µg/m^3 \n", hm330x_data.PM1);
      Serial.printf("PM2.5    = %02d µg/m^3 \n", hm330x_data.PM25);
      Serial.printf("PM10     = %02d µg/m^3 \n", hm330x_data.PM10);
    }

    vTaskDelay(pdMS_TO_TICKS(task_delay));
  }
}

//------------------------------------------------------------------------------
/**
 * @brief Sensor task 5 -- MDWS
 *
 */
void sensorTask5(void* parameter)
{
  while (true) {
    mdws_data.rawdata_temp = ads1015_data.ai0;
    mdws_data.rawdata_wind = ads1015_data.ai2;

    getMDWSValues(&mdws_data);

    if (SERIAL_OUTPUT == true) {
      Serial.printf("MD Wind  = %.1f m/s \n", mdws_data.windms);
      Serial.printf("MD Temp  = %.1f ºC  \n", mdws_data.temperature);
    }

    vTaskDelay(pdMS_TO_TICKS(task_delay));
  }
}

//------------------------------------------------------------------------------
/**
 * @brief Sensor task 6 -- MLX90614
 *
 */
void sensorTask6(void* parameter)
{
  while (true) {
    getMLX90614Values(&mlx90614_data);

    if (SERIAL_OUTPUT == true) {
      Serial.printf("AmbiTemp = %.1f ºC \n", mlx90614_data.AmbiTemp);
      Serial.printf("ObjTemp  = %.1f ºC \n", mlx90614_data.ObjTemp);
    }

    vTaskDelay(pdMS_TO_TICKS(task_delay));
  }
}

//------------------------------------------------------------------------------
/**
 * @brief ISR RG11
 *
 */
void IRAM_ATTR handle_ISR_RG11()
{
  dropCount++;
  rainStatus = RAIN_DETECTED;
}

//------------------------------------------------------------------------------
/**
 * @brief Sensor task 7 -- RG11
 *
 */
void sensorTask7(void* parameter)
{
  while (true) {
    getRG11Values(&rg11_data);

    // unsigned long currentTime = millis();
    // if (currentTime - lastCheckTime >= interval)
    // {
    //   Serial.print("Raindrops per second: ");
    //   Serial.println(dropCount);
    //   dropCount = 0;
    //   lastCheckTime = currentTime;
    // }

    vTaskDelay(pdMS_TO_TICKS(task_delay));
  }
}

//------------------------------------------------------------------------------
/**
 * @brief Sensor task 8 -- RS12
 *
 */
void sensorTask8(void* parameter)
{
  while (true) {
    getRS12Values(&rs12_data);

    vTaskDelay(pdMS_TO_TICKS(task_delay));
  }
}

//------------------------------------------------------------------------------
/**
 * @brief Sensor task 9 -- SCD41
 *
 */
void sensorTask9(void* parameter)
{
  while (true) {
    getSCD41Values(&scd41_data);

    if (SERIAL_OUTPUT == true) {
      Serial.printf("CO2      = %.f ppm \n", scd41_data.co2);
      Serial.printf("Temp     = %.1f ºC \n", scd41_data.temperature);
      Serial.printf("Humi     = %.1f %% \n", scd41_data.humidity);
    }

    vTaskDelay(pdMS_TO_TICKS(task_delay));
  }
}

//------------------------------------------------------------------------------
/**
 * @brief Sensor task 10 -- SH1106
 *
 */
void sensorTask10(void* parameter)
{
  while (true) {
    sh1106_data.temp = scd41_data.temperature;
    sh1106_data.wifistrength = wifi_data.WifiSignal;
    sh1106_data.ipadress = wifi_data.IPAddress;

    setSH1106Values(&sh1106_data);

    vTaskDelay(pdMS_TO_TICKS(task_delay));
  }
}

//------------------------------------------------------------------------------
/**
 * @brief Sensor task 11 -- TSL2591
 *
 */
void sensorTask11(void* parameter)
{
  while (true) {
    getTSL2591Values(&tsl2591_data);

    if (SERIAL_OUTPUT == true) {
      Serial.printf("LVIS     = %02d lum \n", tsl2591_data.vis);
      Serial.printf("LNIR     = %02d lum \n", tsl2591_data.nir);
      Serial.printf("LFULL    = %02d lux \n", tsl2591_data.lux);
    }

    vTaskDelay(pdMS_TO_TICKS(task_delay));
  }
}

//------------------------------------------------------------------------------
/**
 * @brief Sensor task 12 -- WIFI
 *
 */
void sensorTask12(void* parameter)
{
  while (true) {
    CalcWiFiStrength(&wifi_data);

    if (SERIAL_OUTPUT == true) {
      Serial.printf("WIFI     = %02d dBm \n", wifi_data.WifiSignal);
    }

    vTaskDelay(pdMS_TO_TICKS(task_delay));
  }
}

//------------------------------------------------------------------------------
/**
 * @brief Sensor task 13 -- JSON CLIENT
 *
 */
void sensorTask13(void* parameter)
{
  while (true) {
    fetchJSON(&json_client_data);
    Serial.println(json_client_data.temp);
    
    vTaskDelay(pdMS_TO_TICKS(task_delay));
  }
}

//------------------------------------------------------------------------------
/**
 * @brief Setup all
 *
 */
void setup()
{
  Serial.begin(115200);
  delay(2000);
  Serial.printf("Starting FreeRTOS/ESP32S3 \n");
  Serial.printf("ESP Wetterstation \n");
  Serial.printf("Apprelease: ", __APPRELEASE__, "\n");
  Serial.printf("Appdate: ", __APPDATE__, "\n");
  Serial.printf("\n");
  Serial.printf("--------------------------\n");
  Serial.printf("\n");

  /* D1 */
  pinMode(ANEOMETER_ISR_PIN, INPUT_PULLUP);
  attachInterrupt(ANEOMETER_ISR_PIN, handle_ISR_D6410, RISING);

  /* D2 */
  pinMode(RG11_ISR_PIN, INPUT_PULLUP);
  attachInterrupt(RG11_ISR_PIN, handle_ISR_RG11, FALLING);

  initWiFi(ssid, password);

  Wire.begin();

  initADS1015();
  initBME680();
  initD6410();
  initHM330X();
  initMDWS();
  initMLX90614();
  initRG11();
  initRS12();
  initSCD41();
  initSH1106();
  initTSL2591();

  initJSONClient();

  Serial.printf("Sensors connected\n");

  // Initialize LittleFS
  if (!LittleFS.begin(true)) {
    Serial.println("An error occurred while mounting LittleFS");
    return;
  }

  // Initialize LittleFS instead of LittleFS
  if (!LittleFS.begin(true)) {
    Serial.println("LittleFS Mount Failed!");
    return;
  }
  Serial.println("LittleFS Mounted!");

  //-----------------------------------------------------------------------------
  /* HTTP server */
  server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
    File file = LittleFS.open("/index.html", "r");
    if (!file) {
      request->send(500, "text/plain", "Failed to load HTML file");
      return;
    }

    String html = file.readString();
    file.close();

    /* App and website informations */
    html.replace("{{APPNAME}}", String(__APPNAME__).c_str());
    html.replace("{{APPRELEASE}}", String(__APPRELEASE__).c_str());
    html.replace("{{APPDATE}}", String(__APPDATE__).c_str());

    /* Sensor data */
    html.replace("{{ads1015_data_ai0}}", String(ads1015_data.ai0, 1).c_str());
    html.replace("{{ads1015_data_ai1}}", String(ads1015_data.ai1, 1).c_str());
    html.replace("{{ads1015_data_ai2}}", String(ads1015_data.ai2, 1).c_str());
    html.replace("{{ads1015_data_ai3}}", String(ads1015_data.ai3, 1).c_str());
    html.replace("{{bme680_data_temperature}}", String(bme680_data.temperature, 1).c_str());
    html.replace("{{bme680_data_humidity}}", String(bme680_data.humidity, 1).c_str());
    html.replace("{{bme680_data_pressure}}", String(bme680_data.pressure, 1).c_str());
    html.replace("{{bme680_data_airquality}}", String(bme680_data.airquality, 1).c_str());
    html.replace("{{d6410_data_windDIR}}", String(d6410_data.windDIR, 1).c_str());
    html.replace("{{d6410_data_windSPD}}", String(d6410_data.windSpeed_ms, 1).c_str());
    html.replace("{{hm330x_data_PM1}}", String(hm330x_data.PM1).c_str());
    html.replace("{{hm330x_data_PM25}}", String(hm330x_data.PM25).c_str());
    html.replace("{{hm330x_data_PM10}}", String(hm330x_data.PM10).c_str());
    html.replace("{{mdws_data_windms}}", String(mdws_data.windms, 1).c_str());
    html.replace("{{mdws_data_temperature}}", String(mdws_data.temperature, 1).c_str());
    html.replace("{{mlx90614_data_AmbiTemp}}", String(mlx90614_data.AmbiTemp, 1).c_str());
    html.replace("{{mlx90614_data_ObjTemp}}", String(mlx90614_data.ObjTemp, 1).c_str());
    html.replace("{{scd41_data_co2}}", String(scd41_data.co2, 0).c_str());
    html.replace("{{scd41_data_temperature}}", String(scd41_data.temperature, 1).c_str());
    html.replace("{{scd41_data_humidity}}", String(scd41_data.humidity, 1).c_str());
    html.replace("{{tsl2591_data_vis}}", String(tsl2591_data.vis).c_str());
    html.replace("{{tsl2591_data_nir}}", String(tsl2591_data.nir).c_str());
    html.replace("{{tsl2591_data_lux}}", String(tsl2591_data.lux).c_str());
    html.replace("{{dewpoint}}", String(dewpoint_data.dewpoint).c_str());
    html.replace("{{skyquality_norm}}", String(sqi_data.sqi_norm).c_str());
    html.replace("{{skyquality_freq}}", String(sqi_data.sqi_freq).c_str());
    html.replace("{{airqualityindex}}", String(aqi_data.aqi_idx).c_str());
    html.replace("{{wifi_data_WifiSignal}}", String(wifi_data.WifiSignal).c_str());
    // Replace template placeholders with JSON data
    html.replace("{{json_client_init}}", json_client_data.status ? "true" : "false");
    html.replace("{{json_client_temp}}", String(json_client_data.temp, 1));
    html.replace("{{json_client_pres}}", String(json_client_data.pres, 1));
    html.replace("{{json_client_humi}}", String(json_client_data.humi, 1));
    html.replace("{{json_client_airq}}", String(json_client_data.airq, 1));
    
        request->send(200, "text/html", html);
  });

  server.on("/style.css", HTTP_GET,
      [](AsyncWebServerRequest* request) { request->send(LittleFS, "/style.css", "text/css"); });

  server.on("/favicon.png", HTTP_GET,
      [](AsyncWebServerRequest* request) { request->send(LittleFS, "/favicon.png", "image/png"); });

  server.begin();

  Serial.printf("HTTP Server started\n");

  //-----------------------------------------------------------------------------
  /* ElegantOTA */
  ElegantOTA.begin(&server); // Start ElegantOTA
  // ElegantOTA callbacks
  ElegantOTA.onStart(onOTAStart);
  ElegantOTA.onProgress(onOTAProgress);
  ElegantOTA.onEnd(onOTAEnd);

  //-----------------------------------------------------------------------------
  /* REST API endpoint to return sensor values in JSON format */

  server.on("/api/sensors", HTTP_GET, [](AsyncWebServerRequest* request) {
    String jsonResponse = getSensorsJson();
    request->send(200, "application/json", jsonResponse);
  });

  Serial.printf("JSON Server started\n");

  //-----------------------------------------------------------------------------
  /* OTA Support*/
  ElegantOTA.begin(&server);

  server.begin();

  //-----------------------------------------------------------------------------
  /* Initialize the tasks */
  xTaskCreatePinnedToCore(sensorTask1, "SensorTask1", 4096, NULL, 1, &SensorTask1, 1);
  xTaskCreatePinnedToCore(sensorTask2, "SensorTask2", 4096, NULL, 1, &SensorTask2, 1);
  xTaskCreatePinnedToCore(sensorTask3, "SensorTask3", 4096, NULL, 1, &SensorTask3, 1);
  xTaskCreatePinnedToCore(sensorTask4, "SensorTask4", 4096, NULL, 1, &SensorTask4, 1);
  xTaskCreatePinnedToCore(sensorTask5, "SensorTask5", 4096, NULL, 1, &SensorTask5, 1);
  xTaskCreatePinnedToCore(sensorTask6, "SensorTask6", 4096, NULL, 1, &SensorTask6, 1);
  xTaskCreatePinnedToCore(sensorTask7, "SensorTask7", 4096, NULL, 1, &SensorTask7, 1);
  xTaskCreatePinnedToCore(sensorTask8, "SensorTask8", 4096, NULL, 1, &SensorTask8, 1);
  xTaskCreatePinnedToCore(sensorTask9, "SensorTask9", 4096, NULL, 1, &SensorTask9, 1);
  xTaskCreatePinnedToCore(sensorTask10, "SensorTask10", 4096, NULL, 1, &SensorTask10, 1);
  xTaskCreatePinnedToCore(sensorTask11, "SensorTask11", 4096, NULL, 1, &SensorTask11, 1);
  xTaskCreatePinnedToCore(sensorTask12, "SensorTask12", 4096, NULL, 1, &SensorTask12, 1);
  xTaskCreatePinnedToCore(sensorTask13, "SensorTask13", 4096, NULL, 1, &SensorTask13, 1);

  Serial.printf("Startup finished\n\n");
}

//------------------------------------------------------------------------------
/**
 * @brief Main loop, nothing to do due to threads ...
 *
 */
void loop() { }
