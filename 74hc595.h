#ifndef HC74595_H_
#define HC74595_H_

#define HC74595_DDR DDRB
#define HC74595_PORT PORTB

#define HC74595_CS PB2

#define ON                        1
#define OFF                       0

#define HC74595_MODE_DECODE       0x09
#define HC74595_MODE_INTENSITY    0x0A
#define HC74595_MODE_SCAN_LIMIT   0x0B
#define HC74595_MODE_POWER        0x0C
#define HC74595_MODE_TEST         0x0F
#define HC74595_MODE_NOOP         0x00

#define HC74595_DIGIT0            0x01
#define HC74595_DIGIT1            0x02
#define HC74595_DIGIT2            0x03
#define HC74595_DIGIT3            0x04
#define HC74595_DIGIT4            0x05
#define HC74595_DIGIT5            0x06
#define HC74595_DIGIT6            0x07
#define HC74595_DIGIT7            0x08
#define HC74595_DIGIT8            0x09

#define HC74595_CHAR_BLANK        0xF
#define HC74595_CHAR_NEGATIVE     0xA

#define digitsInUse               8



void InitHC74595(void);
void set_HC74595(uint8_t ADR, uint8_t DATA);
void HC74595_writeData(char data_register, char data);
void HC74595_clearDisplay();
void HC74595_displayNumber(uint32_t number);

#endif /* MKUART_H_ */
