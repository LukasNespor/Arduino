unsigned int EchoPin1 = 9;
unsigned int EchoPin2 = 6;
unsigned int TrigPin = 8;
unsigned long Time_Echo_us1 = 0;
unsigned long Time_Echo_us2 = 0;
unsigned long Len_mm1  = 0;
unsigned long Len_mm2  = 0;
bool Show = false;

void setup()
{
    Serial.begin(9600);
    pinMode(EchoPin1, INPUT);
    pinMode(EchoPin2, INPUT);
    pinMode(TrigPin, OUTPUT);
}

void loop()
{
    Show = false;
    digitalWrite(TrigPin, HIGH);              //begin to send a high pulse, then US-020 begin to measure the distance
    delayMicroseconds(50);                    //set this high pulse width as 50us (>10us)
    digitalWrite(TrigPin, LOW);               //end this high pulse
    
    Time_Echo_us1 = pulseIn(EchoPin1, HIGH);               //calculate the pulse width at EchoPin, 
    if((Time_Echo_us1 < 60000) && (Time_Echo_us1 > 1))     //a valid pulse width should be between (1, 60000).
    {
      Len_mm1 = (Time_Echo_us1*34/100)/2;
      Show = true;
    }
    
    Time_Echo_us2 = pulseIn(EchoPin2, HIGH);               //calculate the pulse width at EchoPin, 
    if((Time_Echo_us2 < 60000) && (Time_Echo_us2 > 1))     //a valid pulse width should be between (1, 60000).
    {
      Len_mm2 = (Time_Echo_us2*34/100)/2;
      Show = true;
    }

    if(Show)
    {
      Serial.print("Distance: ");
      Serial.print(Len_mm1, DEC);
      Serial.print("mm and ");
      
      Serial.print(Len_mm2, DEC);
      Serial.println("mm");
    }
    
    delay(1000);                            //take a measurement every second (1000ms)
}
