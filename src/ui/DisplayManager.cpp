#include "DisplayManager.h"

#if defined(ARDUINO)
#include <Arduino.h>
#endif

void DisplayManager::begin()
{
#if defined(ARDUINO)
    lv_obj_t *screen = lv_screen_active();

    objectIdLabel_ = lv_label_create(screen);
    lv_obj_align(objectIdLabel_, LV_ALIGN_TOP_LEFT, 8, 8);

    objectNameLabel_ = lv_label_create(screen);
    lv_obj_align(objectNameLabel_, LV_ALIGN_TOP_LEFT, 8, 36);

    statusLabel_ = lv_label_create(screen);
    lv_obj_align(statusLabel_, LV_ALIGN_TOP_LEFT, 8, 64);

    locationLabel_ = lv_label_create(screen);
    lv_obj_align(locationLabel_, LV_ALIGN_TOP_LEFT, 8, 92);
#endif

    StorageInfo initial;
    initial.objectID = "-";
    initial.objectName = "Waiting...";
    initial.status = "-";
    initial.location = "-";
    updateStorageInfo(initial);
}

void DisplayManager::updateStorageInfo(const StorageInfo &info)
{
#if defined(ARDUINO)
    if (objectIdLabel_ != nullptr) {
        lv_label_set_text_fmt(objectIdLabel_, "Object ID: %s", info.objectID.c_str());
    }

    if (objectNameLabel_ != nullptr) {
        lv_label_set_text_fmt(objectNameLabel_, "Object Name: %s", info.objectName.c_str());
    }

    if (statusLabel_ != nullptr) {
        lv_label_set_text_fmt(statusLabel_, "Status: %s", info.status.c_str());
    }

    if (locationLabel_ != nullptr) {
        lv_label_set_text_fmt(locationLabel_, "Location: %s", info.location.c_str());
    }
#else
    (void)info;
#endif
}
