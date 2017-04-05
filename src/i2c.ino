#include <TinyDHT.h>

#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__) || defined(__AVR_ATmega328__)
#define HAS_SERIAL 1
#endif

#define DHTTYPE DHT22

/* D2 on nano */
#define DHTPIN 2

DHT dht(DHTPIN, DHTTYPE);

void setup() {
#if defined(HAS_SERIAL)
	Serial.begin(9600);
	Serial.println("DHTxx test!");
#endif
	dht.begin();
}

void loop() {
	int8_t h = dht.readHumidity();
	int16_t t = dht.readTemperature(false); // false == C
	if ( t == BAD_TEMP || h == BAD_HUM ) {
#if defined(HAS_SERIAL)
		Serial.println("Failed to read from DHT");
#endif
	} else {
#if defined(HAS_SERIAL)
		Serial.print("Humidity: "); 
		Serial.print(h);
		Serial.print(" %\t");
		Serial.print("Temperature: "); 
		Serial.print(t);
		Serial.println(" *C");
#endif
	}
	delay(2000);
}
