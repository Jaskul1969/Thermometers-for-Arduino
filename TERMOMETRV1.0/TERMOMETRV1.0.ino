
#include "DHT.h"// that was include libray for thermometer
#define DHT11_PIN 12// this command was define pin of thermometr for 12
DHT dht;
void setup() {
 Serial.begin(9600);
dht.setup(DHT11_PIN);

}

void loop() {
 int wilgotnosc = dht.getHumidity();//in my language wilgotność is humidity
  Serial.print(wilgotnosc);//That was showing our humidity on serial port
  Serial.print("%RH|");  
  int temperatura = dht.getTemperature();//in polish temperatura is tmemperature
  Serial.print(temperatura);//Like in humidity this show temperature
  Serial.println("*C");//There is ln on the end of print because this is end of the message for serial port
 delay(1000);
}
