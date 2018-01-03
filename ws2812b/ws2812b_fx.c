#include "ws2812b_fx.h"

void _delay_ms(u16 wait);

RGBColor_t Wheel(unsigned char WheelPos) 
{
  WheelPos = 255 - WheelPos;
  RGBColor_t color;
  if(WheelPos < 85) 
  {
    color.R = 255 - WheelPos * 3;
    color.G = 0;
    color.B = WheelPos * 3;
  return color;
  }
  if(WheelPos < 170) 
  {
    WheelPos -= 85;
    color.R = 0;
    color.G = WheelPos * 3;
    color.B = 255 - WheelPos * 3;
  return color;
  }
  
  WheelPos -= 170;
  color.R = WheelPos * 3; 
  color.G = 255 - WheelPos * 3;
  color.B = 0;
  return color;
}



void rainbowCycle(uint8_t wait) 
{
  uint16_t i, j;
  for(j=0; j<256 * 5; j++) 
  { // 5 cycles of all colors on wheel
    for(i=0; i < NB_LEDS; i++) 
    {
    rgb_SetColor(i,Wheel(((i * 256 / 10) + j) & 255));
    }
    rgb_SendArray();
    _delay_ms(wait);
  }
}


