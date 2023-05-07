/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * FLSUN HiSpeed V1 (STM32F103VET6) board pin assignments
 * FLSun Hispeed (clone MKS_Robin_miniV2) board.
 *
 * MKS Robin Mini USB uses UART3 (PB10-TX, PB11-RX)
 * #define SERIAL_PORT_2 3
 */

#define ALLOW_STM32DUINO
#include "env_validate.h"
/*
#if NOT_TARGET(__STM32F1__, STM32F1)
  #error "Oops! Select an STM32F1 board in 'Tools > Board.'"
#elif HAS_MULTI_HOTEND || E_STEPPERS > 1
  #error "FLSUN HiSpeedV1 only supports 1 hotend / E stepper."
#endif
*/

#define BOARD_INFO_NAME      "FLSun HiSpeedV1"
#define BOARD_WEBSITE_URL    "github.com/Foxies-CSTL"

#define BOARD_NO_NATIVE_USB

// Avoid conflict with TIMER_SERVO when using the STM32 HAL
#define TEMP_TIMER                             5

//
// Release PB4 (Y_ENABLE_PIN) from JTAG NRST role
//
#define DISABLE_DEBUG

//
// EEPROM
//
#if EITHER(NO_EEPROM_SELECTED, FLASH_EEPROM_EMULATION)
  #define FLASH_EEPROM_EMULATION
  #define EEPROM_PAGE_SIZE     (0x800U)           // 2K
  #define EEPROM_START_ADDRESS (0x8000000UL + (STM32_FLASH_SIZE) * 1024UL - (EEPROM_PAGE_SIZE) * 2UL)
  #define MARLIN_EEPROM_SIZE    EEPROM_PAGE_SIZE  // 2K
#endif

//PandaPi sensor
/*
#if BD_SENSOR
  #define  I2C_BD_SDA_PIN   PB7//PC6 EEPROM
  #define  I2C_BD_SCL_PIN   PB6//PB2 EEPROM
  #define  I2C_BD_DELAY  10
#endif
*/

//
// SPI
// Note: FLSun Hispeed (clone MKS_Robin_miniV2) board is using SPI2 interface.
//
#define SD_SCK_PIN                          PB13  // SPI2
#define SD_MISO_PIN                         PB14  // SPI2
#define SD_MOSI_PIN                         PB15  // SPI2
#define SPI_DEVICE                             2

// SPI Flash
#define SPI_FLASH
#if ENABLED(SPI_FLASH)
  // SPI 2
  #define SPI_FLASH_CS_PIN                  PB12  // SPI2_NSS / Flash chip-select
  #define SPI_FLASH_MOSI_PIN                PB15
  #define SPI_FLASH_MISO_PIN                PB14
  #define SPI_FLASH_SCK_PIN                 PB13
  #define SPI_FLASH_SIZE               0x1000000  // 16MB
#endif

//
// Servos
//
//#define SERVO0_PIN                        PA8   // use IO0 to enable BLTOUCH support/remove Mks_Wifi

//
// Limit Switches
//
#define X_DIAG_PIN                          PA15  //-X
#define Y_DIAG_PIN                          PA12  //-Y
#define Z_DIAG_PIN                          PC4   //-Z

#ifdef SENSORLESS_PROBING
  #define X_STOP_PIN                  X_DIAG_PIN 
  #define Y_STOP_PIN                  Y_DIAG_PIN
  #define Z_STOP_PIN                  Z_DIAG_PIN
  #define Z_MIN_PIN                   Z_DIAG_PIN  //Note= do another test with disable this
#else
  #define X_STOP_PIN                  X_DIAG_PIN  // +X 
  #define Y_STOP_PIN                  Y_DIAG_PIN  // +Y
  #define Z_MAX_PIN                   Z_DIAG_PIN  // +Z
  #define Z_MIN_PIN                         PA11  // -Z
#endif

#ifndef FIL_RUNOUT_PIN
  #define FIL_RUNOUT_PIN                    PA4   // MT_DET
#endif

//
// Steppers
//
#define X_ENABLE_PIN                        PE4   // X_EN
#define X_STEP_PIN                          PE3   // X_STEP
#define X_DIR_PIN                           PE2   // X_DIR

