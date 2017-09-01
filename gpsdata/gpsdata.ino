//program to find gps location using arduno and display it on lcd display

#include <SoftwareSerial.h>
#include<string.h>
SoftwareSerial mySerial(8,9);
char gps[100];

void setup()
{
  
  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.print("GPS INITIALISING\n");
 delay(1000);
 Serial.print("................\n");
 delay(1000);
while(mySerial.available()==0);
String gps = mySerial.readStringUntil('\r');
if(gps.substring(0,6)=="$GPGGA")
{
Serial.print("UTC:");
Serial.print(gps.substring(7,8));
Serial.print(":");
Serial.print(gps.substring(9,10));
Serial.print(":");
Serial.println(gps.substring(11,12));
Serial.print("LAT:");
Serial.println(gps.substring(14,29));
Serial.print("LONG:");
Serial.println(gps.substring(30,42));
}
}


void loop()
{

}






  
