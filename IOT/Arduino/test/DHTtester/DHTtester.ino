#include <dht.h>
dht DHT;
#define DHT11_PIN 2
float hum;
float temp;

void setup() {
  Serial.begin(9600);
}

void loop() {
  DHT.read11(DHT11_PIN);
  hum = DHT.humidity;
  temp = DHT.temperature;

  Serial.print("Hum : ");
  Serial.print(hum);
  Serial.print(" Tem : ");
  Serial.print(temp);
  Serial.print("\n");
  delay(3000);
}
