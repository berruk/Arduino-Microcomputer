![image](https://user-images.githubusercontent.com/73575765/119225853-fd631f00-bb0e-11eb-8dbd-0aae2c90416c.png)


```
volatile uint8_t* port;
byte input1, input2;

void setup(){
	DDRD |= B11111111;
	port = &PORTD;
	DDRB &= B11110011;
	PORTB |= B00000100;
}

void loop(){
  input1 = PINB & B00000100;
  input2 = PINB & B00001000;
  if(input1 == B00000100 && input2 == B00000000){
    PORTD++;
  }
  else{
    PORTD--;
  }
  delay(1000);
} // Kadir Özlem advice
```
