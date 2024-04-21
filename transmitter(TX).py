void setup() 
{
   Serial.begin(9600);
}
void loop() 
{
  float TempLM35,Pot;
  char sign = 223;
  TempLM35 = analogRead(A0);
  delay(100);
  Pot = analogRead(A1);
  Serial.print(TempLM35* 0.48828125);
  Serial.print(sign);
  Serial.print("C ");
  Serial.print(Pot* 0.48828125);
  Serial.print("mV\n");
  delay(1000);
}
