/**
 * @file read_json.h
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#ifndef _READ_JSON_H
#define _READ_JSON_H

#include <ArduinoJson.h>
#include <HTTPClient.h>

/**
 * @struct JSON_CLIENT_DATA
 * @param bool status
 * @param float temp
 * @param float pres
 * @param float humi
 * @param float airq
 */
struct JSON_CLIENT_DATA {
    bool status;
    float temp;
    float pres;
    float humi;
    float airq;
  };

void initJSONClient();

void fetchJSON(JSON_CLIENT_DATA* json_client_data);

#endif /* _READ_JSON_H */ 