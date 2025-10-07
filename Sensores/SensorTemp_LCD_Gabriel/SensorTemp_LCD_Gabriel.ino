#include "DHT.h"
#include <LiquidCrystal.h>

DHT dht(3, DHT11);
LiquidCrystal lcd(12,11,10,9,8,7);
float temperatura;

void setup() {
dht.begin();
lcd.begin(16, 2);
lcd.clear();

lcd.setCursor(0, 0);
lcd.print("Temperatura: ");
}

void loop() {
delay(2000);
temperatura = dht.readTemperature();
lcd.setCursor(0, 1);
if (isnan(temperatura)) { lcd.print("ERRO NO SENSOR!");}
else {lcd.print(temperatura); }
}


