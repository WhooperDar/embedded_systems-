

int counterSwitch = 0; 
int counterLED = 0; 

int buttonA = 2; 
int buttonB = 3; 

void setup()
{
  // Buttons 
  pinMode(buttonA, INPUT); 
  pinMode(buttonB, INPUT); 
  
  for(counterLED = 4; counterLED <= 11; counterLED++){ 
      pinMode(counterLED, OUTPUT); 
  }
}

void loop()
{
  if((digitalRead(buttonA) == HIGH) && digitalRead(buttonB) == HIGH){
      
      PatternA(); 
      
      PatternB(); 
    
      BlinkLights();
      
      delay(500); 
      
      BlinkLights(); 
      
      runningToRightToLeft(); 
    
  } else if(digitalRead(buttonB) == HIGH){
        PatternB(); 
  } else if(digitalRead(buttonA) == HIGH){
    PatternA(); 
  } else { 
      OnAllLED();
  } 
 
}

void PatternA(){
    //00111100
      OffAllLED(); 
      digitalWrite(6, HIGH); 
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    
      delay(500); 
    
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      
      delay(500);
      //11000011 
      digitalWrite(4, HIGH); 
      digitalWrite(5, HIGH); 
      digitalWrite(10, HIGH); 
      digitalWrite(11, HIGH); 
    
      delay(500); 
      
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW); 
    
}

void PatternB(){ 
  //10101010
      OffAllLED(); 
      digitalWrite(4, HIGH); 
      digitalWrite(6, HIGH); 
      digitalWrite(8, HIGH); 
      digitalWrite(10, HIGH); 
    
      delay(500); 
    
      digitalWrite(4, LOW); 
      digitalWrite(6, LOW); 
      digitalWrite(8, LOW); 
      digitalWrite(10, LOW); 
    
      delay(500); 
      
      // 01010101 
      digitalWrite(5, HIGH); 
      digitalWrite(7, HIGH); 
      digitalWrite(9, HIGH); 
      digitalWrite(11, HIGH); 
    
      delay(500); 
    
      digitalWrite(5, LOW); 
      digitalWrite(7, LOW); 
      digitalWrite(9, LOW); 
      digitalWrite(11, LOW); 
}

void BlinkLights(){
      delay(500); 
  
    OnAllLED(); 
  
      delay(400); 
  
      OffAllLED(); 
  
      delay(700); 
}

void runningToRightToLeft(){ 
  delay(500); 
  
  for(counterLED = 4; counterLED <= 11; counterLED++){
      digitalWrite(counterLED, HIGH); 
      delay(200); 
      digitalWrite(counterLED, LOW); 
  }
}
void OnAllLED(){ 
     digitalWrite(4, HIGH); 
    digitalWrite(5, HIGH); 
    digitalWrite(6, HIGH); 
    digitalWrite(7, HIGH); 
    digitalWrite(8, HIGH); 
    digitalWrite(9, HIGH); 
    digitalWrite(10, HIGH); 
    digitalWrite(11, HIGH); 
}

void OffAllLED(){
    digitalWrite(4, LOW); 
    digitalWrite(5, LOW); 
    digitalWrite(6, LOW); 
    digitalWrite(7, LOW); 
    digitalWrite(8, LOW); 
    digitalWrite(9, LOW); 
    digitalWrite(10, LOW); 
    digitalWrite(11, LOW); 
  
}