
#include "read_json.h"

// JSON server URL
const char* serverUrl = "http://your-json-server.com/data";

void initJSONClient()
{
  // Initialize JSON client
  Serial.println("JSON Client initialized");
}

void fetchJSON()
{
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverUrl);
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      String payload = http.getString();
      Serial.println("Received JSON:");
      Serial.println(payload);

      // Parse JSON
      JsonDocument doc;
      doc.to<JsonObject>(); // Convert to JSON object
      DeserializationError error = deserializeJson(doc, payload);

      if (error) {
        Serial.print("JSON Parsing failed: ");
        Serial.println(error.f_str());
        return;
      }

      // Extract values based on JSON structure
      const char* name = doc["name"];
      int value = doc["value"];

      Serial.print("Name: ");
      Serial.println(name);
      Serial.print("Value: ");
      Serial.println(value);
    } else {
      Serial.print("HTTP Error: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  } else {
    Serial.println("WiFi not connected");
  }
}
