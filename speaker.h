#ifndef SPEAKER_H
#define SPEAKER_H

#include"common.h"
#include"tones.h"

class Speaker
{
  public:
  	Speaker();  	
    void handle();
    int getCurrentSongID();
    void pauseSong(BOOL);
    void nextSong();
    void setTempo(int);
  private:    
    const int pin = SPEAKER;
    static const int DEFAULT_TEMPO = 140;
    int select = 0;
    BOOL pause = FALSE;
  	int tempo = DEFAULT_TEMPO;    
    int wholeNoteDuration = (60000 * 2) / tempo;  //calculated duration of a whole note
    int noteIndex = 0;
    int toneVal = 0;
    int divider = 0;
    int noteDuration = 0;
    unsigned long last = 0;
    unsigned long elapsed = 0;  //time elapsed since the current note started playing
    //int *melody = SONG_BLOODY_TEARS;
    int *melody = songs[select];
    int numNotes = getNumNotes(melody);
};

Speaker::Speaker()
{
  ;
}

void Speaker::pauseSong(BOOL pause)
{
  this->pause = pause;
}

int Speaker::getCurrentSongID()
{
  return select;
}

void Speaker::nextSong()
{    
  select = (++select)%NUM_SONGS;
  Serial.print("Speaker::nextSong(): song ");
  Serial.println(select);
  melody = songs[select];  
  noteIndex = 0;
  toneVal = 0;
  divider = 0;
  noteDuration = 0;
  last = 0;
  elapsed = 0;
  numNotes = getNumNotes(melody);
}

void Speaker::setTempo(int tempo)
{
  if(tempo > 0) this->tempo = tempo;
  else this->tempo = 1; //avoid div/0
  wholeNoteDuration = (60000 * 2) / this->tempo;
}

void Speaker::handle()
{  
  if(pause) return;
  elapsed = millis() - last;
  if(elapsed >= noteDuration)
  {    
    noTone(SPEAKER);  
    
    toneVal = pgm_read_word_near(melody + noteIndex);
    //Serial.println(toneVal);
    
    divider = pgm_read_word_near(melody + noteIndex + 1);
    if(divider > 0)
    {
      noteDuration = wholeNoteDuration / divider;
    }
    else
    {
      noteDuration = wholeNoteDuration / abs(divider);
      noteDuration *= 1.5;
    }

    tone(SPEAKER, toneVal, noteDuration*0.9);
    last = millis();

    noteIndex += 2;    
    if(pgm_read_word_near(melody + noteIndex) == SONG_TERMINATOR)    
    {
      noteIndex = 0;
      Serial.println("SONG HAS ENDED");
      //nextSong();
    }
  }
}

#endif //SPEAKER_H