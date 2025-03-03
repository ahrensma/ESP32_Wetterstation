/**
 * @file config.h
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#ifndef _CONFIG_H
#define _CONFIG_H

#include "FS.h"
#include <Adafruit_Sensor.h>
#include <Arduino.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ElegantOTA.h> /* https://github.com/ayushsharma82/ElegantOTA */
#include <LittleFS.h>
#include <NTPClient.h>
#include <PubSubClient.h>
#include <TimeLib.h>
#include <Wire.h>
#include <math.h>

//------------------------------------------------------------------------------
#include "mysecrets.h"
#include "wifi_cfg.h"

#include "sensors/dev_MDWS.h"
#include "sensors/dev_ads1015.h"
#include "sensors/dev_bme680.h"
#include "sensors/dev_d6410.h"
#include "sensors/dev_hm330x.h"
#include "sensors/dev_mlx90614.h"
#include "sensors/dev_rg11.h"
#include "sensors/dev_rs12.h"
#include "sensors/dev_scd41.h"
#include "sensors/dev_sh1106.h"
#include "sensors/dev_tsl2591.h"

#include "calc/aqi.h"
#include "calc/dewpoint.h"
#include "calc/sqi.h"

//------------------------------------------------------------------------------
#define __APPNAME__ "ESP Wetterstation"
#define __APPRELEASE__ 0.2
#define __APPDATE__ "2025 Q1"

//------------------------------------------------------------------------------
/* OTA Variables */
unsigned long ota_progress_millis = 0;

//------------------------------------------------------------------------------
/* Pin definition */
#define ANEOMETER_ISR_PIN 2
#define RG11_ISR_PIN 3

/* Interrupt Variables */
volatile int pulseCount = 0; // Variable to track pulses
unsigned long lastTime = 0;
const int pulsesPerRevolution = 20; // Adjust based on encoder specs
const float anemometerFactor = 0.1; // Adjust based on your specific anemometer

//------------------------------------------------------------------------------
typedef enum { NO_RAIN, RAIN_DETECTED } RainState;

RainState rainStatus = NO_RAIN;

volatile int dropCount = 0;
unsigned long lastCheckTime = 0;
const unsigned long interval = 1000; // 1 second interval for drops per second calculation

//------------------------------------------------------------------------------
/* Serial output yes or no */
#define SERIAL_OUTPUT false

/* Task  delay time in milliseconds */
uint16_t task_delay = 2000;

//------------------------------------------------------------------------------
#endif /* _CONFIG_H */