#define Y_ENABLE_PIN                        PE1   // Y_EN
#define Y_STEP_PIN                          PE0   // Y_STEP
#define Y_DIR_PIN                           PB9   // Y_DIR

#define Z_ENABLE_PIN                        PB8   // Z_EN
#define Z_STEP_PIN                          PB5   // Z_STEP
#define Z_DIR_PIN                           PB4   // Z_DIR

#define E0_ENABLE_PIN                       PB3   // E0_EN
#define E0_STEP_PIN                         PD6   // E0_STEP
#define E0_DIR_PIN                          PD3   // E0_DIR

/**
 * FLSUN Hi-Speed has no hard-wired UART pins for TMC drivers.
 * Several wiring options are provided below, defaulting to
 * to the most compatible.
 */
#if HAS_TMC_UART
  #ifndef TMC_BAUD_RATE
    #define TMC_BAUD_RATE                   19200
  #endif
  #ifdef TMC_HARDWARE_SERIAL /*  TMC2209 */
    /**
    * HardwareSerial with one pin for four drivers.
    * Compatible with TMC2209. Provides best performance.
    * Requires SLAVE_ADDRESS definitions in Configuration_adv.h and proper
    * jumper configuration. Uses only one I/O pin like PA10/PA9/PC7/PA8.
    * Install the jumpers in the following way, for example:
    */
    // The 4xTMC2209 module doesn't have a serial multiplexer and
    // needs to set *_SLAVE_ADDRESS in Configuration_adv.h for X,Y,Z,E0
    //#define X_HARDWARE_SERIAL  MSerial3
    //#define Y_HARDWARE_SERIAL  MSerial3
    //#define Z_HARDWARE_SERIAL  MSerial3
    //#define E0_HARDWARE_SERIAL MSerial3
    #define  X_SLAVE_ADDRESS 3    // |  |  :
    #define  Y_SLAVE_ADDRESS 2    // :  |  :
    #define  Z_SLAVE_ADDRESS 1    // |  :  :
    //#define E0_SLAVE_ADDRESS 0    // :  :  :

    #define X_SERIAL_TX_PIN                  PA8  // IO0
    #define X_SERIAL_RX_PIN      X_SERIAL_TX_PIN  // IO0
    #define Y_SERIAL_TX_PIN      X_SERIAL_TX_PIN  // IO0
    #define Y_SERIAL_RX_PIN      X_SERIAL_TX_PIN  // IO0
    #define Z_SERIAL_TX_PIN      X_SERIAL_TX_PIN  // IO0
    #define Z_SERIAL_RX_PIN      X_SERIAL_TX_PIN  // IO0
  #else /*  TMC220x   */
  // SoftwareSerial with one pin per driver
  // Compatible with TMC2208 and TMC2209 drivers
    #define  X_SLAVE_ADDRESS 0
    #define  Y_SLAVE_ADDRESS 0
    #define  Z_SLAVE_ADDRESS 0

    #define X_SERIAL_TX_PIN                   PA10  // RXD1
    #define X_SERIAL_RX_PIN        X_SERIAL_TX_PIN
    #define Y_SERIAL_TX_PIN                   PA9   // TXD1
    #define Y_SERIAL_RX_PIN        Y_SERIAL_TX_PIN
    #define Z_SERIAL_TX_PIN                   PC7   // IO1
    #define Z_SERIAL_RX_PIN        Z_SERIAL_TX_PIN
  #endif
