<p align="center"><img src="buildroot/share/pixmaps/logo/marlin-outrun-nf-500.png" height="250" alt="MarlinFirmware's logo" /></p>

<h1 align="center">Marlin 3D Delta Printer Firmware</h1>

<img align="right" width=175 src="buildroot/share/pixmaps/logo/marlin-250.png" />
<img align="left" width=200 src="https://github.com/Foxies-CSTL/Marlin_2.0.x/wiki/icons/FLSun-LogoColor3.png" />
<p align="center">
    <a href="/LICENSE"><img alt="GPL-V3.0 License" src="https://img.shields.io/github/license/marlinfirmware/marlin.svg"></a>
    <a href="https://github.com/MarlinFirmware/Marlin/graphs/contributors"><img alt="Contributors" src="https://img.shields.io/github/contributors/marlinfirmware/marlin.svg"></a>
    <a href="https://github.com/MarlinFirmware/Marlin/releases"><img alt="Last Release Date" src="https://img.shields.io/github/release-date/MarlinFirmware/Marlin"></a>
    <a href="https://github.com/MarlinFirmware/Marlin/actions"><img alt="CI Status" src="https://github.com/MarlinFirmware/Marlin/actions/workflows/test-builds.yml/badge.svg"></a>
    <a href="https://github.com/sponsors/thinkyhead"><img alt="GitHub Sponsors" src="https://img.shields.io/github/sponsors/thinkyhead?color=db61a2"></a>
    <br />
    <a href="https://fosstodon.org/@marlinfirmware"><img alt="Follow MarlinFirmware on Mastodon" src="https://img.shields.io/mastodon/follow/109450200866020466?domain=https%3A%2F%2Ffosstodon.org&logoColor=%2300B&style=social"></a>
</p>

