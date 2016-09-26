/* Based on Encoder Library
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 */

#include "CONFIG.h"
#include <Encoder.h>
#include <Bounce.h>

long positionLeft  = 0;
long positionCenter = 0;
long positionRight = 0;

/* turns LED off once one of the buttons has been used */
boolean beenUsed = false;
boolean LEDon = true;

#if OutputSerial == 1 && DebugOutput == 1
int DebugTimerStart;
int DebugTimerStop;
#endif

/* setup encoders */
Encoder knobLeft(Encoder1PinA, Encoder1PinB);
Encoder knobCenter(Encoder2PinA, Encoder2PinB);
Encoder knobRight(Encoder3PinA, Encoder3PinB);  


#if EnableMultiplexer == 0
/* setup debounced switch object for push buttons of rotary encoders */
Bounce EncButton1 = Bounce(Encoder1PinC, 10);
Bounce EncButton2 = Bounce(Encoder2PinC, 10);
Bounce EncButton3 = Bounce(Encoder3PinC, 10);

/* setup push buttons on top row */
Bounce PushPutton1 = Bounce(Button_1_Pin, 10);
Bounce PushPutton2 = Bounce(Button_2_Pin, 10);
Bounce PushPutton3 = Bounce(Button_3_Pin, 10);
Bounce PushPutton4 = Bounce(Button_4_Pin, 10);

/* setup debounced switch object for toggel switches */
Bounce PushPutton5 = Bounce(Button_5_Pin, 10);
Bounce PushPutton6 = Bounce(Button_6_Pin, 10);
Bounce PushPutton7 = Bounce(Button_7_Pin, 10);
Bounce PushPutton8 = Bounce(Button_8_Pin, 10);
Bounce PushPutton9 = Bounce(Button_9_Pin, 10);
Bounce PushPutton10 = Bounce(Button_10_Pin, 10);
Bounce PushPutton11 = Bounce(Button_11_Pin, 10);
Bounce PushPutton12 = Bounce(Button_12_Pin, 10);
Bounce PushPutton13 = Bounce(Button_13_Pin, 10);
Bounce PushPutton14 = Bounce(Button_14_Pin, 10);
#endif







void setup() {

  /* multi plexer setup */
  #if EnableMultiplexer == 1
  pinMode(MultiplexerP9, OUTPUT);
  pinMode(MultiplexerP10, OUTPUT);
  pinMode(MultiplexerP11, OUTPUT);
  analogReadResolution(AnalogResolution);
  #endif


  #if EnableMultiplexer == 0
  /* top row push buttons */
  pinMode(Button_1_Pin, INPUT_PULLUP);
  pinMode(Button_2_Pin, INPUT_PULLUP);
  pinMode(Button_3_Pin, INPUT_PULLUP);
  pinMode(Button_4_Pin, INPUT_PULLUP);
  
  /* encoder push buttons */
  pinMode(Button_5_Pin, INPUT_PULLUP);
  pinMode(Button_6_Pin, INPUT_PULLUP);
  pinMode(Button_7_Pin, INPUT_PULLUP);

  /* toggle switches */
  pinMode(Button_7_Pin, INPUT_PULLUP);
  pinMode(Button_8_Pin, INPUT_PULLUP);
  pinMode(Button_9_Pin, INPUT_PULLUP);
  pinMode(Button_10_Pin, INPUT_PULLUP);
  pinMode(Button_11_Pin, INPUT_PULLUP);
  pinMode(Button_12_Pin, INPUT_PULLUP);
  pinMode(Button_13_Pin, INPUT_PULLUP);
  pinMode(Button_14_Pin, INPUT_PULLUP);
  pinMode(Button_15_Pin, INPUT_PULLUP);
  pinMode(Button_16_Pin, INPUT_PULLUP);
  #endif

  delay(BootUpDelay); //wait a few seconds before the "teensy keyboard" becomes active
  pinMode(ledPin, OUTPUT);

  // Anything with "Serial." is only used for development ATM
  #ifdef OutputSerial
    Serial.begin(115200);
    Serial.println("Modular Open Button Box (MOBB) ready...");
  #endif
}



void loop() {
  #if OutputSerial == 1 && DebugOutput == 1
    DebugTimerStart = millis();
  #endif

  /* the LED is distracting when it's dark in the room. this turns it off after the first button use */
  if( beenUsed == true && LEDon == true ) {
    digitalWrite(ledPin, LOW);
    LEDon = false;
  }else if( beenUsed == false ) {
    digitalWrite(ledPin, HIGH);
  }


  /* button check start */
  check_rotary_encoders();

  #if EnableMultiplexer == 1
    check_multiplexed_buttons();
  #else
    check_buttons();
    check_encoder_switches();
  #endif
  /* button check done */


  #if OutputSerial == 1 && DebugOutput == 1
    DebugTimerStop = millis();

    Serial.print("Start: ");
    Serial.print(DebugTimerStart);
    Serial.print(" Stop: ");
    Serial.println(DebugTimerStop);
  #endif
}




void send_key( int key, int del, int mod=0, int btnhold=0 ){
  #ifdef OutputSerial
    Serial.print("Mod:");
    Serial.print(mod);
    Serial.print(" key:");
    Serial.print(key);
    Serial.println();
  #else
    Keyboard.set_modifier(mod);
    Keyboard.set_key1(key);
    Keyboard.send_now();
  #endif

  #ifndef OutputSerial
  if( btnhold == 0 ){
    delay(del); //iRacing will not detect the key without a delay
    release_key();
  }
  #endif

  beenUsed = true;
}

void release_key(){
  #ifndef OutputSerial
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
  #endif
}

