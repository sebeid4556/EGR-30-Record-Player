#ifndef BUTTON_H
#define BUTTON_H

#include"common.h"

typedef void(*BTN_CALLBACK)();

class Button
{
  public:
  	Button(UINT32, BTN_CALLBACK=NULL, BTN_CALLBACK=NULL);  	
  	static const BOOL DOWN = TRUE;
  	static const BOOL UP = FALSE;  	  	
  	void handle();
  private:
  	UINT32 pin;
  	BOOL state = UP;
  	BOOL last_state;
  	BTN_CALLBACK onDown;
  	BTN_CALLBACK onUp;
  	
};

Button::Button(UINT32 pin, BTN_CALLBACK onDown, BTN_CALLBACK onUp)
{
  this->pin = pin;
  this->onDown = onDown;
  this->onUp = onUp;
  
  pinMode(this->pin, INPUT);
}

void Button::handle()
{  
  state = digitalRead(pin);
  if(state == DOWN && last_state == UP)
  {
    if(onDown) onDown();
  }
  else if(state == UP && last_state == DOWN)
  {
    if(onUp) onUp();
  }
  last_state = state;
}

#endif //BUTTON_H