Additional documentation can be found at the [Marlin Home Page](https://marlinfw.org/).
Please test this firmware and let us know if it misbehaves in any way. Volunteers are standing by!

# Last release of Marlin 2.1.x for Delta FLSun.
## QQS-Pro (motherboard HISPEED_V1, ROBIN_MINIv2)
## Q5 (motherboard NANO_V1.x)
## SR (motherboard MKS/BTT with other screen like BTT-TFT35v3/Mks-TS35v2/RepRap TFT).

**20220827** Release 2.1.1
- Marlin 2.1.1 (QQSP, Q5, SR)
- Fix issues from v2.1

**20220618** 2.1
- Add line to re-init EEPROM/TFT.
- Add option "H"  for hotend VOLCANO or HotEndAllMetal.
- Add option "m" for MPC  instead PID nozzle (Menu incl.).
- Adjust MPC values for Delta and cartridge/filament (PLA)
- Add option for host buffers (OCTO, Pronto, Cura)
- Add host notifications/interactions with hosts (Only TFT_COLOR_UI)
- Add host start print by menu (Only TFT_COLOR_UI)
- Validation option "G" and "g" (Stallguard2) for SR.
- Validation option "n" (Neopixels) for QQSP/SRM.
- Add line for nb of leds.
- Fixed "Special Menu" for MPC and levelings.
- Fixed links to Marlin 2.1
- Pending issues: SD card reading and print recovery after PowerOn.

**20220112** 2.0.9.3
- fix issue TFT on QQSPro
- Last Marlin Release 2.0.9.3 (QQSP, Q5, SR)

**20220110** 2.0.9.3
- Last Marlin Release 2.0.9.3
- Easy to configure by "FLSUNQ_Config.h" file,
- Add options in FLSUNQ_Config (LGX/OMG/SDHX(steps) extruder, Frankensun/Custom effector, other Probes, thermistor, ...)
- Integration SR motherboards with other screens like BTT-TFT,...

**20211111** 2.0.9.2
- Last Marlin Release 2.0.9.2

**20210702** 2.0.9.1
- Last Marlin Release 2.0.9.1

**20210610** 2.0.8
- Last Marlin Release 2.0.8.2

**20210602** 2.0.8.1+
- Last Bugfix 2.0.8.2
- Some Tests for users'board.

**20210514** 2.0.8+
- New wizards for UBL and ZoffSet.
- New menu for Delta users.
- Add options in FLSUNQ_Config (BMG&BMGmini(steps), Flying Extruder, thermistor, ...)
- Easy to configure by "FLSUNQ_Config.h" file,
- Integration in the Marlin firmware of the HISPEED motherboard and configuration files for the QQS-Pro,
- Fixed Deploy/Stow ZProbe
- Fixed for users using E3Dv6 hotend
- Others TIPS(QQS_Config.h, Quick calibration, Menu management of NeoPixel leds, etc).

**20201010** Updated Marlin 2.0.7 for FLSun QQS-Pro.
  
  - [Update binairies (U8+S)]
  - [Enlarge range Z probe]
  - [Adjust Step/mm (417) for BMG LG] 

## Marlin 2.1

Marlin 2.1 continues to support both 32-bit ARM and 8-bit AVR boards while adding support for up to 9 coordinated axes and to up to 8 extruders.

Download earlier versions of Marlin on the [Releases page](https://github.com/MarlinFirmware/Marlin/releases).

## Example Configurations

Before you can build Marlin for your machine you'll need a configuration for your specific hardware. Upon request, your vendor will be happy to provide you with the complete source code and configurations for your machine, but you'll need to get updated configuration files if you want to install a newer version of Marlin. Fortunately, Marlin users have contributed dozens of tested configurations to get you started. Visit the [MarlinFirmware/Configurations](https://github.com/MarlinFirmware/Configurations) repository to find the right configuration for your hardware.

## Building Marlin 2.1

To build and upload Marlin you will use one of these tools:

- The free [Visual Studio Code](https://code.visualstudio.com/download) using the [Auto Build Marlin](https://marlinfw.org/docs/basics/auto_build_marlin.html) extension.
- The free [Arduino IDE](https://www.arduino.cc/en/main/software) : See [Building Marlin with Arduino](https://marlinfw.org/docs/basics/install_arduino.html)
- You can also use VSCode with devcontainer : See [Installing Marlin (VSCode devcontainer)](http://marlinfw.org/docs/basics/install_devcontainer_vscode.html).

Marlin is optimized to build with the **PlatformIO IDE** extension for **Visual Studio Code**. You can still build Marlin with **Arduino IDE**, and we hope to improve the Arduino build experience, but at this time PlatformIO is the better choice.

## Hardware Abstraction Layer (HAL)

Marlin includes an abstraction layer to provide a common API for all the platforms it targets. This allows Marlin code to address the details of motion and user interface tasks at the lowest and highest levels with no system overhead, tying all events directly to the hardware clock.

Every new HAL opens up a world of hardware. At this time we need HALs for RP2040 and the Duet3D family of boards. A HAL that wraps an RTOS is an interesting concept that could be explored. Did you know that Marlin includes a Simulator that can run on Windows, macOS, and Linux? Join the Discord to help move these sub-projects forward!

## 8-Bit AVR Boards

A core tenet of this project is to keep supporting 8-bit AVR boards while also maintaining a single codebase that applies equally to all machines. We want casual hobbyists to benefit from the community's innovations as much as possible just as much as those with fancier machines. Plus, those old AVR-based machines are often the best for your testing and feedback!

### Supported Platforms

  Platform|MCU|Example Boards
  --------|---|-------
  [Arduino AVR](https://www.arduino.cc/)|ATmega|RAMPS, Melzi, RAMBo
  [Teensy++ 2.0](https://www.microchip.com/en-us/product/AT90USB1286)|AT90USB1286|Printrboard
  [Arduino Due](https://www.arduino.cc/en/Guide/ArduinoDue)|SAM3X8E|RAMPS-FD, RADDS, RAMPS4DUE
  [ESP32](https://github.com/espressif/arduino-esp32)|ESP32|FYSETC E4, E4d@BOX, MRR
  [LPC1768](https://www.nxp.com/products/processors-and-microcontrollers/arm-microcontrollers/general-purpose-mcus/lpc1700-cortex-m3/512-kb-flash-64-kb-sram-ethernet-usb-lqfp100-package:LPC1768FBD100)|ARM® Cortex-M3|MKS SBASE, Re-ARM, Selena Compact
  [LPC1769](https://www.nxp.com/products/processors-and-microcontrollers/arm-microcontrollers/general-purpose-mcus/lpc1700-cortex-m3/512-kb-flash-64-kb-sram-ethernet-usb-lqfp100-package:LPC1769FBD100)|ARM® Cortex-M3|Smoothieboard, Azteeg X5 mini, TH3D EZBoard
  [STM32F103](https://www.st.com/en/microcontrollers-microprocessors/stm32f103.html)|ARM® Cortex-M3|Malyan M200, GTM32 Pro, MKS Robin, BTT SKR Mini
  [STM32F401](https://www.st.com/en/microcontrollers-microprocessors/stm32f401.html)|ARM® Cortex-M4|ARMED, Rumba32, SKR Pro, Lerdge, FYSETC S6, Artillery Ruby
  [STM32F7x6](https://www.st.com/en/microcontrollers-microprocessors/stm32f7x6.html)|ARM® Cortex-M7|The Borg, RemRam V1
  [STM32G0B1RET6](https://www.st.com/en/microcontrollers-microprocessors/stm32g0x1.html)|ARM® Cortex-M0+|BigTreeTech SKR mini E3 V3.0
  [STM32H743xIT6](https://www.st.com/en/microcontrollers-microprocessors/stm32h743-753.html)|ARM® Cortex-M7|BigTreeTech SKR V3.0, SKR EZ V3.0, SKR SE BX V2.0/V3.0
  [SAMD51P20A](https://www.adafruit.com/product/4064)|ARM® Cortex-M4|Adafruit Grand Central M4
  [Teensy 3.5](https://www.pjrc.com/store/teensy35.html)|ARM® Cortex-M4|
  [Teensy 3.6](https://www.pjrc.com/store/teensy36.html)|ARM® Cortex-M4|

## Submitting Patches

Proposed patches should be submitted as a Pull Request against the ([bugfix-2.1.x](https://github.com/MarlinFirmware/Marlin/tree/bugfix-2.1.x)) branch.

- Follow the [Coding Standards](https://marlinfw.org/docs/development/coding_standards.html) to gain points with the maintainers.
- Please submit Feature Requests and Bug Reports to the [Issue Queue](https://github.com/MarlinFirmware/Marlin/issues/new/choose). Support resources are also listed there.
- Whenever you add new features, be sure to add tests to `buildroot/tests` and then run your tests locally, if possible.
  - It's optional: Running all the tests on Windows might take a long time, and they will run anyway on GitHub.
  - If you're running the tests on Linux (or on WSL with the code on a Linux volume) the speed is much faster.
  - You can use `make tests-all-local` or `make tests-single-local TEST_TARGET=...`.
  - If you prefer Docker you can use `make tests-all-local-docker` or `make tests-all-local-docker TEST_TARGET=...`.

## Marlin Support

For best results getting help with configuration and troubleshooting, please use the following resources:

- [Marlin Documentation](https://marlinfw.org) - Official Marlin documentation
- [Marlin Discord](https://discord.gg/n5NJ59y) - Discuss issues with Marlin users and developers
- Facebook Group ["Marlin Firmware"](https://www.facebook.com/groups/1049718498464482/)
- RepRap.org [Marlin Forum](https://forums.reprap.org/list.php?415)
- Facebook Group ["Marlin Firmware for 3D Printers"](https://www.facebook.com/groups/3Dtechtalk/)
- [Marlin Configuration](https://www.youtube.com/results?search_query=marlin+configuration) on YouTube

## Credits

The current Marlin dev team consists of:

## Project Leadership

Name|Role|Link|Donate
----|----|----|----
🇺🇸 Scott Lahteine|Project Lead|[[@thinkyhead](https://github.com/thinkyhead)]|[💸 Donate](https://marlinfw.org/docs/development/contributing.html#donate)
🇺🇸 Roxanne Neufeld|Admin|[[@Roxy-3D](https://github.com/Roxy-3D)]|
🇺🇸 Keith Bennett|Admin|[[@thisiskeithb](https://github.com/thisiskeithb)]|[💸 Donate](https://github.com/sponsors/thisiskeithb)
🇺🇸 Jason Smith|Admin|[[@sjasonsmith](https://github.com/sjasonsmith)]|
🇧🇷 Victor Oliveira|Admin|[[@rhapsodyv](https://github.com/rhapsodyv)]|
🇬🇧 Chris Pepper|Admin|[[@p3p](https://github.com/p3p)]|
🇳🇿 Peter Ellens|Admin|[[@ellensp](https://github.com/ellensp)]|[💸 Donate](https://ko-fi.com/ellensp)
🇺🇸 Bob Kuhn|Admin|[[@Bob-the-Kuhn](https://github.com/Bob-the-Kuhn)]|
🇳🇱 Erik van der Zalm|Founder|[[@ErikZalm](https://github.com/ErikZalm)]|

## License

Marlin is published under the [GPL license](/LICENSE) because we believe in open development. The GPL comes with both rights and obligations. Whether you use Marlin firmware as the driver for your open or closed-source product, you must keep Marlin open, and you must provide your compatible Marlin source code to end users upon request. The most straightforward way to comply with the Marlin license is to make a fork of Marlin on Github, perform your modifications, and direct users to your modified fork.

While we can't prevent the use of this code in products (3D printers, CNC, etc.) that are closed source or crippled by a patent, we would prefer that you choose another firmware or, better yet, make your own.
