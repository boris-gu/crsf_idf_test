/**
 * (CRSFv3) Heartbeat
 * https://github.com/crsf-wg/crsf/wiki/CRSF_FRAMETYPE_HEARTBEAT
 */
#pragma once

#include <stdio.h>
#include "crsf_frametype_default.h"

#define CRSF_FRAMETYPE_HEARTBEAT 0x0B

typedef struct {
  uint8_t sync;
  uint8_t len;
  uint8_t type;

  uint16_t origin_addr;

  uint8_t crc8;
} crsf_heartbeat;

crsf_heartbeat crsf_default2heartbeat(crsf_default pkt);

int crsf_heartbeat2array(crsf_heartbeat in_pkt, uint8_t* out_pkt);