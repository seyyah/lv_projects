///**
// * @file stm32_test.c
// *
// */
//
///*********************
// *      INCLUDES
// *********************/
//#include "lvgl/lvgl.h"
//#include "misc/gfx/anim.h"
//
///*********************
// *      DEFINES
// *********************/
//
///**********************
// *      TYPEDEFS
// **********************/
//
///**********************
// *  STATIC PROTOTYPES
// **********************/
//static void left_create(void);
//static void mid_create(void);
//static void right_create(void);
//static void select_create(void);
//static void chart_anim(lv_obj_t * chart, uint16_t val);
//static lv_action_res_t write_sel_action(lv_obj_t * btn, lv_dispi_t * dispi);
//static lv_action_res_t list_sel_action(lv_obj_t * btn, lv_dispi_t * dispi);
//static lv_action_res_t show_sel_action(lv_obj_t * btn, lv_dispi_t * dispi);
//static lv_action_res_t slider_action(lv_obj_t * slider, lv_dispi_t * dispi);
//static lv_action_res_t list_add_action(lv_obj_t * btn, lv_dispi_t * dispi);
//
///**********************
// *  STATIC VARIABLES
// **********************/
//LV_IMG_DECLARE(img_blue_1);
//
//static lv_obj_t * wp;
//static lv_obj_t * cont;
//static lv_obj_t * ta;
//static lv_obj_t * sel_line;
//static cord_t chart_val[10] = {29, 33, 43, 21, 38,
//                        52, 67, 58, 77, 85};
//static uint8_t chart_start = 0;
//static uint8_t chart_end = 200;
//static lv_chart_dl_t * dl1;
//static lv_obj_t * chart;
//static lv_obj_t * bar;
//
///**********************
// *      MACROS
// **********************/
//
///**********************
// *   GLOBAL FUNCTIONS
// **********************/
//void stm32_test_init(void)
//{
//    lv_img_create_file("bg", img_blue_1);
//    wp = lv_img_create(lv_scr_act(), NULL);
//    lv_img_set_upscale(wp, true);
//    lv_img_set_file(wp, "U:/bg");
//
//    cont = lv_obj_create(lv_scr_act(), NULL);
//    lv_obj_set_size(cont, LV_HOR_RES * 3 + LV_DPI * 2, LV_VER_RES);
//    lv_obj_set_style(cont, lv_style_get(LV_STYLE_TRANSP_TIGHT, NULL));
//
//    left_create();
//    mid_create();
//    right_create();
//    select_create();
//}
//
///**********************
// *   STATIC FUNCTIONS
// **********************/
//
//static void left_create(void)
//{
//    static lv_style_t style_ta;
//    ta = lv_ta_create(cont, NULL);
//    lv_obj_set_size(ta, LV_HOR_RES, LV_VER_RES / 2 - LV_DPI / 2);
//    lv_ta_set_text(ta, "");
//    lv_style_cpy(&style_ta, lv_obj_get_style(ta));
//
//    style_ta.opa = OPA_60;
//    style_ta.radius = 0;
//    lv_obj_set_style(ta, &style_ta);
//
//    lv_obj_t * kb;
//    kb = lv_app_kb_open(ta, LV_APP_KB_MODE_TXT, NULL, NULL);
//    lv_obj_set_parent(kb, cont);
//    static lv_style_t style_kb;
//    lv_style_cpy(&style_kb, lv_obj_get_style(kb));
//    style_kb.opa = OPA_60;
//    lv_obj_set_style(kb, &style_kb);
//
//    lv_obj_align_us(ta, kb, LV_ALIGN_OUT_TOP_MID, 0, 0);
//
//}
//
//static void mid_create(void)
//{
//
//    /*Create a style for the images on the list buttons*/
//    static lv_style_t style_img;
//    lv_style_get(LV_STYLE_BTN_REL, &style_img);
//    style_img.font = font_get(FONT_SYMBOL_30); /*Only set a symbol font*/
//
//    /*Create a scroll bar style*/
//    static lv_style_t style_sb;
//    lv_style_get(LV_STYLE_PLAIN, &style_sb);
//    style_sb.mcolor = COLOR_GRAY;
//    style_sb.gcolor = COLOR_GRAY;
//    style_sb.bcolor = COLOR_WHITE;
//    style_sb.bwidth = 1 * LV_DOWNSCALE;
//    style_sb.bopa = OPA_70;
//    style_sb.radius = LV_RADIUS_CIRCLE;
//    style_sb.opa = OPA_60;
//
//    static lv_style_t style_bg;
//    lv_style_get(LV_STYLE_TRANSP_TIGHT, &style_bg);
//    style_bg.opad = 0;
//    style_bg.hpad = 0;
//    style_bg.vpad = 0;
//
//    /*Create styles for the buttons*/
//    static lv_style_t style_btn_rel;
//    static lv_style_t style_btn_pr;
//    lv_style_get(LV_STYLE_BTN_REL, &style_btn_rel);
//    style_btn_rel.mcolor = COLOR_MAKE(0x30, 0x30, 0x30);
//    style_btn_rel.gcolor = COLOR_BLACK;
//    style_btn_rel.bcolor = COLOR_SILVER;
//    style_btn_rel.bwidth = 1;
//    style_btn_rel.bopa = OPA_50;
//    style_btn_rel.radius = 0;
//    style_btn_rel.opad = LV_DPI / 4;
//
//    memcpy(&style_btn_pr, &style_btn_rel, sizeof(lv_style_t));
//    style_btn_pr.mcolor = COLOR_MAKE(0x55, 0x96, 0xd8);
//    style_btn_pr.gcolor = COLOR_MAKE(0x37, 0x62, 0x90);
//    style_btn_pr.ccolor = COLOR_MAKE(0xbb, 0xd5, 0xf1);
//
//    /**************************************
//     * Create a list with modified styles
//     **************************************/
//
//    /*Copy the previous list*/
//    lv_obj_t * list2 = lv_list_create(cont,NULL);
//    lv_obj_set_pos(list2, LV_HOR_RES + LV_DPI + LV_HOR_RES / 2 - lv_obj_get_width(list2) / 2, 3 * LV_DPI / 4);
//    lv_list_set_styles_btn(list2, &style_btn_rel, &style_btn_pr, NULL, NULL, NULL); /*Set the new button styles*/
//    lv_obj_set_style(list2, &style_bg);                         /*Set the new bg style for the page and its scrollabe too*/
//    lv_obj_set_style(lv_page_get_scrl(list2), &style_bg);
//    lv_page_set_sb_mode(list2, LV_PAGE_SB_MODE_DRAG);            /*Hide the scroll bar*/
//    lv_page_set_style_sb(list2, &style_sb);                     /*Set the scroll bar style*/
//    lv_list_set_style_img(list2, &style_img);                   /*Set the new image style*/
//    /*Add list elements*/
//    lv_list_add(list2, SYMBOL_FILE, "New", list_add_action);
//    lv_list_add(list2, SYMBOL_FOLDER, "Open", list_add_action);
//    lv_list_add(list2, SYMBOL_DELETE, "Delete", list_add_action);
//    lv_list_add(list2, SYMBOL_EDIT, "Edit", list_add_action);
//    lv_list_add(list2, SYMBOL_SAVE, "Save", list_add_action);
//    lv_list_add(list2, SYMBOL_WIFI, "WiFi", list_add_action);
//    lv_list_add(list2, SYMBOL_GPS, "GPS", list_add_action);
//
//}
//
//static void right_create(void)
//{
//    chart = lv_chart_create(cont, NULL);
//    lv_obj_set_size(chart, LV_HOR_RES, LV_VER_RES / 2);
//    lv_obj_set_pos(chart, 2 *LV_HOR_RES + 2 * LV_DPI, LV_DPI / 2);
//    lv_chart_set_type(chart, LV_CHART_COL);
//
//    static lv_style_t style_chart;
//    lv_style_cpy(&style_chart, lv_obj_get_style(chart));
//    style_chart.opa = OPA_60;
//    style_chart.radius = 0;
//    style_chart.ccolor = COLOR_GRAY;
//
//    lv_obj_set_style(chart, &style_chart);
//    dl1 = lv_chart_add_data_line(chart, COLOR_RED);
//
//    /*Create a bar, an indicator and a knob style*/
//    static lv_style_t style_bar;
//    static lv_style_t style_indic;
//    static lv_style_t style_knob;
//
//    lv_style_get(LV_STYLE_PRETTY, &style_bar);
//    style_bar.mcolor =  COLOR_BLACK;
//    style_bar.gcolor =  COLOR_GRAY;
//    style_bar.radius = LV_RADIUS_CIRCLE;
//    style_bar.bcolor = COLOR_WHITE;
//    style_bar.opa = OPA_60;
//
//    lv_style_get(LV_STYLE_PRETTY, &style_indic);
//    style_indic.gcolor =  COLOR_MARRON;
//    style_indic.mcolor =  COLOR_RED;
//    style_indic.radius = LV_RADIUS_CIRCLE;
//    style_indic.swidth = 10 * LV_DOWNSCALE;
//    style_indic.scolor = COLOR_RED;
//    style_indic.hpad = 3 * LV_DOWNSCALE;
//    style_indic.vpad = 3 * LV_DOWNSCALE;
//
//    lv_style_get(LV_STYLE_PRETTY, &style_knob);
//    style_knob.radius = LV_RADIUS_CIRCLE;
//    style_knob.opa = OPA_70;
//    style_knob.hpad = 0 * LV_DOWNSCALE;
//    style_knob.vpad = 8 * LV_DOWNSCALE;
//
//    /*Create a second slider*/
//    bar = lv_slider_create(cont, NULL);
//    lv_obj_set_style(bar, &style_bar);
//    lv_bar_set_style_indic(bar, &style_indic);
//    lv_slider_set_style_knob(bar, &style_knob);
//    lv_obj_align_us(bar, chart, LV_ALIGN_OUT_BOTTOM_MID, 0, 50); /*Align below 'bar1'*/
//    lv_obj_set_size(bar, 2 * LV_DPI, LV_DPI / 3);
//    lv_slider_set_action(bar, slider_action);
//    lv_bar_set_range(bar, 0, 255);
//    lv_bar_set_value(bar, chart_end);
//}
//
//static void select_create(void)
//{
//    lv_obj_t * sel1 = lv_btn_create(lv_scr_act(), NULL);
//    lv_obj_set_height(sel1, LV_DPI / 2);
//    lv_btn_set_rel_action(sel1, write_sel_action);
//    lv_btn_set_styles(sel1, lv_style_get(LV_STYLE_TRANSP, NULL), NULL, NULL, NULL, NULL);
//    lv_obj_align_us(sel1, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);
//
//    lv_obj_t * sel2 = lv_btn_create(lv_scr_act(), sel1);
//    lv_obj_align_us(sel2, NULL, LV_ALIGN_IN_TOP_MID, 0, 0);
//    lv_btn_set_rel_action(sel2, list_sel_action);
//
//
//    lv_obj_t * sel3 = lv_btn_create(lv_scr_act(), sel1);
//    lv_obj_align_us(sel3, NULL, LV_ALIGN_IN_TOP_RIGHT, 0, 0);
//    lv_btn_set_rel_action(sel3, show_sel_action);
//
//
//    static lv_style_t style_sel_label;
//    lv_style_get(LV_STYLE_PRETTY, &style_sel_label);
//    style_sel_label.font = font_get(FONT_DEJAVU_40);
//    style_sel_label.ccolor = COLOR_MAKE(0xf0, 0xf0, 0xf0);
//
//    lv_obj_t * sel_label = lv_label_create(sel1, NULL);
//    lv_label_set_text(sel_label, "Write");
//    lv_obj_set_style(sel_label, &style_sel_label);
//
//    sel_label = lv_label_create(sel2, sel_label);
//    lv_label_set_text(sel_label, "List");
//
//    sel_label = lv_label_create(sel3, sel_label);
//    lv_label_set_text(sel_label, "Show");
//
//    sel_line = lv_obj_create(lv_scr_act(), NULL);
//    lv_obj_set_size(sel_line, LV_DPI, LV_DPI / 12);
//    lv_obj_align(sel_line, sel1, LV_ALIGN_IN_BOTTOM_MID, 0, 0);
//
//}
//
//
//static void chart_anim(lv_obj_t * chart, uint16_t val)
//{
//    uint8_t p;
//
//    for(p = 0; p < lv_chart_get_pnum(chart); p++) {
//        dl1->points[p] = (uint16_t)((uint16_t)chart_val[p] * val) >> 8;
//    }
//
//    lv_chart_refr(chart);
//}
//
//
//static lv_action_res_t write_sel_action(lv_obj_t * btn, lv_dispi_t * dispi)
//{
//
//    anim_t a;
//    a.var = wp;
//    a.start = lv_obj_get_x(wp);
//    a.end = 0;
//    a.fp = (anim_fp_t)lv_obj_set_x;
//    a.path = anim_get_path(ANIM_PATH_LIN);
//    a.end_cb = NULL;
//    a.act_time = 0;
//    a.time = 500;
//    a.playback = 0;
//    a.playback_pause = 0;
//    a.repeat = 0;
//    a.repeat_pause = 0;
//
//    anim_create(&a);
//
//    a.var = cont;
//    a.start = lv_obj_get_x(cont);
//    a.end = 0;
//    a.fp = (anim_fp_t)lv_obj_set_x;
//    a.path = anim_get_path(ANIM_PATH_LIN);
//    a.end_cb = NULL;
//    a.act_time = 0;
//    a.time = 500;
//    a.playback = 0;
//    a.playback_pause = 0;
//    a.repeat = 0;
//    a.repeat_pause = 0;
//
//    anim_create(&a);
//
//    a.var = sel_line;
//    a.start = lv_obj_get_x(sel_line);
//    a.end = 0;
//    a.fp = (anim_fp_t)lv_obj_set_x;
//    a.path = anim_get_path(ANIM_PATH_LIN);
//    a.end_cb = NULL;
//    a.act_time = 0;
//    a.time = 500;
//    a.playback = 0;
//    a.playback_pause = 0;
//    a.repeat = 0;
//    a.repeat_pause = 0;
//    anim_create(&a);
//
//    return LV_ACTION_RES_OK;
//}
//
//
//static lv_action_res_t list_sel_action(lv_obj_t * btn, lv_dispi_t * dispi)
//{
//    anim_t a;
//    a.var = wp;
//    a.start = lv_obj_get_x(wp);
//    a.end = LV_HOR_RES / 2 - lv_obj_get_width(wp) / 2;
//    a.fp = (anim_fp_t)lv_obj_set_x;
//    a.path = anim_get_path(ANIM_PATH_LIN);
//    a.end_cb = NULL;
//    a.act_time = 0;
//    a.time = 500;
//    a.playback = 0;
//    a.playback_pause = 0;
//    a.repeat = 0;
//    a.repeat_pause = 0;
//
//    anim_create(&a);
//
//    a.var = cont;
//    a.start = lv_obj_get_x(cont);
//    a.end =  LV_HOR_RES / 2 - lv_obj_get_width(cont) / 2;
//    a.fp = (anim_fp_t)lv_obj_set_x;
//    a.path = anim_get_path(ANIM_PATH_LIN);
//    a.end_cb = NULL;
//    a.act_time = 0;
//    a.time = 500;
//    a.playback = 0;
//    a.playback_pause = 0;
//    a.repeat = 0;
//    a.repeat_pause = 0;
//
//    anim_create(&a);
//
//    a.var = sel_line;
//    a.start = lv_obj_get_x(sel_line);
//    a.end =  LV_HOR_RES / 2 - lv_obj_get_width(sel_line) / 2;
//    a.fp = (anim_fp_t)lv_obj_set_x;
//    a.path = anim_get_path(ANIM_PATH_LIN);
//    a.end_cb = NULL;
//    a.act_time = 0;
//    a.time = 500;
//    a.playback = 0;
//    a.playback_pause = 0;
//    a.repeat = 0;
//    a.repeat_pause = 0;
//    anim_create(&a);
//
//    return LV_ACTION_RES_OK;
//}
//
//static lv_action_res_t show_sel_action(lv_obj_t * btn, lv_dispi_t * dispi)
//{
//    anim_t a;
//    a.var = wp;
//    a.start = lv_obj_get_x(wp);
//    a.end = LV_HOR_RES - lv_obj_get_width(wp);
//    a.fp = (anim_fp_t)lv_obj_set_x;
//    a.path = anim_get_path(ANIM_PATH_LIN);
//    a.end_cb = NULL;
//    a.act_time = 0;
//    a.time = 500;
//    a.playback = 0;
//    a.playback_pause = 0;
//    a.repeat = 0;
//    a.repeat_pause = 0;
//
//    anim_create(&a);
//
//    a.var = cont;
//    a.start = lv_obj_get_x(cont);
//    a.end = LV_HOR_RES - lv_obj_get_width(cont);
//    a.fp = (anim_fp_t)lv_obj_set_x;
//    a.path = anim_get_path(ANIM_PATH_LIN);
//    a.end_cb = NULL;
//    a.act_time = 0;
//    a.time = 500;
//    a.playback = 0;
//    a.playback_pause = 0;
//    a.repeat = 0;
//    a.repeat_pause = 0;
//
//    anim_create(&a);
//
//    a.var = sel_line;
//    a.start = lv_obj_get_x(sel_line);
//    a.end = LV_HOR_RES - lv_obj_get_width(sel_line);
//    a.fp = (anim_fp_t)lv_obj_set_x;
//    a.path = anim_get_path(ANIM_PATH_LIN);
//    a.end_cb = NULL;
//    a.act_time = 0;
//    a.time = 500;
//    a.playback = 0;
//    a.playback_pause = 0;
//    a.repeat = 0;
//    a.repeat_pause = 0;
//    anim_create(&a);
//
//
//    a.var = chart;
//    a.start = chart_start;
//    a.end = chart_end;
//    a.fp = (anim_fp_t)chart_anim;
//    a.path = anim_get_path(ANIM_PATH_LIN);
//    a.end_cb = NULL;
//    a.act_time = -400;
//    a.time = 500;
//    a.playback = 0;
//    a.playback_pause = 0;
//    a.repeat = 0;
//    a.repeat_pause = 0;
//    anim_create(&a);
//
//    a.var = bar;
//    a.start = 0;
//    a.end = lv_bar_get_value(bar);
//    a.fp = (anim_fp_t)lv_bar_set_value;
//    a.path = anim_get_path(ANIM_PATH_LIN);
//    a.end_cb = NULL;
//    a.act_time = -400;
//    a.time = 500;
//    a.playback = 0;
//    a.playback_pause = 0;
//    a.repeat = 0;
//    a.repeat_pause = 0;
//    anim_create(&a);
//
//    return LV_ACTION_RES_OK;
//}
//
//static lv_action_res_t slider_action(lv_obj_t * slider, lv_dispi_t * dispi)
//{
//    chart_start = chart_end;
//    chart_end = lv_bar_get_value(slider);
//
//    anim_t a;
//    a.var = chart;
//    a.start = chart_start;
//    a.end = chart_end;
//    a.fp = (anim_fp_t)chart_anim;
//    a.path = anim_get_path(ANIM_PATH_LIN);
//    a.end_cb = NULL;
//    a.act_time = 0;
//    a.time = 500;
//    a.playback = 0;
//    a.playback_pause = 0;
//    a.repeat = 0;
//    a.repeat_pause = 0;
//    anim_create(&a);
//
//    return LV_ACTION_RES_OK;
//}
//
//static lv_action_res_t list_add_action(lv_obj_t * btn, lv_dispi_t * dispi)
//{
//    lv_ta_add_char(ta, '\n');
//    lv_ta_add_text(ta, lv_list_get_element_text(btn));
//
//    return LV_ACTION_RES_OK;
//}
