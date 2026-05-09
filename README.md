# Esp32_Display_Bluetooth_Arduino_IDE

Arduino IDE compatible ESP32-S3 project for the Waveshare ESP32-S3-LCD-3.16 board.

## Features

- `.ino` entrypoint (`main.ino`)
- fixed local RFID (`93A7C412`)
- BLE manager abstraction with mock and placeholder real-BLE path
- mock BLE JSON response support (`USE_MOCK_BLUETOOTH`)
- LVGL-based display manager with dynamic label updates
- modular reusable source layout

## Project Layout

```text
.
├── main.ino
├── user_config.h
├── lvgl_port.h
├── lvgl_port.c
├── lcd_bl_pwm_bsp.h
├── lcd_bl_pwm_bsp.c
└── src
    ├── bluetooth
    │   ├── BluetoothManager.h
    │   └── BluetoothManager.cpp
    ├── ui
    │   ├── DisplayManager.h
    │   ├── DisplayManager.cpp
    │   └── StorageInfo.h
    ├── mock
    │   ├── MockBluetoothServer.h
    │   └── MockBluetoothServer.cpp
    ├── io_additions
    │   ├── esp_io_expander.h
    │   ├── esp_io_expander.c
    │   ├── esp_lcd_panel_io_3wire_spi.c
    │   └── esp_lcd_panel_io_additions.h
    └── st7701_bsp
        ├── esp_lcd_st7701.h
        ├── esp_lcd_st7701.c
        ├── esp_lcd_st7701_interface.h
        ├── esp_lcd_st7701_mipi.c
        └── esp_lcd_st7701_rgb.c
```

## Arduino IDE Setup

1. Install **ESP32 by Espressif Systems** in Arduino IDE Board Manager.
2. Install required libraries in sketchbook libraries:
   - `LVGL9`
   - `SensorLib`
   - `ArduinoJson`
3. Open this repository folder in Arduino IDE.
4. Select board family for ESP32-S3 and target the Waveshare ESP32-S3-LCD-3.16 configuration.
5. Build and upload.

## Modes

- Mock mode (default): `#define USE_MOCK_BLUETOOTH 1`
- Real BLE mode placeholder: change to `#define USE_MOCK_BLUETOOTH 0` and implement ESP32 BLE client logic in `BluetoothManager.cpp`.

## Data Flow

1. `main.ino` requests info for fixed RFID in the loop.
2. `BluetoothManager` sends RFID over BLE abstraction.
3. In mock mode, `MockBluetoothServer` returns JSON such as:

```json
{
  "objectID": "A12",
  "objectName": "Precision Bearings",
  "status": "Available",
  "location": "Shelf 3"
}
```

4. `DisplayManager` updates LVGL labels:
   - Object ID
   - Object Name
   - Status
   - Location
