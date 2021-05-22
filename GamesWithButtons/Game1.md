![image](https://user-images.githubusercontent.com/73575765/119225945-5f238900-bb0f-11eb-97aa-6abfae2aa37f.png)

```
//Part #1
const byte button2 = 2;
const byte button1 = 3;
int period = 150; // period for millis
unsigned long time_now = 0;

volatile byte state = LOW;
int number = 0;
int control = 1;
void setup() {
  DDRB = B11111111; // setting DDRB output bits   
  PORTB = 0; // initializing zero
  DDRD = B00000000; // setting DDRD input bits
  DDRC = B11111111; // setting DDRC output bits
  PORTC = 0; // initializing zero
}

void loop() {
  if(millis() >= time_now + period){ // instead of delay
    time_now += period;
    //interrupt routines for button press
    attachInterrupt(digitalPinToInterrupt(button1), button1pressed, RISING);
    attachInterrupt(digitalPinToInterrupt(button2), button2pressed, RISING);
    //checking the mode and whether it has reached the limit
    if(number==99 && control == 1){
      number = 0; // resetting zero for up mode
      PORTB = number % 10;
      PORTC = number / 10;
    }
    else if(number==0 && control == 0){
      number = 99; // resetting to 99 for down mode
      PORTB = number % 10;
      PORTC = number / 10;
    }
    else if(control)// controlling if it is in up mode or down mode
    {
      number++;
      PORTB = number % 10;
      PORTC = number / 10;
    }
    else
    {
      number--;
      PORTB = number % 10;
      PORTC = number / 10;
    }
  }
}
//subroutines for buttons
void button1pressed() {
  	PORTB = 0; //resetting PORTB
  	number = 0;  //resetting number
  	PORTC = 0; 	//resetting PORTC
}
void button2pressed() {
  if(control) //changing the mode
  {
    control = 0;
  }
  else{
  	control = 1;
  }
}

```
