/*
  ######################
  # Misc Configuration #
  ######################
*/
#define BUTTON_DEBOUNCE 25      //time in ms that must pass before multiplexed buttons are considered pressed
#define AnalogResolution 12     //used when reading multiplexed buttons
#define EEPROM_storage_loop 320 // update EEPROM at most every n seconds






/*
  ###############################
  # Debug Options Configuration #
  ###############################
*/
/*
    the device may be debuged using a serial console
*/
#define DebugOutput 0 //enables debug output mode - DO NOT USE FOR REGULAR OPERATION!
#define EEPROMWrite 1 //set to 1 to enable writes to eeprom (update stored values) - default: 1
