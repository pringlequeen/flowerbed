// Defines pins numbers
const int trigPin = 11;
const int echoPin = 10;
const int ledPin = 9; // LED connected to digital pin 9 (PWM capable pin)

// Defines variables
int distance;
long duration;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(ledPin, OUTPUT); // Sets the ledPin as an Output
  digitalWrite(ledPin, HIGH); // Turn LED ON initially
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance = duration * 0.034 / 2;
  
  // Prints the distance on the Serial Monitor
  Serial.println(distance);
  
  // Control LED based on distance
  if (distance < 4) { // If distance is less than 10 cm
    blinkSlow(); // Call blinkFast function
  } else if (distance < 7) { // If distance is between 10 and 20 cm
    blinkModerate(); // Call blinkModerate function
  } else { // If distance is more than 20 cm
    blinkFast(); // Call blinkSlow function
  }
}

void blinkFast() {
  digitalWrite(ledPin, HIGH); // Turn LED ON
  delay(100); // Wait for 100 milliseconds
  digitalWrite(ledPin, LOW); // Turn LED OFF
  delay(100); // Wait for 100 milliseconds
}

void blinkModerate() {
  digitalWrite(ledPin, HIGH); // Turn LED ON
  delay(500); // Wait for 500 milliseconds
  digitalWrite(ledPin, LOW); // Turn LED OFF 
  delay(500); // Wait for 500 milliseconds
}

void blinkSlow() {
  digitalWrite(ledPin, HIGH);
  delay(10000); // Turn LED ON
// Wait for 1000 milliseconds (1 second)
}

