#pragma once

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

bool lvgl_port_init(void);
void lvgl_port_task(void);

#ifdef __cplusplus
}
#endif
