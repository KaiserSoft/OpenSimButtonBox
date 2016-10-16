/* CONFIG START */

/* 
  ######################
  # Misc Configuration #
  ######################
*/
#define BootUpDelay 2000  //Delay between power on and "ready", set to 0 (zero) to disable
#define delayEnc 75       //debounce for rotary encoders
#define delayBtn 75       //debounce for push button switches
#define ledPin 13 
#define AnalogResolution 12 //used when reading multiplexed buttons
#define EEPROM_storage_loop 320 // update EEPROM at most every n seconds


/**
 * Pit Limiter
 * This is an ON/OFF switch to enable/disable the pit limiter
 * NOT a momentary switch
 */
#define EnablePitLimiterSwitch 1
#define PitLimiterPin 6 // pin for ON/OFF switch used as pit limiter
#define PitLimiterKey KEY_O
#define PitLimiterMod 0
#define PitLimiterHold 0

/** 
 *  Auxillary Port Control
 *  Setting the "EnableAux*" option to 1 will override the button specified in "AUX*_Button"
 *  Holding that button down enables the use of the rotary encoder on the right to change the PWM value 
 *  of each AUX port
 */
#define AUX_RAMP_TIME 3000 //ramp up timer for all AUX port on boot up
#define EnableAux1 1 //use a button to control PWM on AUX 1
#define AUX1_Pin 4 // 5Volt -  fan or UV LED pin
#define AUX1_Button KEY_K // hold this button and use encoder left/right to adjust PWM output on port
#define AUX1_Button_Mod 0 //set to 'MODIFIERKEY_SHIFT' to a capital letter
#define AUX1_PWM_CHANGE 5 //increase or decrease PWM by this much
#define AUX1_PWM_MAX 255 //max valueo for pwm AoBLSOLUTE MAX 255 !!!!
#define AUX1_PWM_MIN 4 //min value for pwm ABSOLUTE MIN 0 !!!!
#define AUX1_PWM_FREQ 100 //PWM frequency
#define AUX1_ENABLE_FAN_START 1 //0 to disable or 1 to ramp up this port when turned on
#define AUX1_FAN_START_RAMP 100 // PWM value used to get the fan spinning
#define AUX1_EEPROM 0 // EEPROM address

#define EnableAux2 1 //use a button to control PWM on AUX 2
#define AUX2_Pin 3 // 5Volt - fan or UV LED pin
#define AUX2_Button KEY_M // hold this button and use encoder left/right to adjust PWM output on port
#define AUX2_Button_Mod 0 //set to 'MODIFIERKEY_SHIFT' to a capital letter
#define AUX2_PWM_CHANGE 10 //increase or decrease PWM by this much
#define AUX2_PWM_MAX 255 //max value for pwm ABLSOLUTE MAX 255 !!!!
#define AUX2_PWM_MIN 9 //min value for pwm ABSOLUTE MIN 0 !!!!
#define AUX2_PWM_FREQ 100 //PWM frequency
#define AUX2_ENABLE_FAN_START 0 //0 to disable or 1 to ramp up this port when turned on
#define AUX2_FAN_START_RAMP 100 // PWM value used to get the fan spinning
#define AUX2_EEPROM 1 // EEPROM address

#define EnableAux3 0 //use a button to control PWM on AUX 3
#define AUX3_Pin 5 // 5Volt - fan or UV LED pin
#define AUX3_Button KEY_O // hold this button and use encoder left/right to adjust PWM output on port
#define AUX3_Button_Mod 0 //set to 'MODIFIERKEY_SHIFT' to a capital letter
#define AUX3_PWM_CHANGE 10 //increase or decrease PWM by this much
#define AUX3_PWM_MAX 255 //max value for pwm ABLSOLUTE MAX 255 !!!!
#define AUX3_PWM_MIN 9  //min value for pwm ABSOLUTE MIN 0 !!!!
#define AUX3_PWM_FREQ 100 //PWM frequency
#define AUX3_ENABLE_FAN_START 0 //0 to disable or 1 to ramp up this port when turned on
#define AUX3_FAN_START_RAMP 100 // PWM value used to get the fan spinning
#define AUX3_EEPROM 2 // EEPROM address



/* 
  #############################
  # Multiplexer Configuration #
  #############################
*/
#define EnableMultiplexer 1 // 1 to use the multiplexer or 0 to use buttons without
#define AnalogLowerLimit 50 // a button is considered pressed when the analog reading drops below this value
#define Multiplexer1 A7     //analog pin to multiplexer
#define Multiplexer2 A9     //analog pin to multiplexer
#define Multiplexer3 A8     //analog pin to multiplexer
#define Multiplexer4 A6     //analog pin to multiplexer
#define MultiplexerP9 0     //4051 pin 9 connected to this Teensy pin (digital)
#define MultiplexerP10 1    //4051 pin 10 connected to this Teensy pin (digital)
#define MultiplexerP11 2    //4051 pin 11 connected to this Teensy pin (digital)


