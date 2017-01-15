/* code checking the toggle switches goes here */
#if EnableMultiplexer == 0


void check_buttons(){
  
  check_button( PushPutton1, Button_1_Key, Button_1_Mod, Button_1_Hold );
  
  check_button( PushPutton2, Button_2_Key, Button_2_Mod, Button_2_Hold );
  
  check_button( PushPutton3, Button_3_Key, Button_3_Mod, Button_3_Hold );
  
  check_button( PushPutton4, Button_4_Key, Button_4_Mod, Button_4_Hold );
  
  check_button( PushPutton5, Button_5_Key, Button_5_Mod, Button_5_Hold );
  
  check_button( PushPutton6, Button_6_Key, Button_6_Mod, Button_6_Hold );
  
  check_button( PushPutton7, Button_7_Key, Button_7_Mod, Button_7_Hold );
  
  check_button( PushPutton8, Button_8_Key, Button_8_Mod, Button_8_Hold );
  
  check_button( PushPutton9, Button_9_Key, Button_9_Mod, Button_9_Hold );
  
  check_button( PushPutton10, Button_10_Key, Button_10_Mod, Button_10_Hold );
  
  check_button( PushPutton11, Button_11_Key, Button_11_Mod, Button_11_Hold );
  
  check_button( PushPutton12, Button_12_Key, Button_12_Mod, Button_12_Hold );
  
  check_button( PushPutton13, Button_13_Key, Button_13_Mod, Button_13_Hold );
  
  check_button( PushPutton14, Button_14_Key, Button_14_Mod, Button_14_Hold );
}

#endif


void check_button( Bounce &btn, int key, int mod, int btnhold ){
  if (btn.update()) {
    if (btn.fallingEdge()) {
        send_key(key, BUTTON_HOLD, mod, btnhold );
    }
    if (btnhold == 1 && btn.risingEdge()) {
        release_key();
    }
  }
}


