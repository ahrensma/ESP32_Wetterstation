/**
 * @file dev_hm330x.cpp
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#include "dev_hm330x.h"

Tomoto_HM330X hm330x;

//-----------------------------------------------------------------------------
void initHM330X()
{

  if (hm330x.begin() == false) {
    Serial.println(F("HM330x not detected ..."));
    while (1)
      ;
  }
}

//-----------------------------------------------------------------------------
void getHM330XValues(HM330X_DATA* hm330x_data)
{

  if (!hm330x.readSensor()) {
    ;
  } else {
    hm330x_data->PM1 = hm330x.atm.getPM1();
    hm330x_data->PM25 = hm330x.atm.getPM2_5();
    hm330x_data->PM10 = hm330x.atm.getPM10();
  }
}