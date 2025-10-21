#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void setup() {
  // ERRO 1 CORRIGIDO: Inicializa a serial com a mesma velocidade do Python
  Serial.begin(9600); 
  
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Porta: ");
}

void loop() {
  // Verifica se há algum dado disponível
  if (Serial.available() > 0) {
    // Lê o caractere recebido
    char command = Serial.read();

    // ERRO 2 CORRIGIDO: O cursor deve ser definido ANTES do switch
    lcd.setCursor(0, 1); 

    // Executa a ação baseada no comando
    switch (command) {
      case 'A':
        // MELHORIA 3: Adiciona espaços para limpar a linha
        lcd.print("Aberta   "); 
        break;
      case 'a':
        // MELHORIA 3: Adiciona espaços para limpar a linha
        lcd.print("Fechada  "); 
        break;
    }
  }
}