#include<LiquidCrystal.h>
#include<SoftwareSerial.h>
LiquidCrystal lcd(12,11,5,4,3,2);
SoftwareSerial mySerial(9,10); //Rx, Tx.

void setup() 
{
  lcd.begin(16,2);
  pinMode(8,INPUT);
  pinMode(13,OUTPUT);
  mySerial.begin(9600);
  Serial.begin(9600);

}

void loop() {
int  moisture=digitalRead(8);
  Serial.print("The moisture value is:");
  Serial.println(moisture);
  delay(1000);
  if(moisture==HIGH)
  {
    digitalWrite(13,LOW);
    lcd.setCursor(0,0);
    lcd.print("  Flood Detector  ");
    lcd.setCursor(0,1);
    lcd.print(" Normal State... ");
    Serial.println("Everything is normal condition");
    delay(1000);
  }
  else if(moisture==LOW)
  {
         mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+911234567890\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("Its Alert message from Cauvery Dam!!!! \n Flood Alert!!! \n ");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);

    digitalWrite(13,HIGH);
    lcd.setCursor(0,0);
    lcd.print("  Flood Detector  ");
    lcd.setCursor(0,1);
    lcd.print(" Flood Alert!!!! ");
    Serial.println("Flood Alert!!!!!");
    delay(8000);
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print("  Flood Detector  ");
    lcd.setCursor(0,1);
    lcd.print(" Final year ECE ");
  }

}

