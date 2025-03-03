/**
 * @file dev_mlx90614.cpp
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#include "dev_mlx90614.h"

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

//-----------------------------------------------------------------------------
void initMLX90614()
{

  if (mlx.begin() == false) {
    Serial.println("Error connecting to MLX sensor. Check wiring.");
    while (1)
      ;
  };
}

//-----------------------------------------------------------------------------
void getMLX90614Values(MLX90614_DATA* mlx90614_data)
{

  mlx90614_data->AmbiTemp = mlx.readAmbientTempC();
  mlx90614_data->ObjTemp = mlx.readObjectTempC();
}
