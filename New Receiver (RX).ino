#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
char serInString[21]; 
int serInIndx = 0;   

void readSerialString() 
{
  while (Serial.available() > 0 && serInIndx < 20) 
   {
    char ch = Serial.read();       
    if (ch != '\n') 
     {               
      serInString[serInIndx++] = ch; 
     } 
    else 
     {                    
      serInString[serInIndx] = '\0'; 
      serInIndx = 0;              
     }
   }
 }

void printSerialString() 
{
  lcd.clear();                   
  lcd.setCursor(0, 0);           
  lcd.print("Temp & Volt Disp.");
  lcd.setCursor(0, 1);            
  lcd.print(serInString);         
}

void setup() 
{
  lcd.begin(16, 2);              
  lcd.print("RMC"); 
  delay(2000);                  
  Serial.begin(9600);            
}

void loop() 
{
  readSerialString();  
  printSerialString();  
  delay(1000);          
}
