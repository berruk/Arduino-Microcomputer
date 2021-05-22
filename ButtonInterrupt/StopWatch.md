A stopwatch that counts time in centisecond
Click the "Start" button (first button)
Two left most 7-segment displays show the seconds
and the other two should show the centiseconds of the stopwatch. 
Second button works as a lap button. 
When the lap button is clicked, lap number, lap time and the
total time is displayed on the serial monitor. 
The third button is the reset button.
Stopwatch is reset as soon as the reset button is clicked. 

```
const byte button1 = 2;
const byte button2 = 3;

unsigned long number,number2,start=0,centi,current,lap,lap_time,total_time,prev_lap=0;
int period=250;
unsigned long time_now = 0;
int count = 1;


int valuesB[] = {B11111000, B11111100, B11111001, B11111000, B11111100,
               B11111010,B11111010, B11111000, B11111000, B11111000,
                 B11111111};
int valuesD[] = {B00011111, B11111111, B00101111, B01101111, B11001111,
               B01001111,B00001111, B11111111, B00001111, B01001111,
                 B11111111};
//storing hex 0 to f display in an array


void display(int number){
// displaying the desired number
  PORTB=valuesB[number];
  PORTD=valuesD[number];
}

void waitMillis(int time){
  long start_time=millis();
  while(millis()-start_time < time);
}

void setup()
{
  Serial.begin(9600); // output selecting and initializing ports
  DDRC = B11111111;
  PORTC = 0;
  DDRD = B11110000;
  PORTD = 0;
  DDRB = B00000111;
  PORTB = 0;
  //subroutines for buttonpress
   attachInterrupt(digitalPinToInterrupt(button1), button1pressed, RISING);
   attachInterrupt(digitalPinToInterrupt(button2), button2pressed, RISING);
 
}

void loop() {
   // Stopwatch Mode
  centi = start*((millis()-current)/10); // getting the time as centiseconds
  PORTC=B011111;
  display(10); // for error handling
  display((centi/1000)%10); // displaying leftmost first digit
  waitMillis(2);
  PORTC=B101111;
  display(10);
  display((centi/100)%10); // displaying leftmost second digit
  waitMillis(2);
  PORTC=B110111;
  display(10);
  display((centi/10)%10); // displaying leftmost third digit
  waitMillis(2);
  PORTC=B111011;
  display(10);
  display(centi%10); // displaying leftmost fourth digit
  waitMillis(2);
  
  int button3 = digitalRead(13); 
  if(button3==1){ // controlling reset button and resetting time and lap
  	current=millis();
    lap=0;
    prev_lap=0;
    
  }
 
}

void button1pressed() { // start the stopwatch
	start=1;
  	current = millis();
    }
void button2pressed() { // lap the stopwatch
  	lap+=1;
  	lap_time=centi-prev_lap; // calculation for lap
  	Serial.println(lap); // displaying lap time and total time
  	Serial.println(lap_time/100.0);
 	prev_lap+=lap_time; // looking for previous laps
	Serial.println(centi/100.0);
    }


```
