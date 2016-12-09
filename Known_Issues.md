KNOWN ISSUES
============



PCB RC5
=======
* Encoder Push Buttons are not working anymore - discovered 09.12.2016    
  This issue is caused by all multi plexed pins beeing pulled LOW when idle and HIGH when pushed. The encoder buttons work the other way around. There is no work around yet.


PCB <RC5
========
* multi plexed pins are floating    
  This works with hock up wire but fails with tiny traces using a manufactured PCB.     
  Has been fixed in PCB RC5