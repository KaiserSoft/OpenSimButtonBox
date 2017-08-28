Wheel Button Bux based on STM32F103C8T6
============

This directory contains the code for a sim racing button box using the STM32F103C8T6 development boards.
* Tested on STM32F103C8T6

*WARNING* The USB connector on my board was not soldered around the clamps. You should apply solder if you want to ensure long life in an environment with a lot of vibration.


Arduino Requirements
====================
You will need the following equipment to install the Arduino Bootloader onto the board.
* An STM32F103C8T6 development board
* A ST-Link v2 programmer for STM8 and STM32. I am using a 3€ clone from ebay. Search for "ST-Link v2 programmer" and you will find a lot to chose from. They should be all the same and only differ in color.



Arduino IDE Setup
=======
Since the STM32F103C8T6 is not supported out of the box you will need to install the Arduino Bootloader and add support for the STM32F103C8T6 
to the IDE. The following steps should get your up and running. Make sure you follow each step or it may not work!
* Download and install the Arduino IDE 1.8.x from https://www.arduino.cc/en/Main/Software
  * Start the Arduino IDE and open the "Boards Manager" under "Tools" => "Board"
  * Enter "arduino zero" into the search box, click on the "Arduino SAMD Boards" result and then on "Install"
  * Close the IDE now
* Clone https://github.com/KaiserSoft/Arduino_STM32 or download https://github.com/KaiserSoft/Arduino_STM32/archive/master.zip    
  * Extract the archive and copy the "Arduino_STM32-master" folder into "My Documents\Arduino\hardware". Create the "hardware" directory if it does not exist yet
  * Goto "My Documents\Arduino\hardware\Arduino_STM32-master\drivers\win" and run "install_drivers.bat"
* Download and install "STM32 ST-LINK Utility" (Part number STSW-LINK004  from http://www.st.com/en/embedded-software/stsw-link004.html
  This is free software but requires registration.
* Connect the ST-Link v2 programmer to your computer and ensure that you see a "STM32 STLink" in the Device Manager. This should be listed unter "Universal Serial Bus devices" in Windows 10. Disconnect the programmer for now.
* Download the "STM32duino-bootloader" from here https://github.com/rogerclarkmelbourne/STM32duino-bootloader/tree/master/binaries
  Look for the file "generic_bootXX_pc13.bin" where PC13 is the pin where the LED is connected on the board. This is not the same on all boards but it is marked on my board as PC13.    
  Check the following ReadMe for details https://github.com/rogerclarkmelbourne/STM32duino-bootloader/blob/master/README.md
* Connect the ST-Linkv2 programmer to the four pins towards the back of the STM32F103C8T6 board.    
  Pay VERY close attention to the voltage line! ONLY CONNECT 3VOLTS to the board since you will destroy the board if you accidentially connect 5Volts!
  * Connect the ST-Link 3V line to the pin marked 3.3, SWDIO to DIO, SWCLK to DCLK and GND to GND. Double check that you connected it correctly!
  * Move the jump that is next to the row of pins (Boot1) to pin 1. If you hold the board with the USB connector to the right, then it is the jumper towards the bottom.
  * Connect the SW-Link v2 programmer directly to your computer. Do not use a USB extension cable for this.
* Start "ST32 ST-Link Utility" and click on "Target => "Connect"
  * Click on "Target" => "Program & Verify", a file selection windows will open. Select the "generic_bootXX_pc13.bin" file you downloaded earlier.
  * Ensure that "Skip Flash Erase" and "Skip Flash Protection verification" are NOT checked and that "Verify while prgramming" is selected.
  * "Reset after programming" should be checked but "Full Flash memory Checksum" should NOT be checked.
  * Click "Start" to write the image to the device.
  * You should see "Memory programmed in xxs and yyms" followed by "Verification...OK"
  * Disconnected the STM32F103C8T6 and set the Boot1 jumper back to pin 0
* At this point the Arduino Bootloader is installed and you should be able to upload programs using the Arduino IDE. You may double check this by opening the Device Manager. Under "Ports (COM & LPT)" you should see a "Maple Serial (COM)" device.
* Test the functionality by opening the Arduino IDE and upload the "Blink" Example
  * Click "File" => "Examples" => "01.Basics" => "Blink"
  * Click "Tools" => "Board:" and select the "Generic STM32F103C series" from the menu
  * Make sure that the following is selected
    * Variant: STM32F103C8 (w0k RAM, 64k Flash)
    * USB Type: Keyboard + Mouse
	* CPU Speed(MHz): 48Mhz (Slow - with USB)
	* Upload method: STM32duino bootloader
	* Port: The COM port used by your device
  * Click "Upload" and check that your STM32F103C8T6 starts blinking