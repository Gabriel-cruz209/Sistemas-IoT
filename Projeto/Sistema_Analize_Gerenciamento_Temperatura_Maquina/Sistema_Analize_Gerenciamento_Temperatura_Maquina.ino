#include "DHT.h"
#include <LiquidCrystal.h>

int pinBuzzer = 6;
int pinVerde = 5;
int pinAmarelo = 4;
int pinVermelho = 3;

DHT dht(A0, DHT11);
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
float temperatura;
float umidade;

void setup() {
  Serial.begin(9600); 

  pinMode(pinBuzzer, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAmarelo, OUTPUT);
  pinMode(pinVermelho, OUTPUT);

  dht.begin();
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {

  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == 'T') {
      
      temperatura = dht.readTemperature();
      umidade = dht.readHumidity(); 

      if (isnan(temperatura) || isnan(umidade)) {
        Serial.println("ERRO");
      } else {
        Serial.print(temperatura);
        Serial.print(";");
        Serial.println(umidade);
      }
      
      if (isnan(temperatura)) { 
        lcd.clear();
        lcd.print("ERRO NO SENSOR!");
        digitalWrite(pinVerde, LOW);
        digitalWrite(pinAmarelo, LOW);
        digitalWrite(pinVermelho, LOW);
        noTone(pinBuzzer);
      }
      else if (temperatura <= 40) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Temp: ");
        lcd.print(temperatura);
        
        digitalWrite(pinVerde, HIGH);
        digitalWrite(pinAmarelo, LOW);
        digitalWrite(pinVermelho, LOW);
        noTone(pinBuzzer);
      }
      else if (temperatura > 40 && temperatura < 60) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Temp: ");
        lcd.print(temperatura);
        
        digitalWrite(pinVerde, LOW);
        digitalWrite(pinAmarelo, HIGH);
        digitalWrite(pinVermelho, LOW);
        tone(pinBuzzer, 262, 500); 
      }
      else if (temperatura > 60) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Temp: ");
        lcd.print(temperatura);
        
        digitalWrite(pinVerde, LOW);
        digitalWrite(pinAmarelo, LOW);
        digitalWrite(pinVermelho, HIGH);
        tone(pinBuzzer, 400, 500);
      }
    }
  }
}