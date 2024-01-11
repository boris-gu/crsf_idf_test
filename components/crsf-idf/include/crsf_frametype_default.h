#pragma once

#include <stdio.h>
#include "crsf_common.h"

typedef struct {
  uint8_t sync;
  uint8_t len;
  uint8_t type;
  uint8_t payload[CRSF_PAYLOAD_MAX_LEN];
  uint8_t crc8;
} crsf_default;