#include <SoftwareSerial.h>
int value;
LiquidCrystal LCD(12, 11, 7, 6, 5, 4);
void setup()
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  LCD.setCursor(0,0);
  LCD.print("SWITCH STATUS");
 
}
void loop()
{
  if(Serial.available()==1)
  {
    value=Serial.read();
  if(value==1)
  {
    digitalWrite(13,HIGH);
  }
  else
  {
    digitalWrite(13,LOW);
  }
  }
}
    
