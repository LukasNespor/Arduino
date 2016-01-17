int pin = 12;

void setup() {
  pinMode(pin, OUTPUT);
}

void loop() {

  //s
  for (int i = 1; i <= 3; i++)
  {
    digitalWrite(pin, HIGH);
    delay(200);
    digitalWrite(pin, LOW);
    delay(200);
  }
  delay(200);
  
  //o
  for (int i = 1; i <= 3; i++)
  {
    digitalWrite(pin, HIGH);
    delay(600);
    digitalWrite(pin, LOW);
    delay(200);
  }
  delay(200);
  
  //s
  for (int i = 1; i <= 3; i++)
  {
    digitalWrite(pin, HIGH);
    delay(200);
    digitalWrite(pin, LOW);
    delay(200);
  }
  
  delay(1000);
}
