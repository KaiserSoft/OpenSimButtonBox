/* Based on Encoder Library
   http://www.pjrc.com/teensy/td_libs_Encoder.html
*/

#include "CONFIG.h"
#include <Encoder.h>
#include <Bounce.h>
#include <EEPROM.h>

long positionLeft  = 0;
long positionCenter = 0;
long positionRight = 0;
boolean AUX1Pressed = false;
boolean AUX2Pressed = false;
boolean AUX3Pressed = false;
byte AUX1PWM = EEPROM.read(AUX1_EEPROM); //current PWM value for port
byte AUX2PWM = EEPROM.read(AUX2_EEPROM); //current PWM value for port
byte AUX3PWM = EEPROM.read(AUX3_EEPROM); //current PWM value for port
boolean AUX1_fan_started = false;
boolean AUX2_fan_started = false;
boolean AUX3_fan_started = false;
long EEPROM_check_last = 0;

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


Bounce PitLimiterButton = Bounce(PitLimiterPin, 10);





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


  pinMode(PitLimiterPin, OUTPUT);

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

  /* Aux 1 and 2 */
  pinMode(Aux1, OUTPUT);
  analogWriteFrequency(Aux1, 100);
  pinMode(Aux2, OUTPUT);
  analogWriteFrequency(Aux2, 100);
  //analogWriteFrequency(Aux2, 375000);
  //pinMode(Aux3, OUTPUT);

  delay(BootUpDelay); //wait a few seconds before the "teensy keyboard" becomes active
  pinMode(ledPin, OUTPUT);

  // Anything with "Serial." is only used for development ATM
#ifdef OutputSerial
  Serial.begin(115200);
  Serial.println("Modular Open Button Box (MOBB) ready...");
#endif
}



void loop() {

  /* get any fans started */
  if( ( AUX1_fan_started == false || AUX1_fan_started == false || AUX1_fan_started == false ) &&
      ( AUX1_ENABLE_FAN_START == 1 || AUX2_ENABLE_FAN_START == 1 || AUX3_ENABLE_FAN_START == 1 ) )
  {
    boolean fan_state_changed = false;
    
    if( AUX1_fan_started == false && AUX1_ENABLE_FAN_START == 1 ){
      analogWrite(Aux1, AUX1_FAN_START_RAMP );
      AUX1_fan_started = true;
      fan_state_changed = true;
      #ifdef OutputSerial
        Serial.print("Fan ramp up AUX 1 PWM: ");
        Serial.println(AUX1_FAN_START_RAMP);
      #endif
    }
    
    if( AUX2_fan_started == false && AUX2_ENABLE_FAN_START == 1 ){
      analogWrite(Aux2, AUX2_FAN_START_RAMP );
      AUX2_fan_started = true;
      fan_state_changed = true;
      #ifdef OutputSerial
        Serial.print("Fan ramp up AUX 2 PWM: ");
        Serial.println(AUX2_FAN_START_RAMP);
      #endif
    }
    
    if( AUX3_fan_started == false && AUX3_ENABLE_FAN_START == 1 ){
      analogWrite(Aux3, AUX3_FAN_START_RAMP );
      AUX3_fan_started = true;
      fan_state_changed = true;
      #ifdef OutputSerial
        Serial.print("Fan ramp up AUX 3 PWM: ");
        Serial.println(AUX3_FAN_START_RAMP);
      #endif
    }

    if( fan_state_changed == true )
    {
      delay(5000); //allow fans to spin up
      AUX1PWM = EEPROM.read(AUX1_EEPROM); //current PWM value for port
      AUX2PWM = EEPROM.read(AUX2_EEPROM); //current PWM value for port
      AUX3PWM = EEPROM.read(AUX3_EEPROM); //current PWM value for port
      #ifdef OutputSerial
        Serial.print("Fan ramp up done / ");
        Serial.print("AUX1:");
        Serial.print(AUX1PWM);
        Serial.print(" / AUX2: ");
        Serial.print(AUX2PWM);
        Serial.print(" / AUX3: ");
        Serial.println(AUX3PWM);
      #endif
    }
  }

  
  if( EnableAux1 == 1 ) { analogWrite(Aux1, AUX1PWM);}
  if( EnableAux2 == 1 ) { analogWrite(Aux2, AUX2PWM);}
  if( EnableAux3 == 1 ) { analogWrite(Aux3, AUX3PWM);}
//  analogWrite(Aux1, 255);
//  analogWrite(Aux2, 255);


#if OutputSerial == 1 && DebugOutput == 1
  DebugTimerStart = millis();
#endif

  /* the LED is distracting when it's dark in the room. this turns it off after the first button use */
  if ( beenUsed == true && LEDon == true ) {
    digitalWrite(ledPin, LOW);
    LEDon = false;
  } else if ( beenUsed == false ) {
    digitalWrite(ledPin, HIGH);
  }

  //digitalWrite(PitLimiterPin, HIGH);
  //check_button( PitLimiterButton, PitLimiterKey, PitLimiterMod, PitLimiterHold );


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

  eeprom_update_pwm();
  //delay(1000);
}


