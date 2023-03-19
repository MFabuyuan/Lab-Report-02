/* PB value displayed on serial monitor and blink (without using Delay) 
This program enables one LED(led1) to blink continuously without using the delay function, which allows other parts of the code to run without being interrupted.
It also enables the builtin pullup resistor on the pushbutton pin by setting it as an INPUT_PULLUP.
The other LED(led2) stays on unless the pushbutton is pressed, and the program also displays the state of the button on the serial monitor. 
When the pushbutton is not pressed, it displays pB=1 (HIGH) to the serial monitor, and when the pushbutton is pressed, it display pB=0 (LOW).
*/

//define the pins for the leds and pushbutton
const int led1 = 10;      //led1 pin is connected to pin 10
const int led2 = 11;      //led2 pin is connected to pin 11
const int pB = 12;        //pushbutton pin is connected to pin 12
int buttonState;          //declare a variable to hold button state value
int ledState = LOW;       //set led state to off

unsigned long previousMillis = 0;  //time since last LED blink
const long interval = 1000;        //interval at which to blink in milliseconds

void setup() {
  pinMode(led1, OUTPUT);        //initialize led1 as an OUTPUT
  pinMode(led2, OUTPUT);        //initialize led2 as an OUTPUT
  pinMode(pB, INPUT_PULLUP);    //initialize pB pin as an INPUT with internal pullup resistor
  Serial.begin(9600);           //initialize Serial monitor with baud rate of 9600
}

void loop() {   

  unsigned long currentMillis = millis();     //get current time

//blink LED if specified interval has passed
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

//toggle led state
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    digitalWrite(led1, ledState);    //set the LED with the ledState of the variable
  }

  buttonState = digitalRead(pB);     //read the pushbutton state and store results in the buttonState variable

if (buttonState == HIGH) {           //if pushbutton is not pressed (HIGH)   
    digitalWrite(led2, HIGH);        //turn led2 ON
  } else {                           //if pushbutton is pressed (LOW)
    digitalWrite(led2, LOW);         //turn led2 OFF
  }

//display pushbutton's state on the Serial Monitor
Serial.print("pB=");             //print the labe pB=
Serial.print("\t");              //add a tab space for easier reading
Serial.println(buttonState);     //display pushbutton's state 
}
