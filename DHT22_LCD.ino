#include "DHT.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht;

byte Temp[8] = {
  B00100,
  B01010,
  B01010,
  B01110,
  B01110,
  B11111,
  B11111,
  B01110
};

byte Umid[8] = {
  B00100,
  B00100,
  B01010,
  B01010,
  B10001,
  B10001,
  B10001,
  B01110
};


void setup()
{
  lcd.begin();
  lcd.backlight();
  dht.setup(5); //data pin D5
  lcd.createChar(0, Temp);
  lcd.createChar(1, Umid);
}

void loop()
{
  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();
  lcd.setCursor(0, 0);
  lcd.print(char(0));
  lcd.setCursor(2, 0);
    lcd.print("Temp :");
      lcd.setCursor(9, 0);
        lcd.print(temperature);
          lcd.setCursor(15, 0);
            lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print(char(1));
  lcd.setCursor(2, 1);          
    lcd.print("Umid :");
      lcd.setCursor(9, 1);
        lcd.print(humidity);
          lcd.setCursor(15, 1);
            lcd.print("%"); 
}
