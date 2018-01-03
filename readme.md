This library is based on code found [here](https://www.joaquim.org/electronic/stm8s-discovery/stm8s-discovery-and-ws2812b-rgb-led/). But it has one major difference - it is configured in more clear way. 
## Usage

Just add files to your project and define pin used to control LEDs and strip length
For example
```
#define WS2812B_PORT    GPIOD_PORT
#define WS2812B_PIN     3
#define NB_LEDS         60
```
Files `WS2812B_LLD.c`, `WS2812B_LLD.h` and `ws2812b_conf.h` do not depend on any external libraries and may be used without STM8 SPL. They are low level drivers for LEDs and are mainly written in assembler. The only requirement is that MCU runs on 16MHz and pin is configured as fast PUSH_PULL output.

File `WS2812B_FX.c` contains some demo animations. It requires some realisation of void `_delay_ms(u16 wait)` for proper operation. 

Only one LED strip is supported.
