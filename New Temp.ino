#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN A5  // Pin where the DHT11 sensor is connected
#define DHTTYPE DHT11  // DHT sensor type

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);  // LCD initialization
DHT dht(DHTPIN, DHTTYPE);  // DHT sensor initialization

char temperature[] = "Temp=--.-C";  // Temperature display string
char humidity[] = "RH=--.-%";       // Humidity display string

void setup() 
{
  lcd.begin(16, 2);  // Initialize the LCD with 16x2        dimensions
  dht.begin();       // Initialize the DHT sensor
}

void loop() 
{
  delay(2000);  // Delay for 2 seconds between readings

  float RH = dht.readHumidity();         // Read humidity from DHT sensor
  float Temp = dht.readTemperature();    // Read temperature from DHT sensor in Celsius

  // Check if readings are valid
  if (isnan(RH) || isnan(Temp)) 
 {
    lcd.clear();                       // Clear the LCD
    lcd.setCursor(0, 0);
    lcd.print("Error: Check Sensor");  // Display error message if readings are invalid
    return;
  }

  // Update temperature and humidity strings with new readings
  dtostrf(Temp, 4, 1, &temperature[4]);  // Update temperature in the string
  dtostrf(RH, 4, 1, &humidity[4]);        // Update humidity in the string

  // Display temperature and humidity on LCD
  lcd.clear();  // Clear the LCD
  lcd.setCursor(0, 0);
  lcd.print(temperature);

  lcd.setCursor(0, 1);
  lcd.print(humidity);
}