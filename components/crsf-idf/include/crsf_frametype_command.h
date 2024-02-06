/**
 * CRSF command execute
 */
#pragma once

#include "crsf_frametype_default.h"

#define CRSF_COMMAND_SUBCMD_RX 0x10
#define COMMAND_MODEL_SELECT_ID 0x05

typedef struct {
  uint8_t sync; // 0xEE CRSF_ADDRESS_CRSF_TRANSMITTER
  // uint8_t len;
  // uint8_t type;

  uint8_t ext_dest;     // 0xEE CRSF_ADDRESS_CRSF_TRANSMITTER
  uint8_t ext_src;      // 0xEA CRSF_ADDRESS_RADIO_TRANSMITTER
  uint8_t command_type; // 0x10 CRSF_COMMAND_SUBCMD_RX
  uint8_t command_id;   // 0x05 COMMAND_MODEL_SELECT_ID
  uint8_t command_data; // ModelID


  // uint8_t crc8;
} crsf_command;

//crsf_command crsf_default_command(crsf_default* pkt);

//int crsf_command2array(crsf_command* in_pkt, uint8_t* out_pkt);