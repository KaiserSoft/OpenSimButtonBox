KNOWN ISSUES
============

fan board RC3
=============
* not manufactured yet / not tested


fan board RC2
=============
* LED can not be turned off by the jumper. it is always on when the load is on
  Solution: Has been fixed in fan board RC3

fan board RC1
=============
* through holes for fan and power headers are too tight
  Solution: Has been fixed in fan board RC2


Mainboard - PCB v1.0
========
* no known issues


Mainboard - PCB RC5
=======
* Encoder Push Buttons are not working anymore - discovered 09.12.2016    
  This issue is caused by all multi plexed pins beeing pulled LOW when idle and HIGH when pushed. So far the  encoder buttons where connected the other way around.    
  Solution: All switches connected to multiplexers need to use the 32 pin header. Connect switches to "+" and "S" pin on 1-32 header and the buttons on rotary encoders will work as well.
  Note: Keep two of the three encoder pins connected to "Encoders" on PCB and center pin to ground.


Mainboard - PCB <RC5
========
* multi plexed pins are floating    
  This works with hock up wire but fails with tiny traces using a manufactured PCB.     
  Solution: Has been fixed in PCB RC5