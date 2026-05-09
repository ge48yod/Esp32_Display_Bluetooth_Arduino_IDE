#pragma once

#if defined(ARDUINO)
#include <Arduino.h>
#else
#include <string>
using String = std::string;
#endif

struct StorageInfo {
    String objectID;
    String objectName;
    String status;
    String location;
};
