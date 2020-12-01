#include <dht.h>
#include <SoftwareSerial.h>

#define TX_PIN 3
#define RX_PIN 4
#define DHT11_PIN 2

dht DHT;
float hum;
float temp;
String s_hum = ":h:";
String s_tem = ":t:";
SoftwareSerial BT(TX_PIN, RX_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BT.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  DHT.read11(DHT11_PIN);
  hum = DHT.humidity;
  temp = DHT.temperature;

  BT.print(s_hum+String(hum)+s_tem+String(temp));
  
  delay(3000);
}
