#include "user_config.h"
#include "lvgl_port.h"
#include "lcd_bl_pwm_bsp.h"

#include "src/bluetooth/BluetoothManager.h"
#include "src/ui/DisplayManager.h"

static BluetoothManager bluetoothManager;
static DisplayManager displayManager;

void setup()
{
    Serial.begin(115200);

    lvgl_port_init();

    lcd_bl_pwm_bsp_init(LCD_PWM_MODE_255);

    // initialize bluetooth
    bluetoothManager.begin();

    // initialize display manager
    displayManager.begin();
}

void loop()
{
    StorageInfo info;

    // periodic BLE request
    if (bluetoothManager.requestStorageInfo(FIXED_RFID_ID, info)) {
        // update display
        displayManager.updateStorageInfo(info);
    }

    lvgl_port_task();
    delay(1000);
}
