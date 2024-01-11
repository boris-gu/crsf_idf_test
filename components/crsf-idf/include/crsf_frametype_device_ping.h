/**
 * Sender requesting DEVICE_INFO from all destination devices
 * https://github.com/crsf-wg/crsf/wiki/CRSF_FRAMETYPE_DEVICE_PING
 */
#pragma once

#include <stdio.h>
#include "crsf_frametype_default.h"

#define CRSF_FRAMETYPE_DEVICE_PING 0x28

typedef struct {
  uint8_t sync;
  uint8_t len;
  uint8_t type;

  uint8_t ext_dest; // 0x00 CRSF_ADDRESS_BROADCAST 
  uint8_t ext_src;  // 0xEA CRSF_ADDRESS_RADIO_TRANSMITTER 

  uint8_t crc8;
} crsf_device_ping;

crsf_device_ping crsf_default2device_ping(crsf_default pkt);

int crsf_device_ping2array(crsf_device_ping in_pkt, uint8_t* out_pkt);