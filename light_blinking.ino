const int buttonPin = 13; //Botão
const int led1Pin = 12;   //LED vermelho
const int led2Pin = 9;   //LED azul
const int buzzerPin = 10; //Buzzer

int buttonPressed = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  
  buttonPressed = digitalRead(buttonPin);   //Variável para detectar se o botão é pressionado

  if(buttonPressed == LOW){
    digitalWrite(led1Pin, HIGH);   //Ligar led vermelhos
    delay(1000);
    digitalWrite(led1Pin, LOW);    //Desligar led vermelho
    digitalWrite(led2Pin, HIGH);   //Ligar led azul
    digitalWrite(buzzerPin, HIGH); //Ligar buzzer;
    delay(200);
    digitalWrite(led2Pin, LOW);    //Desligar led azul
    digitalWrite(buzzerPin, LOW);
    delay(100);
    digitalWrite(led2Pin, HIGH);   //Ligar led azul
    digitalWrite(buzzerPin, HIGH);
    delay(50);
    digitalWrite(led2Pin, LOW);    //Desligar led azul
    digitalWrite(buzzerPin, LOW);
  }
  else {
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  }
  delay(2000);
}
