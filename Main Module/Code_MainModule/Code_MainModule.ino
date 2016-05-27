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


/* setup encoders */
Encoder knobLeft(Encoder1PinA, Encoder1PinB);
Encoder knobCenter(Encoder2PinA, Encoder2PinB);
Encoder knobRight(Encoder3PinA, Encoder3PinB);  

/* setup debounced switch object for push buttons of rotary encoders */
Bounce BBToggle = Bounce(Encoder1PinC, 10);
Bounce BBSelect = Bounce(Encoder2PinC, 10);
Bounce BBSelect2 = Bounce(Encoder3PinC, 10);

/* setup debounced switch object for toggel switches */
Bounce TSwitchOne_UP = Bounce(TSwitch1PinA, 10);
Bounce TSwitchOne_DOWN = Bounce(TSwitch1PinB, 10);
Bounce TSwitchTwo_UP = Bounce(TSwitch2PinA, 10);
Bounce TSwitchTwo_DOWN = Bounce(TSwitch2PinB, 10);
Bounce TSwitchThree_UP = Bounce(TSwitch3PinA, 10);
Bounce TSwitchThree_DOWN = Bounce(TSwitch3PinB, 10);
Bounce TSwitchFour_UP = Bounce(TSwitch4PinA, 10);
Bounce TSwitchFour_DOWN = Bounce(TSwitch4PinB, 10);
Bounce TSwitchFive_UP = Bounce(TSwitch5PinA, 10);
Bounce TSwitchFive_DOWN = Bounce(TSwitch5PinB, 10);

/* setup push buttons on top row */
Bounce BPutton1 = Bounce(PButton1Pin, 10);
Bounce BPutton2 = Bounce(PButton2Pin, 10);
Bounce BPutton3 = Bounce(PButton3Pin, 10);
Bounce BPutton4 = Bounce(PButton4Pin, 10);







void setup() {
  delay(BootUpDelay); //wait a few seconds before the "teensy keyboard" becomes active
  pinMode(ledPin, OUTPUT);
  
  /* top row push buttons */
  pinMode(PButton1Pin, INPUT_PULLUP);
  pinMode(PButton2Pin, INPUT_PULLUP);
  pinMode(PButton3Pin, INPUT_PULLUP);
  pinMode(PButton4Pin, INPUT_PULLUP);
  
  /* encoder push buttons */
  pinMode(Encoder1PinC, INPUT_PULLUP);
  pinMode(Encoder2PinC, INPUT_PULLUP);
  pinMode(Encoder3PinC, INPUT_PULLUP);

  /* toggle switches */
  pinMode(TSwitch1PinA, INPUT_PULLUP);
  pinMode(TSwitch1PinB, INPUT_PULLUP);
  pinMode(TSwitch2PinA, INPUT_PULLUP);
  pinMode(TSwitch2PinB, INPUT_PULLUP);
  pinMode(TSwitch3PinA, INPUT_PULLUP);
  pinMode(TSwitch3PinB, INPUT_PULLUP);
  pinMode(TSwitch4PinA, INPUT_PULLUP);
  pinMode(TSwitch4PinB, INPUT_PULLUP);
  pinMode(TSwitch5PinA, INPUT_PULLUP);
  pinMode(TSwitch5PinB, INPUT_PULLUP);


  // Anything with "Serial." is only used for development ATM
  #ifdef OutputSerial
    Serial.begin(115200);
    Serial.println("Modular Open Button Box (MOBB) ready...");
  #endif
}



void loop() {

  /* the LED is distracting when it's dark in the room. this turns it off after the first button use */
  if( beenUsed == true && LEDon == true ) {
    digitalWrite(ledPin, LOW);
    LEDon = false;
  }else if( beenUsed == false ) {
    digitalWrite(ledPin, HIGH);
  }




  check_push_buttons();

  check_toggle_switches();

  check_encoder_switches();

  check_rotary_encoders();
  
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
    delay(del);
  #endif

  #ifndef OutputSerial
  if( btnhold == 0 ){
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

