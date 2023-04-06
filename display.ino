#include "EasySevenSeg.h"
#include "CountdownLib.h"

const int ledPin = 12;    //led azul
const int sensorPin = 13; //sensor reflexível

const int a = 2;    //
const int b = 3;    //
const int c = 5;    //
const int d = 6;    // pinos do display de 7 segmentos
const int e = 7;    //
const int f = 8;    //
const int g = 9;    //
const int dp = 4;   //

int sensorReading = 0;      //Não utilizada, mas era pra ver se a superfice era reflexivel ou não

EasySevenSeg display;

Countdown countDown(5, []() {countDown.Reset(); digitalWrite(ledPin, LOW); delay(1000);}); //Inicia o timer, junto com suas ações pra quando
                                                                                           //o timer acabar; Nesse caso, resetando o timer,
void setup() {                                                                             //desligando o led azul, e fazendo um delay
  display.begin(e, d, c, dp, b, a, f, g); //Odeio quem fez essa biblioteca

  Serial.begin(9600);         //Inicia a comunicação com o computador a 9600 baud, queria saber por que esse nome
  pinMode(ledPin, OUTPUT);    //Define o led como output
  pinMode(sensorPin, INPUT);  //Define o sensor reflexivo como input
}

void loop() {
  timer();  //Inicia a função timer
}

void timer(){
    Serial.println(countDown.Value);      //Manda o valor do countdown pro serial monitor
    digitalWrite(ledPin, HIGH);           //Liga o led azul
    countDown.Tick();                     //Começa o timer (eu não sei, o cara q desenvolveu isso não trabalhou bem a documentação)
    display.printDigit(countDown.Value);  //Coloca o valor do timer no display
    delay(1000);                          //Esse delay controla o quão rápido o timer é, nesse caso ele demora 1 segundo
}

