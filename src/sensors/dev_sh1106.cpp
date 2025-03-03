/**
 * @file dev_sh1106.cpp
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#include "dev_sh1106.h"

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//-----------------------------------------------------------------------------
void initSH1106()
{
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("ESP32 Wetterstation");
  display.display();
}

//-----------------------------------------------------------------------------
void setSH1106Values(SH1106_DATA* sh1106_data)
{
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(sh1106_data->ipadress);
  display.setCursor(0, 10);
  display.println(sh1106_data->wifistrength);
  display.setCursor(0, 20);
  display.println(sh1106_data->temp);
  display.display();
}
