#pragma once

#if defined(ARDUINO)
#include <Arduino.h>
#else
#include <string>
using String = std::string;
#endif

#include "../mock/MockBluetoothServer.h"
#include "../ui/StorageInfo.h"

class BluetoothManager {
public:
    void begin();
    bool requestStorageInfo(const String &rfidID, StorageInfo &outInfo);
    bool isConnected() const;

private:
    bool parseResponse(const String &json, StorageInfo &outInfo) const;

    bool connected_ = false;
    MockBluetoothServer mockServer_;
};
