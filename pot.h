#ifndef POT_H
#define POT_H

#include"common.h"

typedef void(*POT_CALLBACK)(INT32);

class Potentiometer
{
  public:
  	Potentiometer(UINT32, POT_CALLBACK=NULL);  	
  	void handle();
  private:
  	UINT32 pin;
  	INT32 value;
  	INT32 last_value;
  	POT_CALLBACK onChange;
};

Potentiometer::Potentiometer(UINT32 pin, POT_CALLBACK onChange)
{
  this->pin = pin;
  this->onChange = onChange;
}

void Potentiometer::handle()
{
  value = analogRead(pin);  
  if(abs(value - last_value) > 5) //only detect increments of 5
  {
    last_value = value;
    if(onChange) onChange(value);
  }  
}

#endif //POT_H