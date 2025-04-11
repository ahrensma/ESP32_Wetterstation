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

#pragma once

//------------------------------------------------------------------------------
#define __APPNAME__ "ESP Wetterstation"
#define __APPRELEASE__ 0.3
#define __APPDATE__ "2025 Q2"

//------------------------------------------------------------------------------
/* Pin definition */
#define ANEOMETER_ISR_PIN 2
#define RG11_ISR_PIN 3

/* Rain State */
typedef enum { NO_RAIN, RAIN_DETECTED } RainState;

/* Serial output yes or no */
#define SERIAL_OUTPUT false

//------------------------------------------------------------------------------
#endif /* _CONFIG_H */
