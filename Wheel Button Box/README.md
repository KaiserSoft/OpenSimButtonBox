Arduino Nano Button Box
---

DO NOT USE THIS YET! This is mostly just code to test the concept!


This directory will contain the code for the arduino nano  to work as a simple stand alone button box
and a very simple Windows VB.NET programm to receive the button presses via the serial interface.
Since the Nano can not run as a HID the Windows programm will send the keystrokes to the computer.


Windows Receiver
---
Windows Receiver is a very simple VB.NET program which listens to specific commands.
It will work with any other micro controller as long as it follows the following rules.
Supported Commands:
	* 'wr-rdy' - Windows Receiver will send this on the serial port after the "Connect" button is pressed.
	* 'nano start' - Windows Receiver expects to receive this after sending 'wr-rdy'. It will not accept button commands without receiving this string
	* 'wr-stop' - Windows Receiver sends it before closing the serial port. The Arduino Nano must stop sending button commands once this has been received
	* 'nano stop' - Windows Receiver expects to receive this after 'wr-stop' has been sent.
	* 'B[1-11]' - The Arduino Nano may send button presses by indicating which button was pressed. Example: 'B1', 'B2', 'B6' .....     
		The button number must match the setting in the Windows Receiver GUI
	* 'J[1-2]' - Just like button but for analog "josticks". Send 'J1' or 'J2' where the number must match the GUI