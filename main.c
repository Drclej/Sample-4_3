#include <msp430f249.h>
#include "led.h"
#define uchar unsigned char
#define uint unsigned int


void initialize(void)
{
  P1SEL = 0x00;
  P1DIR = 0xFF;
  P1OUT = 0X00;
  
  P2SEL = 0x00;
  P2DIR = 0xFF;
  P2OUT = 0X00;
}

void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  initialize();
  while(1)
  {
    LEDshow();
  }
}
