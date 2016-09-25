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


#if UseMultiplexer == 0
/* setup debounced switch object for push buttons of rotary encoders */
Bounce BBToggle = Bounce(Encoder1PinC, 10);
Bounce BBSelect = Bounce(Encoder2PinC, 10);
Bounce BBSelect2 = Bounce(Encoder3PinC, 10);

/* setup debounced switch object for toggel switches */
Bounce TSwitchOne_UP = Bounce(Button_7_Pin, 10);
Bounce TSwitchOne_DOWN = Bounce(Button_8_Pin, 10);
Bounce TSwitchTwo_UP = Bounce(Button_9_Pin, 10);
Bounce TSwitchTwo_DOWN = Bounce(Button_10_Pin, 10);
Bounce TSwitchThree_UP = Bounce(Button_11_Pin, 10);
Bounce TSwitchThree_DOWN = Bounce(Button_12_Pin, 10);
Bounce TSwitchFour_UP = Bounce(Button_13_Pin, 10);
Bounce TSwitchFour_DOWN = Bounce(Button_14_Pin, 10);
Bounce TSwitchFive_UP = Bounce(Button_15_Pin, 10);
Bounce TSwitchFive_DOWN = Bounce(Button_16_Pin, 10);

/* setup push buttons on top row */
Bounce BPutton1 = Bounce(Button_1_Pin, 10);
Bounce BPutton2 = Bounce(Button_2_Pin, 10);
Bounce BPutton3 = Bounce(Button_3_Pin, 10);
Bounce BPutton4 = Bounce(Button_4_Pin, 10);
#endif







void setup() {

  /* multi plexer setup */
  #if UseMultiplexer == 1
  pinMode(MultiplexerP9, OUTPUT);
  pinMode(MultiplexerP10, OUTPUT);
  pinMode(MultiplexerP11, OUTPUT);
  analogReadResolution(12);
  #endif


  #if UseMultiplexer == 0
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


  #if UseMultiplexer == 1
    check_multiplexed_buttons();
  #else
    check_push_buttons();
    check_toggle_switches();
    check_encoder_switches();
  #endif

  check_rotary_encoders();

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

