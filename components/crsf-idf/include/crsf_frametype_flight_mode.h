/**
 * Flight controller flight mode string
 * https://github.com/crsf-wg/crsf/wiki/CRSF_FRAMETYPE_flight_mode
 */
#pragma once

#include <stdio.h>
#include "crsf_frametype_default.h"

#define CRSF_FRAMETYPE_FLIGHT_MODE 0x21

typedef struct {
  uint8_t sync;
  uint8_t len;
  uint8_t type;

  char mode[14];

  uint8_t crc8;
} crsf_flight_mode;

crsf_flight_mode crsf_default2flight_mode(crsf_default pkt);

int crsf_flight_mode2array(crsf_flight_mode in_pkt, uint8_t* out_pkt);