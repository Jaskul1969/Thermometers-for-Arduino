#include "DHT.h"
#define DHTTYPE DHT11
#define DHTPIN 12
DHT dht(DHTTYPE, DHTPIN);
 #include <LiquidCrystal.h> 
 LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
void setup()
{
  lcd.begin(16, 2); 
  Serial.begin(9600);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("   TERMOMETR   ");
  lcd.setCursor(0,1);
  lcd.print("     V.1.3       ");
  delay(5000);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  
  
}
 int jasnosc = 0; 
 int zmiana = 5;   
void loop()
{
  
  //Pobranie informacji o wilgotnosci
  int wilgotnosc = dht.humidity;
  Serial.print(wilgotnosc);
  Serial.print("%RH | ");
  lcd.clear();
  delay(500);
  lcd.setCursor(0,1);
  lcd.print("Wilg:");
  lcd.print(wilgotnosc);
  lcd.print("%RH");
  
  //Pobranie informacji o temperaturze
  int temperatura = dht.temperature;
  Serial.print(temperatura);
  Serial.println("*C");
  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.print(temperatura);
  lcd.print("*C");
  if (temperatura > 20)
    digitalWrite(9, HIGH);
  if (temperatura > 0)
    digitalWrite(8, HIGH);
  if (temperatura > 30)
    digitalWrite(10, HIGH);
  
  
 
  delay(1000); //Odczekanie wymaganego czasu
}
