int DS = 10;
int STCP = 9;
int SHCP = 8;
bool reg[8];

void setup() {
  pinMode(DS,OUTPUT);
  pinMode(STCP,OUTPUT);
  pinMode(SHCP,OUTPUT);

  writeReg();
}

void loop() {
  for(int i = 0; i<=7; i++)
  {
   , reg[i] = HIGH;
    delay(100);
    writeReg();
  }

  for(int i = 7; i>=0; i--)
  {
    reg[i] = LOW;
    delay(100);
    writeReg();
  }
}

void writeReg()
{
  digitalWrite(STCP,LOW);

  for (int i = 7; i>=0; i--)
  {
      digitalWrite(SHCP,LOW);
      digitalWrite(DS,reg[i]);
      digitalWrite(SHCP,HIGH);
  }

  digitalWrite(STCP,HIGH);
}
