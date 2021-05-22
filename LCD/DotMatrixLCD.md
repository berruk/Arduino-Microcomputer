16x2 dot mat-rix LCD implementation
A print function which uses char characters as inputs 
and shows them on the LCD display

![image](https://user-images.githubusercontent.com/73575765/119225733-3ea6ff00-bb0e-11eb-9e0d-5ab4836dcf0d.png)


```
char line1[]   = "berru ilya alper";
char line2[]  = "karak nuhi yilma";

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
  
	initLCD();  // starting configuration                               
      
    writeLCD(line1); // writing first line

	// set cursor to start of second line
    internalOP(B11000000);
  	waitMicros(55);
 
    writeLCD(line2); // writing second line
}

void loop(){ }

void initLCD()
{

    PORTD &= B11111011; //rs low for internal operations
    PORTB &= B11111110; //enable low
    
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

void writeLCD(char line[])
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
