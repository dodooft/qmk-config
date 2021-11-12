#pragma once
#include QMK_KEYBOARD_H

#include "progmem.h"
#include "animation.c"

// extern uint8_t is_master;
static uint16_t oled_timer = 0;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void render_animation(uint8_t frame) {
    // oled_write_raw_P(animation[frame], sizeof(animation[frame]));
	// oled_write_P (logo, false);
}

void oled_task_user(void) {
    // render_animation((timer_read() / 60) % 8)
	

}
