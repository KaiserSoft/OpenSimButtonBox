/*
 * Stand Alone Wheel Button Box for the Arduino Nano
 * The buttons for the wheel button box may be connected to the MOBB-PCB or to an
 * Arduino Nano using this code
 * 
 * Designed for an Arduino Nano running at 16MHz
 */
#include "CONFIG.h"
#include "BUTTONS.h"
#include "Bounce2.h"
#include <EEPROM.h>

#define LED 13

// Paddle_1_Pin and Paddle_2_Pin used here or as interrupt .. this may
// be enough since it is only a few pins
Bounce Buttons[11] = {
  Bounce(Button_1_Pin, BUTTON_DEBOUNCE),
  Bounce(Button_2_Pin, BUTTON_DEBOUNCE),
  Bounce(Button_3_Pin, BUTTON_DEBOUNCE),
  Bounce(Button_4_Pin, BUTTON_DEBOUNCE),
  Bounce(Button_5_Pin, BUTTON_DEBOUNCE),
  Bounce(Button_6_Pin, BUTTON_DEBOUNCE),
  Bounce(Button_7_Pin, BUTTON_DEBOUNCE),
  Bounce(Button_8_Pin, BUTTON_DEBOUNCE),
  Bounce(Button_9_Pin, BUTTON_DEBOUNCE),
  Bounce(Paddle_1_Pin, BUTTON_DEBOUNCE),
  Bounce(Paddle_2_Pin, BUTTON_DEBOUNCE)
};

/* serial receive stuff */
boolean serial_done = false;
String serial_cmd;  // holds the received command
boolean button_enabled = false; //don't send commands until the nano is connected to the PC

#define debug_delay  2000
unsigned long debug_last = 0;

void setup() {
  pinMode( Button_1_Pin, INPUT_PULLUP);
  pinMode( Button_2_Pin, INPUT_PULLUP);
  pinMode( Button_3_Pin, INPUT_PULLUP);
  pinMode( Button_4_Pin, INPUT_PULLUP);
  pinMode( Button_5_Pin, INPUT_PULLUP);
  pinMode( Button_6_Pin, INPUT_PULLUP);
  pinMode( Button_7_Pin, INPUT_PULLUP);
  pinMode( Button_8_Pin, INPUT_PULLUP);
  pinMode( Button_9_Pin, INPUT_PULLUP);
  pinMode( Paddle_1_Pin, INPUT_PULLUP);
  pinMode( Paddle_2_Pin, INPUT_PULLUP);
  
  Serial.begin(115200);
  digitalWrite( LED_BUILTIN, LOW);

  //not sure if this is required, need to test
  //attachInterrupt(digitalPinToInterrupt(Paddle_1_Pin), ISR_Paddle_1, LOW); 
  //attachInterrupt(digitalPinToInterrupt(Paddle_2_Pin), ISR_Paddle_2, LOW); 
}



void check_button( int num ){
  if( button_enabled != true ){ return; }

  if( millis() < debug_last + debug_delay ){
    return;
  }
  debug_last = millis();
  
  int fake = random(0,13);
  if( fake < 11 ){
    Serial.print("B");
    Serial.println(ButtonKey[fake]);
  }else{
    Serial.print("J");
    Serial.println(random(1,3));
  }


  if (Buttons[num].update()) {
    if (Buttons[num].fallingEdge()) {
        //Serial.print("B");
        Serial.print("FLOATING-"); //for testing, set to "B" when using actual buttons
        Serial.println(ButtonKey[num]);
    }
  }
}


void loop() {
  boolean led_state = false;
  
  /* listen for program connection from PC */
  if (serial_done == true) {
    if( serial_cmd == "wr"){
      Serial.println("nr");
      debug_last = millis();
      button_enabled = true;
      
    }else if( serial_cmd == "ws" ){
      Serial.println("ns");      
      button_enabled = false;
      for( int x=0 ; x < 20 ; ++x){
        if( led_state == true ){
          digitalWrite(LED_BUILTIN, LOW);
          led_state = false;
        }else{
          digitalWrite(LED_BUILTIN, HIGH);
          led_state = true;
        }
        delay(125);
      }
      digitalWrite(LED_BUILTIN, LOW);
      
    }else{
      Serial.print("invalid ");
      Serial.println(serial_cmd);
    }
    serial_done = false;
    serial_cmd = "";
  }
  
  for( int x=0 ; x < 11 ; ++x ){
    check_button( x );
  }


}



/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();

    if (inChar == '\n' || inChar == '\r' ) {
      serial_done = true;
    }else{
      serial_cmd += inChar;
    }
  }
}
