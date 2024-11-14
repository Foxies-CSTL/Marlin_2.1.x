/*==========================================================================
*=================== Stel AMB8 - CARTESIAN Printer =============================
*================= With pins_.h BOARD =========================
*===========================================================================
*
* For a Delta printer start with one of the configuration files in the
* config/examples/ANET/A8 directory and customize for your machine.
*
* TIPS:
* -For reduce binary size : https://thborges.github.io/blog/marlin/2019/01/07/reducing-marlin-binary-size.html
* 
* -For NeoPixel use library : https://github.com/Foxies-CSTL/Nano-NeoPixel-Lib/archive/master.zip,
* and active it into the part of platformio.ini "env:flsun_hispeed",
* and commented error in SanityCheck.h for pass error check.
* // custom_marlin.NEOPIXEL_LED = Adafruit NeoPixel=https://github.com/p3p/Adafruit_NeoPixel/archive/1.5.0.zip
* -For 2209 change TMC2208 by TMC2209 at the bottom file.
*/

//========= Hardware ==========//
/*------Drivers-(1 CHOICE)-----*/
//#define STOCK                        //(S) For 4xA4988 with Robin_mini Board(Comment POWER_LOSS_RECOVERY)
//#define RAMPS                        //(S) For 4xA4988(green or red color)
//#define SKR                          //env: BIGTREE_SKR_2_USB
#define NANO12                       //env: mks_robin_nano_v1v2

/* MODE TMC */
#define AMB8_TMC                     //(8) For 4xTMC220x_STANDALONE For 2208(white color) or 2209(black color)
//#define AMB8_UARTx                   //(U8/U9) 4xTMC220x Note: For 2209 change TMC2208 by TMC2209 at the bottom file and remove on your printer the module WIFI.
//#define AMB8_UART9                   //(UH) Mode special 2209 wiring with one I/O pin (Remove module ESP12)

/*------- Choice Other driver for EXTRUDER-------//
* Options: 
* LV8729/A4988/TMC2208_STANDALONE/TMC2209_STANDALONE/TMC2208/TMC2209 
*/
#define DRIVER_EXT A4988

/* QQS Stock have a clone TITAN EXtruder,
* also if you have another try this.
* (T=397)/(B=417)/(b=141)
*/
//#define INV_EXT                    //(T) Uncommment to reverse direction.
//#define BMG                        //(B) Uncomment to change Extruder step.

/*--- Choice UI TFT ----*/
//#define TFT_CLASSIC_UI             //(F) UI STANDARD 
#define TFT_COLOR_UI               //(C) UI MARLIN
//#define TFT_LVGL_UI                //(I) UI MKS
//#define TFT_BTT_UI                 //(r) UI Classic (emulation LCD Marlin) for BTT TFT screen.
//#define TFT_DWIN_UI                //(D) UI for DGUS screen
//#define TFT_ROTATION TFT_ROTATE_180

/*----  Modules -----*/
//#define ESP_WIFI                   //(W) Module ESP8266/ESP12

/*For LedStrip which need an external power source on Vcc pin.*/
//#define NEOPIXEL_LED               //(N) Use port GPIO Wifi module (PA10/PA9/PA8/PC7)

//Many options for Modules: 
//#define POWER_LOSS_RECOVERY        //NC LVGL pb SD
//#define FILAMENT_RUNOUT_SENSOR     //NC LVGL
//#define ADVANCED_PAUSE_FEATURE     //NC LVGL
//#define LIN_ADVANCE                //(L) Possible Bug with BabyStep.For TMC_UART prefer mode spreadCycle         
//#define ARC_SUPPORT                //(R)
//#define CLASSIC_JERK
//#define NOZZLE_CLEAN_FEATURE
//#define ADAPTIVE_STEP_SMOOTHING
#ifdef RAMPS
  #define TEMP_SENSOR_0 1
  #define TEMP_SENSOR_BED 5
  #define TEMP_SENSOR_CHAMBER 11
  #define TEMP_CHAMBER_PIN TEMP_1_PIN //
#else
  #define TEMP_SENSOR_0 13
  #define TEMP_SENSOR_BED 0
  //#define TEMP_SENSOR_CHAMBER 0
  //#define TEMP_CHAMBER_PIN TEMP_1_PIN //
#endif
//#define MICROSTEPS32
#define Z_OFFSET  -4.21
//============= End_Hardware ===============//

//Choice add menu: (OPT)
#define SOFT_ENDSTOPS_MENU_ITEM    // for UI CLASSIC and UI COLOR
#define PID_EDIT_MENU              //
#define PID_AUTOTUNE_MENU          //
#define LCD_INFO_MENU              // Informations printer.
#define CUSTOM_MENU_MAIN
#define STATUS_MESSAGE_SCROLLING
#define SET_PROGRESS_MANUALLY

//  Type Calibration (CAL)
//#define AUTO_BED_LEVELING_BILINEAR //(A)
#define AUTO_BED_LEVELING_UBL    //(U) 
#define LCD_BED_TRAMMING
#define G26_MESH_VALIDATION //UBL
//#define Z_STEPPER_AUTO_ALIGN

// Option for Octoprint (OCTO)
//#define HOST_ACTION_COMMANDS       // Action Command Prompt support Message on Octoprint
//#define UTF_FILENAME_SUPPORT
#define EMERGENCY_PARSER
//#define BINARY_FILE_TRANSFER
//#define MEATPACK_ON_SERIAL_PORT_1

//#define USB_FLASH_DRIVE_SUPPORT     //SKR2
//#define SDCARD_CONNECTION ONBOARD//LCD   //Actif default
//#define MULTI_VOLUME
//#define CANCEL_OBJECTS
#define SDCARD_SORT_ALPHA
#define AUTO_REPORT_POSITION
//#define AUTO_REPORT_TEMPERATURES  //Actif
//#define M115_GEOMETRY_REPORT      //Actif
#define M114_DETAIL
#define REPORT_FAN_CHANGE
#define GCODE_CASE_INSENSITIVE

