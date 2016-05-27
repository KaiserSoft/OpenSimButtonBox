/* CONFIG START */

#define BootUpDelay 1000 //Delay between power on and "ready", set to 0 (zero) to disable

#define delayEnc 25 //debounce for rotary encoders
#define delayBtn 50 //debounce for push button switches
#define ledPin 13 




/* Top Row - Push Buttons */
#define PButton1Pin 0
#define PButton1Mod 0
#define PButton1Hold 0 //1 == send key until released, 0 == release key right away
#define PButton1Key KEY_I //ignition

#define PButton2Pin 2
#define PButton2Mod 0
#define PButton2Hold 0 //1 == send key until released, 0 == release key right away
#define PButton2Key KEY_5 //"sorry"

#define PButton3Pin 1
#define PButton3Mod 0
#define PButton3Hold 0 //1 == send key until released, 0 == release key right away
#define PButton3Key KEY_6 //"thanks"

#define PButton4Pin 3
#define PButton4Mod 0
#define PButton4Hold 1 //1 == send key until released, 0 == release key right away
#define PButton4Key KEY_ESC

//#define PButton5Pin 10
//#define PButton5Mod 0
//#define PButton5Hold 0 //1 == send key until released, 0 == release key right away
//#define PButton5Key KEY_SPACE





/* Second Row - Toggle Switches (ON)/OFF/(ON) */
#define TSwitch1PinA      23
#define TSwitch1HoldA     0
#define TSwitch1ModA      MODIFIERKEY_SHIFT
#define TSwitch1KeyA      KEY_0
#define TSwitch1PinB      22
#define TSwitch1HoldB     0
#define TSwitch1ModB      MODIFIERKEY_SHIFT
#define TSwitch1KeyB      KEY_9

#define TSwitch2PinA      21
#define TSwitch2HoldA     0
#define TSwitch2ModA      MODIFIERKEY_SHIFT
#define TSwitch2KeyA      KEY_8
#define TSwitch2PinB      20
#define TSwitch2HoldB     0
#define TSwitch2ModB      MODIFIERKEY_SHIFT
#define TSwitch2KeyB      KEY_7

#define TSwitch3PinA      19
#define TSwitch3HoldA     0
#define TSwitch3ModA      MODIFIERKEY_SHIFT
#define TSwitch3KeyA      KEY_6
#define TSwitch3PinB      18
#define TSwitch3HoldB     0
#define TSwitch3ModB      MODIFIERKEY_SHIFT
#define TSwitch3KeyB      KEY_5

#define TSwitch4PinA      17
#define TSwitch4HoldA     0
#define TSwitch4ModA      MODIFIERKEY_SHIFT
#define TSwitch4KeyA      KEY_4
#define TSwitch4PinB      16
#define TSwitch4HoldB     0
#define TSwitch4ModB      MODIFIERKEY_SHIFT
#define TSwitch4KeyB      KEY_5

#define TSwitch5PinA      15
#define TSwitch5ModA      0
#define TSwitch5HoldA     0
#define TSwitch5KeyA      KEY_SPACE
#define TSwitch5PinB      14
#define TSwitch5HoldB     0
#define TSwitch5ModB      MODIFIERKEY_SHIFT
#define TSwitch5KeyB      KEY_A




/* Third Row - Rotary Encoders */
#define Encoder1PinA      7          //turn
#define Encoder1ModA      0          //turn
#define Encoder1KeyA      KEY_O      //turn
#define Encoder1PinB      8          //turn
#define Encoder1ModB      0          //turn
#define Encoder1KeyB      KEY_P      //turn
#define Encoder1PinC      5          //button push
#define Encoder1ModC      0          //button push
#define Encoder1KeyC      KEY_F3     //button push

#define Encoder2PinA      10            //turn
#define Encoder2ModA      0            //turn
#define Encoder2KeyA      KEY_UP       //turn
#define Encoder2PinB      9            //turn
#define Encoder2ModB      0            //turn
#define Encoder2KeyB      KEY_DOWN      //turn
#define Encoder2PinC      6            //button push
#define Encoder2ModC      0            //button push
#define Encoder2KeyC      KEY_SPACE       //button push

#define Encoder3PinA      12            //turn
#define Encoder3ModA      0            //turn
#define Encoder3KeyA      KEY_LEFT       //turn
#define Encoder3PinB      11            //turn
#define Encoder3ModB      0            //turn
#define Encoder3KeyB      KEY_RIGHT      //turn
#define Encoder3PinC      4            //button push
#define Encoder3ModC      0            //button push
#define Encoder3KeyC      KEY_SPACE       //button push




/* 
 *  debug mode, enable the option below and change the USB type to "serial" 
 *    this will send commands to your serial port instead of typing the keys as a USB keyboard
 *    WARNING! Keys will most likely send their Integer value instead of the actual key!
*/
//#define OutputSerial 1 //enable this to have values printed to serial port instead of keyboard inputs

/* CONFIG END */
