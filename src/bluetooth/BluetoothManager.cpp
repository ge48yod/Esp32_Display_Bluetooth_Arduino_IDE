#include "BluetoothManager.h"

#include "../../user_config.h"

#if defined(ARDUINO)
#include <ArduinoJson.h>
#endif

void BluetoothManager::begin()
{
#if USE_MOCK_BLUETOOTH
    connected_ = true;
#else
    // Placeholder for real ESP32 BLE client setup.
    connected_ = false;
#endif
}

bool BluetoothManager::requestStorageInfo(const String &rfidID, StorageInfo &outInfo)
{
    if (!connected_) {
        return false;
    }

#if USE_MOCK_BLUETOOTH
    const String json = mockServer_.getObjectInfoJson(rfidID);
    return parseResponse(json, outInfo);
#else
    (void)rfidID;
    // Placeholder for real BLE request/response flow.
    return false;
#endif
}

bool BluetoothManager::isConnected() const
{
    return connected_;
}

#if !defined(ARDUINO)
static String extractJsonValue(const String &json, const char *key)
{
    const String token = String("\"") + key + "\":\"";
    const size_t start = json.find(token);
    if (start == String::npos) {
        return String();
    }

    const size_t valueStart = start + token.size();
    const size_t valueEnd = json.find("\"", valueStart);
    if (valueEnd == String::npos) {
        return String();
    }

    return json.substr(valueStart, valueEnd - valueStart);
}
#endif

bool BluetoothManager::parseResponse(const String &json, StorageInfo &outInfo) const
{
#if defined(ARDUINO)
    StaticJsonDocument<256> doc;
    const DeserializationError err = deserializeJson(doc, json);
    if (err) {
        return false;
    }

    outInfo.objectID = doc["objectID"] | "";
    outInfo.objectName = doc["objectName"] | "";
    outInfo.status = doc["status"] | "";
    outInfo.location = doc["location"] | "";
    return true;
#else
    outInfo.objectID = extractJsonValue(json, "objectID");
    outInfo.objectName = extractJsonValue(json, "objectName");
    outInfo.status = extractJsonValue(json, "status");
    outInfo.location = extractJsonValue(json, "location");
    return !outInfo.objectID.empty();
#endif
}
