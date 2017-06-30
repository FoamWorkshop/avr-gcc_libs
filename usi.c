#include <avr/io.h>
#include "usi.h"

void InitSpi(void) {
	// USI_DDR |= (1<<DO)|(1<<SCK)|(1<<CS);
	USI_DDR |= (1<<DO)|(1<<SCK);
	USI_DDR &= ~(1<<DI);
  // USI_PORT |= (1<CS)
  // USI_PORT |= (1<CS)
	USICR |= (0<<USIWM1)|(1<<USIWM0)|(1<<USICS1)|(0<<USICLK);

}

uint8_t Tx_Rx_byte( uint8_t byte ) {
  USIDR = byte;
  USISR = (1<<USIOIF);
  while (!(USISR & (1<<USIOIF))) USICR |= (1<<USITC);
  return USIDR;
}