/* 
  ###################
  # Rotary Encoders #
  ###################
*/
#define Encoder1PinA      12         // the pin the encoder is connected to
#define Encoder1ModA      MODIFIERKEY_SHIFT // modifier key to send
#define Encoder1KeyA      KEY_X      // key to send
#define Encoder1PinB      11         // the pin the encoder is connected to
#define Encoder1ModB      MODIFIERKEY_SHIFT // modifier key to send
#define Encoder1KeyB      KEY_Y      // key to send
#define Encoder1PinC      0          // not used when EnableMultiplexer is 1
#define Encoder1KeyC      0          // not used when EnableMultiplexer is 1
#define Encoder1ModC      0          // not used when EnableMultiplexer is 1
#define Encoder1HoldC     0          // not used when EnableMultiplexer is 1

#define Encoder2PinA      9          // the pin the encoder is connected to
#define Encoder2ModA      0          // modifier key to send
#define Encoder2KeyA      KEY_UP     // key to send
#define Encoder2PinB      10         // the pin the encoder is connected to
#define Encoder2ModB      0          // modifier key to send
#define Encoder2KeyB      KEY_DOWN   // key to send
#define Encoder2PinC      0          // not used when EnableMultiplexer is 1
#define Encoder2KeyC      0          // not used when EnableMultiplexer is 1
#define Encoder2ModC      0          // not used when EnableMultiplexer is 1
#define Encoder2HoldC     0          // not used when EnableMultiplexer is 1

#define Encoder3PinA      8          // the pin the encoder is connected to
#define Encoder3ModA      0          // modifier key to send
#define Encoder3KeyA      KEY_RIGHT  // key to send
#define Encoder3PinB      7          // the pin the encoder is connected to
#define Encoder3ModB      0          // modifier key to send
#define Encoder3KeyB      KEY_LEFT   // key to send
#define Encoder3PinC      0          // not used when EnableMultiplexer is 1
#define Encoder3KeyC      0          // not used when EnableMultiplexer is 1
#define Encoder3ModC      0          // not used when EnableMultiplexer is 1
#define Encoder3HoldC     0          // not used when EnableMultiplexer is 1



/* 
  #############################################
  # Buttons - multiplexed and non-multiplexed #
  #############################################
*/
#define Button_1_Key KEY_A              // key to send
#define Button_1_Mod 0                  // modifier key to send
#define Button_1_Hold 0                 // 1 == send key until released, 0 == release after delayBtn
#define Button_1_Pin 0                  // not used when EnableMultiplexer is 1

#define Button_2_Key KEY_B              // key to send
#define Button_2_Mod 0                  // modifier key to send
#define Button_2_Hold 0                 // 1 == send key until released, 0 == release after delayBtn
#define Button_2_Pin 0                  // not used when EnableMultiplexer is 1

#define Button_3_Key KEY_C              // key to send
#define Button_3_Mod 0                  // modifier key to send
#define Button_3_Hold 0                 // 1 == send key until released, 0 == release after delayBtn
#define Button_3_Pin 0                  // not used when EnableMultiplexer is 1

#define Button_4_Key KEY_D              // key to send
#define Button_4_Mod 0                  // modifier key to send
#define Button_4_Hold 0                 // 1 == send key until released, 0 == release after delayBtn
#define Button_4_Pin 0                  // not used when EnableMultiplexer is 1

#define Button_5_Key KEY_E              // key to send
#define Button_5_Mod 0                  // modifier key to send
#define Button_5_Hold 0                 // 1 == send key until released, 0 == release after delayBtn
#define Button_5_Pin 0                  // not used when EnableMultiplexer is 1

#define Button_6_Key KEY_F              // key to send
#define Button_6_Mod 0                  // modifier key to send
#define Button_6_Hold 0                 // 1 == send key until released, 0 == release after delayBtn
#define Button_6_Pin 0                  // not used when EnableMultiplexer is 1

#define Button_7_Key KEY_G              // key to send
#define Button_7_Mod 0                  // modifier key to send
#define Button_7_Hold 0                 // 1 == send key until released, 0 == release after delayBtn
#define Button_7_Pin 0                  // not used when EnableMultiplexer is 1

#define Button_8_Key KEY_H              // key to send
#define Button_8_Mod 0                  // modifier key to send
#define Button_8_Hold 0                 // 1 == send key until released, 0 == release after delayBtn
#define Button_8_Pin 0                  // not used when EnableMultiplexer is 1

#define Button_9_Key KEY_I              // key to send
#define Button_9_Mod 0                  // modifier key to send
#define Button_9_Hold 0                 // 1 == send key until released, 0 == release after delayBtn
#define Button_9_Pin 0                  // not used when EnableMultiplexer is 1

#define Button_10_Key KEY_J             // key to send
#define Button_10_Mod 0                 // modifier key to send
#define Button_10_Hold 0                // 1 == send key until released, 0 == release after delayBtn
#define Button_10_Pin 0                 // not used when EnableMultiplexer is 1

#define Button_11_Key KEY_K             // key to send
#define Button_11_Mod 0                 // modifier key to send
#define Button_11_Hold 0                // 1 == send key until released, 0 == release after delayBtn
#define Button_11_Pin 0                 // not used when EnableMultiplexer is 1

