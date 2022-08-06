#include <Stepper.h>
#include <Timer.h> 

// Variables
int eventID_clockwise = 0, eventID_counterClockwise = 0, eventID_counterClockwise2 = 0; 

const int stepsPerRevolution = 5;  // change this to fit the number of steps per revolution

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

// Timer instance 
Timer timer; 

void setup() {
  
  // initialize the serial port:
  Serial.begin(9600);

  // set the speed at 40 rpm:
  myStepper.setSpeed(40);
  
  // Clockwise revolution 5 times 
  eventID_clockwise = timer.every(12 * 1000, clockwiseRevolt, 5); 
  
  // Counterclockwise revolution 2 times
  eventID_counterClockwise = timer.every(65000, counterClockwiseRevolt, 1); 
  eventID_counterClockwise2 = timer.every(67000, counterClockwiseRevolt, 1);

  // terminate event 1 (counterclockwise) after one minute
  timer.after(60 * 1000, endEvent1); 
  // terminate event 2 (counterclockwise) after one minute 
  timer.after(120 * 1000, endEvent2);  
}

void loop() {
  timer.update(); 
}

// Clockwise rotation
void clockwiseRevolt(){

  Serial.println("Clockwise direction."); 
 
  myStepper.step(stepsPerRevolution); 
  
  delay(50); 
}

// Counterclockwise rotation 
void counterClockwiseRevolt(){ 
   
  Serial.println("Counter-clockwise direction.");
  
  myStepper.step(-stepsPerRevolution);
 
  delay(50);
}

void endEvent1(){ 
  timer.stop(eventID_clockwise);
}

void endEvent2(){ 

  timer.stop(eventID_counterClockwise);
  timer.stop(eventID_counterClockwise2); 

  Serial.println("Both events end");
}
