/**
 * Configuration item read request
 */
#pragma once

#include "crsf_frametype_default.h"

typedef struct {
  uint8_t sync; // 0xEE CRSF_ADDRESS_CRSF_TRANSMITTER
  // uint8_t len;
  // uint8_t type;

  uint8_t ext_dest; // 0xEE CRSF_ADDRESS_CRSF_TRANSMITTER
  uint8_t ext_src;  // 0xEF CRSF_ADDRESS_ELRS_LUA
  uint8_t config;   // config field index, first is 01
  uint8_t chunk;    // chunk index, first is 00

  // uint8_t crc8;
} crsf_parameter_read;

crsf_parameter_read crsf_default2parameter_read(crsf_default* pkt);

int crsf_parameter_read2array(crsf_parameter_read* in_pkt, uint8_t* out_pkt);