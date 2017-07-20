//the program for home automation using relay module through bluetooth
The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int a;
void setup()
{
  Serial.begin(9600);    
  Serial.write("HELLO TASHI\n");  
  pinMode(13,OUTPUT);
    lcd.begin(16, 2);
     lcd.print("hello, TASHI");

  
  
}
void loop()
{
  if(Serial.available())
  {
    a=Serial.read();
  if(a=='1')
  {
    digitalWrite(13,HIGH);
    Serial.write("The switch is ON\n");
    lcd.clear();
    lcd.setCursor(16, 1);
     lcd.print("The switch is ON");
  }
  else if(a=='0')
  {
    digitalWrite(13,LOW);
    Serial.write("The switch is OFF\n");
    lcd.clear();
    lcd.setCursor(16, 1);
     lcd.print("The switch is OFF");
  }
  }
}
    
