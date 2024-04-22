#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN A5 
#define DHTTYPE DHT11 

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);  
DHT dht(DHTPIN, DHTTYPE); 

char temperature[] = "Temp=--.-C";  
char humidity[] = "RH=--.-%";     

void setup() 
{
  lcd.begin(16, 2); 
  dht.begin();      
}

void loop() 
{
  delay(2000); 

  float RH = dht.readHumidity();         
  float Temp = dht.readTemperature();   


  if (isnan(RH) || isnan(Temp)) 
 {
    lcd.clear();                     
    lcd.setCursor(0, 0);
    lcd.print("Error: Check Sensor");  
    return;
  }

 
  dtostrf(Temp, 4, 1, &temperature[4]); 
  dtostrf(RH, 4, 1, &humidity[4]);  

 
  lcd.clear();  
  lcd.setCursor(0, 0);
  lcd.print(temperature);

  lcd.setCursor(0, 1);
  lcd.print(humidity);
}