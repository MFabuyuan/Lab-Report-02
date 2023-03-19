/* Potentiometer change RGB from black to white through different color variations
This program reads the analog value of  a potentiometer connected to analog pin and converts it to a voltage value. 
This program uses the analogWrite() function to control the RGB Led's brightness,
and its colors varies depending on the potentiometer's value, ranging from white to black using different color variations.
*/

//define the pins for RGB Led and the potentiometer
int rLed = 12;     //red led connected to pin 12
int gLed = 11;     //green led connected to pin 11
int bLed = 10;     //blue led  connected to pin 10
float pM = A0;     //potentiometer connected to analog pin A0
float x;           //declare a varaible to hold to the voltage value

void setup() {
  pinMode(pM, INPUT);     //initialize potentiometer as an INPUT
  pinMode(rLed, 12);      //initialize rLed as an OUTPUT
  pinMode(gLed, 11);      //initialize gLed as an OUTPUT
  pinMode(bLed, 10);      //initialize bLed as an OUTPUT
  Serial.begin(9600);     //initialize Serial Monitor with baud rate of 9600
}

void loop() {
  pM = analogRead(A0);    //reads the analog value of potentiometer
  x = (pM/1023.0)*5.0;    //calculates the corresponding voltage value from the potentiometer reading

//initialize the color of the RGB led based on the analog value of the potentiometer
  if(pM<50 && pM>=0){          //RGB led color is black
    analogWrite(rLed, 0);     
    analogWrite(gLed, 0);     
    analogWrite(bLed, 0);
  }
  if(pM<=400 && pM>=51){       //RGB led color is yellow-green
    analogWrite(rLed, 222);
    analogWrite(gLed, 235);
    analogWrite(bLed, 52);
  }
  if(pM<=850 && pM>=401){      //RGB led color is pink-purple
    analogWrite(rLed, 235);
    analogWrite(gLed, 52);
    analogWrite(bLed, 235);
  }
  if(pM<=1023 && pM>=851) {     //RGB led color is white
    analogWrite(rLed, 255);
    analogWrite(gLed, 255);
    analogWrite(bLed, 255);
}
//display bit and voltage value on the serial monitor
  Serial.print("bVal=");     //print the bVal=
  Serial.print(pM);          //display the bit value
  Serial.print("\t");        //add a tab space for easier reading
  Serial.print("vVal=");     //print vVal=
  Serial.println(x);         //display the voltage value
}
