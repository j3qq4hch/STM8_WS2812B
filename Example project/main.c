#include <string.h>
#include <stdio.h>
#include "stm8s_conf.h"
#include "ws2812B_fx.h"

#define TIM4_PERIOD       124

void clk_config(void);
void TIM4_Config(void);
void delay()
{
  for(u16 i = 0; i < 0xFFFF; i++){}
}
void main( void )
{  
clk_config();
TIM4_Config();
GPIO_Init (GPIOB, GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_FAST);
GPIO_Init (GPIOD, GPIO_PIN_3, GPIO_MODE_OUT_PP_LOW_FAST);

enableInterrupts();

while(1)
{ 
rainbowCycle(25); 
}
}


void clk_config(void)
{
CLK_HSECmd(ENABLE);
CLK_ClockSwitchConfig(CLK_SWITCHMODE_MANUAL, CLK_SOURCE_HSE, DISABLE, CLK_CURRENTCLOCKSTATE_DISABLE);
CLK_ClockSwitchCmd(ENABLE);
}

void TIM4_Config(void)
{
  TIM4_TimeBaseInit(TIM4_PRESCALER_128, TIM4_PERIOD);
  TIM4_ClearFlag(TIM4_FLAG_UPDATE);
  TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);
  TIM4_Cmd(ENABLE);
}


static u32 uptime = 0;
static u32 delay_time = 0;
u8 z = 0;

void uptime_routine(void)
{
 uptime++;
 if(uptime == 0xFFFFFFFF)
 {
 delay_time = 0;
 uptime  = 0;
 }
 z++;
 if(z == 250)
 {
 z = 0;
 GPIO_WriteReverse(GPIOB, GPIO_PIN_5);
 }
}

void _delay_ms(u16 wait)
{ 
  delay_time = uptime + wait;
  while(delay_time > uptime){}
}

