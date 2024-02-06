#include <driver/gpio.h>
#include <driver/uart.h>
#include <freertos/timers.h>

#define UART_BAUDRATE 115200
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
  init_uart(UART_NUM_0, UART_SIGNAL_INV_DISABLE, UART_BAUDRATE,
            UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
  init_uart(UART_NUM_2, UART2_INV, UART_BAUDRATE, UART2_TX, UART2_RX);
  uint8_t buff[UART_BUFF_LEN];
  size_t data_len = 0;
  while (true) {
    data_len = uart_read_bytes(UART_NUM_2, buff, UART_BUFF_LEN,
                               10 / portTICK_PERIOD_MS);
    if (data_len > 0) {
      uart_write_bytes(UART_NUM_0, buff, data_len);
    }
    // Раскомментировать, если что-то идет не так
    // vTaskDelay(1 / portTICK_PERIOD_MS);
  }
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