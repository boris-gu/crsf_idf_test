#include "crsf_frametype_radio_id.h"

uint8_t crsf_default2radio_id(crsf_default* in_pkt, crsf_radio_id* out_pkt) {
  if (in_pkt->type != CRSF_FRAMETYPE_RADIO_ID) {
    return 0;
  }
  out_pkt->ext_dest = in_pkt->payload[0];
  out_pkt->ext_src = in_pkt->payload[1];/* 
  out_pkt->packet_rate = (uint32_t)in_pkt->payload[2] | in_pkt->payload[3] |
                         in_pkt->payload[4] | in_pkt->payload[5];
  out_pkt->shift_corr = (uint32_t)in_pkt->payload[6] | in_pkt->payload[7] |
                         in_pkt->payload[8] | in_pkt->payload[9]; */
  out_pkt->packet_rate = (uint32_t)in_pkt->payload[2]; // TODO: Проверить
  out_pkt->shift_corr = (uint32_t)in_pkt->payload[6];
  return 1;
}

uint8_t crsf_radio_id2array(crsf_radio_id* in_pkt, uint8_t* out_pkt) {
  out_pkt[0] = in_pkt->sync;
  out_pkt[1] = 0x0D;
  out_pkt[2] = CRSF_FRAMETYPE_RADIO_ID;
  out_pkt[3] = in_pkt->ext_dest;
  out_pkt[4] = in_pkt->ext_src;
  out_pkt[5] = in_pkt->subtype;
  out_pkt[6] = in_pkt->packet_rate;
  out_pkt[10] = in_pkt->shift_corr;
  out_pkt[14] = crc8_d5_calc(out_pkt + 2, 0x0C); // TODO: Проверить
  return out_pkt[1] + 2;
}