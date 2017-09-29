// Teplotní čidlo DS18B20
#include <OneWire.h>
#include <DallasTemperature.h>

const int pinCidlaDS = 4;
OneWire oneWireDS(pinCidlaDS);
DallasTemperature senzoryDS(&oneWireDS);

void setup(void) {
  Serial.begin(9600);
  senzoryDS.begin();
}

void loop(void) {
  senzoryDS.requestTemperatures();
  // výpis teploty na sériovou linku, při připojení více čidel
  // na jeden pin můžeme postupně načíst všechny teploty
  // pomocí změny čísla v závorce (0) - pořadí dle unikátní adresy čidel
  Serial.println(senzoryDS.getTempCByIndex(0));
  delay(1000);
}
