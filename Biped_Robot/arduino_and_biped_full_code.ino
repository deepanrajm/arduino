///////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////// Android Controlled Biped - Test Code 1
////////////  Sequence like walk, dance etc.
//////////////////////////////////////////////////////////////////////////////////////////////////////////
                // import the serial library1
#include <VarSpeedServo.h>                    // varialble speed control servo libarary                           // Assigning Integer
VarSpeedServo RU;                          // Ininitalizling servo objects
VarSpeedServo RM;
VarSpeedServo RL;
VarSpeedServo LU;
VarSpeedServo LM;
VarSpeedServo LL;
void setup() 
   {
    blue.begin(9600);                      // Enabling Serial Communication for Bluetooth (HC-05)
    Serial.begin(9600);                   // Enabling Serial communcication for serial monitoring of data
    LU.attach(3);                        // Attaching Servo motors   
    LM.attach(5);
    LL.attach(6);
    RU.attach(9);
    RM.attach(10);
    RL.attach(11);
    
    LU.write(90);           // Initializing all motors to position
    delay(200);
    LM.write(90);
    delay(200);
    LL.write(90);
    delay(200);
    RU.write(90);
    delay(200);
    RM.write(90);
    delay(200);
    RL.write(90);
    delay(200);
    delay (5000);
    int b=60;
  }

void loop() 
  {
   while (blue.available())                // Checking for serial communcation of bluetooth data
     {
       char c=blue.read();        // Geting values in a varialbe
        delay(10); 
       if(c=='#')
    {
      break;
    }
    voice +=c;
     }   
    if (voice.length()>0)
    {
        // prepare for next data ...
      Serial.println(voice);  
      
     if (voice=="*forward")
    {
      Serial.println("moving forward");
      walk ();
    }
    else if (voice=="*stop")
    {
      Serial.println("Stopping");
      halt ();
    }

    else if (voice == "*kick")
    {
      Serial.println("Kicking the ball");
      kick ();
    }
    else  if (voice=="*welcome")
   {
     Serial.println("Greeting you all");
     welcome ();
   } 
   else if (voice=="*left")
   {
     Serial.println("Turning Left");
     left ();
   }
      else if (voice=="*right")
   {
     Serial.println("Turning Right");
     right ();
   }
    else 
    {
      Serial.println("No command found");
      LU.write(90);           // Initializing all motors to position
      delay(200);
      LM.write(90);
      delay(200);
      LL.write(90);
      delay(200);
      RU.write(90);
      delay(200);
      RM.write(90);
      delay(200);
      RL.write(90);
      delay(200);
    }  
      voice="";         // resetting string to get fresh voice command
     }   
  }

  void walk ()
  {
    for (int i=0;i<3;i++)
    {
    LL.write(60,50,true);
    RL.write(60,50,true);
    //RM.write(120,50,true);
    //delay (1000);
    // LL.write(60,50,true);
    RU.write(110,40,true); 
    LM.write(110,50,true);
    // RU.write(90,50,true);
    // LU.write(90,50,true);
    // RM.write(90,20,true);
    RL.write(90,50,true);
    LL.write(90,50,true);
    delay(1000);
    RL.write(125,30,true);
    LL.write(120,100,true);
    int a=RU.read ();
    RU.write(a-10,50,true);
    LM.write(90,50,true);
    LU.write(70,50,true);
    RU.write(60,50,true);
    //LU.write(60,50,true);
    RM.write(60,50,true);
    LL.write(90,50,true);
    RL.write(90,50,true);
    delay(1000);
    // b= RM.read();
    LL.write(60,50,true);
    RL.write(60,50,true);
    RM.write(90,50,true); // updation  
    LU.write(90,50,true);  // updation 
    }
    LU.write(90);           // Initializing all motors to position
      delay(200);
      LM.write(90);
      delay(200);
      LL.write(90);
      delay(200);
      RU.write(90);
      delay(200);
      RM.write(90);
      delay(200);
      RL.write(90);
      delay(200);
    //  delay (1000);
    
   }

    void halt ()
    {
     LU.write(90);  
    delay(200);
    LM.write(90);
    delay(200);
    LL.write(90);
    delay(200);
    RU.write(90);
    delay(200);
    RM.write(90);
    delay(200);
    RL.write(90);
    delay(200);
    }

    void kick ()
    {
    LU.write(90);  
    delay(200);
    LM.write(90);
    delay(200);
    LL.write(90);
    delay(200);
    RU.write(90);
    delay(200);
    RM.write(90);
    delay(200);
    RL.write(90);
    delay(200);
    
   LL.write(60,100,true);
  RL.write(60,100,true);
  
   RM.write(130,100,true);
  // LL.write(60,50,true);
   RL.write(90,10,true); 
   RM.write(90,10,true);
   RU.write(60,10,true);
   RU.write(120,50,true);
   delay(500);
    }
    void welcome ()
    {
    LU.write(90);  
    delay(200);
    LM.write(90);
    delay(200);
    LL.write(90);
    delay(200);
    RU.write(90);
    delay(200);
    RM.write(90);
    delay(200);
    RL.write(90);
    delay(200);
    
    RM.write(60);//,50,true);
    LM.write(120);//,100,true);
    delay(100);
    RM.write(45);
    LM.write(135);
    delay(100);
    RM.write(30);//,50,true);
    LM.write(150);//,100,true);
    delay(500);
    RM.write(60);
    LM.write(120);
    delay(100);
    RM.write(90);
    LM.write(90);
    delay(2000);
    }
    
void left()
{
     LU.write(90);  
    delay(200);
    LM.write(90);
    delay(200);
    LL.write(90);
    delay(200);
    RU.write(90);
    delay(200);
    RM.write(90);
    delay(200);
    RL.write(90);
    delay(200);
    for (int i=0;i<3;i++)
    {
    RL.write(120,50,true);
    LL.write(120,50,true);
    LU.write(70,50,true);
 //RU.write(60,50,true);
 //LU.write(60,50,true);
   RM.write(70,50,true);
   LL.write(90,50,true);
   RL.write(90,50,true);
   delay(500);
   LU.write(110,50,true);
    }
    RL.write(120,50,true);
    LL.write(120,50,true);
    LU.write(90,50,true);
    RL.write(90,50,true);
    LL.write(90,50,true);
    
}

void right ()
{
    LU.write(90);  
    delay(200);
    LM.write(90);
    delay(200);
    LL.write(90);
    delay(200);
    RU.write(90);
    delay(200);
    RM.write(90);
    delay(200);
    RL.write(90);
    delay(200);

    for (int i=0;i<3;i++);
    {
    LL.write(60,50,true);
    RL.write(60,50,true);
  //RM.write(120,50,true);
  //delay (1000);
  // LL.write(60,50,true);

    RU.write(110,40,true); 
 
    LM.write(110,50,true);
  // RU.write(90,50,true);
  // LU.write(90,50,true);
  // RM.write(90,20,true);
    RL.write(90,50,true);
    LL.write(90,50,true);
    delay(400);
    RU.write(70,50,true);
    }
    LL.write(60,50,true);
    RL.write(60,50,true);
    RU.write(90,50,true);
    LL.write(60,50,true);
    RL.write(60,50,true);
    
}
