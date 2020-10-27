/** 
  ******************************************************************************
  * @file    ws2812b_lld.h
  * @brief   Low Level Driver for WS2812B Type RGB/RGBW LED strips
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

#ifndef __WS2812B
#define __WS2812B

/* Includes ------------------------------------------------------------------*/
#include "ws2812b_conf.h"

/* Private define ------------------------------------------------------------*/
#define _ws2812b_create_port(__set__, __port__, __pin__) #__set__" L:"#__port__", #"#__pin__" \n"
#define ws2812b_create_port(__set__, __port__, __pin__) _ws2812b_create_port(__set__, __port__, __pin__)

#define RGBLedPin_Set   ws2812b_create_port(BSET, WS2812B_PORT, WS2812B_PIN)
#define RGBLedPin_ReSet ws2812b_create_port(BRES, WS2812B_PORT, WS2812B_PIN)

/* Private typedef -----------------------------------------------------------*/
typedef struct
{
  unsigned char R;
  unsigned char G;
  unsigned char B;
#ifdef WS2812B_MODE_RGBW
  unsigned char W;
#endif
} RGBColor_t;

/* Private variables ---------------------------------------------------------*/
extern const RGBColor_t RED;
extern const RGBColor_t GREEN;
extern const RGBColor_t BLUE;
extern const RGBColor_t BLACK;
extern const RGBColor_t WHITE;
extern const RGBColor_t YELLOW;
extern const RGBColor_t MAGENTA;

/* Private function prototypes -----------------------------------------------*/
void rgb_SetColor(unsigned char LedId, RGBColor_t Color);
void rgb_SendArray();
#endif
