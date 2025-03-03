/**
 * @file dev_sh1106.h
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#ifndef _DEV_SH1106_H
#define _DEV_SH1106_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

/**
 * @struct SH1106_DATA
 * @param bool status
 * @param String ipadress
 * @param int wifistrength
 * @param float temp
 */
struct SH1106_DATA {
  bool status;
  String ipadress;
  int wifistrength;
  float temp;
};

/**
 * @brief Init SH1106 / 128x64 OLED display
 *
 */
void initSH1106();

/**
 * @brief Get SH1106 values
 * @param sh1106_data
 *
 */
void setSH1106Values(SH1106_DATA* sh1106_data);

#endif /* _DEV_SH1106_H */