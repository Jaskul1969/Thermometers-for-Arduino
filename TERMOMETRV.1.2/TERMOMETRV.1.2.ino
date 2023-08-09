#include "DHT.h"
#define DHT11_PIN 12
DHT dht;
 #include <LiquidCrystal.h> 
 LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
void setup()
{
  lcd.begin(16, 2); 
  Serial.begin(9600);
  dht.setup(DHT11_PIN);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("   TERMOMETR   ");
  lcd.setCursor(0,1);
  lcd.print("     V.1.2       ");
  delay(5000);
  
}
 int jasnosc = 0; 
 int zmiana = 5;   
void loop()
{
  
  //Pobranie informacji o wilgotnosci
  int wilgotnosc = dht.getHumidity();
  Serial.print(wilgotnosc);
  Serial.print("%RH | ");
   lcd.clear();
   delay(500);
   lcd.setCursor(0,1);
   lcd.print("Wilg:");
  lcd.print(wilgotnosc);
  lcd.print("%RH");
  
  //Pobranie informacji o temperaturze
  int temperatura = dht.getTemperature();
  Serial.print(temperatura);
  Serial.println("*C");
  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.print(temperatura);
  lcd.print("*C");
  
  
  
 
  delay(1000); //Odczekanie wymaganego czasu
}
