#ifndef MOTOR_H
#define MOTOR_H

#include"common.h"

class Motor
{
  public:
  	Motor(UINT32);  	
  	void setRPM(UINT32);
  	void handle();
  private:
  	UINT32 pin;
  	UINT32 rpm = 0xCC;	//arbitrary default value
};

Motor::Motor(UINT32 pin)
{
  this->pin = pin;
}

void Motor::setRPM(UINT32 rpm)
{  
  //this->rpm = (255L*rpm) / 1023L;
  this->rpm = 120 + ((50L*rpm) / 2013L);
  /*Serial.print("analogWrite(): ");
  Serial.println(this->rpm);*/
}

void Motor::handle()
{
  analogWrite(pin, rpm);
}

#endif //MOTOR_H