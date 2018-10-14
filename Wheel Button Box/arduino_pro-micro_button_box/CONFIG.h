/*
 * Configuration Options
 */

#define BUTTON_DEBOUNCE 25      //time in ms that must pass before multiplexed buttons are considered pressed
#define AnalogResolution 12     //used when reading multiplexed buttons
#define EEPROM_storage_loop 320 // update EEPROM at most every n seconds
#define KeyboardEnabled true    // true sends key presses, false does not
#define JoystickEnabled true    // true sends key presses, false does not




/*
 * Buttons
 * This programm supports upto 13 momentary (non latching) buttons
 * You may specify the pin each button is connected to.
 * The arduino will send the number of the button once it has been pressed
 */
 #define Shifter_1_Pin 0
 #define Shifter_1_Key 'v'
 #define Shifter_1_Mod ""
 #define Shifter_1_Joy 1
 
 #define Shifter_2_Pin 1
 #define Shifter_2_Key 'u'
 #define Shifter_2_Mod ""
 #define Shifter_2_Joy 2
 
 #define Button_1_Pin 4
 #define Button_1_Key 'a'
 #define Button_1_Mod ""
 #define Button_1_Joy 3
 
 #define Button_2_Pin 5
 #define Button_2_Key 'b'
 #define Button_2_Mod ""
 #define Button_2_Joy 4
 
 #define Button_3_Pin 6
 #define Button_3_Key 'c'
 #define Button_3_Mod ""
 #define Button_3_Joy 5
 
 #define Button_4_Pin 7
 #define Button_4_Key 'e'
 #define Button_4_Mod ""
 #define Button_4_Joy 6
 
 #define Button_5_Pin 8
 #define Button_5_Key 'f'
 #define Button_5_Mod ""
 #define Button_5_Joy 7
 
 #define Button_6_Pin 9
 #define Button_6_Key 'h'
 #define Button_6_Mod ""
 #define Button_6_Joy 8
 
 #define Button_7_Pin 10
 #define Button_7_Key 'i'
 #define Button_7_Mod ""
 #define Button_7_Joy 9

 #define Button_8_Pin 14
 #define Button_8_Key 'j'
 #define Button_8_Mod ""
 #define Button_8_Joy 10
 
 #define Button_9_Pin 15
 #define Button_9_Key 'k'
 #define Button_9_Mod ""
 #define Button_9_Joy 11
 
 #define Button_10_Pin 16
 #define Button_10_Key 'l'
 #define Button_10_Mod ""
 #define Button_10_Joy 12
 
 #define Button_11_Pin A2
 #define Button_11_Key 'm'
 #define Button_11_Mod ""
 #define Button_11_Joy 13
 
 #define Button_12_Pin A3
 #define Button_12_Key 'n'
 #define Button_12_Mod ""
 #define Button_12_Joy 14
 


/*
 * The Joystick is defined below, Each axis uses one pin.
 * Testing has shown that some do not center properly and that the resistor value will change more in 
 * one direction. Use the config options below to adjust values to your joystick.
 */
 #define Joystick_1_Pin A0
 #define Joystick_1_KeyA KEY_UP_ARROW
 #define Joystick_1_ModA ""
 #define Joystick_1_JoyA 15
 #define Joystick_1_KeyB KEY_DOWN_ARROW
 #define Joystick_1_ModB ""
 #define Joystick_1_JoyB 16
 #define Joystick_1_Center 515   // Center value for your joystick
 #define Joystick_1_Move_Min 450 // Stick must move this far of center to trigger a button press

 #define Joystick_2_Pin A1
 #define Joystick_2_KeyA KEY_RIGHT_ARROW
 #define Joystick_2_ModA ""
 #define Joystick_2_JoyA 17
 #define Joystick_2_KeyB KEY_LEFT_ARROW
 #define Joystick_2_ModB ""
 #define Joystick_2_JoyB 18
 #define Joystick_2_Center 515   // Center value for your joystick
 #define Joystick_2_Move_Min 450 // Stick must move this far of center to trigger a button press




 /*
  ###############################
  # Debug Options Configuration #
  ###############################
*/
#define DebugSerialOut false           // controls all non specific debugging messages - MUST BE ENABLED FOR SERIAL TO WORK
#define DebugSendKey false             // Output key presses to seril - does NOT disable the keyboard
#define DebugJoysticksGetValues false  //will send analog readings to serial instead of pressing keys
#define EEPROMWrite 1                  //set to 1 to enable writes to eeprom (update stored values) - default: 1
