#include "DHT.h"    
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int sensor = A0;
int led = 12;

void setup() {
  
 Serial.begin(115200);
 Serial.println("DHTxx test!");
 
 pinMode(led,OUTPUT);
 pinMode(sensor,INPUT);
dht.begin();
}

void loop() 
{
  
 delay(1000);
 int value=analogRead(sensor);
 float h = dht.readHumidity();
 float t = dht.readTemperature();
 Serial.print("Sensor: "); 
 Serial.print(value);
 Serial.print("  Hum: ");
 Serial.print(h);
 Serial.print(" %\t");
 Serial.print("Temp: ");
 Serial.print(t);
 Serial.print(" *C ");
 Serial.print("\n");
 if(value > 100 ){
  digitalWrite(led,HIGH);
  }
  else 
  {
  digitalWrite(led,LOW);
  }
}
# tailieu
