#include <SoftwareSerial.h>
int value;
void setup()
{
  Serial.begin(9600);
  pinMode(13,INPUT);
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
    
