#include <avr/io.h>
#import "max7219.h"
#import "usi.h"

void InitMAX7219(void) {
  MAX7219_DDR|=(1<<MAX7219_CS);
  MAX7219_PORT|=(1<<MAX7219_CS);

}

void set_MAX7219(uint8_t ADR, uint8_t DATA) {
  uint8_t Tx_M  = ADR;
  uint8_t Tx_L  = DATA;

  PORTB &= ~(1<<MAX7219_CS);
  Tx_Rx_byte( Tx_M);
  Tx_Rx_byte( Tx_L);
  PORTB |= (1<<MAX7219_CS);
}

void MAX7219_writeData(char data_register, char data)
{
    PORTB &= ~(1<<MAX7219_CS);
        // Send the register where the data will be stored
        Tx_Rx_byte(data_register);
        // Send the data to be stored
        Tx_Rx_byte(data);
    PORTB |= (1<<MAX7219_CS);
}

void MAX7219_clearDisplay()
{
    char i = digitsInUse;
    // Loop until 0, but don't run for zero
    do {
        // Set each display in use to blank
        MAX7219_writeData(i, MAX7219_CHAR_BLANK);
    } while (--i);
}

void MAX7219_displayNumber(uint32_t number)
{
    char negative = 0;

    // Convert negative to positive.
    // Keep a record that it was negative so we can
    // sign it again on the display.
    if (number < 0) {
        negative = 1;
        number *= -1;
    }

    MAX7219_clearDisplay();

    // If number = 0, only show one zero then exit
    if (number == 0) {
        MAX7219_writeData(MAX7219_DIGIT0, 0);
        return;
    }

    // Initialization to 0 required in this case,
    // does not work without it. Not sure why.
    char i = 0;

    // Loop until number is 0.
    do {
        MAX7219_writeData(++i, number % 10);
        // Actually divide by 10 now.
        number /= 10;
    } while (number);

    // Bear in mind that if you only have three digits, and
    // try to display something like "-256" all that will display
    // will be "256" because it needs an extra fourth digit to
    // display the sign.
    if (negative) {
        MAX7219_writeData(i, MAX7219_CHAR_NEGATIVE);
    }
}
// void set_bulk_MAX7219(uint8_t GA, uint8_t SHDNA, uint8_t SHDNB, uint16_t valA, uint16_t valB) {
// // AB - output A/B: 0 - outputA; 1 - outputB
// // GA - ref. voltage: 1 - 2.048V; 0 - 4.096V
// // SHDN - output power control: 1 - enable; 0 - high impedance
//   set_MAX7219(0, GA, SHDNA, valA );
//   set_MAX7219(1, GA, SHDNB, valB );
//
// }
