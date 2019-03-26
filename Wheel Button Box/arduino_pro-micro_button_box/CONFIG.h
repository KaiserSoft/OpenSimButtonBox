/*
 * Configuration Options
 * Settings Guide: https://github.com/KaiserSoft/simwheel-firmware-arduino-pro-micro/wiki/Firmware-Configuration-Options
 */
 
#define CONTROLLER_OUTPUT_MODE 2          // 1 == keyboard / 2 == joystick + keyboard
#define CONTROLLER_OUTPUT_ENABLED true   // true to enable keyboard and joystick output
#define CONTROLLER_JOYSTICK_ENABLED false // true to enable support for analog joystick type (game controller type)
#define CONTROLLER_ENCODER_ENABLED true  // true to enable rotary encoder support
#define CONTROLLER_SHIFTER_TYPE 2         // 1 == micro switch / 2 == linear hall effect sensor 
#define CONTROLLER_CLUTCH_ENABLED true    // true to enable clutch support, false to disable
#define BUTTON_DEBOUNCE 25                // time in ms that must pass before multiplexed buttons are considered pressed
#define EEPROMWrite 1                     // set to 1 to enable writes to eeprom (update stored values) - default: 1


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
 #define Shifter_1_Pin A0
 #define Shifter_1_Key false
 #define Shifter_1_Mod false
 #define Shifter_1_Joy 0
 #define Shifter_1_ShiftPoint_Default 850
 
 #define Shifter_2_Pin A1
 #define Shifter_2_Key false
 #define Shifter_2_Mod false
 #define Shifter_2_Joy 1
 #define Shifter_2_ShiftPoint_Default 850


#if CONTROLLER_CLUTCH_ENABLED == true
 #define Clutch_1_Pin A2
 #define Clutch_1_Key false
 #define Clutch_1_Mod false
 #define Clutch_1_Joy false
#endif
 

 /**
  * Ratiometric Linear Hall Effect Shifter ( CONTROLLER_SHIFTER_TYPE == 2 )
  */
 #define HESCalibrationAdjust 45   // shift this many values earlier then absolute max
 #define ClutchCalibrationAdjust 10   // adjust min/max by this much
 #define EEPROM_HES_1 0 // 0+1 EEPROM storage location for calibrated value
 #define EEPROM_HES_2 2 // 2+1 EEPROM storage location for calibrated value
 #define EEPROM_CLL_1 4 // 2+1 EEPROM storage location for calibrated value
 #define EEPROM_CLH_1 6 // 2+1 EEPROM storage location for calibrated value


 
/*
 * Buttons
 * This programm supports upto 13 momentary (non latching) buttons
 * You may specify the pin each button is connected to.
 * The arduino will send the number of the button once it has been pressed
 */
 #define Button_1_Pin 0
 #define Button_1_Key false
 #define Button_1_Mod false
 #define Button_1_Joy 2
 
 #define Button_2_Pin 1
 #define Button_2_Key false
 #define Button_2_Mod false
 #define Button_2_Joy 3
 
 #define Button_3_Pin 4
 #define Button_3_Key false
 #define Button_3_Mod false
 #define Button_3_Joy 4
 
 #define Button_4_Pin 5
 #define Button_4_Key false
 #define Button_4_Mod false
 #define Button_4_Joy 5
 
 #define Button_5_Pin 6
 #define Button_5_Key false
 #define Button_5_Mod false
 #define Button_5_Joy 6
 
 #define Button_6_Pin 7
 #define Button_6_Key false
 #define Button_6_Mod false
 #define Button_6_Joy 7
 
 #define Button_7_Pin 8
 #define Button_7_Key false
 #define Button_7_Mod false
 #define Button_7_Joy 8

 #define Button_8_Pin 9
 #define Button_8_Key false
 #define Button_8_Mod false
 #define Button_8_Joy 9
 
 #define Button_9_Pin 10
 #define Button_9_Key false
 #define Button_9_Mod false
 #define Button_9_Joy 10
 
 #define Button_10_Pin 14
 #define Button_10_Key false
 #define Button_10_Mod false
 #define Button_10_Joy 11
 
 #define Button_11_Pin 15
 #define Button_11_Key false
 #define Button_11_Mod false
 #define Button_11_Joy 12
 
 #define Button_12_Pin 16
 #define Button_12_Key false
 #define Button_12_Mod false
 #define Button_12_Joy 13
 
 #define Button_13_Pin A3
 #define Button_13_Key false
 #define Button_13_Mod false
 #define Button_13_Joy 14


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
#define DebugSerialOut false            // controls all non specific debugging messages - MUST BE ENABLED FOR SERIAL TO WORK
#define DebugBackgroundOps false        // receive feedback from background loops like EEPROM storage
#define DebugSendKey false             // Output key presses to serial - does NOT disable the keyboard
#define DebugJoysticksGetValues false  // will send analog readings to serial instead of pressing keys
#define DebugHallEffectShiftPoint false // set to true to get the analog read values of the shifter pins
#define DebugHallEffectCalib false      // true to receive serial feedback from shifter calibration functions
#define DebugClutchGetValues false       // true to get current reading via serial
#define DebugClutchCalib false          // tue to enable clutch calibration
