/* code checking multi plexed push buttons goes here */


// array of analog pins used by the connected multi plexer
byte Devices[4] = { Multiplexer1, Multiplexer2, Multiplexer3, Multiplexer4 };


// action for every button
int ButtonKey[4][8] = { { Button_1_Key, Button_2_Key, Button_3_Key, Button_4_Key, Button_5_Key, Button_6_Key, Button_7_Key, Button_8_Key }
                            , { Button_9_Key, Button_10_Key, Button_11_Key, Button_12_Key, Button_13_Key, Button_14_Key, Button_15_Key, Button_16_Key }
                            , { Button_17_Key, Button_18_Key, Button_19_Key, Button_20_Key, Button_21_Key, Button_22_Key, Button_23_Key, Button_24_Key }
                            , { Button_25_Key, Button_26_Key, Button_27_Key, Button_28_Key, Button_29_Key, Button_30_Key, Button_31_Key, Button_32_Key } };

int ButtonModifier[4][8] = { { Button_1_Mod, Button_2_Mod, Button_3_Mod, Button_4_Mod, Button_5_Mod, Button_6_Mod, Button_7_Mod, Button_8_Mod }
                            , { Button_9_Mod, Button_10_Mod, Button_11_Mod, Button_12_Mod, Button_13_Mod, Button_14_Mod, Button_15_Mod, Button_16_Mod }
                            , { Button_17_Mod, Button_18_Mod, Button_19_Mod, Button_20_Mod, Button_21_Mod, Button_22_Mod, Button_23_Mod, Button_24_Mod }
                            , { Button_25_Mod, Button_26_Mod, Button_27_Mod, Button_28_Mod, Button_29_Mod, Button_30_Mod, Button_31_Mod, Button_32_Mod } };

int ButtonHold[4][8] = { { Button_1_Hold, Button_2_Hold, Button_3_Hold, Button_4_Hold, Button_5_Hold, Button_6_Hold, Button_7_Hold, Button_8_Hold }
                            , { Button_9_Hold, Button_10_Hold, Button_11_Hold, Button_12_Hold, Button_13_Hold, Button_14_Hold, Button_15_Hold, Button_16_Hold }
                            , { Button_17_Hold, Button_18_Hold, Button_19_Hold, Button_20_Hold, Button_21_Hold, Button_22_Hold, Button_23_Hold, Button_24_Hold }
                            , { Button_25_Hold, Button_26_Hold, Button_27_Hold, Button_28_Hold, Button_29_Hold, Button_30_Hold, Button_31_Hold, Button_32_Hold } };

// Multiplexer 4051  pin 9, 10 and 11 channel selection
int ChannelActive[8][3] = { {0,0,0}, {0,0,1}, {0,1,0}, {0,1,1}, {1,0,0}, {1,0,1}, {1,1,0}, {1,1,1} };

//holds time stamp when button was pressed, 0 if not pressed
unsigned int ButtonState[4][8] = { {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0} };
// set to 1 once the assinged key has been executed, used to ensure one key press is only sent once
unsigned int ButtonExecuted[4][8] = { {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0} };

// holds return from analog read
unsigned int AnalogValue = 0;



