
#define ledPin 13
#define BootUpDelay 1000 //Delay between power on and "ready", set to 0 (zero) to disable
#define delayBtn 75 //debounce for push button switches

byte Devices[4] = { A7, A9, A8, A6 };

#define DevicesP9  0 //4051 pin selection
#define DevicesP10 1 //4051 pin selection
#define DevicesP11 2 //4051 pin selection

// 4051 seletion matrix
int ChannelActive[8][3] = { {0,0,0}, {1,0,0}, {1,1,0}, {1,0,1}, {1,1,1}, {0,1,0}, {0,1,1}, {0,0,1} };

//holds time stamp when button was pressed, 0 if not pressed
unsigned int ButtonState[4][8] = { {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0} };
// set to 1 once the assinged key has been executed, used to ensure one key press is only sent once
unsigned int ButtonExecuted[4][8] = { {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0} };

// 
int ButtonModifier[4][8] = { { MODIFIERKEY_SHIFT,MODIFIERKEY_SHIFT,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0} };
int ButtonKey[4][8] = { {KEY_0,KEY_9,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0} };
int ButtonHold[4][8] = { {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0} };

int AnalVal = 0;
byte ButtonReturn = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  delay(BootUpDelay);

  pinMode(DevicesP9, OUTPUT);
  pinMode(DevicesP10, OUTPUT);
  pinMode(DevicesP11, OUTPUT);

  analogReadResolution(12);
  
  Serial.begin(115200);
  Serial.println("Modular Open Button Box (MOBB) ready...");

}

void send_key( int key, int del, int mod=0, int btnhold=0 ){
    Keyboard.set_modifier(mod);
    Keyboard.set_key1(key);
    Keyboard.send_now();
  if( btnhold == 0 ){
    delay(del); //iRacing will not detect the key without a delay
    release_key();
  }
}

void release_key(){
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
}

/**
 * checks analog buttons connected to 4051 multi plexers
 */
void CheckButtons(){

  unsigned int ftime = millis(); //function time used for button press
  
  for( int i=0 ; i < 8 ; i++ ){
    // select 74HC4051 channel 5 (of 0 to 7)
    digitalWrite(DevicesP9, ChannelActive[i][0]);
    digitalWrite(DevicesP10, ChannelActive[i][1]);
    digitalWrite(DevicesP11, ChannelActive[i][2]);
    
    // allow 50 us for signals to stablize
    delayMicroseconds(50);
  
    for( int d=0 ; d < 4 ; d++ ) {
  
      AnalVal = analogRead(Devices[d]);
      if( AnalVal < 5 ){
        if( ButtonState[d][i] == 0 ){
          //press has been registed, store time
          ButtonState[d][i] = millis();
          
        }else if( ButtonState[d][i] + delayBtn < ftime ){
          //button is still pressed
          
          if( ButtonExecuted[d][i] == 0 ){
            ButtonExecuted[d][i] = 1;
            Serial.print("Device ");
            Serial.print(d);
            Serial.print(" - Pin ");
            Serial.print(i);
            Serial.println("  EXECUTE ");
            send_key(ButtonKey[d][i], delayBtn, ButtonModifier[d][i], ButtonHold[d][i] );
          }
        }


      }else{
        if( ButtonExecuted[d][i] == 1 && ButtonHold[d][i] == 1 ){
          release_key();
        }        
        ButtonState[d][i] = 0;
        ButtonExecuted[d][i] = 0;
      }
    }
  }

}

void loop() {


  CheckButtons();

//  for( int d=0 ; d < 4 ; d++){
//    for( int i=0 ; i < 8 ; i++ ){
//      if( ButtonState[d][i] > 0 ){
//        Serial.print("Device ");
//        Serial.print(d);
//        Serial.print(" - Pin ");
//        Serial.print(i);
//        Serial.print("   ");
//        Serial.println( ButtonState[d][i]);
//      }
//    }
//  }




  
}




