const int ledPin = 13;

const int relay1Pin = 16;
const int relay2Pin = 14;
const int relay3Pin = 12;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledPin, OUTPUT);
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  pinMode(relay3Pin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(relay1Pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(relay2Pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(relay3Pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(relay1Pin, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(relay2Pin, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(relay3Pin, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
