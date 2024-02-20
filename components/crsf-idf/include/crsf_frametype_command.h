/**
 * CRSF command execute
 */
#pragma once

#include "crsf_frametype_default.h"

// command_type
#define CRSF_COMMAND_SUBCMD_RX 0x10
#define CRSF_COMMAND_SUBCMD_GENERAL 0x0A

// command_id for CRSF_COMMAND_SUBCMD_RX
#define CRSF_COMMAND_SUBCMD_RX_BIND 0x01
#define COMMAND_MODEL_SELECT_ID 0x05

// command_id for CRSF_COMMAND_SUBCMD_GENERAL
#define CRSF_COMMAND_SUBCMD_GENERAL_CRSF_SPEED_PROPOSAL 0x70
#define CRSF_COMMAND_SUBCMD_GENERAL_CRSF_SPEED_RESPONSE 0x71

// XXX: ТОЛЬКО MODEL ID
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

//uint8_t crsf_default2command(crsf_default* in_pkt, crsf_command* out_pkt);

uint8_t crsf_command2array(crsf_command* in_pkt, uint8_t* out_pkt);
