#include <dht.h>
int sensor_pin = A0; 
int output_value ;

dht DHT;

#define DHT11_PIN 4
#define vcc2 2

void setup(){
  Serial.begin(9600);
  pinMode(7,OUTPUT);
  pinMode(vcc2,OUTPUT);
  digitalWrite(vcc2,HIGH);
Serial.println("Reading From the Sensor ...");
delay(2000);
}

void loop(){
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(2000);
  output_value= analogRead(sensor_pin);
output_value = map(output_value,550,10,0,100);
Serial.print("Mositure : ");
Serial.print(output_value);
Serial.println("%");
if(output_value<0){
digitalWrite(7,HIGH);
  Serial.print("MOTOR IS TURNED ON ");
}
else{
digitalWrite(7,LOW);
  Serial.print("MOTOR IS TURNED OFF ");
}
delay(5000);
}
