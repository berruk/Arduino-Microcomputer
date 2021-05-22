Display various colors with LED by switching RGB channels

![image](https://user-images.githubusercontent.com/73575765/119223993-06e78980-bb05-11eb-934f-8c3f8cced043.png)
![image](https://user-images.githubusercontent.com/73575765/119224031-35656480-bb05-11eb-9e50-9dba29f30fc4.png)

``` 
void setup() {
  Serial.begin(9600);
}
void loop() {
  int ledb = 5; //pins for the leds
  int ledr = 6;
  int ledg = 4;
  int red = analogRead(A0); //reading inputs from portA
  int blue = analogRead(A1);
  int green = analogRead(A3);
  int red_converted,blue_converted,green_converted; //converting input to 0,255 range
  red_converted = map(red, 0, 1023, 0, 255);
  blue_converted = map(blue, 0, 1023, 0, 255);
  green_converted = map(green, 0, 1023, 0, 255);

  analogWrite(ledr, red_converted); //writing each input to output led
  analogWrite(ledg, green_converted);
  analogWrite(ledb, blue_converted);


  delay(1);        
}

```
