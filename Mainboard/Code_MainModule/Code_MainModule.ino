/* 
 *  Modular Button Box (MOBB)
*/

#include "CONFIG.h"
#include "BUTTONS.h"
#include "AUXPins.h"
#include <Encoder.h>
#include <Bounce.h>
#include <EEPROM.h>

long positionLeft  = 0;
long positionCenter = 0;
long positionRight = 0;
unsigned long AUX1Pressed = 0;
unsigned long AUX2Pressed = 0;
unsigned long AUX3Pressed = 0;
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


#ifndef AUX_ramp
void AUX_ramp(byte port);
#endif


void setup() {
  // Anything with "Serial." is only used for development ATM
  #if OutputSerial == 1
    Serial.begin(115200);
  #endif
  delay(BootUpDelay); //wait a few seconds before the "teensy keyboard" becomes active
  #if AUX_LED_Enable == 1
    pinMode(AUX_LED_Pin, OUTPUT);
    digitalWrite(AUX_LED_Pin, 0);  
  #endif
  pinMode(ledPin, OUTPUT);
  
  #if OutputSerial == 1
    while (!Serial){delay(250);}
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
  #if OutputSerial == 1
    Serial.print("AUX ports config");
    
    if( EnableAux1 == 0 ){
      Serial.print(" / AUX1 disabled");
    }else if( EnableAux1 == 1 && EnableAux1_Button == 1 ){
      if( AUX1_Button_Auto_Hold > 0 ){
        Serial.print(" / AUX1 ");
        Serial.print(AUX1PWM);
        Serial.print(" hold ");
        Serial.print(AUX1_Button_Auto_Hold);
        Serial.print("s");
      }else{
        Serial.print(" / AUX1 ");
        Serial.print(AUX1PWM);
      }
    }else if( EnableAux1 == 1 && EnableAux1_Button == 0 ){
      Serial.print(" / AUX1 FIX ");
      Serial.print(AUX1PWM);
    }
    
    if( EnableAux2 == 0 ){
      Serial.print(" / AUX2 disabled");
    }else if( EnableAux2 == 1 && EnableAux2_Button == 1 ){
      if( AUX2_Button_Auto_Hold > 0 ){
        Serial.print(" / AUX2 ");
        Serial.print(AUX2PWM);
        Serial.print(" hold ");
        Serial.print(AUX2_Button_Auto_Hold);
        Serial.print("s");
      }else{
        Serial.print(" / AUX2 ");
        Serial.print(AUX2PWM);
      }
    }else if( EnableAux2 == 1 && EnableAux2_Button == 0 ){
      Serial.print(" / AUX2 FIX ");
      Serial.print(AUX2PWM);
    }

    if( EnableAux3 == 0 ){
      Serial.print(" / AUX3 disabled");
    }else if( EnableAux3 == 1 && EnableAux3_Button == 1 ){
      if( AUX3_Button_Auto_Hold > 0 ){
        Serial.print(" / AUX3 ");
        Serial.print(AUX3PWM);
        Serial.print(" hold ");
        Serial.print(AUX3_Button_Auto_Hold);
        Serial.print("s");
      }else{
        Serial.print(" / AUX3 ");
        Serial.print(AUX3PWM);
      }
    }else if( EnableAux3 == 1 && EnableAux3_Button == 0 ){
      Serial.print(" / AUX3 FIX ");
      Serial.print(AUX3PWM);
    }
    Serial.println();
  #endif
  
  if( ( AUX1_fan_started == false || AUX1_fan_started == false || AUX1_fan_started == false ) &&
      ( AUX1_ENABLE_FAN_START == 1 || AUX2_ENABLE_FAN_START == 1 || AUX3_ENABLE_FAN_START == 1 ) )
  {

    #if EnableAux1 == 1
      if( EEPROM.read(AUX1_EEPROM) >= AUX1_PWM_MIN ){
        if( AUX1_fan_started == false && AUX1_ENABLE_FAN_START == 1 && AUX1_FAN_START_RAMP > AUX1PWM ){
          AUX_ramp(1);
        }
      }
   #endif

    #if EnableAux2 == 1
      if( EEPROM.read(AUX2_EEPROM) >= AUX2_PWM_MIN ){
        if( AUX2_fan_started == false && AUX2_ENABLE_FAN_START == 1 && AUX2_FAN_START_RAMP > AUX2PWM ){
          AUX_ramp(2);
        }
      }
    #endif

    #if EnableAux3 == 1
      if( EEPROM.read(AUX3_EEPROM) >= AUX3_PWM_MIN ){
        if( AUX3_fan_started == false && AUX3_ENABLE_FAN_START == 1 && AUX3_FAN_START_RAMP > AUX3PWM ){
          AUX_ramp(3);
        }
      }
    #endif
  }

} //void setup()








