#define trigPin 9
#define echoPin 10
#define buzzerPin 13

void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzerPin, OUTPUT);
}

void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

long duration = pulseIn(echoPin, HIGH); 
float distance = duration * 0.034 / 2; 


if (distance <= 20) {
digitalWrite(buzzerPin, HIGH);
} else {
digitalWrite(buzzerPin, LOW);
delay(200);}
}