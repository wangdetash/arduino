//program to find gps location using arduno and display it on lcd display

#include<LiquidCrystal.h>

#include <SoftwareSerial.h>
SoftwareSerial mySerial(8,9);
LiquidCrystal LCD(12, 11, 7, 6, 5, 4);
char rec;
String gps="";
int i=0,f1=0,f2=0;

void setup()
{

   Serial.begin(9600);
  mySerial.begin(9600);
  LCD.begin(16,2);
}

void loop()
{
  do
{
 LCD.setCursor(0,0);
LCD.print("GPS INITIALISING");
LCD.setCursor(0,1);
LCD.print("................ ");
}
 while(mySerial.available()==0);

rec=(char)mySerial.read();

  Serial.print(rec);

 if(rec=='*' && f1==6)
    {

      f1=7;
      f2=1;
      i=0;

    }

   
      if(rec=='$')
    {
      f1=1;
      
    }

    if(rec=='G' && f1==1)
    {
      f1=2;
    }
     if(rec=='P' && f1==2)
    {
      f1=3;
    }
     if(rec=='G' && f1==3)
    {
      f1=4;
    }
     if(rec=='G' && f1==4)
    {
      f1=5;
    }
     if(rec=='A' && f1==5)
    {
      f1=6;
    }
    if(f1==6)
    {
      gps+=rec;

    }




LCD.clear();
LCD.setCursor(0,0);
LCD.print("LNG:");
LCD.print(gps.substring(12,23));
LCD.setCursor(0,1);
LCD.print("LAT:");
LCD.print(gps.substring(24,38));
Serial.print(gps);
}






  
