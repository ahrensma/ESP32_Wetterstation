#include "read_json.h"
#include <ArduinoJson.h> // Ensure the library is included

const char* serverUrl = "http://192.168.1.108:3000/data";

void initJSONClient() { Serial.println("JSON Client initialized"); }

void fetchJSON(JSON_CLIENT_DATA* json_client_data)
{
  HTTPClient http;
  http.begin(serverUrl);
  int httpResponseCode = http.GET();

  if (httpResponseCode > 0) {
    String payload = http.getString();
    // Serial.println("Received JSON:");
    // Serial.println(payload);

    // Use StaticJsonDocument with a fixed capacity
    StaticJsonDocument<1024> doc; // Adjust size as needed
    DeserializationError error = deserializeJson(doc, payload);
    if (error) {
      Serial.print("JSON Parsing failed: ");
      Serial.println(error.f_str());
      http.end();
      return;
    }

    // Access the BME680 object from the JSON
    JsonObject bme680 = doc["BME680"];
    if (!bme680.isNull()) {
      Serial.println("yeah");
      
      json_client_data->status = bme680["status"];
      json_client_data->temp = bme680["temp"];
      json_client_data->pres = bme680["pres"];
      json_client_data->humi = bme680["humi"];
      json_client_data->airq = bme680["airq"];
     } else {
      Serial.println("Oh no ...");
      Serial.println("BME680 object not found in JSON.");
      json_client_data->status = false;
      json_client_data->temp = -999;
      Serial.println(-999);
      json_client_data->pres = -999;
      json_client_data->humi = -999;
      json_client_data->airq = -999;
     }
  } else {
    Serial.print("HTTP Error: ");
    Serial.println(httpResponseCode);
  }
  http.end();
}