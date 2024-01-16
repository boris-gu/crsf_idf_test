/**
 * Channels data (both handset to TX and RX to flight controller)
 */
#pragma once

#include <stdio.h>
#include "crsf_frametype_default.h"

#define CRSF_FRAMETYPE_RC_CHANNELS_PACKED 0x16

typedef struct {
  uint8_t sync;
  uint8_t len;
  uint8_t type;

  uint16_t ch[16];

  uint8_t crc8;
} crsf_rc_channels_packed;

crsf_rc_channels_packed crsf_default2rc_channels_packed(crsf_default pkt);

int crsf_rc_channels_packed2array(crsf_rc_channels_packed in_pkt, uint8_t* out_pkt);