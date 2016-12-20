
#define ledPin 13
#define BootUpDelay 1000 //Delay between power on and "ready", set to 0 (zero) to disable
#define Debounce 25 //Debounce in ms

#define ABCDS0 A9 //analog read pins - connects to Pin 3 on 4051
#define ABCDS1 A8 //analog read pins - connects to Pin 3 on 4051
#define ABCDS2 A7 //analog read pins - connects to Pin 3 on 4051
#define ABCDS3 A6 //analog read pins - connects to Pin 3 on 4051

byte Devices[4] = {A7, A9, A8, A6 };

#define DevicesP9  0 //4051 pin selection
#define DevicesP10 1 //4051 pin selection
#define DevicesP11 2 //4051 pin selection

// 4051 seletion matrix
int ChannelActive[8][3] = { {0,0,0}, {1,0,0}, {1,1,0}, {1,0,1}, {1,1,1}, {0,1,0}, {0,1,1}, {0,0,1} };

byte AS1 = 0;
byte AS2 = 0;
byte AS3 = 0;

int AnalVal = 0;

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

void loop() {

  for( int i=0 ; i < 8 ; i++ ){
    // select 74HC4051 channel 5 (of 0 to 7)
    digitalWrite(DevicesP9, ChannelActive[i][0]);
    digitalWrite(DevicesP10, ChannelActive[i][1]);
    digitalWrite(DevicesP11, ChannelActive[i][2]);
    
    // allow 50 us for signals to stablize
    delayMicroseconds(50);

    for( byte d=0 ; d < 4 ; d++ ) {

      AnalVal = analogRead(Devices[d]);
      if( AnalVal < 5 ){
        Serial.print("Device ");
        Serial.print(d);
        Serial.print(" - Pin ");
        Serial.print(i);
        Serial.print(" - Val  ");
        Serial.print(AnalVal);
        Serial.print("   ");
        Serial.println(millis());
        //Serial.println(analogRead(ABCDS0));
        delay(1000);
      }
    }

  }
  

  


  

 


  //Select new pins
//  if( AS1 == 0 && AS2 == 0 && AS3 == 0 ){
//    AS1 = 1;
//  }else if( AS1 == 1 && AS2 == 0 && AS3 == 0 ){
//    AS2 = 1;
//  }else if( AS1 == 1 && AS2 == 1 && AS3 == 0 ){
//    AS3 = 1;
//  }else if( AS1 == 1 && AS2 == 1 && AS3 == 1 ){
//    AS1 = 0;
//    AS2 = 0;
//  }else if( AS1 == 0 && AS2 == 0 && AS3 == 1 ){
//    AS2 = 1;
//  }else if( AS1 == 0 && AS2 == 1 && AS3 == 1 ){
//    AS3 = 0;
//  }else if( AS1 == 0 && AS2 == 1 && AS3 == 0 ){
//    AS1 = 1;
//    AS2 = 0;
//    AS3 = 1;
//  }else if( AS1 == 1 && AS2 == 0 && AS3 == 1 ){
//    AS1 = 0;
//    AS2 = 0;
//    AS3 = 0;
//  }

// Debug pin walk
//  Serial.print(AS1);
//  Serial.print(" ");
//  Serial.print(AS2);
//  Serial.print(" ");
//  Serial.println(AS3);
//  delay(500);

  
}
