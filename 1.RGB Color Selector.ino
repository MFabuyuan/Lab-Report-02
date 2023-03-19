/* RGB Color Selector
This program enables the selection of a specific color for an RGB LED.
It makes use of analogWrite() function to generate signals in the range of 0(minimum) to 255(maximum) and turn on the desired color.
The RGB LED can be modified to a different colour by using the setColor function to set a specific signal range for each pin.
*/

//define the pins for RGB LED
 int rPin = 10;    //rPin is connected to pin 10        
 int gPin = 11;    //gPin is connected to pin 11   
 int bPin = 12;    //bPin is connected to pin 12    

void setup() {
  for (int i=0 ; i<12 ; i++) {    //loop through each pin and set as OUTPUT
  pinMode(i, OUTPUT);             //set the current digital pin as an OUTPUT
  }
}

void loop() {                  
  setColor(255, 255, 255);      //set RGB LED to white color  

  // setColor(154, 205, 50);    Yellow-green
  // setColor(0, 128, 128);     Teal
  // setColor(128, 0, 128);     Purple
      
}

void setColor(int rVal, int gVal, int bVal) {   
  analogWrite(rPin, rVal);     //initialize the red LED value using PWM       
  analogWrite(gPin, gVal);     //initialize the green LED value using PWM   
  analogWrite(bPin, bVal);     //initialize the blue LED value using PWM   
}
