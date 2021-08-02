#include <TinyDHT.h>
#define DHTPIN 6
#define DHTTYPE DHT21

int Led1=10;
int Led2=11;
int Led3=12;
DHT dht(DHTPIN,DHTTYPE);
void setup() {
  Serial.begin(9600);
  dht.begin();

pinMode(6,INPUT);
pinMode(Led1,OUTPUT);
pinMode(Led2,OUTPUT);
pinMode(Led3,OUTPUT);

digitalWrite(Led1,HIGH);
digitalWrite(Led2,LOW);
digitalWrite(Led3,LOW);
}

void loop() {
float  T = dht.readTemperature();
delay(2000);
Serial.print("TEMP C");
Serial.println (T);


if (T<=22){
  digitalWrite(Led1,HIGH);
  digitalWrite(Led2,LOW);
}

if (T>=23 && T<=30)  {
  digitalWrite(Led2,HIGH);
  digitalWrite(Led3,LOW);
  
}

if (T>=30) {
  digitalWrite(Led3,HIGH);
}
}
