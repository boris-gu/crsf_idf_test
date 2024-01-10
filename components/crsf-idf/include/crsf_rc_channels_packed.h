/**
 * Channels data (both handset to TX and RX to flight controller)
 * https://github.com/crsf-wg/crsf/wiki/CRSF_FRAMETYPE_RC_CHANNELS_PACKED
 */
#pragma once

#include <stdio.h>
#include "crsf.h"

typedef struct {
  uint8_t sync;
  uint8_t len;
  uint8_t type;

  uint16_t ch[16];

  uint8_t crc8;
} crsf_rc_channels_packed;

crsf_rc_channels_packed crsf_default2rc_channels_packed(crsf_default pkt);

int crsf_rc_channels_packed2array(crsf_rc_channels_packed in_pkt, uint8_t* out_pkt);