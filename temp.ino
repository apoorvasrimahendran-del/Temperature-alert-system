#include<DHT.h>
DHT dht(2,DHT11);
int buzzer=3;
int led =4;
void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(buzzer,OUTPUT);
  pinMode(led,OUTPUT);
 
}

void loop() {
  float val = dht.readTemperature();
  Serial.println(val);
   if (val >=33){
    digitalWrite(buzzer,HIGH);
    digitalWrite(led,HIGH);
    Serial.println("HIGH TEMPERATURE");
   }
   else{
    digitalWrite(buzzer,LOW);
    digitalWrite(led,LOW);
    Serial.println("NORMAL");
   }
   delay(1000);
}
