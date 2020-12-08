# CS207fall2020 PROJECT

This project is a lcd and laptop controlled drawing robot. It was built due to my interest in integrating art into computer science and this serves as a way to do so. The original project was devloped by DIY Machines on Youtube.com [1] although with the addition of the lcd controller as a modification. An SD card modification can also be made to the project making it fully usable wthout a laptop connected. This i plan to do in the nearest future.

The completed project should look something like this:

![alt text][pic1]

[pic1]: https://github.com/opemipoadigun/CS207fall2020-Project/blob/main/img/Assembled%20image.jpeg

# Repository Contents
* **/src** - Here's where the software for your device goes (.ino, .cpp).
* **/hardware** - All the PCB design files / 3D models (.ftz, .brd, .sch, .stl).
* **/build** - Files that are compiled and ready to run / upload.
* **/libraries** - Any libraries that are needed to build your software for your device.
* **/examples** - Example files that can be run on your hardware. 
* **/img** - This is where the image files for this readme are! Yay!
* **/LICENSE** - The license file.
* **/README.md** - The file you're reading now! :-D

# Requirements and Materials

Dependencies:
* Grbl library - https://github.com/DIY-Machines/CNC-DrawingMachine/tree/master/grbl-mi
* Grbl Config - https://github.com/DIY-Machines/CNC-DrawingMachine/blob/master/GRBL%20Config
* Adafruit Lcd Screen libraries and examples - https://learn.adafruit.com/rgb-lcd-shield 
* Inkcape extension to make gcode - https://github.com/DIY-Machines/CNC-DrawingMachine/tree/master/MI%20Inkscape%20Extension
* Serial port josn - update the link here

Bill of Materials:

Links to most of these can be found at - https://github.com/DIY-Machines/CNC-DrawingMachine
or on Amazon

* 8 x15 x 45mm Linear Bearing (x2)
* 8 x 15 x 25mm Linear Bearing (x1)
* 12v Nema 17 stepper motors (x2)
* GT2 Timing belt and pulleys
* Micro servo (x1)
* Arduino Uno (x2)
* Long breadboard (X1)
* Stepper drivers - TMC2208 (x2)
* Contact switch (x2)
* Arduino CNC Shield (x1)
* 8mm Chromed Steel Rod (35cm x2 & 5.5cm x1) 
* 30cm long linear rail with block (x1)
* Electrical wire
* 12v power supply - 2A or greater (x1)
* 6mm Idler Wheel - 3mm Bore (1)
* Idler Wheel - 5mm Bore (1)
* Wooden panel to mount project at least 36x42cm (I used a 24"x16" board from RONA)
*	Adafruit Standard LCD - 16x2 White on Blue

## Nuts, bolts and screws needed:
* M5 x 25mm (x2)
* M3 x 18 (x3)
* M3 x 12 (x2)
* M3 x10 (x3)
* M3 x 6 (X14)
* M3 nuts (x9)
* M5 nut (x1)
* Short wood screws (x8)

# 3D Printed parts in the link below:
* 3D printed parts can be downloaded from here: https://www.diymachines.co.uk/arduino-cnc-drawing-machine

# Build Instructions

Building tutorial by DIY Machines can be found here - https://youtu.be/XYqx5wg4oLU
* Note there is a difference in the overall wiring of my project compared to the one in the link. My project wiring can be found in the Breadboard and Schematic below 
Instructions on setting up the Robot can be found here - https://youtu.be/8scKLHz77Lg  

* Breadboard and schematics:

![alt text][pic2]

[pic2]: https://github.com/opemipoadigun/CS207fall2020-Project/blob/main/img/Schematics.png

![alt text][pic3]

[pic3]: 

Usage
* Plug in both Arduino Unos 
* Plug in cnc shield
* Home and zero Axes of robot from lcd screen
* Drag and Drop gcode into chilipeppr
* Make sure to have your pencil, pen or marker in place on the robot 
* Run serial-port-json-server-1.96_windows_386
* Select Arduino connected to the computer and also the cnc shield
* Home and Zero Axes of robot on chilipeppr
* Make sure to change Arduino on chilipeppr to grbl and 115200 baud
* Click Play Under Gcode on chilipeppr

Credits
* DIY MACHINES - https://www.diymachines.co.uk/arduino-cnc-drawing-machine
