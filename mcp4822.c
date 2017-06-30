#include <avr/io.h>
#import "mcp4822.h"
#import "usi.h"

void InitMCP4822(void) {
  MCP4822_DDR|=(1<<MCP4822_CS);
  MCP4822_PORT|=(1<<MCP4822_CS);

#ifdef SYNC_LDAC
  MCP4822_DDR|=(1<<MCP4822_LDAC);
  MCP4822_PORT|=(1<<MCP4822_LDAC);
#endif
}

void SyncMCP4822(void) {
  MCP4822_PORT&=~(1<<MCP4822_LDAC);
  MCP4822_PORT|= (1<<MCP4822_LDAC);
}

void set_MCP4822(uint8_t AB, uint8_t GA, uint8_t SHDN, uint16_t val ) {
// AB - output A/B: 0 - outputA; 1 - outputB
// GA - ref. voltage: 1 - 2.048V; 0 - 4.096V
// SHDN - output power control: 1 - enable; 0 - high impedance

  // uint8_t Tx_M  = ((val>>8)&0x0F)|(AB<<7)|(GA<<5)|(SHDN<<4);
  // uint8_t Tx_L  = (val>>0)&0xFF;

  uint8_t Tx_M  = (AB<<7)|(GA<<5)|(SHDN<<4)|((val>>8)&0x0F);
  uint8_t Tx_L  = (val>>0)&0xFF;

  PORTB &= ~(1<<MCP4822_CS);
  Tx_Rx_byte( Tx_M);
  Tx_Rx_byte( Tx_L);
  PORTB |= (1<<MCP4822_CS);

}

void set_bulk_MCP4822(uint8_t GA, uint8_t SHDNA, uint8_t SHDNB, uint16_t valA, uint16_t valB) {
// AB - output A/B: 0 - outputA; 1 - outputB
// GA - ref. voltage: 1 - 2.048V; 0 - 4.096V
// SHDN - output power control: 1 - enable; 0 - high impedance
  set_MCP4822(0, GA, SHDNA, valA );
  set_MCP4822(1, GA, SHDNB, valB );

}
