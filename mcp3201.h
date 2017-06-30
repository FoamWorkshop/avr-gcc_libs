#ifndef MCP3201_H_
#define MCP3201_H_

#define MCP3201_DDR DDRB
#define MCP3201_PORT PORTB

#define MCP3201_CS PB1

// #define SYNC_LDAC 0
// #define MCP4822_LDAC PB3

void InitMCP3201(void);
// void SyncMCP4822(void);

uint16_t get_MCP3201();

#endif /* MKUART_H_ */
