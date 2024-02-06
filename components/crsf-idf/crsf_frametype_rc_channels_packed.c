#include "crsf_frametype_rc_channels_packed.h"

uint8_t crsf_default2rc_channels_packed(crsf_default* in_pkt,
                                        crsf_rc_channels_packed* out_pkt) {
  if (in_pkt->type != CRSF_FRAMETYPE_RC_CHANNELS_PACKED) {
    return 0;
  }
  out_pkt->sync = in_pkt->sync;
  out_pkt->ch[0] = ((in_pkt->payload[0] | in_pkt->payload[1] << 8) & 0x07FF);
  out_pkt->ch[1] = ((in_pkt->payload[1] >> 3 | in_pkt->payload[2] << 5) & 0x07FF);
  out_pkt->ch[2] = ((in_pkt->payload[2] >> 6 | in_pkt->payload[3] << 2 | in_pkt->payload[4] << 10) & 0x07FF);
  out_pkt->ch[3] = ((in_pkt->payload[4] >> 1 | in_pkt->payload[5] << 7) & 0x07FF);
  out_pkt->ch[4] = ((in_pkt->payload[5] >> 4 | in_pkt->payload[6] << 4) & 0x07FF);
  out_pkt->ch[5] = ((in_pkt->payload[6] >> 7 | in_pkt->payload[7] << 1 | in_pkt->payload[8] << 9) & 0x07FF);
  out_pkt->ch[6] = ((in_pkt->payload[8] >> 2 | in_pkt->payload[9] << 6) & 0x07FF);
  out_pkt->ch[7] = ((in_pkt->payload[9] >> 5 | in_pkt->payload[10] << 3) & 0x07FF);
  out_pkt->ch[8] = ((in_pkt->payload[11] | in_pkt->payload[12] << 8) & 0x07FF);
  out_pkt->ch[9] = ((in_pkt->payload[12] >> 3 | in_pkt->payload[13] << 5) & 0x07FF);
  out_pkt->ch[10] = ((in_pkt->payload[13] >> 6 | in_pkt->payload[14] << 2 | in_pkt->payload[15] << 10) & 0x07FF);
  out_pkt->ch[11] = ((in_pkt->payload[15] >> 1 | in_pkt->payload[16] << 7) & 0x07FF);
  out_pkt->ch[12] = ((in_pkt->payload[16] >> 4 | in_pkt->payload[17] << 4) & 0x07FF);
  out_pkt->ch[13] = ((in_pkt->payload[17] >> 7 | in_pkt->payload[18] << 1 | in_pkt->payload[19] << 9) & 0x07FF);
  out_pkt->ch[14] = ((in_pkt->payload[19] >> 2 | in_pkt->payload[20] << 6) & 0x07FF);
  out_pkt->ch[15] = ((in_pkt->payload[20] >> 5 | in_pkt->payload[21] << 3) & 0x07FF);
}

uint8_t crsf_rc_channels_packed2array(crsf_rc_channels_packed* in_pkt,
                                      uint8_t* out_pkt) {}