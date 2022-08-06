int main(void){
  
  DDRB = 0b00111111; 
  DDRD = 0b11000000;
  
  while(1){
   
    // RUNNING LIGHTS
    if(PIND & 0b00001000 && PIND & 0b00000100){ 
    	runningLights();
      
      // Pattern A
    } else if(PIND & 0b00001000){ 
      PORTB |= 0b00101010;
      PORTD |= 0b10000000; 
      
      // Pattern B
    } else if(PIND & 0b00000100){
      PORTB |= 0b00010101; 
      PORTD |= 0b01000000; 
      
    }  else {
      // ON AND OFF LIGHTS
        PORTB |= 0b00111111; 
        PORTD |= 0b11000000; 
        _delay_ms(1000); 
        closeLEDS(); 
    }
  } 
}


void closeLEDS(){
  PORTB &= 0b00000000; 
  PORTD &= 0b00000000;
  
  _delay_ms(1000);
}

void runningLights(){
  PORTB |= 0b00100000; 
  _delay_ms(200); 
  PORTB &= 0b0000000; 
  
  PORTB |= 0b00010000; 
  _delay_ms(200); 
  PORTB &= 0b0000000; 
  
  PORTB |= 0b00001000; 
  _delay_ms(200); 
  PORTB &= 0b0000000; 
  
  PORTB |= 0b0000100; 
  _delay_ms(200); 
  PORTB &= 0b0000000; 
  
  PORTB |= 0b0000010; 
  _delay_ms(200); 
  PORTB &= 0b0000000;
  
  PORTB |= 0b0000001; 
  _delay_ms(200); 
  PORTB &= 0b0000000;
  
  PORTD |= 0b10000000; 
  _delay_ms(200); 
  PORTD &= 0b0000000;
  
  PORTD |= 0b01000000; 
  _delay_ms(200); 
  PORTD &= 0b0000000;
  
  closeLEDS();
}
