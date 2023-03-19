/* Connect potentioemete and display bit value and voltage on serial monitor
The objective of this program is to connect a potentiometer to an Arduino board
and display the voltage and bit values on the Serial Monitor using analogRead() function.
The program reads the voltage and bit values from analog pin A0, which the potentiometer is connected to.
*/

//declare a variable to represent analog pin to which the potentiometer is connected
 float pM = A0;    

//declare a variable to hold voltage value
 float x;

void setup() {
  pinMode(pM, INPUT);     //initialize potentiometer as an INPUT
  Serial.begin(9600);     //initialize Serial Monitor with baud rate of 9600
}

void loop() {
 pM = analogRead(A0);     //reads the analog value of potentiometer
 x = (pM/1023.0)*5.0;     //calculates the corresponding voltage value from the potentiometer reading
 
//display bit value on the the Serial Monitor
 Serial.print("bVal=");    //print the label bitVal=
 Serial.print(pM);         //display the bit value
 Serial.print("\t");       //add a tab space for easier reading

//display voltage value on the Serial Monitor
 Serial.print("vVal=");    //print the label voltage=
 Serial.print("\t");       //add a tab space for easier reading
 Serial.println(x);        //display the voltage value

 delay(100);    //wait for a short time
}
