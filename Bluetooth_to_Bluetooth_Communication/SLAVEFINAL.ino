
int state;
void setup() 
{
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600); // Default communication rate of the Bluetooth module
}
void loop() 
{
 if(Serial.available() > 0)  // Checks whether data is comming from the serial port
 {
    state = Serial.read(); // Reads the data from the serial port
 }
 // Controlling the LED
 if (state == '1') 
 {
  for (int a=0;a<255;a++)
      {
      analogWrite(3,a);
      delay (5);
      } 
  for (int b=0;b<255;b++)
      {
      analogWrite(5,b);
      delay (5);
      } 
  for (int c=0;c<255;c++)
      {
      analogWrite(6,c);
      delay (5);
      } 
  delay(3000);
 }
 else if (state == '0') 
 {
  analogWrite(3,10);
  analogWrite(5,10);
  analogWrite(6,10);
 }
 else if (state == '2')
 {
  analogWrite(3,200);
  analogWrite(5,200);
  analogWrite(6,200);
 }

}
