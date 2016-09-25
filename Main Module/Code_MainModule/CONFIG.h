/* CONFIG START */

#define BootUpDelay 1000 //Delay between power on and "ready", set to 0 (zero) to disable

#define delayEnc 75 //debounce for rotary encoders
#define delayBtn 75 //debounce for push button switches
#define ledPin 13 


/* multi plexer setup */
#define UseMultiplexer 1 // 1 to use the multiplexer or 0 to use buttons without 
#define Multiplexer1 A7 //analog pin to multiplexer
#define Multiplexer2 A9 //analog pin to multiplexer
#define Multiplexer3 A8 //analog pin to multiplexer
#define Multiplexer4 A6 //analog pin to multiplexer
#define MultiplexerP9 0 //4051 pin 9 connected to this Teensy pin (digital)
#define MultiplexerP10 1 //4051 pin 10 connected to this Teensy pin (digital)
#define MultiplexerP11 2 //4051 pin 11 connected to this Teensy pin (digital)



/* Button Configuration - multiplexed and non-multiplexed */
#define Button_1_Mod 0 //modifier key
#define Button_1_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_1_Key KEY_A // Keyboad key
#define Button_1_Pin 0//not used when UseMultiplexer is 1

#define Button_2_Mod 0 //modifier key
#define Button_2_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_2_Key KEY_B // Keyboad key
#define Button_2_Pin 0//not used when UseMultiplexer is 1

#define Button_3_Mod 0 //modifier key
#define Button_3_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_3_Key KEY_C // Keyboad key
#define Button_3_Pin 0//not used when UseMultiplexer is 1

#define Button_4_Mod 0 //modifier key
#define Button_4_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_4_Key KEY_D // Keyboad key
#define Button_4_Pin 0//not used when UseMultiplexer is 1

#define Button_5_Mod 0 //modifier key
#define Button_5_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_5_Key KEY_E // Keyboad key
#define Button_5_Pin 0//not used when UseMultiplexer is 1

#define Button_6_Mod 0 //modifier key
#define Button_6_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_6_Key KEY_F // Keyboad key
#define Button_6_Pin 0//not used when UseMultiplexer is 1

#define Button_7_Mod 0 //modifier key
#define Button_7_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_7_Key KEY_G // Keyboad key
#define Button_7_Pin 0//not used when UseMultiplexer is 1

#define Button_8_Mod 0 //modifier key
#define Button_8_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_8_Key KEY_H // Keyboad key
#define Button_8_Pin 0//not used when UseMultiplexer is 1

#define Button_9_Mod 0 //modifier key
#define Button_9_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_9_Key KEY_I // Keyboad key
#define Button_9_Pin 0//not used when UseMultiplexer is 1

#define Button_10_Mod 0 //modifier key
#define Button_10_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_10_Key KEY_J // Keyboad key
#define Button_10_Pin 0//not used when UseMultiplexer is 1

#define Button_11_Mod 0 //modifier key
#define Button_11_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_11_Key KEY_K // Keyboad key
#define Button_11_Pin 0//not used when UseMultiplexer is 1

#define Button_12_Mod 0 //modifier key
#define Button_12_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_12_Key KEY_L // Keyboad key
#define Button_12_Pin 0//not used when UseMultiplexer is 1

#define Button_13_Mod 0 //modifier key
#define Button_13_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_13_Key KEY_M // Keyboad key
#define Button_13_Pin 0//not used when UseMultiplexer is 1

#define Button_14_Mod 0 //modifier key
#define Button_14_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_14_Key KEY_N // Keyboad key
#define Button_14_Pin 0//not used when UseMultiplexer is 1

#define Button_15_Mod 0 //modifier key
#define Button_15_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_15_Key KEY_O // Keyboad key
#define Button_15_Pin 0//not used when UseMultiplexer is 1

#define Button_16_Mod 0 //modifier key
#define Button_16_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_16_Key KEY_P // Keyboad key
#define Button_16_Pin 0//not used when UseMultiplexer is 1


/* Button Configuration - multiplexed only */
/* !!! moar buttons !!!! */
#define Button_17_Mod MODIFIERKEY_SHIFT //modifier key
#define Button_17_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_17_Key KEY_A // Keyboad key

