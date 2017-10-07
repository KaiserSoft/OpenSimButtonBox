OSW Button Box - DIY Direct Drive Wheel Button Box
===

![Image of fully assembled wheel button box](https://media.githubusercontent.com/media/KaiserSoft/OpenSimButtonBox/master/Wheel%20Button%20Box/Images/Wheel%20Button%20Box%20-%20Version%201%20-%20ProMicro%20-%20tiny.jpg)


Required Parts
===
* Arduino Pro Micro 16MHz - Will not work with most other Arduinos since they can not act as a HID. Teensy should work as well but it is more expensive.
* 10x push buttons with a thread diameter of around 12mm. The kind with a metal body works as well but they are heavier.    
  ![Supported Push Buttons](https://media.githubusercontent.com/media/KaiserSoft/OpenSimButtonBox/master/Wheel%20Button%20Box/Images/buttons%20for%20version%201.jpg)
* 1x Arduino Joystick Module - pay close attention to the circuit board since there are different types and the button box only works when the dimensions are correct.  
  ![Supported Joystick Module](https://media.githubusercontent.com/media/KaiserSoft/OpenSimButtonBox/master/Wheel%20Button%20Box/Images/joystick%20for%20version%201.jpg)
* Coiled Micro USB Cable - this connects the button box to your PC. It needs to be coiled so it can flex all the way to the end stops.


Build Instructions
===
* Print the button box and do basic cleanup. Rough up the sides where the box is split and use glue to join the two halves back together. You don't need much glue since this only makes it easier to install the buttons and cables. The button box will be held in place by the screws connecting the wheel to the mounting hub on the OSW motor.
* Install the buttons and solder the wires in place. Cut the wires long enough so that they can exit the arduino box at the bottom.
* Desolder the connection pin header on your joystick module.
* Solder wires to the joystick module and run them to the arduino box as well
* Ensure that every button is working by using the continuity test setting on your multi meter
* Ensure the joystick is working by testing the resistance
* Add wires for the magnetic paddle shifters as well. I recommend that you don't connect the sifters yet. Simply run wires and solder them to the paddle shifter wires once you are ready to assemble it all.
* Connect all wires as described in "CONFIG.h". Buttons use the "Button_X_Pin" and the joystick the "Joystick_X_Pin" setting.
* Remove some of the plastic on the outside of the micro USB connector. This makes the connector shorter and makes in easier to push it through the hole inside the button box.
* Connect the coiled USB cable to the arduino and upload the scetch to the board
* Test every button and joystick
* Test the buttons again
* Push the arduino into the arduino box at the bottom. Pull extra wires into the button box body and hide them in the wire channel.
* Test the buttons again
* Fill the arduino box with hot glue or silicone sealant. This ensures that the micro USB connector will not disconnect and that the arduino will not move
* Run the rest of the USB cable through wire channel at the bottom of the unit
* Assemble everything and connect the padde shifters
* Mount everything to the OSW and attach the wheel
* All done. You can use the arduino software to change which button sends which command (CONFIG.h file)
* Have fun!
![image showing sections described above](https://media.githubusercontent.com/media/KaiserSoft/OpenSimButtonBox/master/Wheel%20Button%20Box/Images/Image%20for%20Version%201%20Build%20Instructions.png)




Recommended Print / Slicer Settings
===
* Material: PLA
* Layer height: 0.25mm
* Infill: 25% to 30%
* Top/Bottom: 3 solid layers

File and Directory List
===
* **arduino_pro-micro_button_box**    
  This directory contains the Arduino Pro Micro Source Code

* **Face Plate for 320mm Steering Wheel**   
  Contains the STL and 3D source models for the button face plate
  
* **Wheel Box Face Plate for Arduino ProMicro - ONE PIECE**    
  This STL file contains the face plate in one piece. You need about a 200mmx150mm build surface.
  
*  **Wheel Box Face Plate for Arduino ProMicro - TWO PIECES - ONE / TWO**    
  This STL file as the face plate split into two pieces. This will work with a standard 150mmx150mm build surface
  
* **Sparko - Momo - Spacer and Backplate - ProMicro**    
  This is the back plate required to keep the center joystick in place
  
* **Shifter Mount with Joystick Slot**    
  This file contains the paddle shifter mount plate




