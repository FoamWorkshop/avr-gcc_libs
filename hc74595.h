#ifndef HC74595_H_
#define HC74595_H_

#define HC74595_DDR DDRB
#define HC74595_PORT PORTB

#define HC74595_CS PB0

void init_hc74595(void);
void set_hc74595(uint8_t DATA);

#endif
