#ifndef MCP4822_H_
#define MCP4822_H_

#define MCP4822_DDR DDRB
#define MCP4822_PORT PORTB

#define MCP4822_CS PB2

#define SYNC_LDAC 0
#define MCP4822_LDAC PB3

void InitMCP4822(void);
void SyncMCP4822(void);

void set_MCP4822(uint8_t AB, uint8_t GA, uint8_t SHDN, uint16_t val );
void set_bulk_MCP4822(uint8_t GA, uint8_t SHDNA, uint8_t SHDNB, uint16_t valA, uint16_t valB);

#endif /* MKUART_H_ */