#else
  // Motor current PWM pins
  #define MOTOR_CURRENT_PWM_XY_PIN          PA6   // VREF2/3 CONTROL XY
  #define MOTOR_CURRENT_PWM_Z_PIN           PA7   // VREF4 CONTROL Z
  #define MOTOR_CURRENT_PWM_RANGE           1500  // (255 * (1000mA / 65535)) * 257 = 1000 is equal 1.6v Vref in turn equal 1Amp
  #ifndef DEFAULT_PWM_MOTOR_CURRENT
    #define DEFAULT_PWM_MOTOR_CURRENT { 900, 900, 900 }
  #endif

  /**
   * MKS Robin_Wifi or another ESP8266 module
   *
   *      __ESP(M1)__       -J1-
   *  GND| 15 | | 08 |+3v3  (22)  RXD1      (PA10)
   *     | 16 | | 07 |MOSI  (21)  TXD1      (PA9)   Active LOW, probably OK to leave floating
   *  IO2| 17 | | 06 |MISO  (19)  IO1       (PC7)   Leave as unused (ESP3D software configures this with a pullup so OK to leave as floating)
   *  IO0| 18 | | 05 |CLK   (18)  IO0       (PA8)   Must be HIGH (ESP3D software configures this with a pullup so OK to leave as floating)
   *  IO1| 19 | | 03 |EN    (03)  WIFI_EN           Must be HIGH for module to run
   *     | nc | | nc |      (01)  WIFI_CTRL (PA5)
   *   RX| 21 | | nc |
   *   TX| 22 | | 01 |RST
   *       ￣￣ AE￣￣
   */
  // Module ESP-WIFI
  #if ENABLED(WIFISUPPORT)
    //Mode COMMUNICATION_PROTOCOL RAW_SERIAL with monitoring ESP3Dv3
    #define MKS_WIFI_SERIAL_NUM             SERIAL_PORT_2
    #define MKS_WIFI_UART                   USART1
    #undef PLATFORM_M997_SUPPORT            //Issue with the Mks Cura plugin that sends M997s.
    #define MKS_WIFI_IO0                    PA8
    #define MKS_WIFI_IO4                    PC7
    #define MKS_WIFI_IO_RST                 PA5
  #elif HAS_TFT_LVGL_UI
    //Cura monitoring with MksWifi/ESP3Dv3/Mescianti (TFT35v1)
    //Mode COMMUNICATION_PROTOCOL MKS_SERIAL for monitoring ESP3Dv3
    #define USES_MKS_WIFI_FUNCTION
    #define WIFI_IO0_PIN                    PA8   // MKS ESP WIFI IO0 PIN
    #define WIFI_IO1_PIN       			        PC7   // MKS ESP WIFI IO1 PIN
    #define WIFI_RESET_PIN				          PA5   // MKS ESP WIFI RESET PIN
  #else
    //#undef PLATFORM_M997_SUPPORT                //Issue with the Mks Cura plugin that sends M997s(reboot MoBo).
  #endif
  /* fix Marlin 
  #if ENABLED(WIFISUPPORT)
    #define ESP_WIFI_MODULE_COM                  2  // Must also set either SERIAL_PORT or SERIAL_PORT_2 to this
    #define ESP_WIFI_MODULE_BAUDRATE      BAUDRATE  // Must use same BAUDRATE as SERIAL_PORT & SERIAL_PORT_2
    #define ESP_WIFI_MODULE_TXD_PIN           PA9   // MKS or ESP WIFI RX PIN
    #define ESP_WIFI_MODULE_RXD_PIN           PA10  // MKS or ESP WIFI TX PIN
    #define ESP_WIFI_MODULE_RESET_PIN         PA5   // WIFI CTRL/RST
    #define ESP_WIFI_MODULE_ENABLE_PIN        -1
    #define ESP_WIFI_MODULE_GPIO0_PIN         PA8
    #define ESP_WIFI_MODULE_GPIO1_PIN         PC7
  #endif
  */
#endif

//
// EXTRUDER
//
#if AXIS_DRIVER_TYPE_E0(TMC2208) || AXIS_DRIVER_TYPE_E0(TMC2209)
  #define E0_SLAVE_ADDRESS 0
  #define E0_SERIAL_TX_PIN                  PA8   // IO0
  #define E0_SERIAL_RX_PIN                  PA8   // IO0
#else
  // Motor current PWM pins
  #define MOTOR_CURRENT_PWM_E_PIN           PB0   // VREF1 CONTROL E
  #define MOTOR_CURRENT_PWM_RANGE           1500  // (255 * (1000mA / 65535)) * 257 = 1000 is equal 1.6v Vref in turn equal 1Amp
  #ifndef DEFAULT_PWM_MOTOR_CURRENT
   #define DEFAULT_PWM_MOTOR_CURRENT { 900, 900, 900 }
  #endif
