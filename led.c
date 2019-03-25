#include <msp430f249.h>
#include "led.h"
#define uchar unsigned char
#define uint unsigned int

uchar const Table_of_Digits[] = 
{
  0x00,0x3C,0x66,0x42,0x42,0x66,0x3C,0x00, //0
  0x00,0x08,0x38,0x08,0x08,0x08,0x3E,0x00, //1
  0x00,0x3C,0x42,0x04,0x08,0x32,0x7E,0x00, //2
  0x00,0x3C,0x42,0x1C,0x02,0x42,0x3C,0x00, //3
  0x00,0x0C,0x14,0x24,0x44,0x3C,0x0C,0x00, //4
  0x00,0x7E,0x40,0x7C,0x02,0x42,0x3C,0x00, //5
  0x00,0x3C,0x40,0x7C,0x42,0x42,0x3C,0x00, //6
  0x00,0x7E,0x44,0x08,0x10,0x10,0x10,0x00, //7
  0x00,0x3C,0x42,0x24,0x5C,0x42,0x3C,0x00, //8
  0x00,0x38,0x46,0x42,0x3E,0x06,0x3C,0x00  //9
};

uchar const Table_of_rows[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};

void delayus(uint t)
{
  while (t--);
}


void LEDshow (void)
{
  uchar num;
  uchar row;
  uchar fps;
  uint digit;
  digit = 0;
  for(num = 0;num < 10;num++)
  {
    for(fps = 0;fps < 200;++fps)
    {
      digit = num * 8;
      for(row = 0;row < 9;++row)
      {
      P2OUT =~ Table_of_rows[row];
      P1OUT =~ Table_of_Digits[digit];
      ++digit;
      delayus(50);
      }
    }
  }
  digit = 0;
}