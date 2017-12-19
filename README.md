# LittlevGL ported boards and microcontrollers

This directory contains projects where [LittlevGL](http://gl.littlev.hu) is configures for a development board or microcontroller. 

Contrinuting is very welcome in his repository. Please, share if you used LittlevGL with a new bouar or MCU.

## Porojects

### stm32f429_discovery_no_os
Cheap development board with 240x320 TFT, Resistive touch pad, 180 MHz MCU with 256kB RAM + 64 MBit SDRAM and GPU.
The CubeMX drivers are used to initilaize the peripheries. In *hal_stm_lvgl/tft/tft.h* you can enable/disable external frame buffer placement and GPU usage.
