/**
 * (CRSFv3) Channels subset data
 * https://github.com/crsf-wg/crsf/wiki/CRSF_FRAMETYPE_SUBSET_RC_CHANNELS_PACKED
 */
#pragma once

#include <stdio.h>
#include "crsf.h"

typedef struct {
  uint8_t sync;
  uint8_t len;
  uint8_t type;

  uint8_t config_byte;
  uint8_t *data;
  uint8_t data_len;

  uint8_t crc8;
} crsf_subset_rc_channels_packet;

crsf_subset_rc_channels_packet crsf_default2subset_rc_channels_packet(crsf_default pkt);

int crsf_subset_rc_channels_packet2array(crsf_subset_rc_channels_packet in_pkt, uint8_t* out_pkt);