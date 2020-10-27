/** 
  ******************************************************************************
  * @file    ws2812b_fx.h
  * @brief   Effect Library for WS2812B Type RGB/RGBW LED strips
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

#ifndef __WS2812B_FX
#define __WS2812B_FX

/* Includes ------------------------------------------------------------------*/
#include "ws2812b_LLD.h"
#include "stm8l15x.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
RGBColor_t Wheel(unsigned char WheelPos);
void rainbowCycle(uint8_t wait);

#endif
