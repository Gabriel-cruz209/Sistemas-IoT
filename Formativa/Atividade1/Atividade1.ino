
//Biblioteca do DTH
#include "DHT.h"
//armazena o valor flutuante de temperatura
float temperatura;
//porta usada e o tipo de sensor
DHT dht(3, DHT11);


void setup() {
Serial.begin(9600);// inicializando o monitor serial
dht.begin();// Inicializando o sensor
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
}

void loop() {
delay(2000);// Aguarda dois segundos entre as leituras
temperatura = dht.readTemperature();//Lê o valor da temperatura em C°

//Verificando se existe erro na leitura da temperatura
if (isnan(temperatura)) { Serial.println("ERRO NO SENSOR!");}
//Se tudo funcionar envia a temperatura para a serial
else {Serial.println(temperatura); /*em C°*/}

if (temperatura <= 24){
  digitalWrite(12, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, 
  LOW);
} else if (temperatura >= 25 && temperatura <=35 ){
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(12, 
  LOW);
} else{
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, 
  LOW);
}

}