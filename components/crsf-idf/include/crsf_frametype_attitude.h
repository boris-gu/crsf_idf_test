/**
 * Attitude: pitch, roll, yaw
 * https://github.com/crsf-wg/crsf/wiki/CRSF_FRAMETYPE_ATTITUDE
 */
#pragma once

#include <stdio.h>
#include "crsf_frametype_default.h"

#define CRSF_FRAMETYPE_ATTITUDE 0x1E

typedef struct {
  uint8_t sync;
  uint8_t len;
  uint8_t type;

  int16_t pitch;
  int16_t roll;
  int16_t yaw;

  uint8_t crc8;
} crsf_attitude;

crsf_attitude crsf_default2attitude(crsf_default pkt);

int crsf_attitude2array(crsf_attitude in_pkt, uint8_t* out_pkt);