#pragma once

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    LCD_PWM_MODE_OFF = 0,
    LCD_PWM_MODE_255 = 255
} lcd_pwm_mode_t;

bool lcd_bl_pwm_bsp_init(lcd_pwm_mode_t mode);

#ifdef __cplusplus
}
#endif
