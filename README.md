# CS207fall2020 PROJECT

This project is a lcd and laptop controlled drawing robot. It was built due to my interest in integrating art into computer science and this serves as a way to do so. The original project was devloped by DIY Machines on Youtube.com [1] although with the addition of the lcd controller as a modification.

This modification allows me to be able to control the drawing robot with basic commands without it being connected to a computer. 

An SD card modification which streams the gcode from the controller arduino to the arduino controlling the robot can also be made to the project making it fully usable without a laptop connected. This I plan to do in the nearest future.

The completed project should look something like this:

![alt text][pic1]

[pic1]: https://github.com/opemipoadigun/CS207fall2020-Project/blob/main/img/Assembled%20image.jpeg

# Repository Contents 
* **/src** - Contains links to inkscape download as well as chilipeppr
* **/hardware** - Contains link to 3d printed items 
* **/build** - Contains code to run on the arduino connected to the lcd screen
* **/libraries** - Contains link to get the needed libraries
* **/examples** - Example sketch to check if lcd is working after assembling. 
* **/img** - Contains pictures of the build as well as schematics and breadboard 
* **/LICENSE** - The license file.
* **/README.md** - The file you're reading now! :-D

# Requirements and Materials

Dependencies:
* Grbl library - https://github.com/opemipoadigun/CS207fall2020-Project/tree/main/libraries
* Grbl Config - https://github.com/DIY-Machines/CNC-DrawingMachine/blob/master/GRBL%20Config
* Adafruit Lcd Screen libraries and examples - https://github.com/opemipoadigun/CS207fall2020-Project/tree/main/libraries
* Inkcape extension to make gcode - https://github.com/opemipoadigun/CS207fall2020-Project/tree/main/src
* Serial port josn - https://github.com/opemipoadigun/CS207fall2020-Project/tree/main/serial-port-json-server-1.96_windows_386

Bill of Materials:

Links to most of these can be found at - https://github.com/DIY-Machines/CNC-DrawingMachine
and most items are also on Amazon

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
*	Soldering iron and soldering wire
*	Electric Tape
*	Female connector to male connector jumper wires
*	Male connector to male connector jumper wires

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

* Note: There is a difference in the overall wiring of my project compared to the one in the link. My project wiring can be found in the Breadboard and Schematic below 

Instructions on setting up the Robot and making gcode can be found here - https://youtu.be/8scKLHz77Lg

* Note: Keep the Tx and RX pins disconnected while setting up the robot.

After testing that the robot works fine, upload the lcdtest.ino file located under build into the second arduino and then have a jumper wire connetced to tx on the robot arduino to pin 2 on the second arduino and likewise from rx to pin 3.

* Note: Always have Grbl uploaded on the Arduino connected to the cnc shield

* Breadboard and schematics:

![alt text][pic2]

[pic2]: https://github.com/opemipoadigun/CS207fall2020-Project/blob/main/img/Schematics.png

![alt text][pic3]

[pic3]: https://github.com/opemipoadigun/CS207fall2020-Project/blob/main/img/fritzing%20breadboard%20sketch.png

# Usage
* Plug in both Arduino Unos 
* Plug in cnc shield
* Home and zero Axes of robot from lcd screen
* Drag and Drop gcode into chilipeppr
* Make sure to have your pencil, pen or marker in place on the robot 
* Run serial-port-json-server-1.96_windows_386 or the one for other operating system which can be found on chilipeppr
* Make sure to detach the pin 2 and 3 from the lcd arduino 
* Select Arduino connected to the computer and also the cnc shield
* Home and Zero Axes of robot on chilipeppr
* Make sure to change Arduino on chilipeppr to grbl and 115200 baud
* Click Play Under Gcode on chilipeppr

# Credits
* DIY MACHINES (For the assembling of the a working drawing robot) - https://www.diymachines.co.uk/arduino-cnc-drawing-machine
