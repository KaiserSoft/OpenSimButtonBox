/* code checking the toggle switches goes here */
#if UseMultiplexer == 0


void check_push_buttons(){
  
  check_button( BPutton1, Button_1_Key, Button_1_Mod, Button_1_Hold );
  
  check_button( BPutton2, Button_2_Key, Button_2_Mod, Button_2_Hold );
  
  check_button( BPutton3, Button_3_Key, Button_3_Mod, Button_3_Hold );
  
  check_button( BPutton4, Button_4_Key, Button_4_Mod, Button_4_Hold );
}



void check_toggle_switches(){

  check_button( TSwitchOne_UP, Button_7_Key, Button_7_Mod, Button_7_Hold );
  check_button( TSwitchOne_DOWN, Button_8_Key, Button_8_Mod, Button_8_Hold );

  check_button( TSwitchTwo_UP, Button_9_Key, Button_9_Mod, Button_9_Hold );
  check_button( TSwitchTwo_DOWN, Button_10_Key, Button_10_Mod, Button_10_Hold );

  check_button( TSwitchThree_UP, Button_11_Key, Button_11_Mod, Button_11_Hold );
  check_button( TSwitchThree_DOWN, Button_12_Key, Button_12_Mod, Button_12_Hold );

  check_button( TSwitchFour_UP, Button_13_Key, Button_13_Mod, Button_13_Hold );
  check_button( TSwitchFour_DOWN, Button_14_Key, Button_14_Mod, Button_14_Hold );
  
  check_button( TSwitchFive_UP, Button_15_Key, Button_15_Mod, Button_15_Hold );
  check_button( TSwitchFive_DOWN, Button_16_Key, Button_16_Mod, Button_16_Hold );
}



void check_button( Bounce &btn, int key, int mod, int btnhold ){
  if (btn.update()) {
    if (btn.fallingEdge()) {
        send_key(key, delayBtn, mod, btnhold );
    }
    if (btnhold == 1 && btn.risingEdge()) {
        release_key();
    }
  }
}

#endif
