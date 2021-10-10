#include<Servo.h>
Servo servo;
const int servoPin = 9;
const int trigPin = 10;
const int echoPin = 11;
// defines variables
long duration;
int distance;
int safetyDistance;


void setup() {
servo.attach(servoPin);  
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
 servo.write(110);         //close cap on power on
    delay(100);
    servo.detach(); 
Serial.begin(9600); // Starts the serial communication
}


void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance <= 25){ //Enter the Distance 
  servo.attach(servoPin);
  delay(1);
 servo.write(50);  
 delay(3000);       
 servo.write(0);   
}

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}
