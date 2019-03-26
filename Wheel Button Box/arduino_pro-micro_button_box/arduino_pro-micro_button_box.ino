/*
 * Firmware for an Arduino Pro Micro to run sim racing steering wheels or button boxes.
 * Source: https://github.com/KaiserSoft/simwheel-firmware-arduino-pro-micro
 * Wiki: https://github.com/KaiserSoft/simwheel-firmware-arduino-pro-micro/wiki
 * Copyright 2019 Mirko Kaiser
 * License: MIT License
 * 
 * 
 * Required Libraries
 * Arduino Board Manager: https://raw.githubusercontent.com/sparkfun/Arduino_Boards/master/IDE_Board_Manager/package_sparkfun_index.json
 * https://github.com/MHeironimus/ArduinoJoystickLibrary
*/

/* developemnt stuff - remove when done */
#define testing_oled false
/* developemnt stuff - remove when done */


#include "CONFIG.h"
#include "Bounce2.h" 
#include <EEPROM.h>
#if CONTROLLER_OUTPUT_MODE == 1
  #include <Keyboard.h>
#else
  #include <Keyboard.h>
  #include "DynamicHID.h"
  #include "Joystick.h"
  Joystick_ Joystick;
#endif

#if CONTROLLER_ENCODER_ENABLED == true
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


/* reads an int back from EEPROM */
int eepromReadInt(int adr) {
  byte low, high;
  low=EEPROM.read(adr);
  high=EEPROM.read(adr+1);
  return low + ((high << 8)&0xFF00);
}

/*keep times of button presses */
unsigned long ButtonPressed[13]; //stores the time when the key press has been detected
unsigned long ButtonSend[13];    //stores last time the key has been sent to the computer
byte ShifterSend[2];   //stores a 1 if the key is currently being pressed

/* setup debounce library for all push buttons*/
Bounce Buttons[15] = {
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
  Bounce(Button_13_Pin, BUTTON_DEBOUNCE),
  Bounce(Shifter_1_Pin, BUTTON_DEBOUNCE),
  Bounce(Shifter_2_Pin, BUTTON_DEBOUNCE)
};

/* setup array to make processing buttons simpler */
byte ButtonPins[15] = { Button_1_Pin, Button_2_Pin, Button_3_Pin, Button_4_Pin,
                        Button_5_Pin, Button_6_Pin, Button_7_Pin, Button_8_Pin,
                        Button_9_Pin, Button_10_Pin, Button_11_Pin, Button_12_Pin, 
                        Button_13_Pin, Shifter_1_Pin, Shifter_2_Pin };
char ButtonKeys[15][1] = { Button_1_Key, Button_2_Key, Button_3_Key, Button_4_Key,
                        Button_5_Key, Button_6_Key, Button_7_Key, Button_8_Key,
                        Button_9_Key, Button_10_Key, Button_11_Key, Button_12_Key, 
                        Button_13_Key, Shifter_1_Key, Shifter_2_Key };
char ButtonMods[15][1] = { Button_1_Mod, Button_2_Mod, Button_3_Mod, Button_4_Mod,
                        Button_5_Mod, Button_6_Mod, Button_7_Mod, Button_8_Mod,
                        Button_9_Mod, Button_10_Mod, Button_11_Mod, Button_12_Mod, 
                        Button_13_Mod, Shifter_1_Mod, Shifter_2_Mod };
byte ButtonJoy[15][1] = { Button_1_Joy, Button_2_Joy, Button_3_Joy, Button_4_Joy,
                        Button_5_Joy, Button_6_Joy, Button_7_Joy, Button_8_Joy,
                        Button_9_Joy, Button_10_Joy, Button_11_Joy, Button_12_Joy, 
                        Button_13_Joy, Shifter_1_Joy, Shifter_2_Joy };

