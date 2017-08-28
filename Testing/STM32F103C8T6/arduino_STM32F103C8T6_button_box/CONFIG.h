/*
 * Configuration Options
 */

#define BUTTON_DEBOUNCE 25      //time in ms that must pass before multiplexed buttons are considered pressed
#define AnalogResolution 12     //used when reading multiplexed buttons
#define EEPROM_storage_loop 320 // update EEPROM at most every n seconds
#define BUTTON_WAIT_HOLD 725    // button must be held down for this long to be considered "held" down
#define BUTTON_REPEAT 250       // resend keyboard key every this many milliseconds
#define JOYSTICK_REPEAT 500     // resend key for joystick after this many ms. Value should propably 
                                // be larger then BUTTON_REPEAT since operating the joystick is not as quick


/*
 * Buttons
 * This programm supports upto 13 momentary (non latching) buttons
 * You may specify the pin each button is connected to.
 * The arduino will send the number of the button once it has been pressed
 */
 #define Button_1_Pin PB12
 #define Button_2_Pin PB13
 #define Button_3_Pin PB14
 #define Button_4_Pin PB15
 #define Button_5_Pin PA8
 #define Button_6_Pin PA9
 #define Button_7_Pin PA10
 #define Button_8_Pin PA11
 #define Button_9_Pin PA12
 #define Button_10_Pin PA15
 #define Button_11_Pin PB3
 #define Button_12_Pin PB4
 #define Button_13_Pin PB5


/*
 * The Joystick is defined below, Each axis uses one pin.
 * Testing has shown that some do not center properly and that the resistor value will change more in 
 * one direction. Use the config options below to adjust values to your joystick.
 */
 #define Joystick_1_Pin PA0       // must be A6 or A7 since these will not work with INPUT_PULLUP
 #define Joystick_1_Center 512   // Center value for your joystick
 #define Joystick_1_Move_Min 150 // Stick must move this far of center to trigger a button press
 
 #define Joystick_2_Pin PA1       // must be A6 or A7 since these will not work with INPUT_PULLUP
 #define Joystick_2_Center 512   // Center value for your joystick
 #define Joystick_2_Move_Min 150 // Stick must move this far of center to trigger a button press




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
