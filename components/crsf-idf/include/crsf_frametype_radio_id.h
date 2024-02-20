/**
 * Extended type used for OPENTX_SYNC
 */
#pragma once

#include "crsf_frametype_default.h"

#define CRSF_FRAMETYPE_OPENTX_SYNC 0x10

typedef struct {
  uint8_t sync;
  // uint8_t len;
  // uint8_t type;

  uint8_t ext_dest;  // 0xEA CRSF_ADDRESS_RADIO_TRANSMITTER
  uint8_t ext_src;   // 0xEE CRSF_ADDRESS_CRSF_TRANSMITTER
  uint8_t subtype;   // 0x10 CRSF_FRAMETYPE_OPENTX_SYNC

  int32_t packet_rate; // us * 10 (Big endian)
  int32_t shift_corr;

  // uint8_t crc8;
} crsf_radio_id;

uint8_t crsf_default2radio_id(crsf_default* in_pkt, crsf_radio_id* out_pkt);

//uint8_t crsf_radio_id2array(crsf_radio_id* in_pkt, uint8_t* out_pkt);