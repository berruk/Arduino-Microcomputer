![image](https://user-images.githubusercontent.com/73575765/119225979-9db94380-bb0f-11eb-9239-54042a92e587.png)


```
const byte button2 = 3;
const byte button1 = 2;

volatile byte state = LOW;

int valuesB[] = {B11111000, B11111100, B11111001, B11111000, B11111100,
               B11111010,B11111010, B11111000, B11111000, B11111000,B11111111};
int valuesD[] = {B00011111, B11111111, B00101111, B01101111, B11001111,
                 B01001111,B00001111, B11111111, B00001111, B01001111,B11111111};
//storing hex 0 to 9 display in an array

int period = 400; // period variable
unsigned long time_now = 0;
int player1 = 1; // initial values for players
int player2 = 1;
int counter1= 1; // inital value for mod controls
int counter2= 0;
int winner=0;

void display(int number){
// displaying the desired number
  PORTB = valuesB[number];
  PORTD = valuesD[number];
}

void setup()
{
  DDRC = B11111111; // DDRC 1 FOR OUTPUT BITS
  PORTC = 0; // initializing zero
  DDRD = B11110000; // DDRD 1 FOR OUTPUT BITS 0 FOR INPUT
  PORTD = 0; // initializing zero
  DDRB = B00000111; // DDRB 1 FOR OUTPUT BITS 0 FOR INPUT
  PORTB = 0; // initializing zero
}

//subroutines for button presses.
void loop() {
  attachInterrupt(digitalPinToInterrupt(button1), button1pressed, RISING);
  attachInterrupt(digitalPinToInterrupt(button2), button2pressed, RISING);
    
  if(winner==1){
  	PORTC=B000000;
  	display(winner);
  }
  else if(winner==2){
  	PORTC=B000011;
  	display(winner);
  }
  else{
      if(millis() >= time_now + period){ // millis for 1 second delay
      time_now += period;
      player1+=counter1;
      player2+=counter2;
        if(player1==21){ // checking the number limits
          player1=1;
        }
        else if(player2==21){
          player2=1;
        }
      }
      // displaying the current values. 
      PORTC=B011111;
      display(player1/10); // player 1 first digit
      delay(5); // we could not implement the alternative for this
    
      PORTC=B101111;
      display(player1%10); // player 1 second digit
      delay(5); // we could not implement the alternative for this
      
      PORTC=B110111;
      display(player2/10); // player 2 first digit
      delay(5); // we could not implement the alternative for this
    
      PORTC=B111011;
      display(player2%10); // player 2 second digit
      delay(5);  // we could not implement the alternative for this    
  }
}
//button1 subroutine
void button1pressed() {
  	counter1=0; // changing mode to player2
  	counter2=1;
    if(player1==player2){ // player 1 wins
        winner=1;
    }
}
//button2 subroutine
void button2pressed() {
	counter1=1; // changing mode to player1
  	counter2=0;
  	if(player1==player2){ // player 2 wins
        winner=2;
    }
}

```
