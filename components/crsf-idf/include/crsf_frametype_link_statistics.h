/**
 * Signal information.
 * Uplink/Downlink RSSI, SNR, Link Quality (LQ), RF mode, transmit power
 * https://github.com/crsf-wg/crsf/wiki/CRSF_FRAMETYPE_LINK_STATISTICS
 */
#pragma once

#include <stdio.h>
#include "crsf_frametype_default.h"

#define CRSF_FRAMETYPE_LINK_STATISTICS 0x14

typedef struct {
  uint8_t sync;
  uint8_t len;
  uint8_t type;

  uint8_t up_rssi1;
  uint8_t up_rssi2;
  uint8_t up_link_qual;
  int8_t up_snr;
  uint8_t Diversity_act_ant;
  uint8_t rf_mode;
  uint8_t up_tx_power;
  uint8_t down_rssi;
  uint8_t down_link_qual;
  int8_t down_snr;

  uint8_t crc8;
} crsf_link_statistics;

crsf_link_statistics crsf_default2link_statistics(crsf_default pkt);

int crsf_link_statistics2array(crsf_link_statistics in_pkt, uint8_t* out_pkt);