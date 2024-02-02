#pragma once

#include "crsf_common.h"
#include "crsf_frametype_default.h"

typedef enum {
  READ_SYNC = CRSF_PAYLOAD_MAX_LEN,
  READ_LEN,
  READ_TYPE,
  READ_CRC8
} read_status;

uint8_t crsf_parse_char(uint8_t rx_byte, crsf_default* rx_pkt, uint8_t* rx_status);