#define Button_18_Mod MODIFIERKEY_SHIFT //modifier key
#define Button_18_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_18_Key KEY_B // Keyboad key

#define Button_19_Mod MODIFIERKEY_SHIFT //modifier key
#define Button_19_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_19_Key KEY_C // Keyboad key

#define Button_20_Mod MODIFIERKEY_SHIFT //modifier key
#define Button_20_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_20_Key KEY_D // Keyboad key

#define Button_21_Mod MODIFIERKEY_SHIFT //modifier key
#define Button_21_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_21_Key KEY_E // Keyboad key

#define Button_22_Mod MODIFIERKEY_SHIFT //modifier key
#define Button_22_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_22_Key KEY_F // Keyboad key

#define Button_23_Mod MODIFIERKEY_SHIFT //modifier key
#define Button_23_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_23_Key KEY_G // Keyboad key

#define Button_24_Mod MODIFIERKEY_SHIFT //modifier key
#define Button_24_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_24_Key KEY_H // Keyboad key

#define Button_25_Mod MODIFIERKEY_SHIFT //modifier key
#define Button_25_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_25_Key KEY_I // Keyboad key

#define Button_26_Mod MODIFIERKEY_SHIFT //modifier key
#define Button_26_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_26_Key KEY_J // Keyboad key

#define Button_27_Mod MODIFIERKEY_SHIFT //modifier key
#define Button_27_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_27_Key KEY_K // Keyboad key

#define Button_28_Mod MODIFIERKEY_SHIFT //modifier key
#define Button_28_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_28_Key KEY_L // Keyboad key

#define Button_29_Mod MODIFIERKEY_SHIFT //modifier key
#define Button_29_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_29_Key KEY_M // Keyboad key

#define Button_30_Mod MODIFIERKEY_SHIFT //modifier key
#define Button_30_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_30_Key KEY_N // Keyboad key

#define Button_31_Mod MODIFIERKEY_SHIFT //modifier key
#define Button_31_Hold 0 // 1 == send key until released, 0 == release after delayBtn
#define Button_31_Key KEY_O // Keyboad key




/* Third Row - Rotary Encoders */
#define Encoder1PinA      7          //turn
#define Encoder1ModA      0          //turn
#define Encoder1KeyA      KEY_O      //turn
#define Encoder1PinB      8          //turn
#define Encoder1ModB      0          //turn
#define Encoder1KeyB      KEY_P      //turn
#define Encoder1PinC      5          //button push - not used when UseMultiplexer is 1
#define Encoder1ModC      0          //button push - not used when UseMultiplexer is 1
#define Encoder1KeyC      KEY_F3     //button push - not used when UseMultiplexer is 1

#define Encoder2PinA      10            //turn
#define Encoder2ModA      0            //turn
#define Encoder2KeyA      KEY_UP       //turn
#define Encoder2PinB      9            //turn
#define Encoder2ModB      0            //turn
#define Encoder2KeyB      KEY_DOWN      //turn
#define Encoder2PinC      6            //button push - not used when UseMultiplexer is 1
#define Encoder2ModC      0            //button push - not used when UseMultiplexer is 1
#define Encoder2KeyC      KEY_SPACE       //button push - not used when UseMultiplexer is 1

#define Encoder3PinA      12            //turn
#define Encoder3ModA      0            //turn
#define Encoder3KeyA      KEY_LEFT       //turn
#define Encoder3PinB      11            //turn
#define Encoder3ModB      0            //turn
#define Encoder3KeyB      KEY_RIGHT      //turn
#define Encoder3PinC      4            //button push - not used when UseMultiplexer is 1
#define Encoder3ModC      0            //button push - not used when UseMultiplexer is 1
#define Encoder3KeyC      KEY_SPACE       //button push - not used when UseMultiplexer is 1




/* 
 *  debug mode, enable the option below and change the USB type to "serial" 
 *    this will send commands to your serial port instead of typing the keys as a USB keyboard
 *    WARNING! Keys will most likely send their Integer value instead of the actual key!
*/
//#define OutputSerial 1 //enable this to have values printed to serial port instead of keyboard inputs
#define DebugOutput 0 //only works when OutputSerial is enabled as well
/* CONFIG END */
