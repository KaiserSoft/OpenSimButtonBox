/*
 * Stand Alone Wheel Button Box for the Arduino Pro Micro
 * The buttons for the wheel button box may be connected to the MOBB-PCB or to an
 * Arduino Pro Micro using this code
 * 
 * 
 * Required Libraries
 * https://github.com/MHeironimus/ArduinoJoystickLibrary
*/

/* developemnt stuff - remove when done */
#define debug_delay  2000
unsigned long debug_last = 0;
#define testing_oled false
/* developemnt stuff - remove when done */


#include "CONFIG.h"
#include "Bounce2.h" 
#include <EEPROM.h>
#if CONTROLLER_OUTPUT_MODE == 1
  #include <Keyboard.h>
#else
  #include <Keyboard.h> //needed for defines in config.h
  #include "DynamicHID.h"
  #include "Joystick.h"
  Joystick_ Joystick;
#endif

#if EncoderEnabled == true
  #include <Encoder.h>
#endif

#if testing_oled == true
  #include <SPI.h>
  #include <Wire.h>
  #include <Adafruit_GFX.h>
  #include <Adafruit_SSD1306.h>
  
  #define LOGO16_GLCD_HEIGHT 16 
  #define LOGO16_GLCD_WIDTH  16 
  #define OLED_RESET 4
  Adafruit_SSD1306 display(OLED_RESET);
#endif


/*keep times of button presses */
unsigned long ButtonPressed[13]; //stores the time when the key press has been detected
unsigned long ButtonSend[13];    //stores last time the key has been sent to the computer
unsigned long JoystickMoved[2];  //stores the time when a joystick move has been detected
unsigned long JoystickSend[2];   //stores last time the key has been sent to the computer
byte ShifterSend[2];   //stores a 1 if the key is currently being pressed

/* setup debounce library for all push buttons*/
Bounce Buttons[14] = {
  Bounce(Button_1_Pin, BUTTON_DEBOUNCE),
  Bounce(Button_2_Pin, BUTTON_DEBOUNCE),
  Bounce(Button_3_Pin, BUTTON_DEBOUNCE),
  Bounce(Button_4_Pin, BUTTON_DEBOUNCE),
  Bounce(Button_5_Pin, BUTTON_DEBOUNCE),
  Bounce(Button_6_Pin, BUTTON_DEBOUNCE),
  Bounce(Button_7_Pin, BUTTON_DEBOUNCE),
  Bounce(Button_8_Pin, BUTTON_DEBOUNCE),
  Bounce(Button_9_Pin, BUTTON_DEBOUNCE),
  Bounce(Button_10_Pin, BUTTON_DEBOUNCE),
  Bounce(Button_11_Pin, BUTTON_DEBOUNCE),
  Bounce(Button_12_Pin, BUTTON_DEBOUNCE),
  Bounce(Shifter_1_Pin, BUTTON_DEBOUNCE),
  Bounce(Shifter_2_Pin, BUTTON_DEBOUNCE)
};

/* setup array to make processing buttons simpler */
byte ButtonPins[14] = { Button_1_Pin, Button_2_Pin, Button_3_Pin, Button_4_Pin,
                        Button_5_Pin, Button_6_Pin, Button_7_Pin, Button_8_Pin,
                        Button_9_Pin, Button_10_Pin, Button_11_Pin, Button_12_Pin, 
                        Shifter_1_Pin, Shifter_2_Pin };
char ButtonKeys[14][1] = { Button_1_Key, Button_2_Key, Button_3_Key, Button_4_Key,
                        Button_5_Key, Button_6_Key, Button_7_Key, Button_8_Key,
                        Button_9_Key, Button_10_Key, Button_11_Key, Button_12_Key, 
                        Shifter_1_Key, Shifter_2_Key };
