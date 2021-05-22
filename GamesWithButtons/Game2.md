![image](https://user-images.githubusercontent.com/73575765/119225967-85492900-bb0f-11eb-8553-359abd3715b3.png)


```
const byte button = 2;
int target[3] = {0xA,0x4,0x5};  //target
volatile byte state = LOW;
int period=400;
unsigned long time_now = 0;
int player1 = 0;
int count = 1;
int pressed = 0;
int number1 = 0, number2 = 0, number3 = 0;

int valuesB[] = {B11111000, B11111100, B11111001, B11111000, B11111100,
               B11111010,B11111010, B11111000, B11111000, B11111000,
                 B11111000, B11111110, B11111011, B11111100, B11111011,
                 B11111011, B11111111};
int valuesD[] = {B00011111, B11111111, B00101111, B01101111, B11001111,
               B01001111,B00001111, B11111111, B00001111, B01001111,
                 B10001111, B00001111, B00011111, B00101111 ,B00001111,
                 B10001111, B11111111};
//storing hex 0 to f display in an array


void display(int number){
// displaying the desired number
  PORTB=valuesB[number];
  PORTD=valuesD[number];
}

void setup()
{
  DDRC = B11111111;
  PORTC = 0;
  DDRD = B11110000;
  PORTD = 0;
  DDRB = B00000111;
  PORTB = 0;
 
}

void loop() {
//subroutine for interrupt
   attachInterrupt(digitalPinToInterrupt(button), buttonpressed, RISING);
//delay
      if(millis() >= time_now + period){
      time_now += period;
      player1+=count;
        if(player1==16){
          player1=1;
        }
      }
//counter      
      PORTC=B011111;
      display(player1%16);
      delay(5);  // we could not implement the alternative for this
//displaying the 3 chosen digits   
      PORTC=B101111;
      display(number1);
      delay(5);  // we could not implement the alternative for this
   
      PORTC=B110111;
      display(number2);
      delay(5);  // we could not implement the alternative for this
      
      PORTC=B111011;
      display(number3);
      delay(5);  // we could not implement the alternative for this
  
 
}
void buttonpressed() {
//sliding the numbers
  	number3 = number2;
  	number2 = number1;
    number1 = player1%16; // the chosen number
//checking if there is a win
  	if(target[0] == number1 &&
       target[1] == number2 &&
       target[2] == number3){
   	count = 0;
    }
  	

}

```
