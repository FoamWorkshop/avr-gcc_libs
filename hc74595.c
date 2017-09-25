#include <avr/io.h>
#import "hc74595.h"
#import "usi.h"

void init_hc74595(void) {
  HC74595_DDR|=(1<<HC74595_CS);
  HC74595_PORT|=(1<<HC74595_CS);

}

void set_hc74595(uint8_t DATA) {
  HC74595_PORT &= ~(1<<HC74595_CS);
  Tx_Rx_byte(DATA);
  HC74595_PORT |= (1<<HC74595_CS);
}
