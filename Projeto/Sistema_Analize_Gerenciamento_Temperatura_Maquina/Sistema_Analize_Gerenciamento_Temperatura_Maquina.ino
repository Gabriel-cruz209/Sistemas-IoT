#include "DHT.h"
#include <LiquidCrystal.h>

int pinBuzzer = 6;
int pinVerde = 5;
int pinAmarelo = 4;
int pinVermelho = 3;

DHT dht(A0, DHT11);
LiquidCrystal lcd(12,11,10,9,8,7);
float temperatura;

void setup() {

pinMode(pinBuzzer, OUTPUT);
pinMode(pinVerde, OUTPUT);
pinMode(pinAmarelo, OUTPUT);
pinMode(pinVermelho, OUTPUT);

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
if (isnan(temperatura)) { 
  lcd.print("ERRO NO SENSOR!");
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAmarelo, LOW);
  digitalWrite(pinVermelho, LOW);
  noTone(pinBuzzer);
  }
else if(temperatura <= 40) {
  lcd.print(temperatura); 
  digitalWrite(pinVerde, HIGH);
  digitalWrite(pinAmarelo, LOW);
  digitalWrite(pinVermelho, LOW);
  noTone(pinBuzzer);
  }
else if(temperatura > 40 && temperatura < 60 ) {
  lcd.print(temperatura); 
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAmarelo, HIGH);
  digitalWrite(pinVermelho, LOW);
  tone(pinBuzzer, 262, 1000);
  delay(3000);
  }

else if (temperatura > 60 ) {
  lcd.print(temperatura); 
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAmarelo, LOW);
  digitalWrite(pinVermelho, HIGH);
  tone(pinBuzzer, 400, 2000);
  delay(500);
  }

else{
  lcd.print("Error...");
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAmarelo, LOW);
  digitalWrite(pinVermelho, LOW);
  noTone(pinBuzzer);
}

}