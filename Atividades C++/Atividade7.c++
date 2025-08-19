int leds[4] = {1, 2, 3, 4};
void setup() {
for(int i = 0; i < 4; i++){
  pinMode(leds[i], OUTPUT);
  }

}

void loop() {
  for(int g = 0; g < 4; g++){
    digitalWrite(leds[g], HIGH);
    delay(100);}
}