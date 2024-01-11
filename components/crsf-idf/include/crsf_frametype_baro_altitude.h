/**
 * Barometric altitude, vertical speed (optional)
 * https://github.com/crsf-wg/crsf/wiki/CRSF_FRAMETYPE_BARO_ALTITUDE
 */
#pragma once

#include <stdio.h>
#include "crsf_frametype_default.h"

#define CRSF_FRAMETYPE_BARO_ALTITUDE 0x09

typedef struct {
  uint8_t sync;
  uint8_t len;
  uint8_t type;

  uint16_t altitude;
  int16_t v_speed;

  uint8_t crc8;
} crsf_baro_altitude;

crsf_baro_altitude crsf_default2baro_altitude(crsf_default pkt);

int crsf_baro_altitude2array(crsf_baro_altitude in_pkt, uint8_t* out_pkt);