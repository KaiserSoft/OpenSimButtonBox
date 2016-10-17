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
#if EnableAux1_Button == 1
  byte AUX1PWM = EEPROM.read(AUX1_EEPROM); //read PWM value from EEPROM
#else
  byte AUX1PWM = AUX1_PWM_FIXED; //use fixed PWM value
#endif
#if EnableAux2_Button == 1
  byte AUX2PWM = EEPROM.read(AUX2_EEPROM); //read PWM value from EEPROM
#else
  byte AUX2PWM = AUX2_PWM_FIXED; //use fixed PWM value
#endif
#if EnableAux3_Button == 1
  byte AUX3PWM = EEPROM.read(AUX3_EEPROM); //read PWM value from EEPROM
#else
  byte AUX3PWM = AUX3_PWM_FIXED; //use fixed PWM value
#endif
boolean AUX1_fan_started = false;
boolean AUX2_fan_started = false;
boolean AUX3_fan_started = false;
boolean Pit_limiter_active = false;
long EEPROM_check_last = 0; //last time EEPROM values where checked for change
long EEPROM_val_change_last = 0; //last time any EEPROM stored value has changed

/* turns LED off once one of the buttons has been used */
boolean beenUsed = false;
boolean LEDon = true;



#if OutputSerial == 1
  boolean OutEEPROMSkipSend = false;
