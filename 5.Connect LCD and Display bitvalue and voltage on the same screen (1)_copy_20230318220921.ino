/* Connect LCD and display bitvalue and voltage value on the same screen
Connect LCD and Display bitvalue and voltage on the same screen
The objective of this program is to become familiar with libraries in Arduino using the LiquidCrystal library.
This program displays the bit and voltage value on the same screen on LCD scree and
these values are also displays on the Serial Monitor for troubleshooting purposes.
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

float pM = A0;    //potentiometer connected to analog pin A0
float x;          //declare a variable to hold voltage value

void setup() {
  lcd.begin(16, 2);       //set up the LCD's number of columns and rows
  Serial.begin(9600);     //initialize Serial Monitor with baud rate of 9600
}

void loop() {
  pM = analogRead(A0);     //reads the analog value of potentiometer
  x = (pM/1023.0)*5.0;     //calculates the corresponding voltage value from the potentiometer reading

//display the bit value on the LCD screen
  lcd.setCursor(0, 0);       //set the cursor posistion to column 0, row 0
  lcd.print("bVal=");        //print the label bVal=
  lcd.print(pM);             //display the bit value

//display the voltage value on the LCD screen 
  lcd.setCursor(0, 1);       //set the cursor posistion to column 0, row 1
  lcd.print("vVal=");        //print the label vVal=
  lcd.print(x);              //display the voltage value

//display voltage and bit value on the serial monitor
  Serial.print("bVal=");     //print the label bVal=
  Serial.print(pM);          //display the bit value
  Serial.print("\t");        //add a tab space for easier reading
  Serial.print("vVal=");     //print the label vVal=
  Serial.println(x);         //display the voltage value
}
