### 2023-02-09 MARLIN 2.1.2
📝After the flash/update operation, you need to configure/prepare your Delta. Deltas are different in their printing methods from Cartesian printers such as Ender, Prusa or others.

Managing a Delta is already more complicated than managing a simple Cartesian printer because there are some basics to understand:
- The print head of a Cartesian printer uses a stepper motor for each of the X, Y, Z Cartesian axes, so as soon as you give it position coordinates, it does so according to the Cartesian axes associated with those stepper motors.

  An example: 
  a command to move the print head +10mm on the X axis, it is only the X stepper motor that will work i.e. position itself at +10mm on the X Cartesian axis.
  Same for Y and Z. 
  The only thing you need to know is the starting point on the bed (X zero, Y zero, Z zero) and the horizontality or deformation of the bed surface.
  
  That is why a leveling/meshing of the bed surface is necessary (manual leveling or automatic leveling like ABL or UBL).

- For Delta printers, the print head does not know how to move in this Cartesian volume because it uses the three stepper motors to position itself on the X, Y or Z axis. These stepper motors should be called A, B, C but the manufacturers have kept the Cartesian name, hence the confusion for most users. So if we take the example above, for a displacement order in X of +10mm, it is the three stepper motors that will be controlled and without displacement reference, the movement will be random.

So to know this reference, it is necessary to perform a Delta calibration which will define/calculate this space/volume of movements. Thus made, the commands of displacement on the Cartesian X axis of +10mm will be given to the three stepper motors so that they are positioned at +10mm on the Cartesian X axis. Same for Y and Z.

All these operations are calculated by the firmware embedded in your printer. But before carrying out this Delta calibration, you must make a good mechanical check (stability of the structure, identical tension of the belts, play in the moving parts, etc). 

From there, you can launch a calibration of your Delta printer which will provide you with precision in the movement of the print head and will be the basis for a healthy operation.

Important: Also be aware that if you change any part of this assembly, calibration will be necessary/obligatory again,
- moving the printer,
- frame oscillations,
- unbalanced tightening of the stepper motor belts,
- play in the moving parts, stepper motor fasteners
- etc.

and therefore the movements of the head will no longer be precise and will cause printing problems, shocks with the bed or the printing in progress.

**Thank you for reading this far and this is valid regardless of the firmware used.**

***
After the flash and to configure and prepare your printer, please follow the steps on the Wiki 

=> [<img width=400 src="https://github.com/Foxies-CSTL/Marlin_2.1.x/wiki/icons/FLSun-Wiki.png" />](https://github.com/Foxies-CSTL/Marlin_2.1.x/wiki/2.SETTINGS-THE-PRINTER)

Here is a summary of the steps to follow in order:
1. Flash firmware
 
  *Request for a calibration screen* (Note on Wiki)
  
2. Initialize EEPROM (Via "Special Delta" menu)
  
  *Request for a calibration screen*

3. Calibration
 - Fast Calib. > autostore settings (only if you are in a hurry)
 - Fine Calib. > autostore settings

4. Wizard Z_OffSet (Z0 height) > Done > Store settings (no need if you go to the next step)

5. Levelings PLA/PETG/ABS (UBL) > autostore settings in location ( 1=PLA, 2=PETG and 3=ABS)

8. PID nozzle for PLA > autostore settings: PID for PLA or New PID by MCP (Need to have a Z0 adjusted)

9. Tuning your Slicer to choose a correct flavor=Marlin, relative mode(Cura) and remove M82 (Extruder Absolute mode) or replace by M83 (relative mode) in GCodeStart.

9. insert in your GCodeStart after G28, G29 Lx to load your mesh/levelling depending on your filament type.

10. Run a print from SD card and refine the height layer with BabyStepping function (3 ways => Note on Wiki).

 => it's correct so store settings. Go to next print and enjoy.

 => This isn't correct so do a test print of the pattern via "Special Delta" menu (not interruptible).
 
  a. Result is correct on the whole then problem with the Slicer settings, check dot 7.

📌Note:
- In my firmware the G28 automatically loads the last used mesh/levelling. So if you use only PLA, the "G29 L1" command is only needed once.
- the adjustment of the right layer height (Z_OffSet) by babystepping must be memorized because you lose this correction as soon as you power off the machine.
***
