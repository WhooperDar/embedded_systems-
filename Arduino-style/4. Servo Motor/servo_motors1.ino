#include <Servo.h> 

Servo servo; 

int position = 0; 

void setup()
{
  servo.attach(9); 
}

void loop()
{
  for(position = 180; position >= 0; position--){
  	servo.write(position); 
    delay(10); 
  }
  
  for(position = 0; position <= 180; position++){
    servo.write(position); 
    delay(10); 
  } 
  delay(1200); 
}