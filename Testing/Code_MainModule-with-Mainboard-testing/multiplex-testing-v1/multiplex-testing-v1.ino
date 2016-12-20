
#define ledPin 13
#define BootUpDelay 1000 //Delay between power on and "ready", set to 0 (zero) to disable

#define ABCDS0 22
#define ABCDS1 23
#define ABCDS2 21

#define Device1 A6 //analog - connects to Pin 3 on first 4051
//#define Device2 1 //analog - connects to Pin 3 on second 4051
//#define Device3 2 //analog - connects to Pin 3 on third 4051
//#define Device4 3 //analog - connects to Pin 3 on fourth 4051

long knobPin0channel5  = 0;
long knobPin1channel5  = 0;
long knobPin2channel5  = 0;
long knobPin3channel5  = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  delay(BootUpDelay);

  pinMode(ABCDS0, OUTPUT);
  pinMode(ABCDS1, OUTPUT);
  pinMode(ABCDS2, OUTPUT);
  
  Serial.begin(115200);
  Serial.println("Modular Open Button Box (MOBB) ready...");

}

void loop() {
// select 74HC4051 channel 5 (of 0 to 7)
  digitalWrite(ABCDS0, HIGH);
  digitalWrite(ABCDS1, LOW);
  digitalWrite(ABCDS2, HIGH);
  
  // allow 50 us for signals to stablize
  delayMicroseconds(50);

  analogReadResolution(16);
  // read the signals routed to pins 10, 19, 20
  // through channel 5 of each 74HC4051 chip
  //buttonPin10channel5.update();
//  knobPin0channel5 = analogRead(Device1);
//  knobPin1channel5 = analogRead(Device2);
//  knobPin2channel5 = analogRead(Device3);
//  knobPin3channel5 = analogRead(Device4);

//  Serial.print(knobPin0channel5);
//  Serial.print(" ");
//  Serial.print(knobPin1channel5);
//  Serial.print(" ");
//  Serial.print(knobPin2channel5);
//  Serial.print(" ");
//  Serial.print(knobPin3channel5);
//  Serial.print(" ");
//  Serial.println();

Serial.println(analogRead(Device1));

  delay(1500);
}
