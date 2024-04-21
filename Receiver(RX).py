#include <LiquidCrystal.h>
int serIn;
char serInString[20];
int serInIndx = 0;
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int lcd_key = 0;
int adc_key_in = 0;
float volt = 0;
void readSerialString () 
{
 char ch;
 if (Serial.available() > 0) 
  {
    delay(100);
    for(int i = 0; i < 20; ++i)
     {
       serInString[i] = 0;
     }
   do
     {
       ch = (char) Serial.read();
       if(ch != '\n')
        {
          serInString[serInIndx] = ch;
          serInIndx++;
        }
     } while(ch != '\n');
       serInIndx = 0;
   }
}
void printSerialString()
{
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.write("Temp & Volt Disp.");
 lcd.setCursor(0, 1);
 lcd.write(serInString);
}
void setup() 
{
 lcd.begin(16, 2);
 lcd.setCursor(0, 0);
 lcd.print("**More COllege**"); 
 delay(2000);
 Serial.begin(9600);
}
void loop() 
{
 readSerialString();
 printSerialString();
 delay(1000);
}
