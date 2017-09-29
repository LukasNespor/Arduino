//http://navody.arduino-shop.cz/navody-k-produktum/teplotni-senzor-dht11.html

#include <DHT.h>
#define pin 5
#define typ DHT11

DHT sensor(pin, typ);

void setup(void) {
	Serial.begin(9600);
	sensor.begin();
}

void loop(void) {

	float temp = sensor.readTemperature();
	float humi = sensor.readHumidity();
	if (isnan(temp) || isnan(humi))
	{
		Serial.println("Chyba pri cteni dat");
	}
	else
	{
		Serial.print("Teplota: ");
		Serial.print(temp);
		Serial.print(" *C, ");
		Serial.print("Vlhkost: ");
		Serial.print(humi);
		Serial.println(" %");
	}

	delay(2000);
}