#endif

//
// Temperature Sensors (THM)
//
#define TEMP_0_PIN                          PC1   // TEMP_E0
#define TEMP_BED_PIN                        PC0   // TEMP_BED

//
// Heaters / Fans
//
#define HEATER_0_PIN                        PC3   // HEATER_E0
#define HEATER_BED_PIN                      PA0   // HEATER_BED-WKUP

#define FAN0_PIN                            PB1   // E_FAN

//
// Misc. Functions
//
#if HAS_TFT_LVGL_UI
  #define MT_DET_1_PIN                      PA4
  #define MT_DET_PIN_STATE                  LOW
  #if ENABLED(MKS_TEST)
    #define MKS_TEST_POWER_LOSS_PIN         PA2   // PW_DET
    #define MKS_TEST_PS_ON_PIN              PB2   // PW_OFF
  #endif
#elif ENABLED(BACKUP_POWER_SUPPLY)
  #define POWER_LOSS_PIN                    PA2   // PW_DET (UPS) MKSPWC
#else
    #define POWER_LOSS_PIN                  -1    // PW_DET
    #define PS_ON_PIN                       PB2   // PW_OFF
#endif

/**
 *    Connector J2
 *      -------
 * DIO O|1   2|O  3v3
 * CSK O|3   4|O  GND
 * RST O|5   6|O  GND
 *      -------
 */
//#define SW_DIO                            PA13
//#define SW_CLK                            PA14
//#define SW_RST                            NRST  // (14)

//
// Power Supply Control
//
#if ENABLED(MKS_PWC)
  #if ENABLED(TFT_LVGL_UI)
    #undef PSU_CONTROL
    #undef MKS_PWC
    #define SUICIDE_PIN                     PB2   // Enable MKSPWC SUICIDE PIN
    #define SUICIDE_PIN_STATE              false // Enable MKSPWC PIN STATE
    #define KILL_PIN                        PA2   // Enable MKSPWC DET PIN
    #define KILL_PIN_STATE                  true  // Enable MKSPWC PIN STATE
  #else    
    #define PS_ON_PIN                       PA3   // PW_OFF
    #define KILL_PIN                        PA2
    #define KILL_PIN_STATE                  HIGH
  #endif
#endif

#if ENABLED(PSU_CONTROL)
  #define KILL_PIN                          PA2   // PW_DET
  #define KILL_PIN_STATE                    HIGH
  //#define PS_ON_PIN                       PA3   // PW_CN /PW_OFF
#endif


//
// LED / NEOPixel
//
//#define LED_PIN                           PB2   // BOOT1

#if ENABLED(NEOPIXEL_LED)
  #define LED_PWM                           PC7   // IO1
  #ifndef NEOPIXEL_PIN
    #define NEOPIXEL_PIN                 LED_PWM  // USED WIFI IO0/IO1 PIN
  #endif
#endif

//
// SD Card
//
#ifndef SDCARD_CONNECTION
  #define SDCARD_CONNECTION              ONBOARD
#endif

// Use the on-board card socket labeled SD_Extender
#if SD_CONNECTION_IS(CUSTOM_CABLE)
  #define SD_SCK_PIN                        PC12
  #define SD_MISO_PIN                       PC8
  #define SD_MOSI_PIN                       PD2
  #define SD_SS_PIN                         -1
  #define SD_DETECT_PIN                     PD12  // SD_CD (if -1 no detection)
#else
  #define ONBOARD_SDIO
  #define SDIO_CLOCK                     4500000  // 4.5 MHz
  #define ONBOARD_SPI_DEVICE                   1  // SPI1
  #define ONBOARD_SD_CS_PIN                 PC11
  #define SD_DETECT_PIN                     -1    // SD_CD (-1 active refresh)
#endif

//
// LCD / Controller
//
#ifndef BEEPER_PIN
  #define BEEPER_PIN                        PC5
#endif

#if ENABLED(SPEAKER) && BEEPER_PIN == PC5
  //#error "FLSun HiSpeed default BEEPER_PIN is not a SPEAKER."
#endif

