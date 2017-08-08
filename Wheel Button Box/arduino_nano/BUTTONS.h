/*
 * Config Options for buttons
 */


#define Button_1_Key 1              // key to send
#define Button_1_Pin 4              // Pin where the button is connected to on the Arduino board

#define Button_2_Key 2              // key to send
#define Button_2_Pin 5              // Pin where the button is connected to on the Arduino board

#define Button_3_Key 3              // key to send
#define Button_3_Pin 6              // Pin where the button is connected to on the Arduino board

#define Button_4_Key 4              // key to send
#define Button_4_Pin 7              // Pin where the button is connected to on the Arduino board

#define Button_5_Key 5              // key to send
#define Button_5_Pin 8              // Pin where the button is connected to on the Arduino board

#define Button_6_Key 6              // key to send
#define Button_6_Pin 11              // Pin where the button is connected to on the Arduino board

#define Button_7_Key 7              // key to send
#define Button_7_Pin 12              // Pin where the button is connected to on the Arduino board

#define Button_8_Key 8              // key to send
#define Button_8_Pin A2              // Pin where the button is connected to on the Arduino board

#define Button_9_Key 9              // key to send
#define Button_9_Pin A3             // Pin where the button is connected to on the Arduino board

#define Button_10_Key 10              // key to send
#define Button_10_Pin A6             // Pin where the button is connected to on the Arduino board

#define Button_11_Key 11              // key to send
#define Button_11_Pin A7             // Pin where the button is connected to on the Arduino board


/* currently testing without interrupts as there are not that many buttons ... will see */
#define Paddle_1_Key 10             // paddles are handled as interrupts
#define Paddle_1_Pin 2              // must be pin 2 or 3 on arduino nano

#define Paddle_2_Key 11             // paddles are handled as interrupts
#define Paddle_2_Pin 3              //  must be pin 2 or 3 on arduino nano



#define Joystick_1_Key 1
#define Joystick_1_Pin A0

#define Joystick_2_Key 2
#define Joystick_2_Pin A1

/* setup array for key functions */
int ButtonKey[13] = { Button_1_Key, Button_2_Key, Button_3_Key, Button_4_Key, Button_5_Key,
                      Button_6_Key, Button_7_Key, Button_8_Key, Button_9_Key, Button_10_Key,
                      Button_11_Key, Paddle_1_Pin, Paddle_2_Pin };
