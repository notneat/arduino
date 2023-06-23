//Feito por Tobias
//Controles: Vermelho               -> CH-
//           Verde                  -> CH
//           Azul                   -> CH+
//           Desligar LED           -> Play/Pause
//           Parar de editar        -> 0
//           Editar cor vermelha    -> 1
//           Editar cor verde       -> 2
//           Editar cor azul        -> 3
//           Diminuir/Aumentar cor  -> + e -
//
//Comandos do serial:  rLED -> Coloca a cor vermelha no LED
//                     gLED -> Coloca a cor verde no LED
//                     bLED -> Coloca a cor azul no LED
//                     sLED -> Desliga o LED


#include <IRremote.h>

const int signalPin = 8;    //Entrada do sinal
const int ledRed = 13;      //Entrada vermelha do LED rgb
const int ledGreen = 10;    //Entrada verde do LED rgb
const int ledBlue = 12;     //Entrada azul do LED rgb

const String cmdLEDRed = "rLED";
const String cmdLEDGreen = "gLED";
const String cmdLEDBlue = "bLED";
const String cmdLEDStop = "sLED";

const int maxColorValue = 255;

int redColorValue = 0;
int greenColorValue = 0;
int blueColorValue = 0;

bool editingRed = false;
bool editingGreen = false;
bool editingBlue = false;

IRrecv irrecv(signalPin);
decode_results signals;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();

  pinModeFast(ledRed, OUTPUT);
  pinModeFast(ledGreen, OUTPUT);
  pinModeFast(ledBlue, OUTPUT);

  setColor(redColorValue, greenColorValue, blueColorValue);
}

void loop() {
  if (irrecv.decode(&signals)) {
    irrecv.resume();
    handleIRSignal(signals.value);
  }

  serialCommand();
  delay(50);
  correctColorValues();
}

void handleIRSignal(unsigned long value) {
  switch (value) {
    case 0xFFA25D: // Vermelho, CH-
      setColor(maxColorValue, 0, 0);
      Serial.println("Vermelho");
      break;

    case 0xFF629D: // Verde, CH
      setColor(0, maxColorValue, 0);
      Serial.println("Verde");
      break;

    case 0xFFE21D: // Azul, CH+
      setColor(0, 0, maxColorValue);
      Serial.println("Azul");
      break;

    case 0xFFC23D: // Desliga, Play/Pause
      setColor(0, 0, 0);
      Serial.println("Desligar");
      break;

    case 0xFFA857: // Aumenta a cor em 1, VOL+
      editColors(25);
      break;

    case 0xFFE01F: // Diminui a cor em 1, VOL-
      editColors(-25);
      break;

    case 0xFF6897: //Parar de editar, 0
      editingRed = false;
      editingGreen = false;
      editingBlue = false;
      Serial.println("Parou de editar");
      break;

    case 0xFF30CF: //Edita o vermelho, 1
      editingRed = true;
      editingGreen = false;
      editingBlue = false;
      Serial.println("Editando vermelho");
      break;

    case 0xFF18E7: //Edita o verde, 2
      editingRed = false;
      editingGreen = true;
      editingBlue = false;
      Serial.println("Editando verde");
      break;

    case 0xFF7A85: //Edita o azul, 3
      editingRed = false;
      editingGreen = false;
      editingBlue = true;
      Serial.println("Editando azul");
      break;
  }
}

void editColors(int value) {
  if (editingRed) {
    redColorValue = constrain(redColorValue + value, 0, maxColorValue);
    delay(15);
    setColor(redColorValue, greenColorValue, blueColorValue);
  }

  if (editingGreen) {
    greenColorValue = constrain(greenColorValue + value, 0, maxColorValue);
    delay(15);
    setColor(redColorValue, greenColorValue, blueColorValue);
  }

  if (editingBlue) {
    blueColorValue = constrain(blueColorValue + value, 0, maxColorValue);
    delay(15);
    setColor(redColorValue, greenColorValue, blueColorValue);
  }

  Serial.println(redColorValue);
  Serial.println(greenColorValue);
  Serial.println(blueColorValue);
}

void setColor(int red, int green, int blue) {
  analogWrite(ledRed, red);
  analogWrite(ledGreen, green);
  analogWrite(ledBlue, blue);
}

void serialCommand() {
  if (Serial.available()) {
    String command = Serial.readString();

    if (command == cmdLEDRed) {
      setColor(maxColorValue, 0, 0);
      Serial.println("rLED executing");
    } else if (command == cmdLEDGreen) {
      setColor(0, maxColorValue, 0);
      Serial.println("gLED executing");
    } else if (command == cmdLEDBlue) {
      setColor(0, 0, maxColorValue);
      Serial.println("bLED executing");
    } else if (command == cmdLEDStop) {
      setColor(0, 0, 0);
      Serial.println("sLED executing");
    }

    delay(50);
  }
}

void correctColorValues() {
  redColorValue = constrain(redColorValue, 0, maxColorValue);
  greenColorValue = constrain(greenColorValue, 0, maxColorValue);
  blueColorValue = constrain(blueColorValue, 0, maxColorValue);
}
#pragma region 

//Lista dos códigos hexadecimais de cada botão do controle

//CH- 0xFFA25D
//CH 0xFF629D
//CH+ 0xFFE21D
//PREV 0xFF22DD
//NEXT 0xFF02FD
//PLAY/PAUSE 0xFFC23D
//VOL- 0xFFE01F
//VOL+ 0xFFA857
//EQ 0xFF906F
//0 0xFF6897
//100+ 0xFF9867
//200+ 0xFFB04F
//1 0xFF30CF
//2 0xFF18E7
//3 0xFF7A85
//4 0xFF10EF
//5 0xFF38C7
//6 0xFF5AA5
//7 0xFF42BD
//8 0xFF4AB5
//9 0xFF52AD

#pragma endregion