#define Button_12_Key KEY_L             // key to send
#define Button_12_Mod 0                 // modifier key to send
#define Button_12_Hold 0                // 1 == send key until released, 0 == release after delayBtn
#define Button_12_Pin 0                 // not used when EnableMultiplexer is 1

#define Button_13_Key KEY_M             // key to send
#define Button_13_Mod 0                 // modifier key to send
#define Button_13_Hold 0                // 1 == send key until released, 0 == release after delayBtn
#define Button_13_Pin 0                 // not used when EnableMultiplexer is 1

#define Button_14_Key KEY_N             // key to send
#define Button_14_Mod 0                 // modifier key to send
#define Button_14_Hold 0                // 1 == send key until released, 0 == release after delayBtn
#define Button_14_Pin 0                 // not used when EnableMultiplexer is 1

#define Button_15_Key KEY_O             // key to send
#define Button_15_Mod 0                 // modifier key to send
#define Button_15_Hold 0                // 1 == send key until released, 0 == release after delayBtn
#define Button_15_Pin 0                 // not used when EnableMultiplexer is 1

#define Button_16_Key KEY_P             // key to send
#define Button_16_Mod 0                 // modifier key to send
#define Button_16_Hold 0                // 1 == send key until released, 0 == release after delayBtn
#define Button_16_Pin 0                 // not used when EnableMultiplexer is 1


/* 
  ##############################
  # Buttons - multiplexed ONLY #
  ##############################
*/
#define Button_17_Key KEY_A             // key to send
#define Button_17_Mod MODIFIERKEY_SHIFT // modifier key to send
#define Button_17_Hold 0                // 1 == send key until released, 0 == release after delayBtn

#define Button_18_Key KEY_B             // key to send
#define Button_18_Mod MODIFIERKEY_SHIFT // modifier key to send
#define Button_18_Hold 0                // 1 == send key until released, 0 == release after delayBtn

#define Button_19_Key KEY_C             // key to send
#define Button_19_Mod MODIFIERKEY_SHIFT // modifier key to send
#define Button_19_Hold 0                // 1 == send key until released, 0 == release after delayBtn

#define Button_20_Key KEY_D             // key to send
#define Button_20_Mod MODIFIERKEY_SHIFT // modifier key to send
#define Button_20_Hold 0                // 1 == send key until released, 0 == release after delayBtn

#define Button_21_Key KEY_E             // key to send
#define Button_21_Mod MODIFIERKEY_SHIFT // modifier key to send
#define Button_21_Hold 0                // 1 == send key until released, 0 == release after delayBtn

#define Button_22_Mod MODIFIERKEY_SHIFT // modifier key to send
#define Button_22_Hold 0                // 1 == send key until released, 0 == release after delayBtn
#define Button_22_Key KEY_F             // key to send

#define Button_23_Key KEY_G             // key to send
#define Button_23_Mod MODIFIERKEY_SHIFT // modifier key to send
#define Button_23_Hold 0                // 1 == send key until released, 0 == release after delayBtn

#define Button_24_Key KEY_H             // key to send
#define Button_24_Mod MODIFIERKEY_SHIFT // modifier key to send
#define Button_24_Hold 0                // 1 == send key until released, 0 == release after delayBtn

#define Button_25_Key KEY_I             // key to send
#define Button_25_Mod MODIFIERKEY_SHIFT // modifier key to send
#define Button_25_Hold 0                // 1 == send key until released, 0 == release after delayBtn

#define Button_26_Key KEY_J             // key to send
#define Button_26_Mod MODIFIERKEY_SHIFT // modifier key to send
#define Button_26_Hold 0                // 1 == send key until released, 0 == release after delayBtn

#define Button_27_Key KEY_K             // key to send
#define Button_27_Mod MODIFIERKEY_SHIFT // modifier key to send
#define Button_27_Hold 0                // 1 == send key until released, 0 == release after delayBtn

#define Button_28_Key KEY_L             // key to send
#define Button_28_Mod MODIFIERKEY_SHIFT // modifier key to send
#define Button_28_Hold 0                // 1 == send key until released, 0 == release after delayBtn

#define Button_29_Key KEY_M             // key to send
#define Button_29_Mod MODIFIERKEY_SHIFT // modifier key to send
#define Button_29_Hold 0                // 1 == send key until released, 0 == release after delayBtn

#define Button_30_Key KEY_N             // key to send
#define Button_30_Mod MODIFIERKEY_SHIFT // modifier key to send
#define Button_30_Hold 0                // 1 == send key until released, 0 == release after delayBtn

#define Button_31_Key KEY_O             // key to send
#define Button_31_Mod MODIFIERKEY_SHIFT // modifier key to send
#define Button_31_Hold 0                // 1 == send key until released, 0 == release after delayBtn



/* 
 *  debug mode, enable the option below and change the USB type to "serial" 
 *    this will send commands to your serial port instead of typing the keys as a USB keyboard
 *    WARNING! Keys will most likely send their Integer value instead of the actual key!
*/
#define OutputSerial 0 //set to 1 to enable serial output - default: 0
#define DebugOutput 0 //only works when OutputSerial is enabled as well
/* CONFIG END */
