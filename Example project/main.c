/** 
  ******************************************************************************
  * @file    ws2812b_lld.h
  * @brief   example project for WS2812B Library
  * @author  https://github.com/j3qq4hch
  * @author  https://github.com/mnemocron
  * @date    2020-10-27
  * 
  * @note    IAR Embedded Workbench 3.11.1
  *          shared components 8.3.2.5988
  * @note    tested with RGBW LED type: IN-PI55QATPRPGPBPW-XX
  * @note    STM8 must run at 16 MHz
  * 
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include <stdio.h>
#include "stm8s_conf.h"
#include "ws2812B_fx.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define TIM4_PERIOD       124

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
static void CLK_Config(void);
static void TIM4_Config(void);
static void GPIO_Config(void);
void _delay_ms(u16);
void uptime_routine(void);

/* Private user code ---------------------------------------------------------*/
void main( void )
{  
  /* MCU Configuration -------------------------------------------------------*/
  CLK_Config();
  TIM4_Config();
  GPIO_Config();
  
  enableInterrupts();
  
  /* Infinite Loop -----------------------------------------------------------*/
  while(1)
  { 
    rainbowCycle(25); 
  }
}

/* Clock Init ----------------------------------------------------------------*/
/**
  * @brief  Configure system clock to run at Maximum clock speed and output the 
  *         system clock on CCO pin
  * @param  None
  * @retval None
  */
static void CLK_Config(void)
{
CLK_HSECmd(ENABLE);
CLK_ClockSwitchConfig(CLK_SWITCHMODE_MANUAL, CLK_SOURCE_HSE, DISABLE, CLK_CURRENTCLOCKSTATE_DISABLE);
CLK_ClockSwitchCmd(ENABLE);
}

/* GPIO Init -----------------------------------------------------------------*/
/**
  * @brief  Configure GPIO Pins 
  * @param  None
  * @retval None
  */
static void GPIO_Config(void)
{
  GPIO_Init (GPIOB, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_FAST);
  GPIO_Init (GPIOD, GPIO_PIN_3, GPIO_MODE_OUT_PP_LOW_FAST);
}

/* Timer4 Init ---------------------------------------------------------------*/
/**
  * @brief  Configure TIM4 peripheral   
  * @param  None
  * @retval None
  */
static void TIM4_Config(void)
{
  /* TIM4 configuration:
   - TIM4CLK is set to 16 MHz, the TIM4 Prescaler is equal to 128 so the TIM1 counter
   clock used is 16 MHz / 128 = 125 000 Hz
  - With 125 000 Hz we can generate time base:
      max time base is 2.048 ms if TIM4_PERIOD = 255 --> (255 + 1) / 125000 = 2.048 ms
      min time base is 0.016 ms if TIM4_PERIOD = 1   --> (  1 + 1) / 125000 = 0.016 ms
  - In this example we need to generate a time base equal to 1 ms
   so TIM4_PERIOD = (0.001 * 125000 - 1) = 124 */

  /* Time base configuration */
  TIM4_TimeBaseInit(TIM4_Prescaler_128, TIM4_PERIOD);
  /* Clear TIM4 update flag */
  TIM4_ClearFlag(TIM4_FLAG_Update);
  /* Enable update interrupt */
  TIM4_ITConfig(TIM4_IT_Update, ENABLE);
  TIM4_Cmd(ENABLE);
}

static u32 uptime = 0;
static u32 delay_time = 0;
u8 z = 0;

/**
  * @brief  System Tick Counter for delay
  * @param  None
  * @retval None
  */
void uptime_routine(void)
{
  uptime++;
  if(uptime == 0xFFFFFFFF){
    delay_time = 0;
    uptime  = 0;
  }
  z++;
  if(z == 250){
    z = 0;
    GPIO_WriteReverse(GPIOB, GPIO_PIN_5);
  }
}

/**
  * @brief  Delay Routine
  * @param  wait time in ms
  * @retval None
  */
void _delay_ms(u16 wait)
{ 
  delay_time = uptime + wait;
  while(delay_time > uptime){}
}