/** compares current pwm vs the eeprom value every few seconds
 *  updates it if the differ
 */
void eeprom_update_pwm(){
  int must_pass = millis() - (EEPROM_storage_loop * 1000);

  #if OutputSerial == 1 && DebugOutput == 1
    Serial.print("must_pass:  ");
    Serial.print(must_pass);
    Serial.print(" now:  ");
    Serial.println(EEPROM_check_last);
  #endif
  

  if( EEPROM_check_last == 0 ) {
    EEPROM_check_last = millis(); //fresh start, wait a bit
    
  }else if( EEPROM_check_last < must_pass ){
    #if OutputSerial == 1
      Serial.println("comparing EEPROM values");
    #endif

    if( EEPROM.read(AUX1_EEPROM) != AUX1PWM ){
      #if OutputSerial == 1
        Serial.print("INFO: Update AUX1 EEPROM address ");
        Serial.print(AUX1_EEPROM);
        Serial.print(" with value ");
        Serial.println(AUX1PWM);
      #endif
      EEPROM.write(AUX1_EEPROM, AUX1PWM);
    }

    if( EEPROM.read(AUX2_EEPROM) != AUX2PWM ){
      #if OutputSerial == 1
        Serial.print("INFO: Update AUX2 EEPROM address ");
        Serial.print(AUX2_EEPROM);
        Serial.print(" with value ");
        Serial.println(AUX2PWM);
      #endif
      EEPROM.write(AUX2_EEPROM, AUX2PWM);
    }

    if( EEPROM.read(AUX3_EEPROM) != AUX3PWM ){
      #if OutputSerial == 1
        Serial.print("INFO: Update AUX3 EEPROM address ");
        Serial.print(AUX3_EEPROM);
        Serial.print(" with value ");
        Serial.println(AUX3PWM);
      #endif
      EEPROM.write(AUX3_EEPROM, AUX3PWM);
    }

    
    EEPROM_check_last = millis(); //update "last check counter"
  }




}


void send_key( int key, int del, int mod = 0, int btnhold = 0 ) {
#ifdef OutputSerial
  Serial.print("send_key() / ");
  Serial.print("Mod:");
  Serial.print(mod);
  Serial.print(" / key:");
  Serial.print(key);
  Serial.println();
#else
  Keyboard.set_modifier(mod);
  Keyboard.set_key1(key);
  Keyboard.send_now();
#endif

#ifndef OutputSerial
  if ( btnhold == 0 ) {
    delay(del); //iRacing will not detect the key without a delay
    release_key();
  }
#endif

  beenUsed = true;
}

void release_key() {
#ifdef OutputSerial
  Serial.println("ran release_key()");
#else
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
#endif
}

