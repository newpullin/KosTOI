#include <dht.h>
#include <SoftwareSerial.h>

#define TX_PIN 3
#define RX_PIN 4
#define DHT11_PIN 2
#define GREEN_PIN 8
#define YELLOW_PIN 7

dht DHT;
float hum;
float temp;
String s_hum = ":h:";
String s_tem = ":t:";
String readString;

SoftwareSerial BT(TX_PIN, RX_PIN);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BT.begin(9600);
  Serial.write("why");
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  DHT.read11(DHT11_PIN);
  hum = DHT.humidity;
  temp = DHT.temperature;

  BT.print(s_hum+String(hum)+s_tem+String(temp));
  while(BT.available()) {
    delay(3);
    char c = BT.read();
    readString += c;
  }
  readString.trim();

  if(readString.length() > 0) {
    if(readString.startsWith("on")) {
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(YELLOW_PIN, LOW);
    }
    if(readString.startsWith("of")) {
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(YELLOW_PIN, HIGH);
    }
  }
  Serial.println(readString);
  readString = "";
  delay(5000);
}
