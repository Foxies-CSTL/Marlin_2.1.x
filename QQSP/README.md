### 2024-12-18 PRE-RELEASE MARLIN 2.1.3 (compatible with GD32*)

- QQS-Pro STOCK With 4xA4988 = QQSP_STOCK-Robin_mini.bin
- QQS-Pro STOCK With 4xTMC2208 = QQSP_STOCK_TMC8-Robin_mini.bin
- QQS-Pro STOCK With 4xTMC2209 = QQSP_STOCK_TMC9-Robin_mini.bin
  
Each firmware has a header that corresponds to the hardware (board) and functions used in the firmware.
Below is an example with the firmware for a QQS-Pro printer with a HiSpeedv1 board with TMC2208 stepper drivers:

**Exemple:**
SCWTPULR-Robin_mini.bin => QQSPro Stock
=> 
   - (S)4xA4988 - 
   - (C)UI Marlin TFT32 - 
   - (W)Wifi module - 
   - (T)Extruder Titan(Stock) - 
   - (P)PreHeat bed - 
   - (U)Leveling mode -
   - (L)LinearAdvance - 
   - (R)Arc function enabled.
   - (Z) Input Shaper

  🔧**Note**: After choosing your binary, remove the "SCWTPULR-" header or rename the file to "Robin_mini.bin" for QQS,
  place it on your SD card, insert your SD card into the printer and power on your printer.
  
-* With GD32 chip, the rename is "Robin_nano.bin"

  ♻️ **Caution for QQS printer**♻️: In some QQSPs(GD32 chip), the flash is blocked because of the screen. To unblock it, you need to remove the shielding from the wire ribbon that connects the MoBo to the screen and reflash the firmware.
  
  After the flash and to configure and prepare your printer, please follow the steps on the Wiki
  
=> [<img width=400 src="https://github.com/Foxies-CSTL/Marlin_2.1.x/wiki/icons/FLSun-Wiki.png" />](https://github.com/Foxies-CSTL/Marlin_2.1.x/wiki/2.SETTINGS-THE-PRINTER)

  or for a summary of [the steps to follow](../Instructions.md)
  
  📌**New 2023:**
  *Due to the increasing number of user requests and combinations of different HotEnd, MoBo and software features, I can build a firmware suitable for your configuration: A small contribution will be asked* 🍻.

**ADD:** Pack firmwares for BTT-TFT35/50/70 mode landscape and portrait.

  **Header caption:**

  **/*------Drivers--------*/**
  - (S) 4xA4988 (Stock= Default for QQSP)
  - (8) TMC2208 Standalone
  - (9) TMC2209 Standalone
  - (U8) 4xTMC2208_UART with no module ESP12.
  - (U9) 4xTMC2209_UART with no module ESP12.
  - (U8+) 3xTMC2208 (XYZ) + Choice for E0 (A4988,TMC220x) 
  - (U9+) 3xTMC2209 (XYZ) + Choice for E0 (A4988,TMC220x)
  - **(UH) 4xTMC2209_UART with one wire (option modules Wifi/Rpi/Neopixel)**
  - (16) All drivers 16steps (default)
  - (32) All drivers 32steps (TMC-UART)

  **/*-------Options UI TFT--------*/**
  - (F) UI STANDARD (Emulation LCD screen on TFT)
  - (C) UI MARLIN (TFT Color screen) (Default)
  - (I) UI MKS (TFT Color screen>=480x320 use Lvgl/NANOv2-3)
  - (s) UI TOUCH (BTT-TFT) TFT serial Mod. 
  - (r) UI STANDARD (Marlin Mode on TFT FOR SKR/NANOv2-3)
  - (s) UI TOUCH for the BTT-TFT Mod for the QQSP/Q5.
  - (D) UI DWIN (H43)

  **/*------Modules--------*/**
  - (N) NeoPixel (management of led strips, number=nb leds)
  - (W) Module ESP8266/ESP12 (infos at the middle of the page)
  - (w) Module ESP8266/ESP12 with ESP3Dv3.0 Firmware.
  - (T) Extruder Titan/Stock
  - (B) Extruder BMG (also reverse direction)
  - (O) Extruder OMG
  - (X) Extruder DirectDrive Nema14 pancake (SuperDriveHX/Mini-Sherpa/Lgx/...)
  
  **/*-------Others options in firmware----*/**
  - (G) SENSORLESS_HOMING (Only 2209 and need wiring)
  - (g) SENSORLESS_PROBING (Only 2209 and need wiring)
  - (m) MPCTEMP - Model predictive temperature control (New PID Nozzle)
  - (H) Hotend Volcano or HotendAllMetal (number=type thermistor)
  - (A) BED_LEVELING_BILINEAR
  - (U) BED_LEVELING_UBL (levelings saved to location) (Default)
  - (P) PreHeat bed before leveling
  - (R) ARC_SUPPORT (Default)
  - (L) Linear Advance (Default)
  - (M) MEATPACK (Improve dialogue/communication with OctoPrint) (Default)
  - (Z) Input Shaping (no validated on Deltas).
  
  **/*-------Others options for advanced users who build their firmware----*/**
  - HOST_ACTION_COMMANDS (Action Command Prompt support Message on OctoPrint) (default)
  - Host start print by menu (Only TFT_COLOR_UI)
  - BINARY_FILE_TRANSFER
  - TEMP_SENSOR_0 (After changed the thermitor nozzle)
  - LCD_LANGUAGE (Change to the native language)
  - NEOPIXEL_PIXELS (Add line for nb of leds).
  - FWRETRACT (To use the retraction of the extrusion by the firmware).
  - Fixed "Special Menu" for MPC and levelings.
  - etc 
 
  **/*-------Others Firmwares for QQS with SKR family or Mks_Nano Family Boards ----*/**
  - (QQSP_8+SCTPULR-Robin_nano)     QQS with NanoV1.2 + 3xTMC2208standalone+1xA4988 and TITAN/STOCK extruder. 
  - (QQSP_9CBPULR-Robin_nano35)     QQS with NanoV1.3 + 4xTMC2209Standalone and BMG extruder.
  - (QQSP_U9rTPULR16-SKR14_firmware QQS with SKRv1.4 Board + 4x2209Uart with BTT-TFT emulation LCD (Marlin Mode)
 ## ✨Support my work✨

  This FLSun Deltas porting project for Marlin firmware was only possible thanks to its supporters, you can participate:
 <br/>
  <br/> Via [![paypal.me](./icons/paypal_50px.png)](https://www.paypal.me/Foxies40)<br/>[![Donate](https://img.shields.io/badge/Donate-Thanks-green)](https://paypal.me/Foxies40)<br/>
<br/>
 
Via   <a href='https://ko-fi.com/U7U77F782' target='_blank'><img height='36' style='border:0px;height:36px;' src='https://cdn.ko-fi.com/cdn/kofi4.png?v=3' border='0' alt='Buy Me a Coffee at ko-fi.com' /></a>   with a Mini-Blog.

  You can also send me a tip via [Thingiverse](https://www.thingiverse.com/FamStel/about) if you prefer.
 ### Massive thank you in advance :heart:
***
