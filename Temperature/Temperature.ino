#include <math.h>

float tempC;
int reading;
int tempPin = 0;
int ledGreen = 12;
int ledOrange = 11;
int ledRed = 10;

int pinA = 3;
int pinB = 2;
int pinC = 5;
int pinD = 6;
int pinE = 7;
int pinF = 8;
int pinG = 9;
int pinDot = 4;

void setup()
{
  analogReference(INTERNAL);
  //Serial.begin(9600);

  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinDot, OUTPUT);
}

void loop()
{
  reading = analogRead(tempPin);
  tempC = reading / 9.31;
  //Serial.println(tempC);

  if(tempC < 21)
  {
    analogWrite(ledGreen, 255);
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledOrange, LOW);
    digitalWrite(ledRed, LOW);
  }
  
  if(tempC > 21 && tempC < 25)
  {
    digitalWrite(ledGreen, LOW);
    analogWrite(ledOrange, 255);
    digitalWrite(ledOrange, HIGH);
    digitalWrite(ledRed, LOW);
  }
  
  if(tempC > 25)
  {
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledOrange, LOW); 
    analogWrite(ledRed, 255);
    digitalWrite(ledRed, HIGH);
  }

  digitalWrite(pinDot, HIGH);

  String tempStr = String(tempC);
  //int len = tempStr.length();

  for (int i = 0; i < tempStr.length() - 1; i++)
  {
    switch (tempStr[i])
    {
      case '.':
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      digitalWrite(pinDot, HIGH);
      delay(500);
      break;

      case '0':
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      digitalWrite(pinDot, LOW);
      delay(500);
      break;

      case '1':
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      digitalWrite(pinDot, LOW);
      delay(500);
      break;

      case '2':
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinDot, LOW);
      delay(500);
      break;

      case '3':
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinDot, LOW);
      delay(500);
      break;

      case '4':
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinDot, LOW);
      delay(500);
      break;

      case '5':
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinDot, LOW);
      delay(500);
      break;

      case '6':
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinDot, LOW);
      delay(500);
      break;

      case '7':
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      digitalWrite(pinDot, LOW);
      delay(500);
      break;

      case '8':
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinDot, LOW);
      delay(500);
      break;

      case '9':
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinDot, LOW);
      delay(500);
      break;
    }
  }

  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
  digitalWrite(pinDot, LOW);
  delay(1000);
}
