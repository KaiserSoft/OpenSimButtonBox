Arduino Nano Button Box
---

Update 2017-08-15
WARNING: The code in this directory is not finished. The serial communication from the Arduino Nano to the VB.NET program is working but 
I ran into an issue when I tried to send the key presses to iRacing. It works in Windows Editor, other programs and even the iRacing chat box but 
it stops working once I enter the car. This may be an issue with which window has focus so the solution may be to detect the iracing window and 
explicitly send the output to it. I may investigate in the future or if someone else feels like testing it .... feel free.
I have decided to switch to an Arduino Pro Micro since that unit is about the same price as the Nano but offers USB HID support out of the box.
This will eliminate the requirement for the VB.NET program to send the keypresses since the Pro Micro will act as a true HID.
I was not aware of the Pro Micro before, that would have been the better solution to begin with.... I am also investigating using an STM32 since they are also very cheap and very capable. This will be a great replacement for the rather expensive Teensy 3.2

ANYWAY - DO NOT USE THE CODE IN THIS DIRECTORY AND EXPECT IT TO WORK IN GAME! - You have been warned!
/End of Update 2017-08-15


DO NOT USE THIS YET! This is mostly just code to test the concept!


This directory will contain the code for the arduino nano  to work as a simple stand alone button box
and a very simple Windows VB.NET programm to receive the button presses via the serial interface.
Since the Nano can not run as a HID the Windows programm will send the keystrokes to the computer.

Arduino Nano Pinout
---
This button box will support up to 13 push buttons with one analog joystick
The pinout is defined like this:

* D2-D8,D11,D12 are used for push buttons - 9 Buttons
* D13 feedback LED
* A0,A1,A2,A3 are used for push buttons - 4 Buttons
* A6 used for Joystick 1 x/y-axis
* A7 used for Joystick 1 x/y-axis
* D9-D10 reserved for other functions (PWM pins)
* A4,A5 reserved for possible i2c OLED display or LED RPM bar using i2C port extenders


Windows Receiver
---
Windows Receiver is a very simple VB.NET program which listens to specific commands.
It will work with any other micro controller as long as it follows the following rules.
Supported Commands:
	* 'wr' - Windows Receiver will send this on the serial port after the "Connect" button is pressed.
	* 'nr' - Windows Receiver expects to receive this after sending 'wr'. It will not accept button commands without receiving this string
	* 'ws' - Windows Receiver sends it before closing the serial port. The Arduino Nano must stop sending button commands once this has been received
	* 'ns' - Windows Receiver expects to receive this after 'ws' has been sent.
	* 'B[1-13]' - The Arduino Nano may send button presses by indicating which button was pressed. Example: 'B1', 'B2', 'B6' .....     
		The button number must match the setting in the Windows Receiver GUI
	* 'J[1-2]' - Just like button but for analog "jostick". Send 'J1' or 'J2' for one direcion where the number must match the GUI
	* 'K[1-2]' - Sends 'K' instead of 'J' when the same axis is moved in the opposite direction