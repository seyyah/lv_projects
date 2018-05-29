# LittlevGL ported boards and microcontrollers

This repository contains projects where [LittlevGL](https://littlevgl.com) is configures for a development board or microcontroller. 

Contributing is very welcome! Plaase, share with others if you used LittlevGL with a new board or MCU.

## Usage
1. Clone the repository somewhere: `git clone https://github.com/littlevgl/lv_boards.git`
2. Step into the repository: `cd lv_boards`
3. Initalize the submodules: `git submodule update --init`
4. Copy/Paste a project where you want to use it (e.g. IDE workspace)

## Porojects

### arduino_library
LittlevGL as an Arduino library. 
Copy *arduino_library/littelvgl* to your library folder
Check the *lvgl_test* sketch to see the proting and usage

### esp32_ili9431
Driving an 320x240 TFT with ILI9432 controller via SPI using ESP32. The project is craeted in Eclipse using [ESP IDF](https://esp-idf.readthedocs.io/en/latest/). (Getting started guide [here](https://esp-idf.readthedocs.io/en/v1.0/eclipse-setup.html)) To link LittlevGL and lv_examples with ESP-IDF you need to add component.mk files to each directory. Rename `lvgl_component.mk` and `lv_example_component.mk` to `component.mk` and copy to the lvgl and lv_examples directories.  

### stm32f429_discovery_no_os
Cheap development board with 240x320 TFT, Resistive touch pad, 180 MHz MCU with 256kB RAM + 64 MBit SDRAM and GPU.
The CubeMX drivers are used to initilaize the peripheries. In *hal_stm_lvgl/tft/tft.h* you can enable/disable external frame buffer placement and GPU usage.

### stm32f469_discovery_no_os
STM development board with 800x480 TFT and MIPI DSI interface, capacitive touch screen, 180 MHz MCU with 324kB RAM + 128 MBit SDRAM and GPU.
The CubeMX drivers are used to initilaize the peripheries. In *hal_stm_lvgl/tft/tft.h* you can enable/disable external frame buffer placement and GPU usage.

### stm32f746_discovery_no_os
STM development board with 480x272 TFT, Capacitive touch pad, 216 MHz MCU with 320kB RAM + 64 MBit SDRAM and GPU.
The CubeMX drivers are used to initilaize the peripheries. Solution uses frame buffer placed in the external SRAM memory. GPU is configurable over USE_LV_GPU define.
To compile example go to *Release* directory and run `make`.

### pic32mx_r61581_no_os
A custom PIC32MX695H based board drives a 480x320 display with R61581 display controller via software parallel port.
The MCU has 512kB flash, 128 kB RAM and tuns at 80 MHz. It able to applay font anti-aliasing and even screen sized animations. 
Touch pad driver is not added yet.


### pic32mx_ssd1963_no_os
A custom PIC32MX695H based board drives a 800x480 display with SSD1963 display controller via software parallel port.
Still work in progrss.

### linux_frame_buffer
Directly use Linux fame buffer (e.g. /dev/fb0) as frame buffer. Demonstrates the usage winth embedded Linux systems. The project is created in Eclipse CDT. Learn more here: [LittlevGL Blog Post](https://littlevgl.com/blog/23/embedded-gui-using-linux-frame-buffer-device-with-littlevgl)

