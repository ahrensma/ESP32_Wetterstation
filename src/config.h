/**
 * @file config.h
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#ifndef _CONFIG_H
#define _CONFIG_H

#include <Arduino.h>
#include "FS.h"
#include <LittleFS.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <PubSubClient.h>
#include <ElegantOTA.h> /* https://github.com/ayushsharma82/ElegantOTA */
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <NTPClient.h>
#include <TimeLib.h>
#include <math.h>

//------------------------------------------------------------------------------
#include "mysecrets.h"
#include "wifi_cfg.h"
#include "sensors/dev_ads1015.h"
#include "sensors/dev_bme680.h"
#include "sensors/dev_d6410.h"
#include "sensors/dev_hm330x.h"
#include "sensors/dev_MDWS.h"
#include "sensors/dev_mlx90614.h"
#include "sensors/dev_rg11.h"
#include "sensors/dev_rs12.h"
#include "sensors/dev_scd41.h"
#include "sensors/dev_sh1106.h"
#include "sensors/dev_tsl2591.h"

#include "calc/dewpoint.h"
#include "calc/aqi.h"
#include "calc/sqm.h"

//------------------------------------------------------------------------------
#define __APPNAME__ "ESP Wetterstation"
#define __APPRELEASE__ 0.10
#define __APPDATE__ "2025 Q1"

//------------------------------------------------------------------------------
/* Pin D1 for interrupt purpose, see d6410.h for more information */
#define ANEOMETER_ISR_PIN 2

//------------------------------------------------------------------------------

/* OTA Variables */
unsigned long ota_progress_millis = 0;

/* Interrupt Variables */
volatile int pulseCount = 0;        // Variable to track pulses
unsigned long lastTime = 0;
const int pulsesPerRevolution = 20; // Adjust based on encoder specs
const float anemometerFactor = 0.1; // Adjust based on your specific anemometer

/* Serial output yes or no */
#define SERIAL_OUTPUT false

/* Task  delay time in milliseconds */
uint16_t task_delay = 2000;

//------------------------------------------------------------------------------
#endif /* _CONFIG_H */