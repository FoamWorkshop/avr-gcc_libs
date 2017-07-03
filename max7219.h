#ifndef MAX7219_H_
#define MAX7219_H_

#define MAX7219_DDR DDRB
#define MAX7219_PORT PORTB

#define MAX7219_CS PB2

#define ON                        1
#define OFF                       0

#define MAX7219_MODE_DECODE       0x09
#define MAX7219_MODE_INTENSITY    0x0A
#define MAX7219_MODE_SCAN_LIMIT   0x0B
#define MAX7219_MODE_POWER        0x0C
#define MAX7219_MODE_TEST         0x0F
#define MAX7219_MODE_NOOP         0x00

#define MAX7219_DIGIT0            0x01
#define MAX7219_DIGIT1            0x02
#define MAX7219_DIGIT2            0x03
#define MAX7219_DIGIT3            0x04
#define MAX7219_DIGIT4            0x05
#define MAX7219_DIGIT5            0x06
#define MAX7219_DIGIT6            0x07
#define MAX7219_DIGIT7            0x08
#define MAX7219_DIGIT8            0x09

#define MAX7219_CHAR_BLANK        0xF
#define MAX7219_CHAR_NEGATIVE     0xA

#define digitsInUse               8



void InitMAX7219(void);
void set_MAX7219(uint8_t ADR, uint8_t DATA);
void MAX7219_writeData(char data_register, char data);
void MAX7219_clearDisplay();
void MAX7219_displayNumber(uint32_t number);

#endif /* MKUART_H_ */
