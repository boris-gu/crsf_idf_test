#include "crsf.h"

uint8_t crsf_parse_char(uint8_t rx_byte, crsf_default* rx_pkt, uint8_t* rx_status) {
  // SYNC
  if (&rx_status == READ_SYNC){
    if (rx_byte == CRSF_ADDRESS_FLIGHT_CONTROLLER ||
        rx_byte == CRSF_ADDRESS_RADIO_TRANSMITTER ||
        rx_byte == CRSF_ADDRESS_CRSF_RECEIVER ||
        rx_byte == CRSF_ADDRESS_CRSF_TRANSMITTER ||
        rx_byte == CRSF_ADDRESS_ELRS_LUA) {
      rx_pkt->sync = rx_byte;
      *rx_status = READ_LEN;
      return 1;
    } else {
      return 0;
    }
  // LEN
  } else if (*rx_status == READ_LEN) {
    if (rx_byte <= CRSF_LEN_MAX){
      rx_pkt->len = rx_byte;
      *rx_status = READ_TYPE;
    } else {
      *rx_status = READ_SYNC;
      return crsf_parse_char(rx_byte, rx_pkt, rx_status);
    }
    // TYPE
  } else if (*rx_status == READ_TYPE) {
    if (rx_byte == CRSF_FRAMETYPE_LINK_STATISTICS ||
        rx_byte == CRSF_FRAMETYPE_RC_CHANNELS_PACKED ||
        rx_byte == CRSF_FRAMETYPE_DEVICE_PING ||
        rx_byte == CRSF_FRAMETYPE_DEVICE_INFO ||
        rx_byte == CRSF_FRAMETYPE_PARAMETER_SETTINGS_ENTRY ||
        rx_byte == CRSF_FRAMETYPE_PARAMETER_READ ||
        rx_byte == CRSF_FRAMETYPE_PARAMETER_WRITE ||
        rx_byte == CRSF_FRAMETYPE_COMMAND ||
        rx_byte == CRSF_FRAMETYPE_RADIO_ID) {
      rx_pkt->type = rx_byte;
      *rx_status = 0;
      return 1;
    } else {
      *rx_status = READ_SYNC;
      return crsf_parse_char(rx_byte, rx_pkt, rx_status);
    }
    // PAYLOAD
  } else if (*rx_status >= 0 && *rx_status < CRSF_PAYLOAD_MAX_LEN) {
    rx_pkt->payload[*rx_status] = rx_byte;
    ++(*rx_status);
    if (*rx_status == (rx_pkt->len)-2){
      *rx_status = READ_CRC8;
    }
    // CRC8
  } else if (*rx_status == READ_CRC8) {
  } 
  return 0;
}