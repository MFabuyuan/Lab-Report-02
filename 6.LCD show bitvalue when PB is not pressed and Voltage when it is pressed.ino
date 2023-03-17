/*
LCD show bit value when PB is not pressed and voltage value when it is pressed
The objective of this program is to become familiar with libraries in Arduino using the LiquidCrystal library.
This program uses "Hello World" as a reference to display the bit and voltage value on an LCD screen.
When pushbutton is not pressed (HIGH), the LCD displays the bit value.
When pushbutton is pressed (LOW), the LCD displays the voltage value.
This program also displays these values on the Serial Monitor for troubleshooting purposes.
*/

// include the library code:
#include <LiquidCrystal.h>

//initialize the library by associating any needed LCD interface pin
//with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int pM = A0;        //declare a variable to represent analog pin to which the potentiometer is connected
float x;            //declare a variable to hold voltage value
int pB = 13;        //declare a variable to represent digital pin to which the pushbutton is connected
int buttonState;    //declare a variable to hold butto state value

void setup() {
  lcd.begin(16, 2);             //set up the LCD's number of columns and rows
  pinMode(pB, INPUT_PULLUP);    //initialize pB pin as an INPUT with internal pullup resistor
  Serial.begin(9600);           //initialize Serial Monitor with baud rate of 9600
}

void loop() {
  pM = analogRead(A0);              //read the value of potentiometer
  x = (pM/1023.0)*5.0;              //calculate the voltage value from the potentiometer reading
  buttonState = digitalRead(pB);    //read the pushbutton state

//display the bit value on the LCD screen
  if(buttonState==HIGH){      //if PB is not pressed it displays bit value
  lcd.setCursor(0, 0);        //set the cursor position to column 0, row 0
  lcd.print("bVal=");       //print the label bitVal=
  lcd.print(pM);              //display the bit value
  lcd.print("   ");           //print spaces to clear the voltage value from the previous display
  }
//display the voltage value on the LCD screen
  else {                      //if pB is pressed it displays voltage value
  lcd.setCursor(0, 0);        //set the cursor position to column 0, row 0
  lcd.print("vVal=");      //print the label voltage=
  lcd.print(x);               //display the bit value from the previous display
  lcd.print("   ");           //print spaces to clear the bit value from the previous display
  }

  Serial.print("bVal=");       //print the label bitVal
  Serial.print(pM);              //display the bit value
  Serial.print("\t");            //add a tab space for easier reading

//display voltage and bit value, and the state of the button on the serial monitor
  Serial.print("vVal=");      //print the label voltage=
  Serial.print(x);               //display the voltage value
  Serial.print("\t");            //add a tab space for easier reading

  Serial.print("pB=");           //print the labe pB=
  Serial.println(buttonState);   //display the state of the button

}
