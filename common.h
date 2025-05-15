/*=============================================================*/
/*Macros*/
/*=============================================================*/

#ifndef COMMON_H
#define COMMON_H

#define BUTTON_PAUSE 2
#define BUTTON_NEXT_SONG 3
#define BUTTON_TOGGLE_INFO 4

#define POTENTIOMETER_VOLUME A0
#define POTENTIOMETER_SPEED A1

#define SPEAKER 5

#define LCD_RS 12
#define LCD_ENABLE 11
#define LCD_D4 6
#define LCD_D5 7
#define LCD_D6 8
#define LCD_D7 9

#define MOTOR 10	//PWM enabled pin

#define SECONDS(n) delay(n*1000)
#define MILLISECONDS(n) delay(n)

#define TRUE true
#define FALSE false

#define NULL 0

/*=============================================================*/
/*Useful typedefs*/
//NOTE: THESE WERE SUPER BUG PRONE!! 
/*=============================================================*/
typedef long INT32;
typedef int INT16;
typedef char INT8;

typedef unsigned long UINT32;
typedef unsigned int UINT16;
typedef unsigned char UINT8;

typedef bool BOOL;

#endif //COMMON_H