void check_multiplexed_buttons(){
  #if OutputSerial == 1 && DebugMultiplexer == 1
    boolean SerialMultiDebugStart = false; //truen when pin line has been send
    boolean SerialMultiDebugOut = false; //true when something was printed this run
  #endif
  
  unsigned int ftime = millis(); //function time used for button press
  
  for( int i=0 ; i < 8 ; i++ ){
    #if OutputSerial == 1 && DebugMultiplexer == 1
      SerialMultiDebugStart = false;
    #endif

    // select 74HC4051 channel 5 (of 0 to 7)
    digitalWrite(MultiplexerP9, ChannelActive[i][0]);
    digitalWrite(MultiplexerP10, ChannelActive[i][1]);
    digitalWrite(MultiplexerP11, ChannelActive[i][2]);
    
    // allow 50 us for signals to stablize
    delayMicroseconds(50);

  
    for( int d=0 ; d < 4 ; d++ ) {
  
      AnalogValue = analogRead(Devices[d]);

      #if OutputSerial == 1 && DebugMultiplexer == 1
        if( SerialMultiDebugStart == false && AnalogValue < AnalogLowerLimit ) {
          Serial.print("Mpin:");
          Serial.print(i);
          SerialMultiDebugStart = true;
          SerialMultiDebugOut = true;
        }
      
        if( AnalogValue < AnalogLowerLimit ){
          Serial.print(" / Tpin: ");
          Serial.print(Devices[d]);
          Serial.print(" dev:");
          Serial.print(d);
          Serial.print(" val:");
          Serial.print(AnalogValue);
        }
      #endif
      
      if( AnalogValue < AnalogLowerLimit ){
        if( ButtonState[d][i] == 0 ){
          //press has been registed, store time
          ButtonState[d][i] = millis();
          
        }else if( ButtonState[d][i] + BUTTON_HOLD < ftime ){
          //button is still pressed
          
          if( ButtonExecuted[d][i] == 0 ){
            #if OutputSerial == 1 && DebugMultiplexer == 0 
              Serial.println();
              Serial.print("Multiplexer: ");
              Serial.print(d);
              Serial.print(" / Pin ");
              Serial.print(i);
              Serial.print(" / Value ");
              Serial.print(AnalogValue);
              Serial.print(" / ButtonMod ");
              Serial.print(ButtonModifier[d][i]);
              Serial.print(" / AuxMod ");
              Serial.print(AUX1_Button_Mod);
              Serial.println(" / check_multiplexed_buttons()");
            #endif

              
            //check if AUX control is enabled
            #if EnableAux1 == 1 && EnableAux1_Button == 1
              if( AUX1_Button == ButtonKey[d][i] && AUX1_Button_Mod == ButtonModifier[d][i] ){
                  AUX1Pressed = millis();
                  #if AUX_LED_Enable == 1
                    analogWrite(AUX_LED_Pin, AUX_LED_PWD);
                  #endif
                  AUX2Pressed = 0;
                  AUX3Pressed = 0;
                #if OutputSerial == 1 && DebugMultiplexer == 0
                  if( AUX1_Button_Auto_Hold > 0 ) {
                    Serial.print("AUX1 pressed (hold) / PWM ");
                  }else{
                    Serial.print("AUX1 pressed / PWM ");
                  }
                  Serial.print(AUX1PWM);
                  Serial.print(" / AnalogValue ");
                  Serial.print(AnalogValue);
                  Serial.println(" / check_multiplexed_buttons()");
                #endif
                
              }
            #endif
            
            #if EnableAux2 && EnableAux2_Button == 1
              if( AUX2_Button == ButtonKey[d][i] && AUX2_Button_Mod == ButtonModifier[d][i] ){
                  AUX2Pressed = millis();
                  #if AUX_LED_Enable == 1
                    analogWrite(AUX_LED_Pin, AUX_LED_PWD);
                  #endif
                  AUX1Pressed = 0;
                  AUX3Pressed = 0;
                #if OutputSerial == 1 && DebugMultiplexer == 0
                  if( AUX2_Button_Auto_Hold > 0 ) {
                    Serial.print("AUX2 pressed (hold) / PWM ");
                  }else{
                    Serial.print("AUX2 pressed / PWM ");
                  }
                  Serial.print(AUX2PWM);
                  Serial.print(" / AnalogValue ");
                  Serial.print(AnalogValue);
                  Serial.println(" / check_multiplexed_buttons()");
                #endif

                
              }
            #endif
              
            #if EnableAux3 == 1 && EnableAux3_Button == 1
              if( AUX3_Button == ButtonKey[d][i] && AUX3_Button_Mod == ButtonModifier[d][i] ){
                  AUX3Pressed = millis();
                  #if AUX_LED_Enable == 1
                    analogWrite(AUX_LED_Pin, AUX_LED_PWD);
                  #endif
                  AUX1Pressed = 0;
                  AUX2Pressed = 0;
                #if OutputSerial == 1 && DebugMultiplexer == 0
                  if( AUX3_Button_Auto_Hold > 0 ) {
                    Serial.print("AUX3 pressed (hold) / PWM ");
                  }else{
                    Serial.print("AUX3 pressed / PWM ");
                  }
                  Serial.print(AUX3PWM);
                  Serial.print(" / AnalogValue ");
                  Serial.print(AnalogValue);
                  Serial.println(" / check_multiplexed_buttons()");
                #endif
              }
            #endif

            if( AUX1Pressed == 0 && AUX2Pressed == 0 && AUX3Pressed == 0   ){
              send_key(ButtonKey[d][i], BUTTON_HOLD, ButtonModifier[d][i], ButtonHold[d][i] );
            }
            
            
            ButtonExecuted[d][i] = 1;
          }
        }


      }else{
       
          if( AUX1Pressed == 0 && AUX2Pressed == 0 && AUX3Pressed == 0   ){
            if( ButtonExecuted[d][i] == 1 && ButtonHold[d][i] == 1 ){
              release_key();
            }
          }        


        #if EnableAux1 == 1 && EnableAux1_Button == 1 && AUX1_Button_Auto_Hold == 0
          if( ButtonExecuted[d][i] == 1 && AUX1_Button == ButtonKey[d][i] && AUX1_Button_Mod == ButtonModifier[d][i] ){
            AUX2Pressed = 0;
            #if AUX_LED_Enable == 1
              analogWrite(AUX_LED_Pin, 0);
            #endif
            #if OutputSerial == 1
              Serial.print("AUX1 released / PWM ");
              Serial.print(AUX1PWM);
              Serial.print(" / AnalogValue ");
              Serial.print(AnalogValue);
              Serial.println(" / check_multiplexed_buttons()");
            #endif
          }
        #endif

        #if EnableAux2 == 1 && EnableAux2_Button == 1 && AUX2_Button_Auto_Hold == 0
          if( ButtonExecuted[d][i] == 1 && AUX2_Button == ButtonKey[d][i] && AUX2_Button_Mod == ButtonModifier[d][i] ){
            AUX2Pressed = 0;
            #if AUX_LED_Enable == 1
              analogWrite(AUX_LED_Pin, 0);
            #endif
            #if OutputSerial == 1
              Serial.print("AUX2 released / PWM ");
              Serial.print(AUX2PWM);
              Serial.print(" / AnalogValue ");
              Serial.print(AnalogValue);
              Serial.println(" / check_multiplexed_buttons()");
            #endif
          }
        #endif

        #if EnableAux3 == 1 && EnableAux3_Button == 1 && AUX3_Button_Auto_Hold == 0
          if( ButtonExecuted[d][i] == 1 && AUX3_Button == ButtonKey[d][i] && AUX3_Button_Mod == ButtonModifier[d][i] ){
              AUX3Pressed = 0;
            #if AUX_LED_Enable == 1
              analogWrite(AUX_LED_Pin, 0);
            #endif
              #if OutputSerial == 1
                Serial.print("AUX3 released / PWM ");
                Serial.print(AUX3PWM);
                Serial.print(" / AnalogValue ");
                Serial.print(AnalogValue);
                Serial.println(" / check_multiplexed_buttons()");
              #endif
          }
        #endif

        ButtonState[d][i] = 0;
        ButtonExecuted[d][i] = 0;
      }

      
    }

  }

  #if OutputSerial == 1 && DebugMultiplexer == 1
    if( SerialMultiDebugOut == true ){
      Serial.println("");
    }
    delay(1000);
  #endif

}


