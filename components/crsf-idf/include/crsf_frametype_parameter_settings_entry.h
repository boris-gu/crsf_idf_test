/**
 * Configuration item data chunk
 */
#pragma once

#include "crsf_frametype_default.h"

/**
 * TYPE
 */
#define CRSF_UINT8   0x00
#define CRSF_INT8    0x01
#define CRSF_UINT16  0x02
#define CRSF_INT16   0x03
#define CRSF_FLOAT   0x08  // 4 byte
#define CRSF_SELECT  0x09
#define CRSF_STRING  0x0A  // null-terminated
#define CRSF_FOLDER  0x0B
#define CRSF_INFO    0x0C  // display string, not configurable
#define CRSF_COMMAND 0x0D

typedef struct {
  uint8_t sync; // 0xEE CRSF_ADDRESS_CRSF_TRANSMITTER
  //uint8_t len;
  //uint8_t type;

  uint8_t ext_dest; // 0xEA CRSF_ADDRESS_RADIO_TRANSMITTER
  uint8_t ext_src;  // 0xEE CRSF_ADDRESS_CRSF_TRANSMITTER
  uint8_t index;
  uint8_t chunks_remaining;
  uint8_t parent;
  uint8_t type;
  // TODO: ДОПИСАТЬ

  // uint8_t crc8;
} crsf_parameter_settings_entry;

//crsf_parameter_settings_entry crsf_default2parameter_settings_entry(crsf_default* pkt);

//int crsf_parameter_settings_entry2array(crsf_parameter_settings_entry* in_pkt, uint8_t* out_pkt);