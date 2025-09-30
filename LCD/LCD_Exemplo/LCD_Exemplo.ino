#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  //Inicializa o LCD
  lcd.begin(16, 2);
  //Acende a Luz do Fundo
  lcd.clear();
  //Posiciona o Cursor na Primeira Coluna e Primeira Linha
  lcd.setCursor(0, 0);
  // Exibe a primeira mensagem
  lcd.print("Ola Mundo");
  //Posiciona o Cursor na Primeira Coluna e Segunda Linha
  lcd.setCursor(0, 1);
  //Exibe a segunda Mensagem
  lcd.print("Oi Gabriel!");
}

void loop() {
  // Nada por enquanto
}
