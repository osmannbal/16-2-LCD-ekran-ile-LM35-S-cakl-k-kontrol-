#include <LiquidCrystal.h>
int ledPin = 6;
int buzzerPin = 7;
int lm35 = A0;
int zaman = 2000;
float lm35deger;
float sicaklikGerilim;
float sicaklik;
int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(lm35, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  lcd.begin(16, 2);

}

void loop() {
  lm35deger = analogRead(A0);
  sicaklikGerilim = (5000.0 / 1023.0) * lm35deger;
  sicaklik = sicaklikGerilim / 10.0;
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sicaklik degeri");
  lcd.setCursor(0, 1);
  lcd.print(sicaklik);
  lcd.print(" C");

  if (sicaklik > 25.0) {
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    delay(zaman);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
  else {
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
delay(zaman);
}
