/*
 * Configuration Options
 */
 
#define CONTROLLER_OUTPUT_MODE 2          // 1 == keyboard / 2 == joystick + keyboard
#define CONTROLLER_OUTPUT_ENABLED false   // true to enable keyboard and joystick output
#define CONTROLLER_JOYSTICK_ENABLED false // true to enable support for analog joystick type (game controller type)
#define CONTROLLER_ENCODER_ENABLED false  // true to enable rotary encoder support
#define CONTROLLER_SHIFTER_TYPE 2         // 1 == micro switch / 2 == linear hall effect sensor 
#define BUTTON_DEBOUNCE 25                // time in ms that must pass before multiplexed buttons are considered pressed
#define EEPROM_storage_loop 320           // update EEPROM at most every n seconds
#define EEPROMWrite 1                     // set to 1 to enable writes to eeprom (update stored values) - default: 1

/* private stuff 
 *  DEVWHEELTYPE 1 == Round with analog joystick 
 *  DEVWHEELTYPE 2 = Proto 5 
 *  DEVWHEELTYPE 3 = Proto 6
 */
#define DEVWHEELTYPE 1


/*
 * Encoder Config
 */
 #define Encoder_A_Pin  2
 #define Encoder_A_Key KEY_LEFT_ARROW
 #define Encoder_A_Mod false
 #define Encoder_A_Joy 27
 
 #define Encoder_B_Pin  3
 #define Encoder_B_Key KEY_RIGHT_ARROW
 #define Encoder_B_Mod false
 #define Encoder_B_Joy 28


/*
 * Shifter Config
 */
 #define Shifter_1_Pin 0
 #define Shifter_1_Key false
 #define Shifter_1_Mod false
 #if DEVWHEELTYPE == 2
  #define Shifter_1_Joy 1
 #else
  #define Shifter_1_Joy 0
 #endif
 
 #define Shifter_2_Pin 1
 #define Shifter_2_Key false
 #define Shifter_2_Mod false
 #if DEVWHEELTYPE == 2
  #define Shifter_2_Joy 0
 #else
  #define Shifter_2_Joy 1
 #endif

 /**
  * Ratiometric Linear Hall Effect Shifter ( CONTROLLER_SHIFTER_TYPE == 2 )
  */
 #define HallEffectShiftPoint 880  // set to analog read value when a shift should be triggered
                                   // see debug section at bottom to get the analog read value


 
/*
 * Buttons
 * This programm supports upto 13 momentary (non latching) buttons
 * You may specify the pin each button is connected to.
 * The arduino will send the number of the button once it has been pressed
 */
 #define Button_1_Pin 4
 #define Button_1_Key false
 #define Button_1_Mod false
 #if DEVWHEELTYPE == 1
  #define Button_1_Joy 9
 #elif DEVWHEELTYPE == 2
  #define Button_1_Joy 5
 #endif
 
 #define Button_2_Pin 5
 #define Button_2_Key false
 #define Button_2_Mod false
 #if DEVWHEELTYPE == 1
  #define Button_2_Joy 12
 #else
  #define Button_2_Joy 10
 #endif
 
 #define Button_3_Pin 6
 #define Button_3_Key false
 #define Button_3_Mod false
 #if DEVWHEELTYPE == 1
  #define Button_3_Joy 8
 #elif DEVWHEELTYPE == 2
  #define Button_3_Joy 11
 #endif
 
 #define Button_4_Pin 7
 #define Button_4_Key false
 #define Button_4_Mod false
 #if DEVWHEELTYPE == 1
  #define Button_4_Joy 3
 #elif DEVWHEELTYPE == 2
  #define Button_4_Joy 9
 #endif
 
 #define Button_5_Pin 8
 #if DEVWHEELTYPE == 1
  #define Button_5_Key KEY_ESC
 #else
  #define Button_5_Key false
 #endif
 #define Button_5_Mod false
 #if DEVWHEELTYPE == 1
  #define Button_5_Joy 4
 #elif DEVWHEELTYPE == 2
  #define Button_5_Joy 8
 #endif
 
 #define Button_6_Pin 9
 #define Button_6_Key false
 #define Button_6_Mod false
 #if DEVWHEELTYPE == 1
  #define Button_6_Joy 2
 #elif DEVWHEELTYPE == 2
  #define Button_6_Joy 3
 #endif
 
 #define Button_7_Pin 10
 #define Button_7_Key false
 #define Button_7_Mod false
 #if DEVWHEELTYPE == 1
  #define Button_7_Joy 12
 #elif DEVWHEELTYPE == 2
  #define Button_7_Joy 4
 #endif

 #define Button_8_Pin 14
 #if DEVWHEELTYPE == 2
  #define Button_8_Key KEY_ESC
 #elif DEVWHEELTYPE == 1
  #define Button_8_Key false
 #endif
 #define Button_8_Mod false
 #define Button_8_Joy 13
 
 #define Button_9_Pin 15
 #if DEVWHEELTYPE == 1
  #define Button_9_Key ' ' //space joystick oush button
 #elif DEVWHEELTYPE == 2
  #define Button_9_Key false
 #endif
 #define Button_9_Mod false
 #if DEVWHEELTYPE == 1
  #define Button_9_Joy 19
 #elif DEVWHEELTYPE == 2
  #define Button_9_Joy 12
 #endif
 
 #define Button_10_Pin 16
 #define Button_10_Key false
 #define Button_10_Mod false
 #if DEVWHEELTYPE == 1
  #define Button_10_Joy 11
 #elif DEVWHEELTYPE == 2
  #define Button_10_Joy 2
 #endif
 
 #define Button_11_Pin A2
 #define Button_11_Key false
 #define Button_11_Mod false
 #if DEVWHEELTYPE == 1
  #define Button_11_Joy 6
 #elif DEVWHEELTYPE == 2
  #define Button_11_Joy 7
 #endif
 
 #define Button_12_Pin A3
 #define Button_12_Key false
 #define Button_12_Mod false
 #if DEVWHEELTYPE == 1
  #define Button_12_Joy 7
 #elif DEVWHEELTYPE == 2
  #define Button_12_Joy 6
 #endif
 


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
#define DebugSerialOut true           // controls all non specific debugging messages - MUST BE ENABLED FOR SERIAL TO WORK
#define DebugSendKey false             // Output key presses to serial - does NOT disable the keyboard
#define DebugJoysticksGetValues false  // will send analog readings to serial instead of pressing keys
#define DebugHallEffectShiftPoint true // set to true to get the analog read values of the shifter pins
