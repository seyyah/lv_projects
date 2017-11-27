/**
 * @file disp.h
 * 
 */

#ifndef DISP_H
#define DISP_H

/*********************
 *      INCLUDES
 *********************/
#include <stdint.h>
#include "lvgl/lv_misc/lv_color.h"
#include "lvgl/lv_misc/lv_area.h"

/*********************
 *      DEFINES
 *********************/
#define DISP_HOR_RES 240
#define DISP_VER_RES 320

#define DISP_EXT_FB		1		/*Frame buffer is located into an external SDRAM*/
#define DISP_HW_ACC		0		/*Enable hardware accelerator ('disp_color_cpy()' has to be implemented)*/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void tft_init(void);

/**********************
 *      MACROS
 **********************/

#endif