//
// TFT with FSMC interface
//
#if HAS_FSMC_TFT
  /**
   * Note: MKS Robin TFT screens use various TFT controllers
   * Supported screens are based on the ILI9341, ST7789V and ILI9328 (320x240)
   * ILI9488 is not supported
   * Define init sequences for other screens in u8g_dev_tft_320x240_upscale_from_128x64.cpp
   *
   * If the screen stays white, disable 'LCD_RESET_PIN'
   * to let the bootloader init the screen.
   *
   * Setting an 'LCD_RESET_PIN' may cause a flicker when entering the LCD menu
   * because Marlin uses the reset as a failsafe to revive a glitchy LCD.
   */
  #define LCD_RESET_PIN                     PC6   // FSMC_RST
  #define LCD_BACKLIGHT_PIN                 PD13

  #define LCD_USE_DMA_FSMC                        // Use DMA transfers to send data to the TFT
  #define FSMC_CS_PIN                       PD7   // NE4
  #define FSMC_RS_PIN                       PD11  // A0

  #define TOUCH_BUTTONS_HW_SPI
  #define TOUCH_BUTTONS_HW_SPI_DEVICE          2

  #define TFT_CS_PIN                 FSMC_CS_PIN
  #define TFT_RS_PIN                 FSMC_RS_PIN 
  #define TFT_RESET_PIN                     PC6   // FSMC_RST
  #define TFT_BACKLIGHT_PIN                 PD13
  #define DOGLCD_MOSI                       -1    // Prevent auto-define by Conditionals_post.h
  #define DOGLCD_SCK                        -1
  //-----------------------------//
  /*
  //#define TFT_RESET_PIN                     PC6   // FSMC_RST
  #define TFT_BACKLIGHT_PIN                 PD13
  
  //#define LCD_RESET_PIN            TFT_RESET_PIN
  #define LCD_BACKLIGHT_PIN    TFT_BACKLIGHT_PIN
  
  #define LCD_USE_DMA_FSMC                        // Use DMA transfers to send data to the TFT
  #define FSMC_DMA_DEV                      DMA2
  #define FSMC_DMA_CHANNEL               DMA_CH5
  #define FSMC_CS_PIN                       PD7   // NE4
  #define FSMC_RS_PIN                       PD11  // A0  

  #define TFT_CS_PIN                 FSMC_CS_PIN
  #define TFT_RS_PIN                 FSMC_RS_PIN

  #define TOUCH_BUTTONS_HW_SPI
  #define TOUCH_BUTTONS_HW_SPI_DEVICE          2
  
  #define DOGLCD_MOSI                       -1    // Prevent auto-define by Conditionals_post.h
  #define DOGLCD_SCK                        -1
  */
  #define TOUCH_CS_PIN                      PC2   // SPI2_NSS
  #define TOUCH_SCK_PIN                     PB13  // SPI2_SCK
  #define TOUCH_MISO_PIN                    PB14  // SPI2_MISO
  #define TOUCH_MOSI_PIN                    PB15  // SPI2_MOSI
  
  #ifdef TFT_CLASSIC_UI
    #define TFT_MARLINBG_COLOR            0x3186  // Grey
    #define TFT_MARLINUI_COLOR            0xC7B6  // Green
    #define TFT_BTARROWS_COLOR            0xDEE6  // Yellow
    #define TFT_BTOKMENU_COLOR            0x145F  // Cyan
  #endif
  #ifdef MKS_WIFI
    #undef TFT_BUFFER_SIZE
    #define TFT_BUFFER_SIZE                  480*8
  #else  
    #define TFT_BUFFER_SIZE                  14400  
  #endif
#endif

/* Module TEST TFT BTT */
#if HAS_WIRED_LC
  #define BEEPER_PIN                      PC5 //PB5//EXP1_10
  //#define BTN_ENC                         -1 //PA15//EXP1_09
  
  //#define LCD_PINS_RS                         13
  //#define LCD_PINS_ENABLE                     17
  //#define LCD_PINS_D4                         16
  //#define BEEPER_PIN                       151

  #define BTN_EN2                         PA10//EXP1_06//RX1
  #define BTN_EN1                         PA9//EXP1_08//TX1
  //#define BEEPER_PIN                      -1 //Vcc
  #define LCD_PINS_RS                     PD11
  #define LCD_PINS_ENABLE                 PA10
