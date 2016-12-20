Modular Open Sim Racing Button Box
==================================

The Modular Open Button Box (MOBB) project is a complete open source solution to build your own button box. It provides complete plans on how to build your own 
Teensy 3.2 shield, button box ideas, box designs for 3D printers, drill tempaltes for your face plates or just ideas for your own design.    
The design is modular so you may pick and choose from various parts to design YOUR button box the way YOU imagine it.    
    
    

![example image of the Open Button Box (MOBB) PCB rev5](https://raw.githubusercontent.com/KaiserSoft/OpenSimButtonBox/master/Images/MainBoard-PCB/PCB_MOBB-rc5-arrived-small.jpg)    

Design idea with UV-LEDs to provide illumunation when it is dark
![design idea with UV-LEDs](https://raw.githubusercontent.com/KaiserSoft/OpenSimButtonBox/master/Documentation/Images/Prototype-v3.PNG)

Side by side box design    
![side by side sim button box](https://raw.githubusercontent.com/KaiserSoft/OpenSimButtonBox/master/Images/Prototype%203/Prototype%203%20-%20Main%20Module%20%2B%20Side%20Box%20-%20Layout%201%20-%20small.jpg)

Two of the boxes used for current development    
![two development button boxes](https://raw.githubusercontent.com/KaiserSoft/OpenSimButtonBox/master/Documentation/Images/button_box-full_layout-vertical-760.jpg)

Example of pit limiter switch on older development board   
![pit limiter switch example](https://raw.githubusercontent.com/KaiserSoft/OpenSimButtonBox/master/Documentation/Images/button_box_pit_limiter-ON-small.jpg)

The PCB
===========
The PCB is a shield for the Teensy 3.2 micro controller board. You may use the provided schematic to build your own on a perfboard, use the provided gerber files to have one manfucatured or contact me to send you one.    
Assembly requires minor soldering skills but assembly is quite easy if you follow the instruction videos.       

The current version supports
* through hole component design for easy soldering
* 32 buttons
* 1 latching toggle switch with LED inside - used to enable/disable the pit limiter
* 3 rotary encoders
* 3 Auxillary ports providing 0-5Volt @ 100mA each
* one handed operation to adjust AUX ports (always have one hand on the steering wheel)
* fully open source in design and code
* code written using the Arduino IDE for easy customizations
* (Optional) 12Volt Fan Board with optical isolation between 12Volt supply and host PC. Connects to one AUX port and controls up to two fans.
![image of fan controller board](https://raw.githubusercontent.com/KaiserSoft/OpenSimButtonBox/master/Images/PCB-Fan-Board/fan_board-RC1-with-dev_small.jpg)



INSTRUCTIONS & Sources List
===========================
December 2016 - Instructions and Assembly Videos will be released once PCB RC6 arrives at the end of the month.
Any documentation in the "Documentation" directory is not up to date anymore!    



    
This is an open source project - contributions are welcome!