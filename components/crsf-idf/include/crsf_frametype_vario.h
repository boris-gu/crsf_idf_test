/**
 * Vertical speed
 * https://github.com/crsf-wg/crsf/wiki/CRSF_FRAMETYPE_VARIO
 */
#pragma once

#include <stdio.h>
#include "crsf_frametype_default.h"

#define CRSF_FRAMETYPE_VARIO 0x07

typedef struct {
  uint8_t sync;
  uint8_t len;
  uint8_t type;

  int16_t v_speed;

  uint8_t crc8;
} crsf_crsf_vario;

crsf_crsf_vario crsf_default2vario(crsf_default pkt);

int crsf_crsf_vario2array(crsf_crsf_vario in_pkt, uint8_t* out_pkt);