#ifndef USI_H_
#define USI_H_

#define USI_DDR DDRB
#define USI_PORT PORTB
#define DO PB6	//   <---- MOSI
#define DI PB5	//   <---- MISO
#define SCK PB7		//   <---- SHIFT CLOCK (SC)

void InitSpi(void);					/* inicjalizacja sprzêtowego SPI */
void init_spi(void);					/* inicjalizacja sprzêtowego SPI */
uint8_t Tx_Rx_byte( uint8_t bajt );		/* wys³anie bajtu - sprzêtowe SPI */

#endif /* MKUART_H_ */
