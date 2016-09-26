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
  
  newLeft = knobLeft.read()/4;
  newCenter = knobCenter.read()/4;
  newRight = knobRight.read()/4;
  if (newLeft != positionLeft || newCenter != positionCenter || newRight != positionRight ){

      if( newLeft > positionLeft ){
        #ifdef OutputSerial
          Serial.println("EncLeft:left ");
        #endif
        send_key(Encoder1KeyA, delayEnc, Encoder1ModA );
        
      }else if( newLeft < positionLeft ){
        #ifdef OutputSerial
          Serial.println("EncLeft:right ");
        #endif
        send_key(Encoder1KeyB, delayEnc, Encoder1ModB );
      }

      if( newCenter > positionCenter ){
        #ifdef OutputSerial
          Serial.println("EncCenter:left ");
        #endif
        send_key(Encoder2KeyA, delayEnc, Encoder2ModA );
        
      }else if( newCenter < positionCenter ){
        #ifdef OutputSerial
          Serial.println("EncCenter:right ");
        #endif
        send_key(Encoder2KeyB, delayEnc, Encoder2ModB );
      }


      if( newRight > positionRight ){
        #ifdef OutputSerial
          Serial.println("EncRight:left ");
        #endif
        send_key(Encoder3KeyA, delayEnc, Encoder3ModA );
        
      }else if( newRight < positionRight ){
        #ifdef OutputSerial
          Serial.println("EncRight:right ");
        #endif
        send_key(Encoder3KeyB, delayEnc, Encoder3ModB );
      }


      positionLeft = newLeft;
      positionCenter = newCenter;
      positionRight = newRight;
  }
}
