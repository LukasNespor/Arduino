#include "SevSeg.h"

SevSeg display;
unsigned long timer;
unsigned long timerBuzzer;

float tempC;
int reading;
int tempPin = 0;
bool firstRun = 1;
bool alarm = 0;

int ledGreen = A1;
int ledOrange = A2;
int ledRed = A3;

void setup()
{
  int displayType = COMMON_CATHODE; //Your display is either common cathode or common anode
  
  //Declare what pins are connected to the GND pins (cathodes)
  int digit1 = 7; //Pin 1
  int digit2 = 4; //Pin 10
  int digit3 = 3; //Pin 4
  int digit4 = 8; //Pin 6
  
  //Declare what pins are connected to the segments (anodes)
  int segA = 6; //Pin 12
  int segB = 2; //Pin 11
  int segC = 10; //Pin 3
  int segD = 12; //Pin 8
  int segE = 13; //Pin 2
  int segF = 5; //Pin 9
  int segG = 9; //Pin 7
  int segDP= 11; //Pin 5

  analogReference(INTERNAL);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledOrange, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(A4, OUTPUT);

  int numberOfDigits = 4;
  display.Begin(displayType, numberOfDigits, digit1, digit2, digit3, digit4, segA, segB, segC, segD, segE, segF, segG, segDP);
  display.SetBrightness(100); //Set the display to 100% brightness level
  timer = millis();
}

void loop()
{
  reading = analogRead(tempPin);

  if(firstRun)
  {
    tempC = reading / 9.31;
    firstRun = 0;
  }
  
  if (millis() - timer >= 1000)
  {
    timer = millis();
    tempC = reading / 9.31;
  }

  ledStatus(tempC);

  int tempInt = tempC * 100;
  char tempChars[10];
  sprintf(tempChars, "%4d", tempInt);
  display.DisplayString(tempChars, 2);

  delay(1);
}

void ledStatus(float value)
{
  if(value < 21)
  {
    analogWrite(ledGreen, 255);
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledOrange, LOW);
    digitalWrite(ledRed, LOW);

    alarm = 0;
  }

  if(value > 21 && value < 26)
  {
    digitalWrite(ledGreen, LOW);
    analogWrite(ledOrange, 255);
    digitalWrite(ledOrange, HIGH);
    digitalWrite(ledRed, LOW);

    alarm = 0;
  }

  if(value > 26)
  {
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledOrange, LOW);
    analogWrite(ledRed, 255);
    digitalWrite(ledRed, HIGH);

    if(!alarm)
    {
      alarm = 1;
      //digitalWrite(A4, HIGH);
      timerBuzzer = millis();
    }
    else turnOffAlarm();
  }
}

void turnOffAlarm()
{
  if (millis() - timerBuzzer >= 1000)
  {
    digitalWrite(A4, LOW);
  }
}