/* setup array for joystick to make it simpler to read it */
#if CONTROLLER_JOYSTICK_ENABLED == true
byte JoystickPins[2] = { Joystick_1_Pin, Joystick_2_Pin };
char JoystickKeys[2][2][1] = { { Joystick_1_KeyA, Joystick_1_KeyB }, { Joystick_2_KeyA, Joystick_2_KeyB } };
char JoystickMods[2][2][1] = { { Joystick_1_ModA, Joystick_1_ModB }, { Joystick_2_ModA, Joystick_2_ModB } };
byte JoystickJoys[2][2][1] = { { Joystick_1_JoyA, Joystick_1_JoyB }, { Joystick_2_JoyA, Joystick_2_JoyB } };

int  JoyStickCenters[2] = { Joystick_1_Center, Joystick_2_Center };
int  JoyStickMoveMin[2] = { Joystick_1_Move_Min, Joystick_2_Move_Min };
byte JoyStickDirection[2] = { 0, 0 }; // 0 center, 1=direction 1 2=direction 2
byte JoyStickMoved = 0; // lockup other axis when joystick is moved. Only allows move left/right or up/down but not at the same time. 0 = no move, 1= joystick direction 1, 2= joy direction 2

unsigned long JoystickMoved[2];  //stores the time when a joystick move has been detected
unsigned long JoystickSend[2];   //stores last time the key has been sent to the computer
#endif

#if CONTROLLER_ENCODER_ENABLED == true
  /* rotary encoder */
  byte EncoderPins[2] = { Encoder_A_Pin, Encoder_B_Pin };
  char EncoderKeys[2][1] = { Encoder_A_Key, Encoder_B_Key };
  char EncoderMods[2][1] = { Encoder_A_Mod, Encoder_B_Mod };
  byte EncoderJoys[2][1] = { Encoder_A_Joy, Encoder_B_Joy };
#endif

#if CONTROLLER_SHIFTER_TYPE == 2
  #define HES_CALIBRATION_DELAY 5000 // hold shifter for this long to enter calibration mode
  unsigned long HESCalibrationStart[2] = { 0, 0 }; //time of initial button press
  unsigned int HESshiftPoint_1 = eepromReadInt(EEPROM_HES_1); // default shift value before calibration
  unsigned int HESshiftPoint_2 = eepromReadInt(EEPROM_HES_2); // default shift value before calibration
#endif

#if CONTROLLER_CLUTCH_ENABLED == true
  #define CLUTCH_CALIBRATION_DELAY 5000
  #define CLUTCH_UPDATE_DELAY 25 // send joystick axis position only every this many ms
  unsigned long ClutchCalibrationStart = 0;
  unsigned long ClutchUpdateLaste = 0;
  unsigned int ClutchLow = eepromReadInt(EEPROM_CLL_1);
  unsigned int ClutchHigh = eepromReadInt(EEPROM_CLH_1);
  unsigned int ClutchLastValue = 0 ; // Last value of clutch, only send position update if this changes
#endif

/* serial receive stuff */
#if DebugSerialOut == true
  unsigned long DebugSerialHallEffectLast = 0; // time for debug message
  boolean DebugSerialHallEffectLastNow = false;
  unsigned long DebugJoysticksGetValuesLast = 0; // time for debug message
  unsigned long DebugSerialClutchLast = 0; // time for debug message
#endif

#if CONTROLLER_ENCODER_ENABLED == true
  Encoder EncoderKnob(Encoder_A_Pin, Encoder_B_Pin);
  long positionEnc  = 0;
  unsigned long sendKeyStart[2] = { 0, 0 }; // holds time for automatic key press
#endif

unsigned long EEPROM_check_last = 0; //last time EEPROM values where checked for change
unsigned long EEPROM_val_change_last = 0; //last time any EEPROM stored value has changed




