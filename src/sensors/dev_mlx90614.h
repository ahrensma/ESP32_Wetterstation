/**
 * @file dev_MLX90614.h
 * @author Martin Ahrens
 * @date 2025_Q1
 */

#ifndef _DEV_MLX90614_H
#define _DEV_MLX90614_H

#include <Adafruit_MLX90614.h>

/**
 * @struct MLX90614_DATA
 * @param bool status
 * @param float AmbiTemp
 * @param float ObjTemp
 */
struct MLX90614_DATA
{
  bool status;
  float AmbiTemp;
  float ObjTemp;
};

/**
 * @brief Init MLX90614
 *
 */
void initMLX90614();

/**
 * @brief Get MLX90614 values
 * @param mlx90614_data
 *
 */
void getMLX90614Values(MLX90614_DATA *mlx90614_data);

#endif /* _DEV_MLX90614_H */