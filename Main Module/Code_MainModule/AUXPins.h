

//Pin for feedback LED. High when AUX key is pushed or hold is active
#define AUX_LED_Enable 1 // 1 to enable LED feedback, default: 0
#define AUX_LED_Pin 3 // pin number of LED
#define AUX_LED_PWD 255 //PWM value for output




#define EnableAux1 1 // Enable / Disable AUX port. Set this to 1 to use the feature
#define EnableAux1_Button 1 //hold down a button to control the PMW output
#define AUX1_Pin 3 // 5Volt -  fan or UV LED pin
#define AUX1_Button KEY_A // hold this button and use encoder left/right to adjust PWM output on port
#define AUX1_Button_Mod 0 //set to 'MODIFIERKEY_SHIFT' to a capital letter
#define AUX1_Button_Auto_Hold 0 //seconds the button is "held" in software to allow one hand operation. 0 = hold and turn knob 0< push, release button and turn knop within the time your set here
#define AUX1_PWM_FIXED 100 //fixed PWM value used when "EnableAux*_Button" is not set to 1
#define AUX1_PWM_CHANGE 5 //increase or decrease PWM by this much
#define AUX1_PWM_MAX 255 //max valueo for pwm AoBLSOLUTE MAX 255 !!!!
#define AUX1_PWM_MIN 4 //min value for pwm ABSOLUTE MIN 0 !!!!
#define AUX1_PWM_FREQ 100   //PWM frequency in Hz - set to zero to use default value of 488.28Hz
                            //Pins 3 & 4 share FTM1, Pins 5,6,9,10,20,21,22,23 share FTM0 and Pins 25,26 share FTM2
                            //setting a frequency on one pin will set the same frequency on all other pins connected to the same timer!
                            // https://www.pjrc.com/teensy/td_pulse.html
#define AUX1_ENABLE_FAN_START 0 //0 to disable or 1 to ramp up this port when turned on
#define AUX1_FAN_START_RAMP 100 // PWM value used to get the fan spinning
#define AUX1_EEPROM 0 // EEPROM address






#define EnableAux2 1 // Enable / Disable AUX port. Set this to 1 to use the feature
#define EnableAux2_Button 1 //hold down a button to control the PMW output
#define AUX2_Pin 4 // 5Volt - fan or UV LED pin
#define AUX2_Button KEY_B // hold this button and use encoder left/right to adjust PWM output on port
#define AUX2_Button_Mod 0 //set to 'MODIFIERKEY_SHIFT' to a capital letter
#define AUX2_Button_Auto_Hold 0 //seconds the button is "held" in software to allow one hand operation. 0 = hold and turn knob 0< push, release button and turn knop within the time your set here
#define AUX2_PWM_FIXED 100 //fixed PWM value used when "EnableAux*_Button" is not set to 1
#define AUX2_PWM_CHANGE 10 //increase or decrease PWM by this much
#define AUX2_PWM_MAX 255 //max value for pwm ABLSOLUTE MAX 255 !!!!
#define AUX2_PWM_MIN 9 //min value for pwm ABSOLUTE MIN 0 !!!!
#define AUX2_PWM_FREQ 100   //PWM frequency in Hz - set to zero to use default value of 488.28Hz
                            //Pins 3 & 4 share FTM1, Pins 5,6,9,10,20,21,22,23 share FTM0 and Pins 25,26 share FTM2
                            //setting a frequency on one pin will set the same frequency on all other pins connected to the same timer!
                            // https://www.pjrc.com/teensy/td_pulse.html
#define AUX2_ENABLE_FAN_START 0 //0 to disable or 1 to ramp up this port when turned on
#define AUX2_FAN_START_RAMP 100 // PWM value used to get the fan spinning
#define AUX2_EEPROM 1 // EEPROM address





#define EnableAux3 1 // Enable / Disable AUX port. Set this to 1 to use the feature
#define EnableAux3_Button 1 //hold down a button to control the PMW output
#define AUX3_Pin 5 // 5Volt - fan or UV LED pin
#define AUX3_Button KEY_C // hold this button and use encoder left/right to adjust PWM output on port
#define AUX3_Button_Mod 0 //set to 'MODIFIERKEY_SHIFT' to a capital letter
#define AUX3_Button_Auto_Hold 0 //seconds the button is "held" in software to allow one hand operation. 0 = hold and turn knob 0< push, release button and turn knop within the time your set here
#define AUX3_PWM_FIXED 100 //fixed PWM value used when "EnableAux*_Button" is not set to 1
#define AUX3_PWM_CHANGE 10 //increase or decrease PWM by this much
#define AUX3_PWM_MAX 255 //max value for pwm ABLSOLUTE MAX 255 !!!!
#define AUX3_PWM_MIN 9  //min value for pwm ABSOLUTE MIN 0 !!!!
#define AUX3_PWM_FREQ 0   //PWM frequency in Hz - set to zero to use default value of 488.28Hz
                          //Pins 3 & 4 share FTM1, Pins 5,6,9,10,20,21,22,23 share FTM0 and Pins 25,26 share FTM2
                          //setting a frequency on one pin will set the same frequency on all other pins connected to the same timer!
                          // https://www.pjrc.com/teensy/td_pulse.html
#define AUX3_ENABLE_FAN_START 0 //0 to disable or 1 to ramp up this port when turned on
#define AUX3_FAN_START_RAMP 100 // PWM value used to get the fan spinning
#define AUX3_EEPROM 2 // EEPROM address
