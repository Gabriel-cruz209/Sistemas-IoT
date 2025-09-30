#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int pin1 = 8;
int pin2 = 9;
int pin3 = 10;

void setup() {
  //Inicializa o LCD
  lcd.begin(16, 2);
  //Acende a Luz do Fundo
  lcd.clear();
  //Posiciona o Cursor na Primeira Coluna e Primeira Linha
  lcd.setCursor(0, 0);
  // Exibe a primeira mensagem
  lcd.print("Mostrando Pino:");
  //Posiciona o Cursor na Primeira Coluna e Segunda Linha
  lcd.setCursor(0, 1);
  //Exibe a segunda Mensagem
  lcd.print("ON ou OFF");
  lcd.clear();

  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);


}

void loop() {
  //Pino Verde Ativado
  digitalWrite(pin1, HIGH);
  lcd.setCursor(0,0);
  lcd.print("Pino Verde:");
  lcd.setCursor(0, 1);
  lcd.print("ON");
  delay(5000);
  lcd.clear();
  //Pino Verde Desativado
  digitalWrite(pin1, LOW);
  lcd.setCursor(0, 0);
  lcd.print("Pino Verde:");
  lcd.setCursor(0, 1);
  lcd.print("OFF");
  delay(5000);
  lcd.clear();
  
  //Pino Vermelho Ativado
  digitalWrite(pin2, HIGH);
  lcd.setCursor(0,0);
  lcd.print("Pino Vermelho:");
  lcd.setCursor(0, 1);
  lcd.print("ON");
  delay(5000);
  lcd.clear();
  //Pino Vermelho Desativado
  digitalWrite(pin2, LOW);
  lcd.setCursor(0, 0);
  lcd.print("Pino Vermelho:");
  lcd.setCursor(0, 1);
  lcd.print("OFF");
  delay(5000);
  lcd.clear();

  //Pino Azul Ativado
  digitalWrite(pin3, HIGH);
  lcd.setCursor(0,0);
  lcd.print("Pino Azul:");
  lcd.setCursor(0, 1);
  lcd.print("ON");
  delay(5000);
  lcd.clear();
  //Pino Azul Desativado
  digitalWrite(pin3, LOW);
  lcd.setCursor(0, 0);
  lcd.print("Pino Azul:");
  lcd.setCursor(0, 1);
  lcd.print("OFF");
  delay(5000);
  lcd.clear();

  
}