#endif
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
  delay(BootUpDelay); //wait a few seconds before the "teensy keyboard" becomes active
  pinMode(ledPin, OUTPUT);
  
  // Anything with "Serial." is only used for development ATM
  #if OutputSerial == 1
    Serial.begin(115200);
  #endif

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
  
  #if EnablePitLimiterSwitch == 1
    pinMode(PitLimiterPin, INPUT_PULLUP);
  #endif


  /* Setup AUX ports */
  pinMode(AUX1_Pin, OUTPUT);
  analogWrite(AUX1_Pin, 0 ); //start board with power turned off
  #if EnableAux1 == 1
    #if AUX1_PWM_FREQ > 0
      analogWriteFrequency(AUX1_Pin, AUX1_PWM_FREQ);
      #if OutputSerial == 1
        Serial.print("AUX1 PWM frequency set to ");
        Serial.println(AUX1_PWM_FREQ);
      #endif
    #endif
  #endif

  
  pinMode(AUX2_Pin, OUTPUT);
  analogWrite(AUX2_Pin, 0 ); //start board with power turned off
  #if EnableAux2 == 1
    #if AUX2_PWM_FREQ > 0
      analogWriteFrequency(AUX2_Pin, AUX2_PWM_FREQ);
      #if OutputSerial == 1
        Serial.print("AUX2 PWM frequency set to ");
        Serial.println(AUX2_PWM_FREQ);
      #endif
    #endif
  #endif

  
  pinMode(AUX3_Pin, OUTPUT);
  analogWrite(AUX3_Pin, 0 ); //start board with power turned off
  #if EnableAux3 == 1
    #if AUX3_PWM_FREQ > 0
      analogWriteFrequency(AUX3_Pin, AUX3_PWM_FREQ);
      #if OutputSerial == 1
        Serial.print("AUX3 PWM frequency set to ");
        Serial.println(AUX3_PWM_FREQ);
      #endif
    #endif
  #endif
  /* AUX ports done */





  #if OutputSerial == 1
    Serial.println("Modular Open Button Box (MOBB) ready...");
  #endif

  /* get any fans started */
  if( ( AUX1_fan_started == false || AUX1_fan_started == false || AUX1_fan_started == false ) &&
      ( AUX1_ENABLE_FAN_START == 1 || AUX2_ENABLE_FAN_START == 1 || AUX3_ENABLE_FAN_START == 1 ) )
  {
    boolean fan_state_changed = false;

    #if EnableAux1 == 1
      if( AUX1_fan_started == false && AUX1_ENABLE_FAN_START == 1 && AUX1_FAN_START_RAMP > AUX1PWM ){
        analogWrite(AUX1_Pin, AUX1_FAN_START_RAMP );
        AUX1_fan_started = true;
        fan_state_changed = true;
        #if OutputSerial == 1
          Serial.print("Fan ramp up AUX 1 PWM: ");
          Serial.println(AUX1_FAN_START_RAMP);
        #endif
      }
   #endif

    #if EnableAux2 == 1
      if( AUX2_fan_started == false && AUX2_ENABLE_FAN_START == 1 && AUX2_FAN_START_RAMP > AUX2PWM ){
        analogWrite(AUX2_Pin, AUX2_FAN_START_RAMP );
        AUX2_fan_started = true;
        fan_state_changed = true;
        #if OutputSerial == 1
          Serial.print("Fan ramp up AUX 2 PWM: ");
          Serial.println(AUX2_FAN_START_RAMP);
        #endif
      }
    #endif

    #if EnableAux3 == 1
      if( AUX3_fan_started == false && AUX3_ENABLE_FAN_START == 1 && AUX3_FAN_START_RAMP > AUX3PWM ){
        analogWrite(AUX3_Pin, AUX3_FAN_START_RAMP );
        AUX3_fan_started = true;
        fan_state_changed = true;
        #if OutputSerial == 1
          Serial.print("Fan ramp up AUX 3 PWM: ");
          Serial.println(AUX3_FAN_START_RAMP);
        #endif
      }
    #endif

    if( fan_state_changed == true )
    {
      delay(AUX_RAMP_TIME); //allow fans to spin up
      #if OutputSerial == 1
        Serial.println("Fan ramp up done");
      #endif
      
      if( EnableAux1_Button == 1 ) { 
        AUX1PWM = EEPROM.read(AUX1_EEPROM); //current PWM value for port
      }else if ( EnableAux1 == 1 ){
        AUX1PWM = AUX1_PWM_FIXED;       
      }
      
      if( EnableAux2_Button == 1 ) { 
        AUX2PWM = EEPROM.read(AUX2_EEPROM); //current PWM value for port
      }else if ( EnableAux2 == 1 ){
        AUX2PWM = AUX2_PWM_FIXED;
      }
      
      if( EnableAux3_Button == 1 ) {
        AUX3PWM = EEPROM.read(AUX3_EEPROM); //current PWM value for port
      }else if ( EnableAux3 == 1 ){
        AUX3PWM = AUX3_PWM_FIXED;
      }
    }
  }

  #if OutputSerial == 1
    Serial.print("AUX ports ready ");
    
    if( EnableAux1 == 0 ){
      Serial.print(" / AUX1 disabled");
    }else if( EnableAux1 == 1 && EnableAux1_Button == 1 ){
      Serial.print(" / AUX1 ");
      Serial.print(AUX1PWM);
    }else if( EnableAux1 == 1 && EnableAux1_Button == 0 ){
      Serial.print(" / AUX1 FIX ");
      Serial.print(AUX1PWM);
    }
    
    if( EnableAux2 == 0 ){
      Serial.print(" / AUX2 disabled");
    }else if( EnableAux2 == 1 && EnableAux2_Button == 1 ){
      Serial.print(" / AUX2 ");
      Serial.print(AUX2PWM);
    }else if( EnableAux2 == 1 && EnableAux2_Button == 0 ){
      Serial.print(" / AUX2 FIX ");
      Serial.print(AUX2PWM);
    }

    if( EnableAux3 == 0 ){
      Serial.print(" / AUX3 disabled");
    }else if( EnableAux3 == 1 && EnableAux3_Button == 1 ){
      Serial.print(" / AUX3 ");
      Serial.print(AUX3PWM);
    }else if( EnableAux3 == 1 && EnableAux3_Button == 0 ){
      Serial.print(" / AUX3 FIX ");
      Serial.print(AUX3PWM);
    }
    Serial.println();
  #endif  

} //void setup()








