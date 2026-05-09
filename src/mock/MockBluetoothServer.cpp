#include "MockBluetoothServer.h"

#include "../../user_config.h"

String MockBluetoothServer::getObjectInfoJson(const String &rfidID) const
{
    if (rfidID == FIXED_RFID_ID) {
        return "{\"objectID\":\"A12\",\"objectName\":\"Precision Bearings\",\"status\":\"Available\",\"location\":\"Shelf 3\"}";
    }

    return "{\"objectID\":\"UNKNOWN\",\"objectName\":\"Unknown Object\",\"status\":\"Not Found\",\"location\":\"N/A\"}";
}
