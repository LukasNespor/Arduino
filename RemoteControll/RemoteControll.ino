#include <IRremote.h>

#define POWER 0xFFA25D
#define VOL_UP 0xFF906F
#define VOL_DOWN 0xFFA857
#define BTN_1  0xFF30CF
#define BTN_2 0xFF18E7
#define BTN_3 0xFF7A85

#define MAX_BRIGHT 255
#define REC_PIN 11
#define LED_PIN_1 3
#define LED_PIN_2 5
#define LED_PIN_3 6

byte ledStep = 20;
byte ledState = MAX_BRIGHT;
bool ledPower = LOW;

IRrecv irrecv(REC_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  irrecv.enableIRIn();
}

void loop() {
  if(irrecv.decode(&results)) {
    Serial.println(results.value, HEX);

    switch (results.value)
    {
      case POWER:
        if(ledPower == LOW) {
          ledState = MAX_BRIGHT;
          ledPower = HIGH;
          analogWrite(LED_PIN_1, MAX_BRIGHT);
          digitalWrite(LED_PIN_1, ledPower);

          analogWrite(LED_PIN_2, MAX_BRIGHT);
          digitalWrite(LED_PIN_2, ledPower);

          analogWrite(LED_PIN_3, MAX_BRIGHT);
          digitalWrite(LED_PIN_3, ledPower);
        }
        else {
          ledState = ledStep;
          ledPower = LOW;
          digitalWrite(LED_PIN_1, ledPower);
          digitalWrite(LED_PIN_2, ledPower);
          digitalWrite(LED_PIN_3, ledPower);
        }
      break;
      
      case VOL_UP:
        if(ledState < MAX_BRIGHT) {
          ledState += ledStep;
  
          if(digitalRead(LED_PIN_1) != ledStep) {
            analogWrite(LED_PIN_1, ledState);
          }
  
          if(digitalRead(LED_PIN_2) != ledStep) {
            analogWrite(LED_PIN_2, ledState);
          }
  
          if(digitalRead(LED_PIN_3) != ledStep) {
            analogWrite(LED_PIN_3, ledState);
          }
        }
      break;

      case VOL_DOWN:
        if(ledState > ledStep) {
          ledState -= ledStep;

          if(digitalRead(LED_PIN_1) != ledStep) {
            analogWrite(LED_PIN_1, ledState);
          }
  
          if(digitalRead(LED_PIN_2) != ledStep) {
            analogWrite(LED_PIN_2, ledState);
          }
  
          if(digitalRead(LED_PIN_3) != ledStep) {
            analogWrite(LED_PIN_3, ledState);
          }
        }
      break;

      case BTN_1:
        if(digitalRead(LED_PIN_1) == HIGH) {
          digitalWrite(LED_PIN_1, LOW);
        }
        else {
          digitalWrite(LED_PIN_1, HIGH);
        }
      break;
      
      case BTN_2:
        if(digitalRead(LED_PIN_2) == HIGH) {
          digitalWrite(LED_PIN_2, LOW);
        }
        else {
          digitalWrite(LED_PIN_2, HIGH);
        }
      break;

      case BTN_3:
        if(digitalRead(LED_PIN_3) == HIGH) {
          digitalWrite(LED_PIN_3, LOW);
        }
        else {
          digitalWrite(LED_PIN_3, HIGH);
        }
      break;
    }

    irrecv.resume();
  }
  
  delay(200);  
}
