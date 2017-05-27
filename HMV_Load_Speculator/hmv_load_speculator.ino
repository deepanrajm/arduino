//HMV load speculator with One GSM:

#include<LiquidCrystal.h>
#include <SoftwareSerial.h>
#include "HX711.h"
int kg=0;

HX711 scale; //HX711 scale(DOUT, SCK);
SoftwareSerial mySerial(5,6); //Rx, Tx.


LiquidCrystal lcd(8,9,10,11,12,13);
void setup()  
{ 
   scale.begin(A1, A0);
    scale.set_scale(2280.f);                       // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare();  
  lcd.begin(16,2);
   lcd.setCursor(0,0);
   lcd.print("HMV LOAD SPECULATOR");
   lcd.setCursor(0,1);
   lcd.print("Jai");
   mySerial.begin(9600);
    Serial.begin(9600); //Baud Rate  
    pinMode(11, OUTPUT);  
    pinMode(12, OUTPUT);
}  
void loop()
{
  
    int kg = (scale.get_units()*0.45359237);
     Serial.println("In kg=");
     Serial.println(kg);
     delay(1000);
   
   if(kg>=8 && kg<=10)
   {
     mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+918122716635\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Carrying tons is:");// The SMS text you want to send
  mySerial.println(kg);
  mySerial.println("Your vehicle carrying between 8 tons to 10 tons \n Carrying minimum weight \n Speed limit of vehicle is 80kmph");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Speed limit 80kmph");
     lcd.setCursor(0,1);
     lcd.print("Vehicle Empty");
     
     Serial.println("Speed limit of vehicle is 80kmph");
     Serial.println("Your vehicle is empty");
     Serial.println("Weight is =");
     Serial.println(kg);
     delay(10000);
   }
   else if(kg>=11 && kg<=20)
   {
    mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+918122716635\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Carrying tons is:");// The SMS text you want to send
  mySerial.println(kg);
  mySerial.println("Your vehicle lifting less than 20 tons \n Speed limit of vehicle is 60kmph \n your vehicle carrying valid weight");
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Speed limit 60kmph");
     lcd.setCursor(0,1);
     lcd.print("Valid weight");
     Serial.println("Speed limit of vehicle is 60kmph");
     Serial.println("Your vehicle is carrying the valid weight");
     Serial.println("Weight is =");
     Serial.println(kg);
     delay(10000);
   }
   if(kg>=21 && kg<=25)
   {
     mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+918122716635\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Carrying tons is:");// The SMS text you want to send
  mySerial.println(kg);
  mySerial.println("Your vehicle lifting less than 25 tons \n Speed limit of vehicle is 40kmph \n your vehicle almost reached maximum weight to carry");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Speed limit 40kmph");
     lcd.setCursor(0,1);
     lcd.print("Almost Maximum");
     Serial.println("Speed limit of vehicle is 40kmph");
     Serial.println("Your vehicle almost reached the maximum weight");
     Serial.println("Weight is =");
     Serial.println(kg);
     delay(10000);
   }


 
   else if(kg>=26)
   {
    mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+918122716635\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Carrying tons is:");// The SMS text you want to send
  mySerial.println(kg);
  mySerial.println("Your vehicle carrying more than 26 tons \n Its Illegal to carry \n Your vehicle carrying more weight and it should stop at this condition");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Exceed weight");
     lcd.setCursor(0,1);
     lcd.print("Vehicle halt");
     Serial.println("Your vehicle carrying more weight");
     Serial.println("Vechile should stop at this condition");
     Serial.println("Weight is =");
     Serial.println(kg);
     delay(10000);
   }
      else
   {
    lcd.clear();
     lcd.setCursor(0,0);
   lcd.print("HMV LOAD SPECULATOR");
   lcd.setCursor(0,1);
   lcd.print("Deepan");

   }
}




