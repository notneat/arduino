const int buttonPin = 2;    //Define a entrada do botão como o pino 2
const int ledPin = 10;      //Define a entrada do led como o pino 10
const int buzzerPin = 8;    //Define a entrada do buzzer como o pino 8

void setup(){
    Serial.begin(9600);                 
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
}

void loop(){
    int pushed = digitalRead(buttonPin);  //Declara uma variável `pushed`
                                          //a função `digitalRead()` fica lendo o input do botão
    if(pushed == LOW){
      digitalWrite(ledPin, HIGH);         //Resumindo as próximas linhas, caso o botão seja pressionado
      digitalWrite(buzzerPin, HIGH);      //o led é acendido e o buzzer é ativado
    }
    else{
      digitalWrite(ledPin, LOW);          //Se não, o led é desligado e o buzzer não faz som
      digitalWrite(buzzerPin, LOW);
    }
}