/* LCD with Arduino to work as ohmmeter with display of the ohm symbol
The objective of this program is to calculate the resistance of an unknown resistor(Rb) 
and display the result on the LCD screen.
This program uses LCD custom character to display the ohm symbol on the LCD screen.
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte customChar [] = {
  B00000,
  B00000,
  B00000,
  B00100,
  B01010,
  B11011,
  B00000,
};

void setup() {
  lcd.begin(16, 2);                  //set up the LCD's number of columns and rows
  lcd.createChar(0, customChar);     //create a custom character to display the ohm symbol
  analogRead(A0);                    //initialze the analog input A0
  Serial.begin(9600);                //initialize Serial Monitor with baud rate of 9600
}

void loop() {
  float val = analogRead(A0);      //read the analog value from A0  
  float x = (val/1023.0)*5.0;      //calculates the corresponding voltage value from the analog reading   
  float Ia = (5.0-x/1.0);          //formula to find the current flowing through the resistor (Ra)
  float Ib = Ia;                   //assign the value of Ia to Ib
  float Vb = x;                    //assign the value of Vb to x
  float Rb = (Vb/Ib);              //formula to find the value of the unknown resistor(Rb)

  delay(1000);               //wait for a second
  lcd.setCursor(0,0);        //set the cursor posistion to column 0, row 0
  lcd.print("Rb=");          //print the labe Rb on the LCD screen
  lcd.print(Rb);             //display the Rb value
  lcd.print("k");            //print the label k to indicate kilo ohms on the LCD screen
  lcd.write((byte)0);        //display ohm symbol on the LCD screen

//display the bit voltage current(Ia) and unknown resistor value(Rb) on the Serial monitor
  Serial.print("bVal=");    //print the label bVal=
  Serial.print(val);        //print the bit value
  Serial.print("\t");       //add a tab space for easier reading
  Serial.print("vVal=");    //print the label vVal=
  Serial.print(x);          //print the voltage value
  Serial.print("\t");       //add a tab space for easier reading
  Serial.print("Ia=");      //print the labe Ia=
  Serial.print(Ia);         //display the current value
  Serial.print("\t");       //add a tab space for easier reading
  Serial.print("Rb=");      //print the label Rb=
  Serial.println(Rb);       //display the resistor value(Rb) 
}
