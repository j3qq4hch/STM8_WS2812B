#ifndef WS2812B_PIN_H
#define WS2812B_PIN_H

////////////////////////////////////////
#define GPIOA_PORT    0x5000
#define GPIOB_PORT    0x5005
#define GPIOC_PORT    0x500A
#define GPIOD_PORT    0x500F
#define GPIOE_PORT    0x5014
#define GPIOF_PORT    0x5019
#define GPIOG_PORT    0x501E
#define GPIOH_PORT    0x5023
#define GPIOI_PORT    0x5028
////////////////////////////////////////

#define WS2812B_PORT  GPIOD_PORT
#define WS2812B_PIN   3

#define NB_LEDS         60

#endif