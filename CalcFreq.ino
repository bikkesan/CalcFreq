// include the library code:
#include <LiquidCrystal.h>

const byte interruptPin = 2;
volatile long count = 0;

const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), edgeIntr, RISING);
  lcd.begin(16, 2);
}

void loop() {
  delay(1000);
  
  float time = millis();

  float f = count;
  f /= time / 1000.0;
   
  lcd.clear();
  
  lcd.print("f = ");
  lcd.print(f);
  lcd.print(" (Hz)");
  
  lcd.setCursor(0, 2);
  lcd.print("count = ");
  lcd.print(count);
}

void edgeIntr() {
  count += 1;
}
