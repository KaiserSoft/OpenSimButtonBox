/*
 * Configuration Options
 */

#define BUTTON_DEBOUNCE 25      //time in ms that must pass before multiplexed buttons are considered pressed
#define AnalogResolution 12     //used when reading multiplexed buttons
#define EEPROM_storage_loop 320 // update EEPROM at most every n seconds
#define BUTTON_WAIT_HOLD 250    // button must be held down for this long to be considered "held" down
#define BUTTON_REPEAT 125       // resend keyboard key every this many milliseconds
#define JOYSTICK_REPEAT 250     // resend key for joystick after this many ms. Value should propably 
                                // be larger then BUTTON_REPEAT since operating the joystick is not as quick


/*
 * Buttons
 * This programm supports upto 13 momentary (non latching) buttons
 * You may specify the pin each button is connected to.
 * The arduino will send the number of the button once it has been pressed
 */
 #define Button_1_Pin 2
 #define Button_2_Pin 3
 #define Button_3_Pin 4
 #define Button_4_Pin 5
 #define Button_5_Pin 6
 #define Button_6_Pin 7
 #define Button_7_Pin 8
 #define Button_8_Pin 11
 #define Button_9_Pin 12
 #define Button_10_Pin A2
 #define Button_11_Pin A3
 #define Button_12_Pin A6
 #define Button_13_Pin A7


/*
 * The Joystick is defined below, Each axis uses one pin.
 * Testing has shown that some do not center properly and that the resistor value will change more in 
 * one direction. Use the config options below to adjust values to your joystick.
 */
 #define Joystick_1_Pin A0
 #define Joystick_1_Center 512   // Center value for your joystick
 #define Joystick_1_Move_Min 150 // Stick must move this far of center to trigger a button press
 
 #define Joystick_2_Pin A1
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
