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
Serial.print("LAT:");
Serial.print(gps.substring(12,23));
Serial.print('\n');
Serial.print("LONG:");
Serial.print(gps.substring(24,38));
Serial.print('\n');
}


void loop()
{

}






  
