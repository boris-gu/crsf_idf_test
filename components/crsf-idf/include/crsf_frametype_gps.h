/**
 * GPS position, ground speed, heading, altitude, satellite count
 * https://github.com/crsf-wg/crsf/wiki/CRSF_FRAMETYPE_GPS
 */
#pragma once

#include <stdio.h>
#include "crsf_frametype_default.h"

#define CRSF_FRAMETYPE_GPS 0x02

typedef struct {
  uint8_t sync;
  uint8_t len;
  uint8_t type;

  int32_t lat;
  int32_t lon;
  int16_t g_speed;
  int16_t g_course;
  uint16_t gps_alt;
  uint8_t sat_count;

  uint8_t crc8;
} crsf_gps;

crsf_gps crsf_default2gps(crsf_default pkt);

int crsf_gps2array(crsf_gps in_pkt, uint8_t* out_pkt);