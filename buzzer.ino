const int buzzer = 5; //Define a entrada do buzzer como o pino 5

void setup() {
  pinMode(buzzer, OUTPUT); //Define o buzzer como output
}

void loop() {
    digitalWrite(buzzer, HIGH); //Liga o buzzer... Sim, o código é só isso
}
