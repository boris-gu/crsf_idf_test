/**
 * Device name, firmware version, hardware version, serial number (PING response)
 * https://github.com/crsf-wg/crsf/wiki/CRSF_FRAMETYPE_DEVICE_INFO
 */
#pragma once

#include <stdio.h>
#include "crsf_frametype_default.h"

#define CRSF_FRAMETYPE_DEVICE_INFO 0x29
#define CRSF_DISPLAY_NAME_MAX_LEN (CRSF_PAYLOAD_MAX_LEN - 16)

typedef struct {
  uint8_t sync;
  uint8_t len;
  uint8_t type;

  uint8_t ext_dest; // 0xEA CRSF_ADDRESS_RADIO_TRANSMITTER 
  uint8_t ext_src;  // 0xEE CRSF_ADDRESS_CRSF_TRANSMITTER
  char display_name[CRSF_DISPLAY_NAME_MAX_LEN]; // null terminated string
  uint8_t display_name_len; // TODO: сделать с нижним подчеркиванием?
  uint32_t serial_num; // always "ELRS" for ExpressLRS
  uint32_t hard_ver;
  uint32_t soft_ver;
  uint8_t conf_param_count;
  uint8_t param_protocol_ver; // 0x00

  uint8_t crc8;
} crsf_device_info;

crsf_device_info crsf_default2device_info(crsf_default pkt);

int crsf_device_info2array(crsf_device_info in_pkt, uint8_t* out_pkt);