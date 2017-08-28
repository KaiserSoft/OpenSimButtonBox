/*
 * Stand Alone Wheel Button Box for the Arduino Nano
 * The buttons for the wheel button box may be connected to the MOBB-PCB or to an
 * Arduino Nano using this code
 * 
 * 
*/

/* developemnt stuff - remove when done */
#define enable_fake_keys false //ignore button presses and send fake keys instead
#define debug_delay  2000
unsigned long debug_last = 0;
#define testing_oled false
/* developemnt stuff - remove when done */


#include "CONFIG.h"
#include <EEPROM.h>


/*keep times of button presses */
unsigned long ButtonPressed[13]; //stores the time when the key press has been detected
unsigned long ButtonSend[13];    //stores last time the key has been sent to the computer
unsigned long JoystickMoved[2];  //stores the time when a joystick move has been detected
unsigned long JoystickSend[2];   //stores last time the key has been sent to the computer


/* setup array to make processing buttons simpler */
byte ButtonPins[13] = { Button_1_Pin, Button_2_Pin, Button_3_Pin, Button_4_Pin,
                        Button_5_Pin, Button_6_Pin, Button_7_Pin, Button_8_Pin,
                        Button_9_Pin, Button_10_Pin, Button_11_Pin, Button_12_Pin, 
                        Button_13_Pin };

/* setup array for joystick to make it simpler to read it */
byte JoystickPins[2] = { Joystick_1_Pin, Joystick_2_Pin };
int  JoyStickCenters[2] = { Joystick_1_Center, Joystick_2_Center };
int  JoyStickMoveMin[2] = { Joystick_1_Move_Min, Joystick_2_Move_Min };

/* serial receive stuff */
boolean serial_done = false;
String serial_cmd;  // holds the received command
boolean button_enabled = false; //don't send commands until the nano is connected to the PC


void setup() {
  for( byte x=0 ; x < sizeof(ButtonPins)/sizeof(byte) ; ++x ){
    pinMode( ButtonPins[x], INPUT_PULLUP);
    ButtonPressed[x] = 0;
    ButtonSend[x] = 0;
  }
  for( byte x=0 ; x < sizeof(JoystickPins)/sizeof(byte) ; ++x ){
    pinMode( JoystickPins[x], INPUT);
    JoystickMoved[x] = 0;
    JoystickSend[x] = 0;
  }

  #if testing_oled == true
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  #endif

  Serial.begin(115200);
  digitalWrite( LED_BUILTIN, LOW);

}


void loop() {
  /* listen for commands from PC */
  if (serial_done == true)
  {
    if( serial_cmd == "wr"){
      Serial.println("nr");
      button_enabled = true;
      #if enable_fake_keys == true
        debug_last = millis();
      #endif
      
    }else if( serial_cmd == "ws" ){
      Serial.println("ns");      
      button_enabled = false;
      
    }else{
      Serial.print("invalid ");
      Serial.println(serial_cmd);
    }
    serial_done = false;
    serial_cmd = "";
  }


  /* using random to fake button presses for development 
   *  this must be removed for release  */
  #if enable_fake_keys == true
    if( random(0, 2) == 1 ){
      check_buttons();
    }else{
      check_joystick();
    }
  #else
    check_buttons();
    check_joystick();
    check_button_hold();
  #endif

}


/* sends keypresses over serial com port */
void sendKey( char KeyType, byte KeyValue){
  #if enable_fake_keys == true
    debug_last = millis();
  #endif
  Serial.print(KeyType);
  Serial.println(KeyValue);
}

/* checks if the joystick has been moved */
void check_joystick(){  
  if( button_enabled != true ){ return; }
  int joyval = 0;

  #if enable_fake_keys == true
    if( millis() < debug_last + debug_delay ){
      return;
    }
  #endif

  for( byte x = 0 ; x < sizeof(JoystickPins)/sizeof(byte) ; x++ ){
    joyval = analogRead(JoystickPins[x]);

    #if enable_fake_keys == true
      //fake for testing
      x = random(0, 2);
      if( random(1,3) > 1 ){
        joyval = random(512, 1024);
      }else{
        joyval = random(0, 512);
      }
    #endif
    

    if( JoystickSend[x] + JOYSTICK_REPEAT < millis() )
    {
      if( joyval > (JoyStickCenters[x] + JoyStickMoveMin[x]) ){
        JoystickSend[x] = millis();
        JoystickMoved[x] = millis();
        sendKey( 'J', x+1);
        return;
      }else if( joyval < (JoyStickCenters[x] - JoyStickMoveMin[x]) ){
        JoystickSend[x] = millis();
        JoystickMoved[x] = millis();
        sendKey( 'K', x+1);
        return;
      }
    }
  }
}



/* checks all buttons and sends key when one has been pressed */
void check_buttons(){
  if( button_enabled != true ){ return; }

  #if enable_fake_keys == true
    if( millis() < debug_last + debug_delay ){
      return;
    }
  
    int fake = random(0, (sizeof(ButtonPins)/sizeof(byte)));
    sendKey( 'B', fake + 1);
    return;
  #endif

  

  for( byte x=0 ; x < sizeof(ButtonPins)/sizeof(byte) ; ++x ){
    if (CheckButtonPressed(ButtonPins[x]) == true ) {
     
        ButtonPressed[x] = millis();
        sendKey( 'B', x + 1);
        ButtonSend[x] = millis();

    }
  }

}

boolean CheckButtonPressed( int btn ){
  if( digitalRead(btn) == HIGH ){
    return true;
  }else{
    return false;
  }
}


/* checks if buttons are held down */
void check_button_hold(){  
  if( button_enabled != true ){ return; }
  
  for( byte x=0 ; x < sizeof(ButtonPressed)/sizeof(unsigned long) ; ++x ){
    
    // check if button is held down
    if( ButtonPressed[x] > 0 ){
      if( ButtonPressed[x] + BUTTON_WAIT_HOLD < millis() ){
        //button is beeing held down
        if( ButtonSend[x] + BUTTON_REPEAT < millis() ){
          //time is up - resend the key
          sendKey( 'B', x + 1);
          ButtonSend[x] = millis();
        }
      }
    }

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
