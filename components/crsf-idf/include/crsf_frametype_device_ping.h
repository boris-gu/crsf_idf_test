/**
 * Sender requesting DEVICE_INFO from all destination devices
 */
#pragma once

#include "crsf_frametype_default.h"

typedef struct {
  uint8_t sync; // 0xEE CRSF_ADDRESS_CRSF_TRANSMITTER
  // uint8_t len;
  // uint8_t type;

  uint8_t ext_dest; // 0x00 CRSF_ADDRESS_BROADCAST 
  uint8_t ext_src;  // 0xEA CRSF_ADDRESS_RADIO_TRANSMITTER 

  // uint8_t crc8;
} crsf_device_ping;

crsf_device_ping crsf_default2device_ping(crsf_default* pkt);

int crsf_device_ping2array(crsf_device_ping* in_pkt, uint8_t* out_pkt);