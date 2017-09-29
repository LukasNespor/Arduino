#include <SoftwareSerial.h>
#include <OBD2UART.h>

#define lowLed 12
#define midLed 8
#define higLed 7
#define rxPin 3
#define txPin 4

COBD obd;
SoftwareSerial ss = SoftwareSerial(rxPin, txPin);
int value;

void setup()
{
	pinMode(lowLed, OUTPUT);
	pinMode(midLed, OUTPUT);
	pinMode(higLed, OUTPUT);
	testLed();

	ss.begin(9600);
	ss.println("Initializing OBD...");

	obd.begin();
	while (!obd.init());

	ss.println("OBD initialized");
}

void loop()
{
	digitalWrite(lowLed, LOW);
	digitalWrite(midLed, LOW);
	digitalWrite(higLed, LOW);

	if (obd.readPID(PID_RPM, value))
	{
		ss.println(value);

		if (value <= 2000)
			digitalWrite(lowLed, HIGH);
		else if (value <= 4000)
			digitalWrite(midLed, HIGH);
		else
			digitalWrite(higLed, HIGH);
	}

	delay(10);
}

void testLed()
{
	digitalWrite(lowLed, HIGH);
	delay(250);
	
	digitalWrite(lowLed, LOW);
	digitalWrite(midLed, HIGH);
	delay(250);
	
	digitalWrite(midLed, LOW);
	digitalWrite(higLed, HIGH);
	
	delay(250);
	digitalWrite(higLed, LOW);
}