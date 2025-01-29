// water sensor
#include <Servo.h> //include servo library

Servo myservo; //define servo as servo

const int waterSens = A0;//set water sensor to A0

int pos = 0;//define servo position


void setup() {
 

  Serial.begin(9600);

  myservo.attach(9);//attach servo to pin 9
 

}
void loop() {

  int sensorValue = analogRead(waterSens);//read the water sensor value
 

  sensorValue = map(sensorValue, 0, 1023, 0, 180); 

     if (sensorValue >= 50) {

        for (pos = 0; pos <= 160; pos++) { // goes from 0 degrees to 180 degrees

    // in steps of 1 degree

    myservo.write(pos);              // tell servo to go to position in variable 'pos'

    delay(1);                       // waits 15ms for the servo to reach the position

  }

  for (pos = 160; pos >= 00; pos--) { // goes from 180 degrees to 0 degrees

    myservo.write(pos);              // tell servo to go to position in variable 'pos'

    delay(1);                       // waits 15ms for the servo to reach the position

  }
 

     }
 

  else{

    myservo.write(0);

  }
}