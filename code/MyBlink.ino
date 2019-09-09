/*
  My Blink

  Turns the built-in LED on for 100ms, then off for 2000ms (2 seconds), repeatedly
  
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize serial monitor to log messages
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  Serial.write("On"); // print when LED is lit
  delay(100);                       // wait for 100ms
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  Serial.write("Off"); // print when LED is not lit
  delay(2000);                       // wait for 2 seconds
}
