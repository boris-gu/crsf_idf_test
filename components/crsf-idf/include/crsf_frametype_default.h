#pragma once

#include <stdio.h>
#include "crsf_enum.h"

typedef enum {
  READ_SYNC = CRSF_PAYLOAD_MAX_LEN,
  READ_LEN,
  READ_TYPE,
  READ_CRC8
} read_status;

typedef struct {
  uint8_t sync;
  uint8_t len;
  uint8_t type;
  uint8_t payload[CRSF_PAYLOAD_MAX_LEN];
  uint8_t crc8;
} crsf_default;

uint8_t crsf_parse_char(uint8_t rx_byte, crsf_default* rx_pkt, uint8_t* rx_status);

uint8_t crc8_calc(crsf_default* pkt);