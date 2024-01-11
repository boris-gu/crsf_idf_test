/**
 * Receiver RSSI percent, power?
 * https://github.com/crsf-wg/crsf/wiki/CRSF_FRAMETYPE_LINK_RX_ID
 */
#pragma once

#include <stdio.h>
#include "crsf_frametype_default.h"

#define CRSF_FRAMETYPE_LINK_RX_ID 0x1C

typedef struct {
  uint8_t sync;
  uint8_t len;
  uint8_t type;

  int8_t rssi;
  int8_t unknown1;
  int8_t unknown2;
  int8_t rf_power_index;

  uint8_t crc8;
} crsf_link_rx_id;

crsf_link_rx_id crsf_default2gps(crsf_default pkt);

int crsf_link_rx_id2array(crsf_link_rx_id in_pkt, uint8_t* out_pkt);