void send_key( int key, int del, int mod = 0, int btnhold = 0 ) {
  #if OutputSerial == 1
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

    if ( btnhold == 0 ) {
      delay(del); //iRacing will not detect the key without a short delay
      release_key();
    }
  #endif


  beenUsed = true;

} //void send_key()




void loop() {
  
  if( EnableAux1 == 1 ) { analogWrite(AUX1_Pin, AUX1PWM);}
  if( EnableAux2 == 1 ) { analogWrite(AUX2_Pin, AUX2PWM);}
  if( EnableAux3 == 1 ) { analogWrite(AUX3_Pin, AUX3PWM);}



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
  
  
  /**
   * pit limiter is permanent ON/OFF switch so this is must be handeled seperately
   */
  #if EnablePitLimiterSwitch == 1
    if (PitLimiterButton.update()) {
  
  
      if (PitLimiterButton.fallingEdge()) {
        Pit_limiter_active = true;
        #if OutputSerial == 1
          Serial.println("Pit limiter ON");
        #endif
        send_key(PitLimiterKey, BUTTON_HOLD, PitLimiterMod, PitLimiterHold );
  
        
      }else{
        if( Pit_limiter_active == true ){
          Pit_limiter_active = false;
          #if OutputSerial == 1
            Serial.println("Pit limiter OFF");
          #endif
          send_key(PitLimiterKey, BUTTON_HOLD, PitLimiterMod, PitLimiterHold );
        }
      }
    }
  #endif

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
    Serial.print(EEPROM_check_last);
    Serial.println(" / eeprom_update_pwm()");
  #endif
  

  if( EEPROM_check_last == 0 ) {
    //system just booted, wait at least for "EEPROM_storage_loop" delay
    EEPROM_check_last = millis();
    EEPROM_val_change_last = millis();
    
  }else if( EEPROM_check_last < must_pass && EEPROM_val_change_last < must_pass ){
    #if OutputSerial == 1
      OutEEPROMSkipSend = false;
      Serial.println("comparing EEPROM values / eeprom_update_pwm()");
    #endif

    if( EnableAux1_Button == 1 && EEPROM.read(AUX1_EEPROM) != AUX1PWM ){
      #if OutputSerial == 1
        Serial.print("INFO: Update AUX1 EEPROM address ");
        Serial.print(AUX1_EEPROM);
        Serial.print(" with value ");
        Serial.print(AUX1PWM);
        Serial.println(" / eeprom_update_pwm()");
      #endif
      EEPROM.write(AUX1_EEPROM, AUX1PWM);
    }

    if( EnableAux2_Button == 1 && EEPROM.read(AUX2_EEPROM) != AUX2PWM ){
      #if OutputSerial == 1
        Serial.print("INFO: Update AUX2 EEPROM address ");
        Serial.print(AUX2_EEPROM);
        Serial.print(" with value ");
        Serial.print(AUX2PWM);
        Serial.println(" / eeprom_update_pwm()");
      #endif
      EEPROM.write(AUX2_EEPROM, AUX2PWM);
    }

    if( EnableAux3_Button == 1 && EEPROM.read(AUX3_EEPROM) != AUX3PWM ){
      #if OutputSerial == 1
        Serial.print("INFO: Update AUX3 EEPROM address ");
        Serial.print(AUX3_EEPROM);
        Serial.print(" with value ");
        Serial.print(AUX3PWM);
        Serial.println(" / eeprom_update_pwm()");
      #endif
      EEPROM.write(AUX3_EEPROM, AUX3PWM);
    }

    
    EEPROM_check_last = millis(); //update "last check counter"
  }else{
    #if OutputSerial == 1
      if(  OutEEPROMSkipSend == false && EEPROM_check_last < must_pass && EEPROM_val_change_last > must_pass) {
        OutEEPROMSkipSend = true;
        Serial.println("skipping EEPROM checks - value recently changed / eeprom_update_pwm()");
      }
    #endif
  }




}




void release_key() {
  #if OutputSerial == 1
    Serial.println("ran release_key()");
  #else
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
  #endif
}

