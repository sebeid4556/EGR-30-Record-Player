// C++ code
//

#include"common.h"
#include"button.h"
#include"pot.h"
#include"speaker.h"
#include"motor.h"
#include"tones.h"
#include"display.h"

/*=============================================================*/
/*Globals and Prototypes*/
/*=============================================================*/

BOOL pause = FALSE;

void test();
void pauseSong();
void nextSong();
void pot_Zolume(INT32);
void pot_Zpeed(INT32);

Button btn_pause(BUTTON_PAUSE, pauseSong, NULL);
Button btn_next_song(BUTTON_NEXT_SONG, nextSong, NULL);
Button btn_toggle_info(BUTTON_TOGGLE_INFO, test, test);

Potentiometer pot_volume(POTENTIOMETER_VOLUME, pot_Zolume);
Potentiometer pot_speed(POTENTIOMETER_SPEED, pot_Zpeed);

Speaker speaker;

Motor motor(MOTOR);

Display display;

/*=============================================================*/
/*Logic*/
/*=============================================================*/

void test()
{
  Serial.println("YIPPPEE");
}

void pauseSong()
{
  pause = !pause;
  speaker.pauseSong(pause);
}

void nextSong()
{
  Serial.println("NEXT SONG");
  speaker.nextSong();
  display.say(songNames[speaker.getCurrentSongID()]);
}

//for some reason the tinkercad compiler complains if this is INT32 and not int
void pot_Zolume(long value)
{  
  /*Serial.print("Volume: ");
  Serial.println(value);*/
}

void pot_Zpeed(long value)
{
  motor.setRPM(value);
  int tempo = 70 + ((150L*value) / 1023L);
  speaker.setTempo(tempo);
  
  Serial.print("Speed analogRead(): ");
  Serial.println(value);
}

void setup()
{
  Serial.begin(9600);    
  motor.setRPM(0x10);  

  display.say(songNames[speaker.getCurrentSongID()]);
}

void loop()
{
  btn_pause.handle();
  btn_next_song.handle();
  btn_toggle_info.handle();  
  pot_volume.handle();
  pot_speed.handle();
  motor.handle();
  speaker.handle();
  display.handle();
}