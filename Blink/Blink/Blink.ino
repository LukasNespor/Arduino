#include <SoftwareSerial.h>

SoftwareSerial ss(10, 11);

void setup() {
	pinMode(13, OUTPUT);
	Serial.begin(57600);
	while (!Serial);
	Serial.println("Serial started...");

	ss.begin(4800);
	ss.println("SoftwareSerial started...");
}

void loop()
{
	digitalWrite(13, LOW);
	delay(500);
	digitalWrite(13, HIGH);
	delay(500);
}