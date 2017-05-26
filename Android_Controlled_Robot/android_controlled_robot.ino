////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////// Android Controlled robot using Arduino 
///////////// OVerall code
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <SoftwareSerial.h>                // import the serial library1
SoftwareSerial blue(10, 11);               // Defining RX, TX
char BluetoothData;                        // Assigning Integer
//char F,B,S,L,R;

void setup() 
   {
    blue.begin(9600);                      // Enabling Serial Communication for Bluetooth (HC-05)
    Serial.begin(9600);                    // Enabling Serial communcication for serial monitoring of data
    pinMode(2,OUTPUT);                     //Enabling ports for motor interface - Left Motor
    pinMode(3,OUTPUT);      
    pinMode(4,OUTPUT);                    // Enabling ports for motor interface - Right Motor
    pinMode(5,OUTPUT);
  }

void loop() 
  {
   if (blue.available()>0)                // Checking for serial communcation of bluetooth data
     {
        BluetoothData=blue.read();        // Geting values in a varialbe
        delay(10);                       // prepare for next data ...
        Serial.println(BluetoothData);    // Printing values in the monitor for reference
     }
  
switch (BluetoothData) {
      case 'F':
       digitalWrite(2,LOW);
       digitalWrite(3,HIGH);
       digitalWrite(4,LOW);
       digitalWrite(5,HIGH);
        Serial.println("Going forward");
        break;
      case 'R':
       
       digitalWrite(2,LOW);
       digitalWrite(3,LOW);
       digitalWrite(4,LOW);
       digitalWrite(5,HIGH);
        Serial.println("Turning right");
        break;
      case 'L':
       digitalWrite(2,LOW);
       digitalWrite(3,HIGH);
       digitalWrite(4,LOW);
       digitalWrite(5,LOW);
        Serial.println("Turning left");
        break;
      case 'B':
       digitalWrite(2,HIGH);
       digitalWrite(3,LOW);
       digitalWrite(4,HIGH);
       digitalWrite(5,LOW);
        Serial.println("Going backwards");
        break;
      case 'S':
       digitalWrite(2,LOW);
       digitalWrite(3,LOW);
       digitalWrite(4,LOW);
       digitalWrite(5,LOW);
        Serial.println("Stopping");
        break;
      default: 
                                   // if nothing matches, do nothing
        break;
    }
  }
