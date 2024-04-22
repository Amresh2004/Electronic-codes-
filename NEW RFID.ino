#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>

#define SS_PIN 10
#define RST_PIN 9
#define LCD_RS A5
#define LCD_EN A4
#define LCD_D4 A0
#define LCD_D5 A1
#define LCD_D6 A2
#define LCD_D7 A3
#define OK_LCD 3
#define ERROR_BUZ 4

LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
MFRC522 rfid(SS_PIN, RST_PIN);

byte myRFIDTag[4] = {0xD0, 0x36, 0x1A, 0xA4};

void setup() 
{
  pinMode(OK_LCD, OUTPUT);
  pinMode(ERROR_BUZ, OUTPUT);
  digitalWrite(OK_LCD, LOW);
  digitalWrite(ERROR_BUZ, LOW);
  lcd.begin(16, 2);
  lcd.print("SYMBOISIS COLLEGE");
  delay(1000);
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
}

void loop() 
{
  lcd.clear();
  lcd.print("Put your ID-Card");
  
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    return;

  bool isCardValid = true;
  for (int i = 0; i < 4; i++) 
   {
    if (myRFIDTag[i] != rfid.uid.uidByte[i]) 
     { 
      isCardValid = false;
      break;
      }
   }

  if (isCardValid)
  {
    lcd.clear();
    lcd.print("Welcome to class");
    lcd.setCursor(0, 1);
    lcd.print("Access granted");
    digitalWrite(OK_LCD, HIGH);
    delay(1000);
    digitalWrite(OK_LCD, LOW);
   } 
  else
   {
    lcd.clear();
    lcd.print("Card not found");
    lcd.setCursor(0, 1);
    lcd.print("Access denied");
    digitalWrite(ERROR_BUZ, HIGH);
    delay(1500);
    digitalWrite(ERROR_BUZ, LOW);
   }
}