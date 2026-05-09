#include "lvgl_port.h"

#if defined(ARDUINO)
#include <lvgl.h>
#endif

bool lvgl_port_init(void)
{
#if defined(ARDUINO)
    lv_init();
#endif
    return true;
}

void lvgl_port_task(void)
{
#if defined(ARDUINO)
    lv_timer_handler();
#endif
}
