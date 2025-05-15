#ifndef DISPLAY_H
#define DISPLAY_H

#include<LiquidCrystal.h>

#include"common.h"

LiquidCrystal lcd(LCD_RS, LCD_ENABLE, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

class Display
{
  public:
    Display();
    void say(String);
    void setMsg(String);
    void handle();
  private:
    String msg = "EVANGELION";    
};

Display::Display()
{
  lcd.begin(16, 2);
  say(msg.c_str());
}

void Display::setMsg(String msg)
{
  this->msg = msg;
}

void Display::say(String msg)
{
  this->msg = msg;
  static int dots = 0;  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("NOW PLAYING");
  for(int i = 0;i < dots;i++) lcd.print(".");
  dots++;
  dots %= 4;
  lcd.setCursor(0, 1);
  lcd.print(this->msg.c_str());
}


void Display::handle()
{
  static unsigned long last = millis();
  unsigned long elapsed = millis() - last;
  if(elapsed >= 1000)
  {
    say(msg);
    last = millis();
  }  
}

#endif //DISPLAY_H