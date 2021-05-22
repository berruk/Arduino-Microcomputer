Countdown timer that counts down in seconds,
minutes, and hours using LCD and timer interrupt 
LCD shows the countdown timer as hh:mm:ss.

![image](https://user-images.githubusercontent.com/73575765/119225778-9d6c7880-bb0e-11eb-902a-5ed1e9693ffc.png)


```
uint8_t line1[] = "COUNTDOWN TIMER:";
int num = 24;
int num2 = 00;
int num3 = 00;
int flag = 0;
int stop = 0;

void waitMicros(int time){
  long start_time=micros();
  while(micros()-start_time < time);
}

void waitMillis(int time){
  long start_time=millis();
  while(millis()-start_time < time);
}

void setup ()
{
    DDRD = B11110000; // output setting
    DDRB = B00001001; 
  
	initLCD(); // starting configuration                            
      
    writeLCD(line1); // writing first line

	// set cursor to start of second line
    internalOP(B11000000);
  	waitMicros(55);
 
}

void loop(){ 
  uint8_t number[] = {num/10+'0',num%10+'0',':',num2/10+'0',num2%10+'0',':',num3/10+'0',num3%10+'0',' ',' ',' ',' ',' ',' ',' ',' '};
  writeLCD(number); // adjusting number array and writing second line
  if(num == 0 && num2 == 0 && num3 == 0){ stop = 1;} // countdown ends
  if(stop == 0){
    if(num2 == 00 && num3 == 00) // adjustment for hour end
    {
        num--;
        num2 = 59;
        num3 = 59;
        flag = 1;
    }
    if(num3 == 00) // adjustment for minute end
    {
        num2--;
        num3 = 59;
        flag = 2;
    }
    if(flag == 0) // decrease
    {
        num3--;
    }
  }
  flag = 0; // release flag
  internalOP(B11000000); // set cursor
  waitMillis(500);
  

}

void initLCD()
{

    PORTD &= B11111011; //rs low for internal operations
    PORTB &= B11111110; //enable low
    waitMillis(10);
  	
  	//reset commands for display
    sendCMD(0b00110000);                 
    waitMillis(10);                                      
    sendCMD(0b00110000);                 
    waitMicros(55);                        
    
  	//function set for 2 display lines
   	sendCMD(0b00101000);               
    waitMicros(55);                            
    
  	internalOP(0b00101000);  
    waitMicros(55);                         

	//display on
    internalOP(0b00001100);  
    waitMicros(55);                    
}

void sendCMD(int cmd)
{
  	//enable low
  	PORTB &= B11111110;
  	//set LCD inputs zero
    PORTD &= B01111111;
    PORTD &= B10111111;  
    PORTD &= B11011111;
    PORTD &= B11101111;

  	if (cmd & B10000000) // controlling if cmd bits are high
    	PORTD |= B10000000;   // if it is making PORTD bit high
  	      
  	if (cmd & B01000000)
    	PORTD |= B01000000;    
  	
    if (cmd & B00100000) 
      	PORTD |= B00100000;

    if (cmd & B00010000) 
      	PORTD |= B00010000;
    
  	//enable high then low to write
    PORTB |= B00000001;                
    PORTB &= B11111110;                 
}

void writeLCD(uint8_t line[])
{
    for (int i=0;i<16;i++)
    {
        PORTD |= B00000100;  //register selector high for r&w data
      
 		//writing 4bits at a time
    	sendCMD(line[i]);	 
   		sendCMD(line[i] << 4); 
    }
}

void internalOP(int cmd)
{
    PORTD &= B11111011;  // register selector low for internal operations
    sendCMD(cmd);                    
    sendCMD(cmd << 4);               
}

```
