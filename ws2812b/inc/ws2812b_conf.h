/** 
  ******************************************************************************
  * @file    ws2812b_conf.h
  * @brief   configuration file
  * @author  https://github.com/j3qq4hch
  * @author  https://github.com/mnemocron
  * @date    2020-10-27
  * 
  * @note    IAR Embedded Workbench 3.11.1
  *          shared components 8.3.2.5988
  * @note    tested with RGBW LED type: IN-PI55QATPRPGPBPW-XX
  * 
  ******************************************************************************
  */

#ifndef WS2812B_PIN_H
#define WS2812B_PIN_H

/* ---------------------------------------------------------------------------*/
/* GPIO Port Register Map */
/** @todo why not use SPL definitions? */
#define GPIOA_PORT    0x5000
#define GPIOB_PORT    0x5005
#define GPIOC_PORT    0x500A
#define GPIOD_PORT    0x500F
#define GPIOE_PORT    0x5014
#define GPIOF_PORT    0x5019
#define GPIOG_PORT    0x501E
#define GPIOH_PORT    0x5023
#define GPIOI_PORT    0x5028
/* ---------------------------------------------------------------------------*/

/* User Config ---------------------------------------------------------------*/
/* GPIO Output Pin - must be initialized as output*/ 
#define WS2812B_PORT  GPIOD_PORT
#define WS2812B_PIN   0

/* LED Strip - number of LEDs */
#define NB_LEDS       8

/* LED Type (RGB / RGBW) */
// #define WS2812B_MODE_RGB
#define WS2812B_MODE_RGBW

#endif