void setup() {

  // sane values for shifters
  #if CONTROLLER_SHIFTER_TYPE == 2
    if( HESshiftPoint_1 > 1024 ){ HESshiftPoint_1 = Shifter_1_ShiftPoint_Default; }
    if( HESshiftPoint_2 > 1024 ){ HESshiftPoint_2 = Shifter_2_ShiftPoint_Default; }
  #endif


  #if CONTROLLER_OUTPUT_MODE == 2
    Joystick.setXAxis(0);
    Joystick.setYAxis(512);
  #endif
  
  for( byte x=0 ; x < sizeof(ButtonPins)/sizeof(byte) ; ++x ){
    pinMode( ButtonPins[x], INPUT_PULLUP);
    ButtonPressed[x] = 0;
    ButtonSend[x] = 0;
  }
  
  #if CONTROLLER_JOYSTICK_ENABLED == true
    for( byte x=0 ; x < sizeof(JoystickPins)/sizeof(byte) ; ++x ){
      pinMode( JoystickPins[x], INPUT);
      JoystickMoved[x] = 0;
      JoystickSend[x] = 0;
    }
  #endif

  #if testing_oled == true
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  #endif

  //initial setup Stuff
  #if DebugSerialOut == true && DebugForceShiftPoint > 0
    HESshiftPoint_1 = DebugForceShiftPoint;
    HESshiftPoint_2 = DebugForceShiftPoint;
  #endif
  #if DebugSerialOut == true && DebugForceClutchPointLow > 0 && DebugForceClutchPointHigh > 0
    ClutchLow = DebugForceClutchPointLow;
    ClutchHigh = DebugForceClutchPointHigh;
  #endif

  #if DebugSerialOut == true
    Serial.begin(115200);
    while (!Serial) {
      // wait for serial port to connect. Needed for native USB port only
      delay(50);
    }
    Serial.println("Loaded from EEPROM");
    Serial.print("Shift1:");Serial.print(HESshiftPoint_1);
    Serial.print(" / Shift2:");Serial.print(HESshiftPoint_2);
    Serial.print(" / Clutch:");Serial.print(ClutchLow);Serial.print("/");Serial.println(ClutchHigh);
  #endif

  #if CONTROLLER_OUTPUT_ENABLED == true
    #if CONTROLLER_OUTPUT_MODE == 1
      Keyboard.begin();
    #else
      Keyboard.begin();
      Joystick.begin();
    #endif
  #endif
}


void loop() {
 check_buttons();
 
 #if CONTROLLER_JOYSTICK_ENABLED == true
  check_joystick();
 #endif
 
 #if CONTROLLER_ENCODER_ENABLED == true
  check_rotary_encoders();
 #endif

 #if CONTROLLER_SHIFTER_TYPE == 2
  check_shifter_halleffect();
 #endif

 #if CONTROLLER_CLUTCH_ENABLED == true
  check_clutch();
 #endif
}


