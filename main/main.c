#include <driver/gpio.h>
#include <driver/uart.h>
#include <freertos/timers.h>
#include "crsf.h"

#define UART0_BAUDRATE 115200
#define UART2_BAUDRATE 400000
#define UART2_TX GPIO_NUM_17
#define UART2_RX GPIO_NUM_16
// Раскомментируйте, если входящие данные инвертированы
#define UART2_INV (UART_SIGNAL_TXD_INV + UART_SIGNAL_RXD_INV)
// Раскомментируйте, если входящие данные не инвертированы
// #define UART2_INV UART_SIGNAL_INV_DISABLE
#define UART_BUFF_LEN 1024 


void init_uart(uint8_t uart_num, uint32_t inverse_mask, int baud_rate,
               uint8_t tx_io_num, uint8_t rx_io_num);

void app_main(void) {
  init_uart(UART_NUM_0, UART_SIGNAL_INV_DISABLE, UART0_BAUDRATE,
            UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
  init_uart(UART_NUM_2, UART2_INV, UART2_BAUDRATE, UART2_TX, UART2_RX);
  crsf_default pkt_buff;
  uint8_t crsf_stat = READ_SYNC;
  uint8_t rx_byte = 0;

  uint64_t count = 0;
  while (xTaskGetTickCount() < pdMS_TO_TICKS(10000)) {
    vTaskDelay(pdMS_TO_TICKS(1000));
    printf("%llu\n", count++);
  }
  printf("START\n");
  count = 0;
  while (xTaskGetTickCount() <= pdMS_TO_TICKS(30000)) {
    if (uart_read_bytes(UART_NUM_2, &rx_byte, 1, 10 / portTICK_PERIOD_MS)) {
      if (crsf_parse_char(rx_byte, &pkt_buff, &crsf_stat)) {
        if (pkt_buff.type == CRSF_FRAMETYPE_RC_CHANNELS_PACKED) {
          ++count;
          //printf("%llu\n", count);
        }
      }
    }
  }
  printf("%llu in second\n\n", count / 20);

  /* vTaskDelay(1000 / portTICK_PERIOD_MS);
  // RC
  rc.sync = CRSF_ADDRESS_CRSF_TRANSMITTER;
  for (int i = 0; i < 16; i++) {
    rc.ch[i] = us2ticks(1500);
  }
  pkt_len = crsf_rc_channels_packed2array(&rc, pkt_buff);
  uart_write_bytes(UART_NUM_0, pkt_buff, pkt_len);
  vTaskDelay(100 / portTICK_PERIOD_MS);
  // MODEL ID
  model_id.sync = CRSF_ADDRESS_FLIGHT_CONTROLLER;
  model_id.ext_dest = CRSF_ADDRESS_CRSF_TRANSMITTER;
  model_id.ext_src = CRSF_ADDRESS_RADIO_TRANSMITTER;
  model_id.command_type = CRSF_COMMAND_SUBCMD_RX;
  model_id.command_id = COMMAND_MODEL_SELECT_ID;
  model_id.command_data = 0x36;
  pkt_len = crsf_command2array(&model_id, pkt_buff);
  uart_write_bytes(UART_NUM_0, pkt_buff, pkt_len);
  vTaskDelay(100 / portTICK_PERIOD_MS); */



  /* while (true) {
    // Раскомментировать, если что-то идет не так
    tick
    uart_write_bytes(UART_NUM_0, pkt_buff, 1);
    vTaskDelay(100000 / portTICK_PERIOD_MS);
  } */
}

void init_uart(uint8_t uart_num, uint32_t inverse_mask, int baud_rate,
               uint8_t tx_io_num, uint8_t rx_io_num) {
  uart_config_t conf = {.baud_rate = baud_rate,
                        .data_bits = UART_DATA_8_BITS,
                        .parity = UART_PARITY_DISABLE,
                        .stop_bits = UART_STOP_BITS_1,
                        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
                        .rx_flow_ctrl_thresh = 0,
                        .source_clk = UART_SCLK_DEFAULT};
  uart_param_config(uart_num, &conf);
  uart_set_line_inverse(uart_num, inverse_mask);
  uart_set_pin(uart_num, tx_io_num, rx_io_num, UART_PIN_NO_CHANGE,
               UART_PIN_NO_CHANGE);
  uart_driver_install(uart_num, UART_BUFF_LEN, UART_BUFF_LEN, 0, NULL, 0);
}