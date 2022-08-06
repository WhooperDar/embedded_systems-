#include <Timer.h> 

Timer timer; 

int i, potentiometerVal = 0, timeDelay = 0; 
uint8_t buttonState = LOW, eventEnder = 0;
int buttonPin = 3, blinkCounter = 0; 
int blinker = 0; 

void setup() {

  Serial.begin(9600);
  
  for(i =13; i >= 11; i--){
    pinMode(i, OUTPUT);   
  }
  pinMode(buttonPin, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(buttonPin), alarmRed, CHANGE); 
}

void loop() {
  timer.update(); 
  
  potentiometerVal = analogRead(A0); 
  timeDelay = map(potentiometerVal, 0, 1023, 0, 255); 

  if (buttonState == LOW){
    trafficLights(); 
  }
  if(buttonState == HIGH) {
    emergencyRed(); 
  }
}

void alarmRed(){
  buttonState = !buttonState;
}

void trafficLights(){
  Serial.println("Playing traffic lights!");
  for(i = 13; i >= 11; i--){
      digitalWrite(i, HIGH); 
      delay(timeDelay);
      
      digitalWrite(i, LOW);
      delay(timeDelay); 

     if(i == 11){ 
       i++; 
       digitalWrite(i, HIGH); 
       delay(timeDelay); 
       digitalWrite(i, LOW); 
       i--; 
      }
    }
  
    delay(200); 
  
    offAllLeds();
}
void emergencyRed(){ 
  eventEnder = timer.oscillate(13, 1000, HIGH);  
  
  int lightState = digitalRead(13); 
  int blinkLight = lightState - blinker; 
  
   if(blinkLight == 1 || blinkLight == -1){
    blinker = blinkLight;

    if(lightState == HIGH){
      blinkCounter++;
      Serial.print("Blinking: ");
      Serial.println(blinkCounter); 
    }
   }

  timer.after(60000, stopEvent);
  
  offAllLeds();
}

void stopEvent(){
  timer.stop(eventEnder); 
  Serial.println("Blinking Stops");
}

void offAllLeds(){
  for(i = 12; i >= 11; i--){
    digitalWrite(i, LOW); 
  }
}