char ButtonMods[14][1] = { Button_1_Mod, Button_2_Mod, Button_3_Mod, Button_4_Mod,
                        Button_5_Mod, Button_6_Mod, Button_7_Mod, Button_8_Mod,
                        Button_9_Mod, Button_10_Mod, Button_11_Mod, Button_12_Mod, 
                        Shifter_1_Mod, Shifter_2_Mod };
byte ButtonJoy[14][1] = { Button_1_Joy, Button_2_Joy, Button_3_Joy, Button_4_Joy,
                        Button_5_Joy, Button_6_Joy, Button_7_Joy, Button_8_Joy,
                        Button_9_Joy, Button_10_Joy, Button_11_Joy, Button_12_Joy, 
                        Shifter_1_Joy, Shifter_2_Joy };

/* setup array for joystick to make it simpler to read it */
byte JoystickPins[2] = { Joystick_1_Pin, Joystick_2_Pin };
char JoystickKeys[2][2][1] = { { Joystick_1_KeyA, Joystick_1_KeyB }, { Joystick_2_KeyA, Joystick_2_KeyB } };
char JoystickMods[2][2][1] = { { Joystick_1_ModA, Joystick_1_ModB }, { Joystick_2_ModA, Joystick_2_ModB } };
byte JoystickJoys[2][2][1] = { { Joystick_1_JoyA, Joystick_1_JoyB }, { Joystick_2_JoyA, Joystick_2_JoyB } };

int  JoyStickCenters[2] = { Joystick_1_Center, Joystick_2_Center };
int  JoyStickMoveMin[2] = { Joystick_1_Move_Min, Joystick_2_Move_Min };
byte  JoyStickDirection[2] = { 0, 0 }; // 0 center, 1=direction 1 2=direction 2
byte JoyStickMoved = 0; // lockup other axis when joystick is moved. Only allows move left/right or up/down but not at the same time. 0 = no move, 1= joystick direction 1, 2= joy direction 2


#if EncoderEnabled == true
/* rotary encoder */
byte EncoderPins[2] = { Encoder_A_Pin, Encoder_B_Pin };
char EncoderKeys[2][1] = { Encoder_A_Key, Encoder_B_Key };
char EncoderMods[2][1] = { Encoder_A_Mod, Encoder_B_Mod };
byte EncoderJoys[2][1] = { Encoder_A_Joy, Encoder_B_Joy };
#endif

/* serial receive stuff */
#if DebugSerialOut == true
  boolean serial_done = false;
  String serial_cmd;  // holds the received command
#endif

#if EncoderEnabled == true
  Encoder EncoderKnob(Encoder_A_Pin, Encoder_B_Pin);
  long positionEnc  = 0;
  long sendKeyStart[2] = { 0, 0 }; // holds time for automatic key press
#endif



void setup() {
  
  
  for( byte x=0 ; x < sizeof(ButtonPins)/sizeof(byte) ; ++x ){
    pinMode( ButtonPins[x], INPUT_PULLUP);
    ButtonPressed[x] = 0;
    ButtonSend[x] = 0;
  }
  for( byte x=0 ; x < sizeof(JoystickPins)/sizeof(byte) ; ++x ){
    pinMode( JoystickPins[x], INPUT);
    JoystickMoved[x] = 0;
    JoystickSend[x] = 0;
  }

  #if testing_oled == true
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  #endif

  #if DebugSerialOut == true
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
    delay(50);
  }
  Serial.println("ready");
  delay(4000);
  #endif

  #if KeyboardEnabled == true
    #if CONTROLLER_OUTPUT_MODE == 1
      Keyboard.begin();
    #else
      Keyboard.begin();
      Joystick.begin();
    #endif
  #endif
}


void loop() {
  #if DebugSerialOut == true
    if (serial_done == true){
        //maybe add config options later so the unit may be configured without compiling the code again
        serial_done = false;
        serial_cmd = "";
    }
  #endif


 check_buttons();
 
 #if AnalogJoystickEnabled == true
  check_joystick();
 #endif
 
 #if EncoderEnabled == true
  check_rotary_encoders();
 #endif

 #if ShifterType == 2
  check_shifter_halleffect();
 #endif

}


