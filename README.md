Open Modular Button Box Project
===============================

The Open Modular Button Box Project is an expandable button box designed for iRacing, build on a Teensy 3.2. The "main module" is designed to be very simple to build while still offering 15 buttons and 3 rotary encoders to navigate the iRacing Black Box screens. 
The design uses the internal resistors so wires connect directly from the switch to the Teensy board.


The main module requires (see "Sources List" for details)
* 3D printed case
* 5 (ON)/OFF/(ON) Toggle Switches (12mm neck)
* 3 Rotary Encoders with Push Button (6mm neck)
* 5 Momentary Push Switches (12mm neck)
* Arduino IDE (check Teensyduino Library for supported version)
  https://www.arduino.cc/en/Main/Software
* Teensyduino Library 
  https://www.pjrc.com/teensy/td_download.html

The Open Modular Button Box Project - Main Module is complete and is currently being tested.



Expansion Modules
=================
Expansion modules will offer additional buttons, encoders and will connect to the main module. Each expansion module will serve a specific purpose like pit box, ERS control module, many push buttons and so on. 
Building these expansion modules will be a bit more advanced since it will require a button matrix or additional ICs.




Sources List
============
* 1x Teensy 3.2
  (USA) https://www.pjrc.com
  (Europe) http://www.reichelt.de
  (other) Google.com is your fiend
  
* 5x Toggle Switches Arcolectric Model KS C3922 (ON)/OFF/(ON)
   The "(ON)" indicatates a momentary switch while an "ON" switch is permanenent (does not snap back to center). 
   ONLY PURCHASE MOMENTARY SWITCHES FOR THIS BUTTON BOX!!!
   (Europe) http://www.reichelt.de
   
* 3x Rotary Encoder with push button (3 bit gray code)
  The cheap encoders can only indicate "left" or "right". They are perfect for menu navigation or increasing numbers quickly (fuel refill).
  (Europe) https://www.amazon.de
  (other) https://www.amazon.com
  
* 4x Momentary Push Switch (ON)/OFF
  These cheap switches can be found on ebay or Amazon. Make sure that you get the "momentary" or "reset" type. Operation must be "push" ON, "release" OFF.
  Double check the item instructions since chinese sellers tend to put every term into the item name.
  (Europe) https://www.amazon.de
  (other) https://www.amazon.com
  
  
* Hookup wire - I use 0,6mm solid core from Conrad "Schaltdraht 10m 2x0,6/1,1"
* Long USB cable. Get the "AmazonBasics A-to-Micro-B USB 2.0 Cable" while you get the switches.
* 4x M4x10mm Screws with Nuts (for the mount)
* 6x M3x15mm Screws or self taping screws to attach face plate to box



INSTRUCTIONS
============
* Print "Face Plate Box MAIN" and "Face Plate Box MAIN BODY" found in "Main Module\Case"
* Screw your switches onto the face plate
* Find the ground pin for your switches and solder them all together
* Attach one wire each to the rest of the switch pins. Wires should all reach 15 cm out of the case, see screenshot.
* Attach one more wire to ground
* Check all connections with a multimeter. Set it to continuity (where it beeps when you short it) and connect one probe to the ground wire. Now test every switch before your connect them to the board!
* Connect wires to the Teensy as seen in the image


