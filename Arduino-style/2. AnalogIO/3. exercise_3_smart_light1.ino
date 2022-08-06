int lightlevel, percent; 

void setup()
{
  Serial.begin(9600); 
  pinMode(A0, INPUT);
  pinMode(10, OUTPUT); 
}

void loop()
{
  lightlevel = analogRead(A0); 
  
  // day = LED OFF 
  if(lightlevel == 344){ 
    analogWrite(10, lightlevel-lightlevel); 
    delay(70); 
  } 
  
  if(lightlevel > 344 && lightlevel <= 488){
    analogWrite(10, 1023 + lightlevel); 
    delay(70); 
  }
  
  // night = LED ON
  if(lightlevel >= 900 && lightlevel <= 1017){
    analogWrite(10, lightlevel/4); 
    delay(70); 
  }
}

