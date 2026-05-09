#pragma once

#if defined(ARDUINO)
#include <Arduino.h>
#else
#include <string>
using String = std::string;
#endif

class MockBluetoothServer {
public:
    String getObjectInfoJson(const String &rfidID) const;
};
