/**
 * Device name, firmware version, hardware version, serial number (PING response)
 */
#pragma once

#include <stdio.h>
#include "crsf_frametype_default.h"

#define CRSF_FRAMETYPE_DEVICE_INFO 0x29
#define CRSF_DISPLAY_NAME_MAX_LEN (CRSF_PAYLOAD_MAX_LEN - 16)

typedef struct {
  uint8_t sync;
  uint8_t len; // TODO: оставить или ввести display_name_len
  // uint8_t type;

  uint8_t ext_dest; // 0xEA CRSF_ADDRESS_RADIO_TRANSMITTER 
  uint8_t ext_src;  // 0xEE CRSF_ADDRESS_CRSF_TRANSMITTER
  char display_name[CRSF_DISPLAY_NAME_MAX_LEN]; // null terminated string
  uint32_t serial_num; // [0x45 0x4C 0x52 0x53] always "ELRS" for ExpressLRS
  uint32_t hard_ver;
  uint32_t soft_ver; // all 00 for ELRSv2, 00 MAJ MIN REV for ELRSv3
  uint8_t conf_param_count;   // XXX: 19?
  uint8_t param_protocol_ver; // 0x00

  uint8_t crc8;
} crsf_device_info;

crsf_device_info crsf_default2device_info(crsf_default pkt);

int crsf_device_info2array(crsf_device_info in_pkt, uint8_t* out_pkt);