/* does the actual key pessing */
void sendKey( char Key, char Mod, char Joy){

  #if CONTROLLER_OUTPUT_ENABLED == true
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

  #if CONTROLLER_OUTPUT_ENABLED == true
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


#if CONTROLLER_CLUTCH_ENABLED == true
/* do the clutch */
void check_clutch(){
  // don't flood USB with position updates
  if( CLUTCH_UPDATE_DELAY > millis()-ClutchUpdateLaste ) { return; }

  int joy=0,raw = analogRead(Clutch_1_Pin);
  joy = map(raw, (ClutchLow-ClutchCalibrationAdjust), (ClutchHigh+ClutchCalibrationAdjust), 0, 1024);
  if( joy > 1024 ){ joy = 1024; }
  
  if( raw > ClutchLow ){
    if( ClutchCalibrationStart == 0 ){ ClutchCalibrationStart = millis(); }

    if( ClutchLastValue != joy ){
      
      #if CONTROLLER_OUTPUT_ENABLED == true
        Joystick.setXAxis(joy);
      #endif
      ClutchLastValue = joy;
      ClutchUpdateLaste = millis();

      #if DebugSerialOut == true && DebugSendKey == true 
        Serial.print("Clutch X Axis: "); Serial.println(joy);
      #endif
    }
    
  }else{
    ClutchCalibrationStart == 0;
    if( ClutchLastValue != 0 ){
      #if CONTROLLER_OUTPUT_ENABLED == true
        Joystick.setXAxis(0);
      #endif
      ClutchLastValue = 0;
      
      #if DebugSerialOut == true && DebugSendKey == true 
        Serial.print("Clutch X Axis: "); Serial.println(0);
      #endif
    }
  }
    
  #if DebugSerialOut == true && DebugClutchGetValues == true
    if( millis() - DebugSerialClutchLast > 1500 ){
      Serial.print(millis());
      Serial.print(" - Clutch val:");
      Serial.println(raw);
      DebugSerialClutchLast = millis();
    }
  #endif

#if DebugClutchCalib == true
   /* enter calibration mode if paddle is held down */
  if( ClutchCalibrationStart != 0 && millis() - ClutchCalibrationStart > CLUTCH_CALIBRATION_DELAY ){
    ClutchCalibrationStart = 0;
    clutch_calibrate();
  }
#endif
}

/* calibrate min max for the clutch */
void clutch_calibrate(){
      // calibrate current shifter for max reading
    #if DebugSerialOut == true && DebugClutchCalib == true
      Serial.println("entered calibration mode clutch_calibrate()");
    #endif
 
    int high=0,low=0;
    for( byte x=0; x < 10 ; x++ ){
      high += analogRead(Clutch_1_Pin);
      delay(500);
    }
    high = high / 10;

    //wait for shifter release
    while(true){
      #if DebugSerialOut == true && DebugClutchCalib == true
        Serial.println("high collected, waiting for release");
      #endif
      
      if( analogRead(Clutch_1_Pin) < high - ClutchCalibrationAdjust ){
        for( byte x=0; x < 10 ; x++ ){
          low += analogRead(Clutch_1_Pin);
          delay(500);
        }
        low = low / 10;

        ClutchLow = low + ClutchCalibrationAdjust;
        ClutchHigh = high - ClutchCalibrationAdjust;
        
        #if DebugSerialOut == true && DebugClutchCalib == true
            Serial.print("Clutch 1 high: ");
            Serial.print(high);
            Serial.print("(");
            Serial.print( ClutchHigh );
            Serial.print(")");
            Serial.print(" / low: ");
            Serial.print( low );
            Serial.print("(");
            Serial.print( ClutchLow );
            Serial.println(")");
        #endif
        

        #if EEPROMWrite == 1 && DebugClutchCalib == true
          eeprom_update_hes();
        #endif
        return;
      }
      delay(500);
    }
}
#endif

#if CONTROLLER_SHIFTER_TYPE == 2
/* checks if a shift is happening */
void check_shifter_halleffect(){

  int raw = analogRead(Shifter_1_Pin);
  if( raw > HESshiftPoint_1 ){
    if( ShifterSend[0] == 0 ){
      ShifterSend[0] = 1;
      sendKey( Shifter_1_Key, Shifter_1_Mod, Shifter_1_Joy );
      HESCalibrationStart[0] = millis();
    }
  }else{
    if( ShifterSend[0] == 1 ){
      ShifterSend[0] = 0;
      HESCalibrationStart[0] = 0;
      releaseKey( Shifter_1_Key, Shifter_1_Mod, Shifter_1_Joy );
    }
  }

  #if DebugSerialOut == true && DebugHallEffectShiftPoint == true
    if( millis() - DebugSerialHallEffectLast > 1500 ){
      Serial.print(millis());
      Serial.print(" - Shifter_1 val:");
      Serial.print(raw);
      DebugSerialHallEffectLastNow = true;
    }
  #endif
  
  raw = analogRead(Shifter_2_Pin);
  if( raw > HESshiftPoint_2 ){
    if( ShifterSend[1] == 0 ){
      ShifterSend[1] = 1;
      sendKey( Shifter_2_Key, Shifter_2_Mod, Shifter_2_Joy );
      HESCalibrationStart[1] = millis();
    }
  }else{
    if( ShifterSend[1] == 1 ){
      ShifterSend[1] = 0;
      HESCalibrationStart[1] = 0;
      releaseKey( Shifter_2_Key, Shifter_2_Mod, Shifter_2_Joy );
    }
  }


#if DebugHallEffectCalib == true
  /* enter calibration mode if paddle is held down */
  for( char x = 0 ; x < 2 ; x++ ){
    if( HESCalibrationStart[x] != 0 && millis() - HESCalibrationStart[x] > HES_CALIBRATION_DELAY ){
      HESCalibrationStart[x] = 0;
      HES_calibrate_max();
      break;
    }
  }
#endif
  

  #if DebugSerialOut == true && DebugHallEffectShiftPoint == true
    if( DebugSerialHallEffectLastNow == true ){
      Serial.print("  /  Shifter_2 val:");
      Serial.println(raw);
      DebugSerialHallEffectLast = millis();
      DebugSerialHallEffectLastNow = false;
    }
  #endif
}

void HES_calibrate_max(){
      // calibrate current shifter for max reading
    #if DebugSerialOut == true && DebugHallEffectCalib == true
      Serial.println("entered calibration mode HES_calibrate_max()");
    #endif
 
    int total1=0,total2=0;
    for( byte x=0; x < 10 ; x++ ){
      total1 += analogRead(Shifter_1_Pin);
      total2 += analogRead(Shifter_2_Pin);
      delay(500);
    }
    total1 = total1 / 10;
    total2 = total2 / 10;

    //wait for shifter release
    while(true){
      #if DebugSerialOut == true && DebugHallEffectCalib == true
        Serial.println("Please release the paddle to continue.");
      #endif
      
      if( analogRead(Shifter_1_Pin) < total1 - HESCalibrationAdjust ){
        #if DebugSerialOut == true && DebugHallEffectCalib == true
            Serial.print("Shifter 1 max: ");
            Serial.print(total1);
            Serial.print(" / new shift point: ");
            Serial.println( total1 - HESCalibrationAdjust );
        #endif
        HESshiftPoint_1 = total1 - HESCalibrationAdjust;
        #if EEPROMWrite == 1 && DebugHallEffectCalib == true
          eeprom_update_hes();
        #endif
        return;
      }
      if( analogRead(Shifter_2_Pin) < total2 - HESCalibrationAdjust ){
        HESshiftPoint_2 = total2 - HESCalibrationAdjust;
        #if DebugSerialOut == true && DebugHallEffectCalib == true
            Serial.print("Shifter 2 max: ");
            Serial.print(total2);
            Serial.print(" / new shift point: ");
            Serial.println( total2 - HESCalibrationAdjust );
        #endif
        HESshiftPoint_2 = total2 - HESCalibrationAdjust;
         #if EEPROMWrite == 1 && DebugHallEffectCalib == true
          eeprom_update_hes();
         #endif
        return;
      }
      delay(1500);
    }
    
}

#endif

#if CONTROLLER_JOYSTICK_ENABLED == true
/* checks if the joystick has been moved */
void check_joystick(){
  int joyval = 0;
  
  #if DebugSerialOut == true && DebugJoysticksGetValues == true
  if( millis() - DebugJoysticksGetValuesLast > 1500 ){

    Serial.print("check_joystick()");
    for( byte x = 0 ; x < sizeof(JoystickPins)/sizeof(byte) ; x++ ){
      joyval = analogRead(JoystickPins[x]);
    
      Serial.print(" / pin:");
      Serial.print(JoystickPins[x]);
      Serial.print(" value:");
      Serial.print(joyval);
    }
    Serial.println();
    DebugJoysticksGetValuesLast = millis();
  }
  #endif

  for( byte x = 0 ; x < sizeof(JoystickPins)/sizeof(byte) ; x++ ){
    joyval = analogRead(JoystickPins[x]);
    
    #if JoysticksGetValues == false
      if( joyval > (JoyStickCenters[x] + JoyStickMoveMin[x]) ){
        JoystickSend[x] = millis();
        JoystickMoved[x] = millis();
        JoyStickDirection[x] = 1;
        if( JoyStickMoved == 0 || JoyStickMoved == x ){
          JoyStickMoved = x;
          sendKey( JoystickKeys[x][0][0], JoystickMods[x][0][0], JoystickJoys[x][1][0] );
        }
        return;
        
      }else if( joyval < (JoyStickCenters[x] - JoyStickMoveMin[x]) ){
        JoystickSend[x] = millis();
        JoystickMoved[x] = millis();
        JoyStickDirection[x] = 2;
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


#if CONTROLLER_ENCODER_ENABLED == true
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


#if EEPROMWrite == 1
/** compares current hall effect sensor shift value vs the eeprom value every few seconds
 *  updates it if the differ
 */
void eeprom_update_hes(){

    if( HESshiftPoint_1 > 10 && eepromReadInt(EEPROM_HES_1) != HESshiftPoint_1 ){
      #if DebugSerialOut == true
        Serial.print("INFO: HES_1 EEPROM address ");
        Serial.print(EEPROM_HES_1);
        Serial.print(" write value ");
        Serial.print(HESshiftPoint_1);
        Serial.println(" / eeprom_update_pwm()");
      #endif
      
      #if EEPROMWrite == 1
        byte low, high;
        low=HESshiftPoint_1&0xFF;
        high=(HESshiftPoint_1>>8)&0xFF;
        EEPROM.write(EEPROM_HES_1, low); // dauert 3,3ms 
        EEPROM.write(EEPROM_HES_1+1, high);
      #else
        #if DebugSerialOut == true
          Serial.println("INFO: write disabled by configuration / eeprom_update_pwm()");
        #endif        
      #endif      
    }


    if( HESshiftPoint_2 > 10 && eepromReadInt(EEPROM_HES_2) != HESshiftPoint_2 ){
      #if DebugSerialOut == true
        Serial.print("INFO: HES_1 EEPROM address ");
        Serial.print(EEPROM_HES_2);
        Serial.print(" write value ");
        Serial.print(HESshiftPoint_2);
        Serial.println(" / eeprom_update_pwm()");
      #endif
      
      #if EEPROMWrite == 1
        byte low, high;
        low=HESshiftPoint_2&0xFF;
        high=(HESshiftPoint_2>>8)&0xFF;
        EEPROM.write(EEPROM_HES_2, low); // dauert 3,3ms 
        EEPROM.write(EEPROM_HES_2+1, high);
        return;
      #else
        #if DebugSerialOut == true
          Serial.println("INFO: write disabled by configuration / eeprom_update_pwm()");
        #endif        
      #endif      
    }

  #if CONTROLLER_CLUTCH_ENABLED == true
    if( ClutchLow > 1 && eepromReadInt(EEPROM_CLL_1) != ClutchLow ){
      #if DebugSerialOut == true
        Serial.print("INFO: Clutch_1 EEPROM address ");
        Serial.print(EEPROM_CLL_1);
        Serial.print(" write value ");
        Serial.print(ClutchLow);
        Serial.println(" / eeprom_update_pwm()");
      #endif
      
      #if EEPROMWrite == 1
        byte low, high;
        low=ClutchLow&0xFF;
        high=(ClutchLow>>8)&0xFF;
        EEPROM.write(EEPROM_CLL_1, low); // dauert 3,3ms 
        EEPROM.write(EEPROM_CLL_1+1, high);
      #else
        #if DebugSerialOut == true
          Serial.println("INFO: write disabled by configuration / eeprom_update_pwm()");
        #endif        
      #endif      
    }


    if( ClutchHigh > 10 && eepromReadInt(EEPROM_CLH_1) != ClutchHigh ){
      #if DebugSerialOut == true
        Serial.print("INFO: Clutch_1 EEPROM address ");
        Serial.print(EEPROM_CLH_1);
        Serial.print(" write value ");
        Serial.print(ClutchHigh);
        Serial.println(" / eeprom_update_pwm()");
      #endif
      
      #if EEPROMWrite == 1
        byte low, high;
        low=ClutchHigh&0xFF;
        high=(ClutchHigh>>8)&0xFF;
        EEPROM.write(EEPROM_CLH_1, low); // dauert 3,3ms 
        EEPROM.write(EEPROM_CLH_1+1, high);
      #else
        #if DebugSerialOut == true
          Serial.println("INFO: write disabled by configuration / eeprom_update_pwm()");
        #endif        
      #endif      
    }
  #endif
     
    EEPROM_check_last = millis(); //update "last check counter"
}
#endif
