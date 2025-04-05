/**
 * @file read_json.h
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#ifndef _READ_JSON_H
#define _READ_JSON_H

#include <ArduinoJson.h>
#include <HTTPClient.h>

void initJSONClient();

void fetchJSON();

#endif /* _READ_JSON_H */