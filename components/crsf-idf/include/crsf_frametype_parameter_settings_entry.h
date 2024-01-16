/**
 * Configuration item data chunk
 */
#pragma once

#include <stdio.h>
#include "crsf_frametype_default.h"

#define CRSF_FRAMETYPE_PARAMETER_SETTINGS_ENTRY 0x2B

typedef struct {
  uint8_t sync; // 0xEE CRSF_ADDRESS_CRSF_TRANSMITTER
  uint8_t len;
  uint8_t type;

  uint8_t ext_dest; // 0xEA CRSF_ADDRESS_RADIO_TRANSMITTER
  uint8_t ext_src;  // 0xEE CRSF_ADDRESS_CRSF_TRANSMITTER
  // TODO: ДОПИСАТЬ

  uint8_t crc8;
} crsf_parameter_settings_entry;

crsf_parameter_settings_entry crsf_default2parameter_settings_entry(crsf_default pkt);

int crsf_parameter_settings_entry2array(crsf_parameter_settings_entry in_pkt, uint8_t* out_pkt);