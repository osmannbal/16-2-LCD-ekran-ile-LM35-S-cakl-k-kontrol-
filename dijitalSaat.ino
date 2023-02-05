
#include <LiquidCrystal_I2C.h>
#include <virtuabotixRTC.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0X27, 16, 2);
int clkPin =6;
int dataPin = 7;
int rstPin=8;

virtuabotixRTC myRTC(6,7,8);

void setup() {
  lcd.init();
  lcd.backlight();

}

void loop() {
  myRTC.updateTime();

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(myRTC.dayofmonth);
  lcd.print("/");
  lcd.print(myRTC.month);
  lcd.print("/");
  lcd.print(myRTC.year);
  
  lcd.setCursor(0,1);
  lcd.print(myRTC.hours);
  lcd.print(":");
  lcd.print(myRTC.minutes);
  lcd.print(":");
  lcd.print(myRTC.seconds);
  
  delay(1000);

}
