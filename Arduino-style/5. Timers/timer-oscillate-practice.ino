#include <Event.h>
#include <Timer.h> 

Timer timer; 

int i; 
int sensorVal; 

void setup() {

  Serial.begin(9600); 
  
  // put your setup code here, to run once:
  for(i = 13; i >= 6; i--){
    pinMode(i, OUTPUT); 
  }

  // Sensor Value 
  sensorVal = analogRead(A0); 
  sensorVal = map(sensorVal, 0, 1023, 0, 128); 

  Serial.println("Sensor Value: ");
  Serial.print(sensorVal); 
  
  if(sensorVal > 64){
     timer.every(2000, patternA, 5); 
     delay(2000); 
     timer.every(4000, patternB, 1); 
  }
  
  closeAllLEDs();
}

void loop() {
  // put your main code here, to run repeatedly:

  timer.update(); 
}

void patternA(){
   // display pattern 11110000
  for(i = 13; i >= 10; i--){
    timer.oscillate(i, 300, LOW, 1); 
  } 
}

void patternB(){
  // display pattern 00001111
  for(i = 6; i <= 9; i++){
    timer.oscillate(i, 700, HIGH, 1); 
  }
}

void secondPatterns(){
  // display pattern 00110011
  for(i = 6; i <= 11; i++){
    if(i == 11 || i == 10 || i == 7 || i == 6){
      timer.oscillate(i, 1000, LOW); 
    }
  }
  
  delay(1000); 

  closeAllLEDs();

  // display pattern 11001100 
  for(i = 13; i >= 8; i--){
    if(i == 13 || i == 12 || i == 9 || i == 8){
      timer.oscillate(i, 1000, HIGH); 
    }
  }

  closeAllLEDs();
}

void closeAllLEDs(){
  for(i = 6; i <= 13; i++){
    digitalWrite(i, LOW); 
  }

  delay(500); 
}
