/* code for rotary encoders goes here */


#if EnableMultiplexer == 0
/* check push buttons of encoders */
void check_encoder_switches(){

  check_button( EncButton1, Encoder1KeyC, Encoder1ModC, Encoder1HoldC );
  
  check_button( EncButton2, Encoder2KeyC, Encoder2ModC, Encoder2HoldC );
  
  check_button( EncButton3, Encoder3KeyC, Encoder3ModC, Encoder3HoldC );
}
#endif


/* check rotary encourders */
void check_rotary_encoders(){
  long newLeft, newCenter, newRight;
  int AUX1PWM_new = 0;
  int AUX2PWM_new = 0;
  int AUX3PWM_new = 0;
  
  newLeft = knobLeft.read()/4;
  newCenter = knobCenter.read()/4;
  newRight = knobRight.read()/4;
  if (newLeft != positionLeft || newCenter != positionCenter || newRight != positionRight ){

      if( newLeft > positionLeft ){
        #if OutputSerial == 1
          Serial.println("EncLeft:left ");
        #endif
        send_key(Encoder1KeyA, delayEnc, Encoder1ModA );
        
      }else if( newLeft < positionLeft ){
        #if OutputSerial == 1
          Serial.println("EncLeft:right ");
        #endif
        send_key(Encoder1KeyB, delayEnc, Encoder1ModB );
      }

      if( newCenter > positionCenter ){
        #if OutputSerial == 1
          Serial.println("EncCenter:left ");
        #endif
        send_key(Encoder2KeyA, delayEnc, Encoder2ModA );
        
      }else if( newCenter < positionCenter ){
        #if OutputSerial == 1
          Serial.println("EncCenter:right ");
        #endif
        send_key(Encoder2KeyB, delayEnc, Encoder2ModB );
      }


      if( newRight > positionRight ){
        #if OutputSerial == 1
          Serial.println("EncRight:left ");
        #endif
        if( AUX1Pressed != true && AUX2Pressed != true  && AUX3Pressed != true ) {
          send_key(Encoder3KeyA, delayEnc, Encoder3ModA );
        }else if( AUX1Pressed == true ) {
          AUX1PWM_new = AUX1PWM + AUX1_PWM_CHANGE;
          AUX1PWM = (AUX1PWM_new < AUX1_PWM_MAX ) ? AUX1PWM_new : AUX1_PWM_MAX;
          EEPROM_val_change_last = millis();
        }else if( AUX2Pressed == true ) {
          AUX2PWM_new = AUX2PWM + AUX2_PWM_CHANGE;
          AUX2PWM = (AUX2PWM_new < 255 ) ? AUX2PWM_new : 255;
          EEPROM_val_change_last = millis();
        }else if( AUX3Pressed == true ) {
          AUX3PWM_new = AUX3PWM + AUX3_PWM_CHANGE;
          AUX3PWM = (AUX3PWM_new < 255 ) ? AUX3PWM_new : 255;
          EEPROM_val_change_last = millis();
        }
        
      }else if( newRight < positionRight ){
        #if OutputSerial == 1
          Serial.println("EncRight:right ");
        #endif
        if( AUX1Pressed != true && AUX2Pressed != true  && AUX3Pressed != true ) {
          send_key(Encoder3KeyB, delayEnc, Encoder3ModB );
        }else if( AUX1Pressed == true ) {
          AUX1PWM_new = AUX1PWM - AUX1_PWM_CHANGE;
          AUX1PWM = (AUX1PWM_new > AUX1_PWM_MIN ) ? AUX1PWM_new : 0;
          EEPROM_val_change_last = millis();
        }else if( AUX2Pressed == true ) {
          AUX2PWM_new = AUX2PWM - AUX2_PWM_CHANGE;
          AUX2PWM = (AUX2PWM_new > AUX2_PWM_MIN ) ? AUX2PWM_new : 0;
          EEPROM_val_change_last = millis();
        }else if( AUX3Pressed == true ) {
          AUX3PWM_new = AUX3PWM - AUX3_PWM_CHANGE;
          AUX3PWM = (AUX3PWM_new > AUX3_PWM_MIN ) ? AUX3PWM_new : 0;
          EEPROM_val_change_last = millis();
        }
      }


      positionLeft = newLeft;
      positionCenter = newCenter;
      positionRight = newRight;
  }
}
