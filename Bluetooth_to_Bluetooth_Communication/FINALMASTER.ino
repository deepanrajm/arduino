
int ObstaclePin_1 = 7; 
int ObstaclePin_2 = 8; 
int button = 2;
//int state;
int Obstacle_1 = LOW;
int Obstacle_2 = LOW;
int button_value = LOW;
int i=0;

void setup() {
 pinMode(ObstaclePin_1, INPUT);
 pinMode(ObstaclePin_2, INPUT);
 pinMode(button, INPUT);
  Serial.begin(9600); // Default communication rate of the Bluetooth module
 
}
void loop() 
{

Obstacle_1 = digitalRead(ObstaclePin_1);
Obstacle_2 = digitalRead(ObstaclePin_2);
button_value = digitalRead (button);
if (button_value == LOW)
{
if (Obstacle_1 == HIGH)
  {
    i=1;
 
if (Obstacle_2 == HIGH)
  {
    if (i==1)
    {
      Serial.write('1');
      i=0;
    }
   else 
   {
     Serial.write('0');
   }
  }

else 
{
 Serial.write('0');
 }
}
else if (button_value == HIGH)
{
  Serial.write ('2');
}
 
}

