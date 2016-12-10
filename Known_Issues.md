KNOWN ISSUES
============



PCB RC5
=======
* Encoder Push Buttons are not working anymore - discovered 09.12.2016    
  This issue is caused by all multi plexed pins beeing pulled LOW when idle and HIGH when pushed. So far the  encoder buttons where connected the other way around.    
  Solution: All switches connected to multiplexers need to use the 32 pin header. Connect switches to "+" and "S" pin on 1-32 header and the buttons on rotary encoders will work as well.
  Note: Keep two of the three encoder pins connected to "Encoders" on PCB and center pin to ground.


PCB <RC5
========
* multi plexed pins are floating    
  This works with hock up wire but fails with tiny traces using a manufactured PCB.     
  Solution: Has been fixed in PCB RC5