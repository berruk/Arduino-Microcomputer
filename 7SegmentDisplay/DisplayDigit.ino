//Display the last digit of the analog input value on a 7-Segment Display

![image](https://user-images.githubusercontent.com/73575765/119224153-bfadc880-bb05-11eb-9ad8-e8859271ad90.png)

```
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
//setting bjt pin as output and using it as low
pinMode(8, OUTPUT);  
}
void loop() {
int input = analogRead(A0); //reading input from port
int number = input%10; // getting the last digit
  display(number); //displaying
}
```