/* does the actual key pessing */
void sendKey( char Key, char Mod, char Joy){

  #if KeyboardEnabled == true
    #if CONTROLLER_OUTPUT_MODE == 1 || CONTROLLER_OUTPUT_MODE == 2
      if( Key != false ){
        Keyboard.press(Mod);
        Keyboard.press(Key);
      }
    #endif

    #if CONTROLLER_OUTPUT_MODE == 2
      if( Key == false ){
        Joystick.setButton(Joy, 1);
      }
    #endif
  #endif
  
  #if DebugSendKey == true
    if( Key != false ){
      Serial.print("sendKey key:");
      Serial.print(Key);
      Serial.print(" mod:");
      Serial.println(Mod);
    }else{
      Serial.print("joystick output HIGH btn:");
      Serial.println(Joy);
    }
  #endif
}

/* release the pressed key */
void releaseKey( char Key, char Mod, char Joy ){

  #if KeyboardEnabled == true
    #if CONTROLLER_OUTPUT_MODE == 1 || CONTROLLER_OUTPUT_MODE == 2
      if( Key != false ){
        Keyboard.release(Mod);
        Keyboard.release(Key);
      }
    #endif

    #if CONTROLLER_OUTPUT_MODE == 2
      if( Key == false ){
        Joystick.setButton(Joy, 0);
      }
    #endif
  #endif

  #if DebugSendKey == true
    if( Key != false ){
      Serial.print("releaseKey key:");
      Serial.print(Key);
      Serial.print(" mod:");
      Serial.println(Mod);
    }else{
      Serial.print("joystick output LOW btn:");
      Serial.println(Joy);
    }
  #endif
}

#if ShifterType == 2
/* checks if a shift is happening */
void check_shifter_halleffect(){

  int raw = analogRead(Shifter_1_Pin);
  if( raw > HallEffectShiftPoint ){
    if( ShifterSend[0] == 0 ){
      ShifterSend[0] = 1;
      sendKey( Shifter_1_Key, Shifter_1_Mod, Shifter_1_Joy );
    }
  }else{
    if( ShifterSend[0] == 1 ){
      ShifterSend[0] = 0;
      releaseKey( Shifter_1_Key, Shifter_1_Mod, Shifter_1_Joy );
    }
  }
  
  raw = analogRead(Shifter_2_Pin);
  if( raw > HallEffectShiftPoint ){
    if( ShifterSend[1] == 0 ){
      ShifterSend[1] = 1;
      sendKey( Shifter_2_Key, Shifter_2_Mod, Shifter_2_Joy );
    }
  }else{
    if( ShifterSend[1] == 1 ){
      ShifterSend[1] = 0;
      releaseKey( Shifter_2_Key, Shifter_2_Mod, Shifter_2_Joy );
    }
  }
}
#endif

