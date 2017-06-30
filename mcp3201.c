#include <avr/io.h>
#import "mcp3201.h"
#import "usi.h"
#include <util/delay.h>

void InitMCP3201(void) {
  MCP3201_DDR|=(1<<MCP3201_CS);
  MCP3201_PORT|=(1<<MCP3201_CS);
}


uint16_t get_MCP3201() {
// AB - output A/B: 0 - outputA; 1 - outputB
// GA - ref. voltage: 1 - 2.048V; 0 - 4.096V
// SHDN - output power control: 1 - enable; 0 - high impedance

  // uint8_t Tx_M  = ((val>>8)&0x0F)|(AB<<7)|(GA<<5)|(SHDN<<4);
  // uint8_t Tx_L  = (val>>0)&0xFF;

  uint8_t Rx_M;
  uint8_t Rx_L;
  uint16_t val;

  PORTB &= ~(1<<MCP3201_CS);
  Rx_M = Tx_Rx_byte(0);
  Rx_L = Tx_Rx_byte(0);
  PORTB |= (1<<MCP3201_CS);

  return ((Rx_M<<7) | (Rx_L>>1))&0xFFF;
}
