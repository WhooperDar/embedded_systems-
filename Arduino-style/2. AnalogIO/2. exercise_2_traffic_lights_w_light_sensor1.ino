// C++ code
//

int LED_red = 13; 
int LED_yellow = 12; 
int LED_green = 11; 
int pushButtonPin = 7;
int potentiometerSensor = A0; 
const int delayYellowLED = 1000; 
int sensorVal = 0; 
unsigned long timeDelay = 0; 

int lightSensor = A1; 
void setup()
{
  Serial.begin(9600); 
  pinMode(LED_red, OUTPUT);
  pinMode(LED_yellow, OUTPUT);
  pinMode(LED_green, OUTPUT); 
  pinMode(potentiometerSensor, INPUT); 
  pinMode(pushButtonPin, INPUT_PULLUP); 
  
  pinMode(lightSensor, INPUT); 
}

void loop()
{
  // Push Button 
  	pushButtonFunctionality();
  
  // Light Sensor 
  lightSensorPlay(); 
  
  // Potentiometer Sensor Reading 
  sensorVal = analogRead(potentiometerSensor); 
  
  if(sensorVal != 0){ 
    //  proportional second from analog
    timeDelay = sensorVal * 10; 
    
    Serial.print("Time: "); 
    Serial.println(timeDelay/1000); 
    openLED(timeDelay); 
  } 
}

void lightSensorPlay(){
  int lightValue = analogRead(A1); 
  
  	// Night Time 
  if(lightValue >= 489 && lightValue <= 1071){
   	 digitalWrite(LED_red, HIGH); 
  	 delay(10000); 
     digitalWrite(LED_red, LOW); 
  } 
  
  	 // Day Time  
  if(lightValue >= 344 && lightValue <= 488){
   	 digitalWrite(LED_green, HIGH); 
     delay(4000); 
     digitalWrite(LED_green, LOW); 
    
     digitalWrite(LED_yellow, HIGH); 
     delay(1000); 
     digitalWrite(LED_yellow, LOW); 
    
     digitalWrite(LED_red, HIGH); 
     delay(4000); 
    
     digitalWrite(LED_red, LOW); 
  }
  
  
}

void pushButtonFunctionality(){
  
  // push button functionality
  
  // first option to on LED green 
  if(digitalRead(pushButtonPin) == LOW && digitalRead(LED_red) == HIGH){
  	digitalWrite(LED_green, HIGH); 
    digitalWrite(LED_red, LOW); 
    digitalWrite(LED_yellow, LOW); 
  }
 
  
  // second option to on LED red
  if(digitalRead(pushButtonPin) == LOW && 
     digitalRead(LED_yellow) == LOW && 
     digitalRead(LED_red) == LOW)
  {
    
    // LED Green On
    digitalWrite(LED_yellow, LOW); 
    digitalWrite(LED_red, LOW); 
    digitalWrite(LED_green, HIGH); 
    
    delay(500); 
  } 
  
  
  if (digitalRead(pushButtonPin) == LOW && 
					digitalRead(LED_green) == HIGH &&
      				digitalRead(LED_red) == LOW){
    // LED yellow ON 
    digitalWrite(LED_green, LOW); 
    digitalWrite(LED_red, LOW); 
    digitalWrite(LED_yellow, HIGH); 
    
    delay(500); 
  }
  
  
  if (digitalRead(pushButtonPin) == LOW && 
     			  digitalRead(LED_yellow) == HIGH &&
  				  digitalRead(LED_green) == LOW){
    
    // LED red ON
    digitalWrite(LED_yellow, LOW); 
    digitalWrite(LED_green, LOW); 
    digitalWrite(LED_red, HIGH);
    
    delay(500); 
  } 
}

void openLED(unsigned long timeDelay){
  	digitalWrite(LED_green, HIGH); 
  	delay(timeDelay);
   	digitalWrite(LED_green, LOW); 
  	
  	digitalWrite(LED_yellow, HIGH); 
  	delay(delayYellowLED); 
  	digitalWrite(LED_yellow, LOW); 
  
	digitalWrite(LED_red, HIGH); 
    delay(timeDelay);
  	digitalWrite(LED_red, LOW); 
}