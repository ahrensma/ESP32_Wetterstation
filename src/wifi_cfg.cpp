/**
 * @file wifi_cfg.cpp
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#include "wifi_cfg.h"

//-----------------------------------------------------------------------------
void initWiFi(const char* ssid, const char* password)
{

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" Connected!");
  Serial.println(WiFi.localIP());
}

//-----------------------------------------------------------------------------
void CalcWiFiStrength(WIFI_DATA* wifi_data)
{
  for (int x = 0; x < 100; x = x + 1) {
    if (signal_dBM[x] == WiFi.RSSI()) {
      wifi_data->WifiSignal = signal_percent[x];
    }
  }
  wifi_data->IPAddress = WiFi.localIP().toString();
}
