const int ledPin = 12;      //Define a entrada do led como o pino 12
const int sensorPin = 13;   //Define a entrada do sensor reflexivo como o pino 13

int alice = 0;    //Eu não sei (mentira, eu sei sim, é a variável que a leitura do sensor é amarzenada)

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  if (digitalRead(sensorPin) ==  LOW) {   
    digitalWrite(ledPin, HIGH);           //Se a leitura do sensor for 1, acender o led
  }
  else {
    digitalWrite(ledPin, LOW);            //Se a leitura do sensor for 0, apagar o led
  }

  desceEscada(); //Função pra mandar a leitura do sensor pro computador
}

void desceEscada(){                   //Socorro
  alice = digitalRead(sensorPin);
  Serial.println(alice);
  delay(200);
}
