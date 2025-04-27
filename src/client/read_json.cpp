#include "read_json.h"
#include <ArduinoJson.h> // Ensure the library is included

const char* serverUrl = "http://192.168.1.13";

void initJSONClient() { Serial.println("JSON Client initialized"); }

void fetchJSON(JSON_CLIENT_DATA* json_client_data)
{
  HTTPClient http;
  http.begin(serverUrl);
  int httpResponseCode = http.GET();

  if (httpResponseCode > 0) {
    String payload = http.getString();

    // Use StaticJsonDocument with a fixed capacity
    StaticJsonDocument<1024> doc; // Adjust size as needed
    DeserializationError error = deserializeJson(doc, payload);
    if (error) {
      Serial.print("JSON Parsing failed: ");
      Serial.println(error.f_str());
      http.end();
      return;
    }

    if (doc.containsKey("weather")) {
      JsonObject weather = doc["weather"];
      if (weather.containsKey("BME680")) {
        JsonObject bme680 = weather["BME680"];
        Serial.println("BME680 object found in JSON.");

        // Parse and store the sensor data
        json_client_data->status = bme680["init"];
        json_client_data->temp = bme680["Temp"];
        json_client_data->pres = bme680["Pres"];
        json_client_data->humi = bme680["Hum"];
        json_client_data->airq = bme680["Air"];

        // Print out the values to debug
        Serial.print("Temperature: ");
        Serial.println(json_client_data->temp);
        Serial.print("Pressure: ");
        Serial.println(json_client_data->pres);
        Serial.print("Humidity: ");
        Serial.println(json_client_data->humi);
      }
    }

  } else {
    Serial.print("HTTP Error: ");
    Serial.println(httpResponseCode);
  }
  http.end();
}