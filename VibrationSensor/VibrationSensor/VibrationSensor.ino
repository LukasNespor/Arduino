#define SensorLed 13
#define SensorInput 3
unsigned char state = 0;

void setup() {
	Serial.begin(9600);
	pinMode(SensorLed, OUTPUT);
	pinMode(SensorInput, INPUT);
	attachInterrupt(1, blink, FALLING);
}

void loop()
{
	if (state != 0)
	{
		state = 0;
		digitalWrite(SensorLed, HIGH);
		Serial.println(analogRead(SensorInput));
		delay(500);
	}
	else
	{
		digitalWrite(SensorLed, LOW);
	}
}

void blink()
{
	state++;
}