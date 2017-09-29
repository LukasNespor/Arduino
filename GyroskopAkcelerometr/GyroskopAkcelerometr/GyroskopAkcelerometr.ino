//http://arduino8.webnode.cz/news/lekce-25-arduino-a-akcelerometr-s-mpu-6050/

#include <Wire.h>
#include <Math.h>
#include <I2Cdev.h>
#include <MPU6050.h>

MPU6050 akcelerometr;
const float pi = 3.141592;
const int pocet_vzorku = 100;
int16_t ax, ay, az;
float x, y, z;
int pocet;
float _angle_x, angle_x, _angle_y, angle_y;
long ax_p, ay_p, az_p;

void setup()
{
	Wire.begin();
	Serial.begin(38400);
	akcelerometr.initialize();

	if (akcelerometr.testConnection())
		Serial.println("Spojeni OK...");
}

void loop() {
	// nacten vsech hodnot
	akcelerometr.getAcceleration(&ax, &ay, &az);

	// secteme potrebny pocet hodnot
	ax_p = ax_p + ax;
	ay_p = ay_p + ay;
	az_p = az_p + az;

	// pomocne urceni poctu vzorku
	pocet++;

	if (pocet == pocet_vzorku)
	{
		// zjistime prumerne hodnoty
		x = ax_p / pocet_vzorku;
		y = ay_p / pocet_vzorku;
		z = az_p / pocet_vzorku;

		// vypocitame sklon a naklon
		angle_x = atan2(x, sqrt(square(y) + square(z))) / (pi / 180);
		angle_y = atan2(y, sqrt(square(x) + square(z))) / (pi / 180);

		// vynulujeme hodnoty pro dalsi pouziti
		pocet = 0;
		ax_p = 0;
		ay_p = 0;
		az_p = 0;

		Serial.print(angle_x);
		Serial.print("\t");
		Serial.println(angle_y);
	}
}