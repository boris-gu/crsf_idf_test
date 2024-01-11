/**
 * Battery voltage, current, mAh, remaining percent
 * https://github.com/crsf-wg/crsf/wiki/CRSF_FRAMETYPE_BATTERY_SENSOR
 */
#pragma once

#include <stdio.h>
#include "crsf_frametype_default.h"

#define CRSF_FRAMETYPE_BATTERY_SENSOR 0x08

typedef struct {
  uint8_t sync;
  uint8_t len;
  uint8_t type;

  int16_t voltage;
  int16_t current;
  int32_t used : 24;
  int8_t estimated;

  uint8_t crc8;
} crsf_battery_sensor;

crsf_battery_sensor crsf_default2battery_sensor(crsf_default pkt);

int crsf_battery_sensor2array(crsf_battery_sensor in_pkt, uint8_t* out_pkt);