#if AnalogJoystickEnabled == true
/* checks if the joystick has been moved */
void check_joystick(){
  int joyval = 0;


  for( byte x = 0 ; x < sizeof(JoystickPins)/sizeof(byte) ; x++ ){
    joyval = analogRead(JoystickPins[x]);


    #if DebugJoysticksGetValues == true
      Serial.print("check_joystick() pin:");
      Serial.print(JoystickPins[x]);
      Serial.print(" value:");
      Serial.println(joyval);
    #endif
    

    #if JoysticksGetValues == false
      if( joyval > (JoyStickCenters[x] + JoyStickMoveMin[x]) ){
        JoystickSend[x] = millis();
        JoystickMoved[x] = millis();
        JoyStickDirection[x] = 1;
        #if DebugSerialOut == true
          Serial.print("check_joystick() x:");
          Serial.print(x);
          Serial.print(" pin:");
          Serial.print(JoystickPins[x]);
          Serial.print(" value:");
          Serial.println(joyval);
        #endif
        if( JoyStickMoved == 0 || JoyStickMoved == x ){
          JoyStickMoved = x;
          sendKey( JoystickKeys[x][0][0], JoystickMods[x][0][0], JoystickJoys[x][1][0] );
        }
        return;
        
      }else if( joyval < (JoyStickCenters[x] - JoyStickMoveMin[x]) ){
        JoystickSend[x] = millis();
        JoystickMoved[x] = millis();
        JoyStickDirection[x] = 2;
        #if DebugSerialOut == true
          Serial.print("check_joystick() x:");
          Serial.print(x);
          Serial.print(" pin:");
          Serial.print(JoystickPins[x]);
          Serial.print(" value:");
          Serial.println(joyval);
        #endif
        if( JoyStickMoved == 0 || JoyStickMoved == x ){
          JoyStickMoved = x;
          sendKey( JoystickKeys[x][1][0], JoystickMods[x][1][0], JoystickJoys[x][1][0] );
        }
        return;
        
      }else{
        if( JoystickSend[x] > 0 ){
          
          if( JoyStickDirection[x] == 1 ){
            releaseKey( JoystickKeys[x][0][0], JoystickMods[x][0][0], JoystickJoys[x][1][0] );
            JoyStickDirection[x] = 0;
            JoystickSend[x] = 0;
            JoyStickMoved = 0;
            
          }else if( JoyStickDirection[x] == 2 ){
            releaseKey( JoystickKeys[x][1][0], JoystickMods[x][1][0], JoystickJoys[x][1][0] );
            JoyStickDirection[x] = 0;
            JoystickSend[x] = 0;            
            JoyStickMoved = 0;
          }
          
        }
      }
    #endif
  }//for
}
#endif



/* checks all buttons and sends key when one has been pressed */
void check_buttons(){
  for( byte x=0 ; x < sizeof(ButtonPins)/sizeof(byte) ; ++x ){
    if( Buttons[x].update() ) {

      //pressed
      if( Buttons[x].fallingEdge() ) {
        ButtonPressed[x] = millis();
        ButtonSend[x] = millis();
        sendKey( ButtonKeys[x][0], ButtonMods[x][0], ButtonJoy[x][0] );

       // released
      }else{
        ButtonSend[x] = 0;
        ButtonPressed[x] = 0;
        releaseKey( ButtonKeys[x][0], ButtonMods[x][0], ButtonJoy[x][0] );
      }
    }
  }
}


#if EncoderEnabled == true
/* check rotary encourders */
void check_rotary_encoders(){  
  long newEncPos = -999;

  for( byte x = 0 ; x < 2 ; x++ ){
    if( sendKeyStart[x] > 0 && sendKeyStart[x] < millis() - 25 )
    {
      sendKeyStart[x] = 0;
      releaseKey( EncoderKeys[x][0], EncoderMods[x][0], EncoderJoys[x][0] );
    }
  }
    
  newEncPos = EncoderKnob.read()/4;
  if (newEncPos != positionEnc ){

      if( newEncPos > positionEnc ){
        #if DebugSerialOut == true
          Serial.println("EncLeft:left / check_rotary_encoders()");
        #endif
        sendKeyStart[0] = millis();
        sendKey( EncoderKeys[0][0], EncoderMods[0][0], EncoderJoys[0][0] );
        
      }else if( newEncPos < positionEnc ){
        #if DebugSerialOut == true
          Serial.println("EncLeft:right / check_rotary_encoders()");
        #endif
        sendKeyStart[1] = millis();
        sendKey( EncoderKeys[1][0], EncoderMods[1][0], EncoderJoys[1][0] );
      }
      positionEnc = newEncPos;
  }
}
#endif


/*
  SerialEvent occurs whenever a new data comes in the
  hardware serial RX.  This routine is run between each
  time loop() runs, so using delay inside loop can delay
  response.  Multiple bytes of data may be available.
 */
#if DebugSerialOut == true
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();

    if (inChar == '\n' || inChar == '\r' ) {
      serial_done = true;
    }else{
      serial_cmd += inChar;
    }
  }
}
#endif
