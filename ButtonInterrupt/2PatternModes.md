Generate the following sequences, change the mode with button press.

![image](https://user-images.githubusercontent.com/73575765/119224533-81190d80-bb07-11eb-9071-a0af3af141de.png)


```
int period=400;
unsigned long time_now = 0;
const byte button = 3;
int control = 0,counter=0,counter2=0,counter3=0,i=1,j=0,k=6;
void setup()
{
  cli();         
  TCCR1A = 0;    
  TCCR1B = 0;    
  TCCR1A |= (1 << WGM21); 
  OCR2A = 124;
  TCCR1B |= (1 << CS11);
  TIMSK1 |= ( 1 << OCIE1A); 
  sei();
  DDRB = B11111111;
  DDRD = B11000000;
  PORTB = B00000110;
  attachInterrupt(digitalPinToInterrupt(button), buttonpressed, RISING);
}

void loop()
{
 
}
ISR(TIMER1_COMPA_vect) // In every timer intterupt, it executes.
{
  if(millis() >= time_now + period){ //in order to perform once for every period
    time_now += period;
    
    /*if the button is clicked control parameter changes the pattern                     which is going to be implemented*/
    if(control==0){ 
      
      //this if else block controls the leftmost 4 LEDs for the first pattern
      if(counter==0){   //counter paramater is for controlling the pattern movements
        PORTD&=B00111111;
        PORTB=(PORTB&B00000011)|1<<(i+2);
        i++;
          if(PORTB & 1<<5){ //if it reaches the leftmost index of the first pattern
              counter=1;
              i--;
          }
      }
      else{
        PORTD&=B00111111;
        PORTB=(PORTB&B00000011)|1<<(i+2);
        i--;
          if(PORTB & 1<<2){ //if it reaches the rightmost LED of the leftmost 4 LEDs
              counter=0;
              i++;
          }
      }
      //this if else block controls the rightmost 4 LEDs for the first pattern
      if(counter2==0){
        if(j==3){
         PORTB&=B11111100;
         PORTD=(PORTD&B00111111)|B10000000;
         j--;
        }
        else if(j==2){  // if it reaches the rightmost LED of the first pattern
         PORTD=(PORTD&B00111111)|B01000000;
         counter2=1;
        }
        else{
         PORTD&=B00111111;
         PORTB=(PORTB&B11111100)|1<<j;
         j--;
         if(j==-1)j=3;
        }
      }
      else{
        if(j==2){
          PORTD=(PORTD&B00111111)|B01000000;
          j++;
        }
        else if(j==3){
         PORTD=(PORTD&B00111111)|B10000000;                  
         j=0;
        }
        else if(j==1){  // if it reaches leftmost LED of the rightmost 4 LEDs
          PORTB=(PORTB&B11111100)|1<<j;
          counter2=0;
        }
        else{
          PORTD&=B00111111;
          PORTB=(PORTB&B11111100)|1<<j;
         j++;
        }
      }
    }
    
    // this part works if the control button is not 0. Implements the second pattern.
    else{
      if(counter3==0){
        if(k==6){
         PORTB&=B00000000;
         PORTD = (PORTD&B00111111)|B01000000;
         PORTB|=B00100000;
         k++;
        }
        else if(k==7){
         PORTB&=B00000000;
         PORTD = (PORTD&B00111111)|B10000000;
         k=0;
        }
        else if(k==5){  // if it reaches the leftmost LED for the seccond pattern
         PORTD&=B00111111;
         PORTB = B00100000;
         counter3=1;    // in order to go to outer else block
        }
        else{
         PORTD&=B00111111;
         PORTB=(PORTB&B11000000)|1<<k;
          if((k%2)==0){ // if my k values is even leftmost LED should light.
            PORTB|=B00100000;
          }
         k++;
        }
      }
      else{
        if(k==6){   // if it reaches the rightmost LED for the second pattern
         PORTB&=B00000000;
         PORTD = (PORTD&B00111111)|B01000000;
         PORTB|=B00100000;
         counter3=0; // in order to go the outer if block
        }
        else if(k==7){
         PORTB&=B00000000;
         PORTD = (PORTD&B00111111)|B10000000;
         k--;
        }
        else if(k==5){
      	k--;
        }
        else{
         PORTD&=B00111111;
         PORTB=(PORTB&B11000000)|1<<k;
          if((k%2)==0){ // if my k values is even leftmost LED should light.
            PORTB|=B00100000;
          }
         k--;
          if(k==-1)k=7;
      }
     }
    }
  }
}

void buttonpressed(){
  if(control==0){
    control = 1;
  }
  else
    control =0;
}
   
```