void send_key( int key, int del, int mod = 0, int btnhold = 0 ) {
    
  #if OutputSerial == 1 && DebugMultiplexer == 0
    Serial.print("send_key() / ");
    Serial.print("Mod:");
    Serial.print(mod);
    Serial.print(" / key:");
    Serial.print(key);
    Serial.print(" / kb:");
    key_int2str(key, mod);
    Serial.println();
  #endif

  #if OutputKeyboard == 1 && DebugMultiplexer == 0
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




/*
 ##############
 # LOOOOOOOOP #
 ##############
*/
void loop() {


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
    pit_limit();
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

  #if AUX1_Button_Auto_Hold > 0 || AUX2_Button_Auto_Hold > 0 || AUX3_Button_Auto_Hold > 0
    release_aux_button();
  #endif


  AUX_ramp(0); //maintain AUX ramps
}



 /*
 * handles pit limiter operation
 * pit limiter is permanent ON/OFF switch so this is must be handeled seperately
 */
 #if EnablePitLimiterSwitch == 1
 void pit_limit(){
    if (PitLimiterButton.update()) {

      #if PitLimiterIgnoreOnAux == 1
        if( AUX1Pressed != 0 || AUX2Pressed != 0 || AUX3Pressed != 0 ){
            #if OutputSerial == 1
              Serial.println("Pit limiter ignored - AUX ist active");
            #endif
            return;
        }
      #endif
  
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
 }
 #endif


/*
 * was supposed to only ramp AUX ports but now maintains values as well. needs to be rewritten for cleanup later ... lets test it first
 * ramps a ports .... was added later needs to be improved to use defined values from config files
 * port == 0 check current ramps or 1,2,3 for AUX
 */
void AUX_ramp( byte port ){
  static unsigned long ramp_start[3] = { 0, 0, 0 }; // 0 = not active, >0 = ramping
  byte ramp_value[3] = { AUX1_FAN_START_RAMP, AUX2_FAN_START_RAMP, AUX3_FAN_START_RAMP};
  byte ramp_pin[3] = { AUX1_Pin, AUX2_Pin, AUX3_Pin};
  byte ramp_enabled[3] {AUX1_ENABLE_FAN_START, AUX2_ENABLE_FAN_START, AUX3_ENABLE_FAN_START };
  byte pwm_vals[3] = { AUX1PWM, AUX2PWM, AUX3PWM};
  byte aux_active[3] = { EnableAux1, EnableAux2, EnableAux3};

  if( port == 0 ) {
    // maintain ramps
    for( byte x=0 ; x < 3 ; ++x ){
      if( ramp_start[x] > 0 && (ramp_start[x] + AUX_RAMP_TIME) < millis() ){
        analogWrite(ramp_pin[x], pwm_vals[x] );
        ramp_start[x]  = 0;
        #if OutputSerial == 1
          Serial.print("Ramp OFF AUX ");
          Serial.print(x+1);
          Serial.print(" pin ");
          Serial.print(ramp_pin[x]);
          Serial.print(" speed ");
          Serial.print(pwm_vals[x]);
          Serial.println();
        #endif
      }else if( ramp_start[x] == 0 ){
        if( aux_active[x] == 1 ) {  analogWrite(ramp_pin[x], pwm_vals[x]);}
        else{ analogWrite(ramp_pin[x], 0);}
      }
    }
    return;
  }


  byte address = port - 1; //array address or port
  if( ramp_start[address] == 0 ){
    if( ramp_enabled[address] == 1 ){
      analogWrite(ramp_pin[address], ramp_value[address] );
      ramp_start[address] = millis();
  
      #if OutputSerial == 1
        Serial.print("Ramp ON AUX ");
        Serial.print(port);
        Serial.print(" pin ");
        Serial.print(ramp_pin[address]);
        Serial.print(" speed ");
        Serial.print(ramp_value[address]);
        Serial.println();
      #endif
    }
    return;
  }
}



#if AUX1_Button_Auto_Hold > 0 || AUX2_Button_Auto_Hold > 0 || AUX3_Button_Auto_Hold > 0
/**
 * checks if any AUX buttons need to be released
 */
void release_aux_button(){
  unsigned long timenow = millis();

  if( AUX1_Button_Auto_Hold > 0 && AUX1Pressed > 0 && timenow > ( AUX1Pressed + AUX1_Button_Auto_Hold * 1000) ){
    #if OutputSerial == 1
      Serial.print("AUX1 auto hold released / PWM ");
      Serial.print(AUX1PWM);
      Serial.print(" / AuxMod ");
      Serial.print(AUX1_Button_Mod);
      Serial.println(" / release_aux_button()");
    #endif
    AUX1Pressed = 0;
    #if AUX_LED_Enable == 1
      analogWrite(AUX_LED_Pin, 0);
    #endif
  }

  if( AUX2_Button_Auto_Hold > 0 && AUX2Pressed > 0 && timenow > ( AUX2Pressed + AUX2_Button_Auto_Hold * 1000) ){
    #if OutputSerial == 1
      Serial.print("AUX2 auto hold released / PWM ");
      Serial.print(AUX2PWM);
      Serial.print(" / AuxMod ");
      Serial.print(AUX2_Button_Mod);
      Serial.println(" / release_aux_button()");
    #endif
    AUX2Pressed = 0;
    #if AUX_LED_Enable == 1
      analogWrite(AUX_LED_Pin, 0);
    #endif
  }

  if( AUX3_Button_Auto_Hold > 0 && AUX3Pressed > 0 && timenow > ( AUX3Pressed + AUX3_Button_Auto_Hold * 1000) ){
    #if OutputSerial == 1
      Serial.print("AUX3 auto hold released / PWM ");
      Serial.print(AUX3PWM);
      Serial.print(" / AuxMod ");
      Serial.print(AUX3_Button_Mod);
      Serial.println(" / release_aux_button()");
    #endif
    AUX3Pressed = 0;
    #if AUX_LED_Enable == 1
      analogWrite(AUX_LED_Pin, 0);
    #endif
  }
  
}
#endif





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
        Serial.print("INFO: AUX1 EEPROM address ");
        Serial.print(AUX1_EEPROM);
        Serial.print(" write value ");
        Serial.print(AUX1PWM);
        Serial.println(" / eeprom_update_pwm()");
      #endif
      
      #if EEPROMWrite == 1
        EEPROM.write(AUX1_EEPROM, AUX1PWM);
      #else
        #if OutputSerial == 1
          Serial.println("INFO: write disabled by configuration / eeprom_update_pwm()");
        #endif        
      #endif      
    }

    if( EnableAux2_Button == 1 && EEPROM.read(AUX2_EEPROM) != AUX2PWM ){
      #if OutputSerial == 1
        Serial.print("INFO: AUX2 EEPROM address ");
        Serial.print(AUX2_EEPROM);
        Serial.print(" write value ");
        Serial.print(AUX2PWM);
        Serial.println(" / eeprom_update_pwm()");
      #endif
      
      #if EEPROMWrite == 1
        EEPROM.write(AUX2_EEPROM, AUX2PWM);
      #else
        #if OutputSerial == 1
          Serial.println("INFO: write disabled by configuration / eeprom_update_pwm()");
        #endif
      #endif      
    }

    if( EnableAux3_Button == 1 && EEPROM.read(AUX3_EEPROM) != AUX3PWM ){
      #if OutputSerial == 1
        Serial.print("INFO: AUX3 EEPROM address ");
        Serial.print(AUX3_EEPROM);
        Serial.print(" write value ");
        Serial.print(AUX3PWM);
        Serial.println(" / eeprom_update_pwm()");
      #endif
      
      #if EEPROMWrite == 1
        EEPROM.write(AUX3_EEPROM, AUX3PWM);
      #else
        #if OutputSerial == 1
          Serial.println("INFO: write disabled by configuration / eeprom_update_pwm()");
        #endif
      #endif
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
  #if OutputSerial == 1 && DebugMultiplexer == 0
    Serial.println("ran release_key()");
  #endif

  #if OutputKeyboard == 1 && DebugMultiplexer == 0
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
  #endif
}


#if OutputSerial == 1
// returns keyboard string value for constant - NULL on failure
void key_int2str( int value, int mod ) {
  #define asize 28
  int Code[asize] = { 16395, 16393, 16392, 16391, 16397, 16405, 16402, 16396, 16390, 16389, 16394, 16399, 16388, 16401, 16413, 16411, 16414, 16398, 16418, 16406, 16407, 16408, 16409, 16410, 16412, 16404, 16403, 16400 };
  char Key[asize] = { 'h', 'f', 'e', 'd', 'j', 'r', 'o', 'i', 'c', 'b', 'g', 'l', 'a', 'n', 'y', 'x', '1', 'k', '5', 's', 't', 'u', 'v', 'w', 'z', 'q', 'p', 'm'  };

  //hardcode some values
  if( value == 16425 ){
    Serial.print("<ESC>");
    return;
  }else if( value == 16428 ){
    Serial.print("<SPACE>");
    return;
  }else if( value == 61520 ){
    Serial.print("<LEFT-ARROW>");
    return;
  }else if( value == 61519 ){
    Serial.print("<RIGHT-ARROW>");
    return;
  }else if( value == 61522 ){
    Serial.print("<UP-ARROW>");
    return;
  }else if( value == 61521 ){
    Serial.print("<DOWN-ARROW>");
    return;
  }

  for( int i=0 ; i < asize ; i++ ){
    
    if( Code[i] == value ){
      if( mod == 0 ) {
         Serial.print( Key[i] );
      }else{
        String upper = Key[i];
        Serial.print( upper.toUpperCase() );
      }
      return;
    }
  }
}
#endif


