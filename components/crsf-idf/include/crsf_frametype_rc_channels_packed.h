/**
 * Channels data (both handset to TX and RX to flight controller)
 */
#pragma once

#include "crsf_frametype_default.h"

typedef struct {
  uint8_t sync;
  //uint8_t len;
  //uint8_t type;

  uint16_t ch[16];

  // uint8_t crc8;
} crsf_rc_channels_packed;

uint8_t crsf_default2rc_channels_packed(crsf_default* in_pkt, crsf_rc_channels_packed* out_pkt);

uint8_t crsf_rc_channels_packed2array(crsf_rc_channels_packed* in_pkt, uint8_t* out_pkt);