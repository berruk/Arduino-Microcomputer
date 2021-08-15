//Displaying 4-Digit Numbers



```

int a = 6; //getting hex led pins
int b = 5;
int c = 4;
int d = 3;
int e = 2;
int f = 1;
int g = 0;
int values[] = {B00000001, B11001111, B00010010, B00000110, B01001100,
               B00100100,B00100000, B00001111, B00000000, B00000100,
               B00000100};
//storing hex 0 to 9 display in an array

void display(int number){
// displaying the desired number
switch(number)
{

case 0 :
  PORTD = values[0];
break;
  
case 1:
  PORTD = values[1];

break;
  
case 2:
  PORTD = values[2];

break;
case 3:
  PORTD = values[3];

break;
case 4:
   PORTD = values[4];

break;
case 5:
   PORTD = values[5];

break;
case 6:
  PORTD = values[6];

break;
case 7:
   PORTD = values[7];

break;
case 8:
   PORTD = values[8];

break;
case 9:
   PORTD = values[9];  

break;
}
}

void setup()
{
//setting all hex leds as output
pinMode(a, OUTPUT); 
pinMode(b, OUTPUT);
pinMode(c, OUTPUT);
pinMode(d, OUTPUT);
pinMode(e, OUTPUT);
pinMode(f, OUTPUT);
pinMode(g, OUTPUT);
//setting bjt pins as output 
pinMode(8, OUTPUT);  
pinMode(9, OUTPUT);  
pinMode(10, OUTPUT);  
pinMode(11, OUTPUT);  

}
void loop() {
int input = analogRead(A0); //reading input from port
int number = input%10; // getting the last digit
  	PORTB = B1110; //displaying in the left most digit by setting the left most bjt low
    display(number);
input = input/10; // getting the next digit
number = input%10;
    PORTB = B1101; //displaying in the proper digit by setting the proper bjt to low
display(number);
input = input/10; // getting the next digit
number = input%10;
    PORTB = B1011; //displaying in the proper digit by setting the proper bjt to low
	display(number);
input = input/10; // getting the next digit
number = input%10;
    PORTB = B0111; //displaying in the proper digit by setting the proper bjt to low
    display(10);  
	display(number);  
delay(10);
}

```
