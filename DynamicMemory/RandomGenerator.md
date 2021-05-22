```

const byte button = 3; // pin for button subroutine
int count = 2; // array index 
int prev1,prev2,newnum; 
int m=0,range=8;
int* arr = new int[m];
void setup()  
{
  Serial.begin(9600);
  Serial.println("Enter a number");

  DDRB = B00011111; // output pins for hex
  DDRD = B11111111;
  attachInterrupt(digitalPinToInterrupt(button), buttonpress, RISING);
	//subroutine attach for button press
}

void loop()
{	
	//empty
}


void buttonpress() 
{	
  // reads input from serial command line
  if(Serial.available()>0){
  	int input = Serial.read()-'0';
    m = m*10 + input;
  }
  int count_arr[range]; // array for how many counts in arr
  arr[0] = 1; //initializing first two index for arr
  arr[1] = 1;
  for(int j = 0; j < range; j++)
  {
  		// filling count array with 0
  		count_arr[j] = 0;	
  }
  for(int i = 2; i < m; i++){
      int a = random()%i;
      int b = random()%i;
   	  prev1 = arr[a]; //choose random 2 previous numbers
      prev2 = arr[b];
      newnum = (prev1 + prev2) % 8; // additive lagged fibonacci with range m
      arr[i] = newnum; // add new generated random number to array
	Serial.println(newnum);
    count_arr[newnum]++;    
  }

 
  for(int j = 0; j < range; j++)
  {
    if(count_arr[j]!= 0){
      	Serial.print("Arr has "+String(j)+" element, counts of ");
  		Serial.println(count_arr[j]);
    }
    }
}
```
