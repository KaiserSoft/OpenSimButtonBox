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
  Bounce(Button_10_Pin, BUTTON_DEBOUNCE),
  Bounce(Button_11_Pin, BUTTON_DEBOUNCE)
};

/* serial receive stuff */
boolean serial_done = false;
String serial_cmd;  // holds the received command
boolean button_enabled = false; //don't send commands until the nano is connected to the PC

#define debug_delay  2000
unsigned long debug_last = 0;

void setup() {
  Serial.begin(115200);
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
        Serial.print("B-WTF!");
        Serial.println(ButtonKey[num]);
    }
  }
}


void loop() {
  /* listen for program connection from PC */
  if (serial_done == true) {
    if( serial_cmd == "wr-rdy"){
      Serial.println("nano ready");
      debug_last = millis();
      button_enabled = true;
    }else if( serial_cmd == "wr-stop" ){
      Serial.println("nano stop");
      button_enabled = false;
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
