const int ledPin = 3;   //Define a entrada do led como o pino 3
const int ldrPin = A5;  //Define a entrada do sensor de luminosidade como a entrada analoga 5 (mínima ideia da diferença da entrada analoga
                        //pra entrada normal)
int lrdValue = 0;       //Variável pra calcular a luminosidade usando o sensor

void setup() {
  pinMode(ledPin, OUTPUT); //Define o led como output
  Serial.begin(9600);      //Inicia a comunicação com o computador
}

void loop() {
  lrdValue = analogRead(ldrPin);  //Lê os valores vindos do sensor e coloca eles no `lrdValue`

  if(lrdValue >= 300){
    digitalWrite(ledPin, HIGH);   //Se a luminosidade for maior que 300, acender o led
  }
  else{
    digitalWrite(ledPin, LOW);    //Se não, deixar o led apagado
  }

  delay(100);                     //Delay de 100ms, porque? não sei
}
