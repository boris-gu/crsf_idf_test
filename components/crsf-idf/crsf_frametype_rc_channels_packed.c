#include "crsf_frametype_rc_channels_packed.h"

uint8_t crsf_default2rc_channels_packed(crsf_default* in_pkt, crsf_rc_channels_packed* out_pkt) {
  if (in_pkt->type != CRSF_FRAMETYPE_RC_CHANNELS_PACKED) {
    return 0;
  }

  out_pkt->sync = in_pkt->sync;
  // TODO: ПРОВЕРИТЬ
  const uint16_t mask = 0x07FF;
  const uint8_t bits_on_ch = 11;
  const uint8_t num_of_ch = 16;
  uint8_t bits_merged = 0;
  uint32_t read_value = 0;
  uint8_t i_payload = 0;
  for (uint8_t i = 0; i < num_of_ch; i++) {
    while (bits_merged < bits_on_ch) {
      read_value |= ((uint32_t)in_pkt->payload[i_payload]) << bits_merged;
      bits_merged += 8;
      ++i_payload;
    }
    out_pkt->ch[i] = (uint16_t)(read_value & mask);
    read_value >>= bits_on_ch;
    bits_merged -= bits_on_ch;
  }
  return 1;
}

uint8_t crsf_rc_channels_packed2array(crsf_rc_channels_packed* in_pkt, uint8_t* out_pkt) {
  out_pkt[0] = in_pkt->sync;
  out_pkt[1] = 0x18; // LEN 24 byte = 22(16ch, 11 bit) + type + crc8
  out_pkt[2] = CRSF_FRAMETYPE_RC_CHANNELS_PACKED;
  // TODO: ПРОВЕРИТЬ
  const uint16_t mask = 0xFF; // XXX: Нужна ли?
  const uint8_t bits_on_ch = 11;
  uint8_t bits_merged = 0;
  uint32_t read_value = 0;
  uint8_t i_ch = 0;
  for (int i = 3; i < 25; i++){
    while (bits_merged < 8) {
      read_value |=((uint32_t)in_pkt->ch[i_ch]) << bits_merged; // XXX: Тут не уверен
      bits_merged += bits_on_ch;
      ++i_ch;
      //read_value |= ((uint32_t)in_pkt->payload[i_payload]) << bits_merged;
    }
    out_pkt[i] = (uint8_t)(read_value & mask);
    read_value >>= 8;
    bits_merged -= 8;
  }

  out_pkt[25] = crc8_d5_calc(out_pkt + 2, 23);
  return out_pkt[1] + 2;
}

uint16_t ticks2us(uint16_t value) { return (value - 992) * 5 / 8 + 1500; }

uint16_t us2ticks(uint16_t value) { return (value - 1500) * 8 / 5 + 992; }