/* OPTION no validate */
//#define USE_CONTROLLER_FAN         //BOARD FAN
//EXTRUDER_AUTO_FAN   //
//#define TMC_HOME_PHASE { 896, 896, 896 }
//
//==================Part for Driver defintions=============//
// Options for Modules Hardware
#ifdef ESP_WIFI
  #define BINARY_FILE_TRANSFER       // Bin transfert for host like ESP3D or others.
#endif
#ifdef NEOPIXEL_LED
  #define LED_CONTROL_MENU           // To control LedStrip.
#endif

/*-------Driver TFT Color--(1 CHOICE)-----*/
#ifdef TFT_DWIN_UI
  #define DGUS_LCD_UI_MKS           //Mks_H43_v1.0 (T5LCFG_800x480)
  //#define USE_MKS_GREEN_UI  // Actif default Comment blue
//Note for H43: The wiring is done on the UART2 (Wifi socket pins(PA10/PA9) for Tx/Rx).
  //#define DWIN_CREALITY_TOUCHLCD  // CREALITY/SuperRacer (T5LCFG_480x272)
  //#define DWIN_MARLINUI_PORTRAIT  // A DWIN display with Rotary Encoder (Ender-3 v2 OEM display).
  //#define CR10_STOCKDISPLAY       //skrminiE3_V2 
  // CR-6 OEM touch screen. A DWIN display with touch.
  //#define DWIN_CREALITY_TOUCHLCD
  //#define DWIN_CREALITY_LCD_ENHANCED
  //#define DWIN_CREALITY_LCD_JYERSUI
  //#define DWIN_MARLINUI_PORTRAIT
  //#define LCD_SERIAL_PORT 1
  //#define DGUS_LCD_UI_ORIGIN
  //#define DGUS_LCD_UI_RELOADED
#elif ENABLED(TFT_BTT_UI)
/* For BTT-TFT35v2 , 43, ... */
  //#define HAS_BTT_EXP_MOT 1
  //#define CR10_STOCKDISPLAY
  //#define REPRAP_DISCOUNT_SMART_CONTROLLER
  #define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER //(r)(Default) UI Color FLSUN or BTT screen  
#elif ENABLED(TFT_GENERIC)
  #define TFT_DRIVER AUTO
  #define TFT_INTERFACE_FSMC        //Default socket on MKS_nano, mini, hispeed.
  #define TFT_RES_320x240
#else
/*-MKS Robin TFT24/28/32 ： ST7789V 320*240 MCU 16bit FSMC-*/
  #define MKS_ROBIN_TFT32           // (Default) Mks_Robin_TFT_V2.0(FSMC)
  //#define MKS_ROBIN_TFT35         //Mks_Robin_TFT
  //#define MKS_ROBIN_TFT_V1_1R
  //#define MKS_ROBIN_TFT24
  //#define MKS_ROBIN_TFT35         // Mks_Robin_TFT (FSMC)
  //#define MKS_ROBIN_TFT_V1_1R
  //#define MKS_TS35_V2_0           // Only for NanoV2 or V3 (SPI)
  #define TOUCH_SCREEN              // (C/F) (Default) UI MARLIN
#endif

//variables to calculate steps and current
#ifdef MICROSTEPS32
  #define XYZ_MICROSTEPS 32
  #define E_MICROSTEPS 32
#else
  #define XYZ_MICROSTEPS 16
  #define E_MICROSTEPS 16
#endif

//Set for A4988 
#ifdef STOCK
    #define DRIVER_AXES A4988
    #ifndef DRIVER_EXT
      #define DRIVER_EXT A4988
    #endif
#endif

//For set 2209 change TMC2208 by TMC2209 
#ifdef AMB8_TMC
    #define DRIVER_AXES TMC2208_STANDALONE
    #ifndef DRIVER_EXT
      #define DRIVER_EXT TMC2208_STANDALONE
    #endif
#endif

// Software Serial UART for TMC 2208 / TMC 2209
#ifdef AMB8_UARTx
    #define QQS_UART
    #define DRIVER_AXES TMC2208
    #ifndef DRIVER_EXT
      #define DRIVER_EXT TMC2209
    #endif
#endif

// Note:
// HardwareSerial with one pins for four drivers
// Compatible with TMC2209. Provides best performance.
// Requires SLAVE_ADDRESS definitions in Configuration_adv.h
// and proper jumper configuration. Uses I/O pins
// like PA10/PA9/PC7/PA8 only.
#ifdef AMB8_UART9
    #define QQS_UART
    #define HARDWARE_SERIAL
    #define DRIVER_AXES TMC2209
    #ifndef DRIVER_EXT
      #define DRIVER_EXT TMC2209
    #endif
#endif

 /**
 * Modif 2020:EVO3.3
 *      2.0.6 SERIAL_PORT 0=>3
 *      BNBSX v1 (Modif des Vref à 0.74v Max)
 *      BEAR  Modif parametres firmware BEAR/BNBSX en 16bits (X,Y,Z) et 32 (E0)
 *      OPT   Calcul avec MicroStep à 32 (TMC + STEPS_PER_UNIT ())                                   
 *      act. Modif FAN_SOFT_PWM, FWRETRACT, ARC_SUPPORT, STEALTHCHOP_E
 *      TEMP  Activation Temp. enceinte "#define TEMP_CHAMBER_PIN TEMP_1_PIN" (PIN A15 T2)
 *            Modif LCD logo _Statusscreen.h
 *      LCD_AMB8  Modif
 */