#endif  
/*/    
  #define BTN_ENC                           PA15
  #define BTN_EN1                           PA9
  #define BTN_EN2                           PA10
  #define LCD_PINS_RS                       PB8
  #define LCD_PINS_ENABLE                   PB15
  #define LCD_PINS_D4                       PB9
  #define BEEPER_PIN                        PB5

    //#define LCD_PINS_D4                     -1  //PB9
    #ifndef TFT_BUFFER_SIZE
      #define TFT_BUFFER_SIZE               1200
    #endif
    #ifndef TFT_QUEUE_SIZE
      #define TFT_QUEUE_SIZE                6144
    #endif    
*/
//#endif
//
/**
 *            SKR Mini E3 V2.0
 *                ------
 *            5V | 1  2 | GND
 * (LCD_EN) PB15 | 3  4 | PB8  (LCD_RS)
 * (LCD_D4) PB9  | 5  6   PA10 (BTN_EN2)RX1
 *         RESET | 7  8 | PA9  (BTN_EN1)TX1
 *(BTN_ENC) PA15 | 9 10 | PB5  (BEEPER)
 *                ------
 *                 EXP1
 *        ------              ------         
 *   VCC | 1  2 | GND    VCC | 1  2 | GND    
 *     A | 3  4 | B        A | 3  4 | B      
 *       | 5  6   TX    BEEP | 5  6   ENT    
 *       | 7  8 | RX      TX | 7  8 | RX     
 *  BEEP | 9 10 | ENT        | 9 10 |        
 *        ------              ------         
 *         EXP1                DWIN           
   #if ENABLED(CR10_STOCKDISPLAY)

    #define BEEPER_PIN                      PB5//EXP1_10
    #define BTN_ENC                         PA15//EXP1_09

    #define BTN_EN1                         PA9//EXP1_06//RX1
    #define BTN_EN2                         PA10//EXP1_08//TX1

    #define LCD_PINS_RS                     PB8
    #define LCD_PINS_ENABLE               EXP1_3
    #define LCD_PINS_D4                     PB9

  #else     // !CR10_STOCKDISPLAY- SKR13 TFT AUX
 *               SKR 13
 *                ------
 *       0.3 RX0 | 2  1 | NC
 *       0.2 TX0 | 4  3 | NC 
 *           GND | 6  5   GND
 *            5v | 8  7 | 5V
 *                ------
 *                 AUX-1
    #define LCD_PINS_RS              EXP1_07_PIN  //Reset

    #define BTN_EN1                  EXP2_08_PIN  //3.26 (31) J3-2 & AUX-4
    #define BTN_EN2                  EXP2_06_PIN  //3.25 (33) J3-4 & AUX-4
    #define BTN_ENC                  EXP1_09_PIN  //0.28 (58) open-drain

    #define LCD_PINS_ENABLE          EXP1_08_PIN
    #define LCD_PINS_D4              EXP1_06_PIN

    #define LCD_SDSS                 EXP2_07_PIN  //0.16 (SD_SS)// (16) J3-7 & AUX-4
    #define SD_DETECT_PIN            EXP2_04_PIN  //1.31 (SD_DETECT)// (49) (NOT 5V tolerant)


 */
/*
#if HAS_WIRED_LCD
  #define LCD_PINS_ENABLE        PD13
  #define LCD_PINS_D4              -1 //PE14 //dataline EXP1_06_PIN  // PA6(LCD_D4)
  #if IS_ULTIPANEL
    #define LCD_PINS_D5            -1 //PE15 //dataline EXP1_05_PIN  // PA7(LCD_D5)
    #define LCD_PINS_D6            -1 //PD11 //rs EXP1_04_PIN  // PC4(LCD_D6)
    #define LCD_PINS_D7            -1 //PD10 //dataline EXP1_03_PIN  // PC5(LCD_D7)

    #if !defined(BTN_ENC_EN) && ENABLED(REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER)
      #define BTN_ENC_EN           LCD_PINS_D7  // Detect the presence of the encoder
    #endif
  #endif
#endif
*/

