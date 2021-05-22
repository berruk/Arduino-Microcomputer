![image](https://user-images.githubusercontent.com/73575765/119225891-1ff53800-bb0f-11eb-8c49-a4fabb680ad5.png)


```

volatile uint8_t* port;
byte input1, input2; 

void setup(){
	DDRD |= B11111111;
	port = &PORTD;
	DDRB &= B11111100;
	PORTB |= B00000011;
	PORTD = B00000001;
    input1 = PINB & B00000001;
  	input2 = PINB & B00000010;
}

void loop(){
 
  if(input1 == B00000001 && input2 == B00000010) // LL
  {
    	PORTD = B00000001;
  		for(int i=0; i<14 ; i++){
          input1 = PINB & B00000001;
  		  input2 = PINB & B00000010;
          if(!(input1 == B00000001 && input2 == B00000010))
          {
          	break;
          }
          else if(i>=7)
          {
            delay(1000);
            PORTD = PORTD >> 1;
          }
          else
          {
            delay(1000);
            PORTD = PORTD << 1;
          }
  		}
  }
  else if(input1 == B00000000 && input2 == B00000010) // LH
  {
  		PORTD = B10000000;
   		for(int i=0; i < 8; i++)
    	{
          input1 = PINB & B00000001;
  		  input2 = PINB & B00000010;
          if(!(input1 == B00000000 && input2 == B00000010))
          {
          	break;
          }
          else
          {
    		delay(1000);
            PORTD = PORTD >> 1;
          }
    	} 
  }
  else if(input1 == B00000001 && input2 == B00000000) // HL
  {
    	PORTD = B10000000;
   		for(int i=1; i < 9; i++)
    	{
          input1 = PINB & B00000001;
  		  input2 = PINB & B00000010;
          if(!(input1 == B00000001 && input2 == B00000000))
          {
          	break;
          }
          else
          {
            if(i>4)
            {
            	delay(1000);
            	PORTD = (PORTD << (2*(i-4))) % 255;
            }
            else
            {
    			delay(1000);
            	PORTD = (PORTD << (2*i)) % 255;
            }
          }
    	} 
  }
  else if(input1 == B00000000 && input2 == B00000000) // HH
  {
  		 PORTD = B00000001;
    	 for(int i=0; i<7 ; i++){
          input1 = PINB & B00000001;
  		  input2 = PINB & B00000010;
          if(!(input1 == B00000000 && input2 == B00000000))
          {
          	break;
          }
          else if(i>=3)
          {
            delay(1000);
            PORTD = PORTD >> 1;
          }
          else
          {
            delay(1000);
            PORTD = PORTD << 1;
          }
         }  
         PORTD = B10000000;
         for(int i=0; i<7 ; i++){
          input1 = PINB & B00000001;
  		  input2 = PINB & B00000010;
          if(!(input1 == B00000000 && input2 == B00000000))
          {
          	break;
          }
          else if(i>=3)
          {
            delay(1000);
            PORTD = PORTD << 1;
          }
          else
          {
            delay(1000);
            PORTD = PORTD >> 1;
          }
  		}
  }
}
```
