/* CONFIG START */

/*
  ######################
  # Misc Configuration #
  ######################
*/
#define BootUpDelay 2000        //Delay between power on and "ready", set to 0 (zero) to disable
#define BUTTON_HOLD 75          //button is send to the computer for this many ms, then it is released
#define BUTTON_DEBOUNCE 25      //time in ms that must pass before multiplexed buttons are considered pressed
#define ledPin 13
#define AnalogResolution 12     //used when reading multiplexed buttons
#define EEPROM_storage_loop 320 // update EEPROM at most every n seconds


/**
    Auxillary Port Control
    Setting the "EnableAux*" option to 1 will override the button specified in "AUX*_Button"
    Holding that button down enables the use of the rotary encoder on the right to change the PWM value
    of each AUX port
*/
#define AUX_RAMP_TIME 3000 //ramp up timer for all AUX port on boot up


/*
  #############################
  # Multiplexer Configuration #
  #############################
*/
#define EnableMultiplexer 1     // 1 to use the multiplexer or 0 to use buttons without
#define AnalogLowerLimit 1600   // a button is considered pressed when the analog reading drops below this value
#define Multiplexer1 A8         //  analog pin to multiplexer
#define Multiplexer2 A7         //  analog pin to multiplexer
#define Multiplexer3 A9         //  analog pin to multiplexer
#define Multiplexer4 A6         //  analog pin to multiplexer
#define MultiplexerP9 0         //  4051 pin 9 connected to this Teensy pin (digital)
#define MultiplexerP10 1        //  4051 pin 10 connected to this Teensy pin (digital)
#define MultiplexerP11 2        //  4051 pin 11 connected to this Teensy pin (digital)
#define MultiplexerPortDelay 2  // wait this many microseconds after a port change, before reading the results



/*
  ###############################
  # Debug Options Configuration #
  ###############################
*/
/*
    the device may be debuged using a serial console
*/
#define OutputKeyboard 1 // set to 1 to send keys as a USB keyboard or disable for debugging - default: 1
#define OutputSerial 0 //set to 1 to enable serial output - default: 0
#define DebugMultiplexer 0 //set to 1 to get pin and device info for pins 1-32. Serial must be 1 and disables send_key()
#define DebugShiterPriority 0 //set to 1 to ensure shifter priority is used
#define DebugOutput 0 //enables timing info ... very verbose. keep this disabled  - default: 0
#define EEPROMWrite 1 //set to 1 to enable writes to eeprom (update stored values) - default: 1
/* CONFIG END */
