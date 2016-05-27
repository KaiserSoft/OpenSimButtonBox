/* code checking the toggle switches goes here */



void check_push_buttons(){
  
  check_button( BPutton1, PButton1Key, PButton1Mod, PButton1Hold );
  
  check_button( BPutton2, PButton2Key, PButton2Mod, PButton2Hold );
  
  check_button( BPutton3, PButton3Key, PButton3Mod, PButton3Hold );
  
  check_button( BPutton4, PButton4Key, PButton4Mod, PButton4Hold );
}



void check_toggle_switches(){

  check_button( TSwitchOne_UP, TSwitch1KeyA, TSwitch1ModA, TSwitch1HoldA );
  check_button( TSwitchOne_DOWN, TSwitch1KeyB, TSwitch1ModB, TSwitch1HoldB );

  check_button( TSwitchTwo_UP, TSwitch2KeyA, TSwitch2ModA, TSwitch2HoldA );
  check_button( TSwitchTwo_DOWN, TSwitch2KeyB, TSwitch2ModB, TSwitch2HoldB );

  check_button( TSwitchThree_UP, TSwitch3KeyA, TSwitch3ModA, TSwitch3HoldA );
  check_button( TSwitchThree_DOWN, TSwitch3KeyB, TSwitch3ModB, TSwitch3HoldB );

  check_button( TSwitchFour_UP, TSwitch4KeyA, TSwitch4ModA, TSwitch4HoldA );
  check_button( TSwitchFour_DOWN, TSwitch4KeyB, TSwitch4ModB, TSwitch4HoldB );
  
  check_button( TSwitchFive_UP, TSwitch5KeyA, TSwitch5ModA, TSwitch5HoldA );
  check_button( TSwitchFive_DOWN, TSwitch5KeyB, TSwitch5ModB, TSwitch5HoldB );
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

