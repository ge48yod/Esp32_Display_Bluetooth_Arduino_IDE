#pragma once

#include "StorageInfo.h"

#if defined(ARDUINO)
#include <lvgl.h>
#endif

class DisplayManager {
public:
    void begin();
    void updateStorageInfo(const StorageInfo &info);

private:
#if defined(ARDUINO)
    lv_obj_t *objectIdLabel_ = nullptr;
    lv_obj_t *objectNameLabel_ = nullptr;
    lv_obj_t *statusLabel_ = nullptr;
    lv_obj_t *locationLabel_ = nullptr;
#endif
};
