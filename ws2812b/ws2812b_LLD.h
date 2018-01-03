#ifndef __WS2812B
#define __WS2812B

#include "ws2812b_conf.h"

#define _ws2812b_create_port(__set__, __port__, __pin__) #__set__" L:"#__port__", #"#__pin__" \n"
#define ws2812b_create_port(__set__, __port__, __pin__) _ws2812b_create_port(__set__, __port__, __pin__)

#define RGBLedPin_Set   ws2812b_create_port(BSET, WS2812B_PORT, WS2812B_PIN)
#define RGBLedPin_ReSet ws2812b_create_port(BRES, WS2812B_PORT, WS2812B_PIN)


typedef struct
{
  unsigned char R;
  unsigned char G;
  unsigned char B;
}RGBColor_t;


extern const RGBColor_t RED;
extern const RGBColor_t GREEN;
extern const RGBColor_t BLUE;
extern const RGBColor_t BLACK;
extern const RGBColor_t WHITE;
extern const RGBColor_t YELLOW;
extern const RGBColor_t MAGENTA;

void rgb_SetColor(unsigned char LedId, RGBColor_t Color);
void rgb_SendArray();
#endif