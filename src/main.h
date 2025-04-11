/**
 * @file main.h
 * @author Martin Ahrens
 * @date 2025_Q2
 */

#ifndef _MAIN_H
#define _MAIN_H

unsigned long ota_progress_millis = 0;

// Interrupt Variables and global variables
const int pulsesPerRevolution = 20; // Adjust based on encoder specs
const float anemometerFactor = 0.1; // Adjust based on your specific anemometer
volatile int pulseCount = 0;
unsigned long lastTime = 0;

RainState rainStatus = NO_RAIN; // Now RainState is defined
volatile int dropCount = 0;
unsigned long lastCheckTime = 0;
uint16_t task_delay = 2000;
const unsigned long interval = 1000; // 1 second interval

struct BME680_JSON_Data {
  bool init;
  float Temp;
  float Pres;
  float Hum;
  float Air;
};

BME680_JSON_Data bme680_json_data;

//------------------------------------------------------------------------------
#endif /* _MAIN_H */