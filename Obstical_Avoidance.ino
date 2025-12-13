#include <Servo.h> // include the servo external library
Servo myServo ; // create servo object
// definining the ultrasonic trigger pin to pin 13 and ultrasonic echo pin to pin 12
#define trigPin 13 
#define echoPin 12 

float distance; // variable to store distance
long duration; // variable to store duratio

  void setup() {
  pinMode(5,OUTPUT); // PWMA speed motor A
  pinMode(7,OUTPUT); // AIN_1 Direction motor A
  pinMode(3,OUTPUT); // Standy
  pinMode(6,OUTPUT); //  PWMB speed motor B
  pinMode(8,OUTPUT); // BIN_1 direction motor B
  pinMode(echoPin, INPUT); // setting echopin as an input
  pinMode(trigPin, OUTPUT); // setting trigger pin as an output
  Serial.begin(9600);
  myServo.attach(10); // attaching the servo motor to pin 10
  }


void loop() {
    float distance = GetDistance(); // mesure distance in fron

    if (distance > 35) { // if front is clear
Forward(75);       // Move forward at speed 75
ServoStraight();   // Keep servo straight
    }
    else { // Front blocked
Stop(); //stop the car
ServoLeft();       // Check left side

delay(500);        // Small delay to stabilize sensor
float leftDistance = GetDistance(); // measure left

        if (leftDistance > 35) { // if left clear
            ServoStraight(); // turn servo straight
            Left(75); // move left
        }
        else { // Left blocked
            ServoRight();   // Check right side
            delay(500);
            float rightDistance = GetDistance(); // measure right

            if (rightDistance > 35) { // if right clear
                ServoStraight(); // move servo straight
                Right(75); // move diagonally right forward
            }
            else { // All blocked
                ServoStraight(); // move sero straight
                Backward(75);    // Move backward
                delay(500);
                Left(100); // Rotate 180° in place
                delay(1100);     // Adjust timing to rotate 180°
                Stop(); //stop the car
            }
        }
    }

    delay(1000); // small delay before next loop
}
void ServoLeft(){
  myServo.write(180); // rotate servo left means rotate it to 180 degrees
}

void ServoRight(){
  myServo.write(0); //rotate servo right means rotate it to 0 degrees
}

void ServoStraight(){
  myServo.write(90); // rotate servo straight means rotate it to 90 degrees
}

float GetDistance(){
  digitalWrite(trigPin,LOW); //make sure trigger is low
delayMicroseconds(2);

digitalWrite(trigPin, HIGH); // send ultrasonic pulse
delayMicroseconds(10);

digitalWrite(trigPin, LOW);

duration = pulseIn (echoPin, HIGH); //read echo pulse
return (duration *0.0343) / 2; // return the calculation to get the distance in cm
}



void Forward ( int x) {
analogWrite(5,x); // Motor A speed = x
digitalWrite(7,1); // Motor A direction forward
analogWrite(6,x);// Motor B speed = x
digitalWrite(8,1);// Motor B direction forward
digitalWrite(3,1); // Enable motor driver (STBY)
 }

void Backward ( int x){
analogWrite(5,x); // Motor A speed = x
digitalWrite(7,0); // Motor A direction forward
analogWrite(6,x); // Motor B speed = x
digitalWrite(8,0); // Motor B direction forward
digitalWrite(3,1); // Enable motor driver (STBY)
}

void Left ( int x){
analogWrite(5,x); // Motor A speed = x
digitalWrite(7,1); // Motor A direction backward
analogWrite(6,x); // Motor B speed = x
digitalWrite(8,0); // Motor B direction backward
digitalWrite(3,1); // Enable motor driver (STBY)
}

void Right ( int x){
analogWrite(5,x); // Motor A speed = x
digitalWrite(7,0); // Motor A direction backward
analogWrite(6,x); // Motor B speed = x
digitalWrite(8,1); // Motor B direction forward
digitalWrite(3,1); // Enable motor driver (STBY)
}

void LeftForward ( float x){
  float y = x * 0.5; // setting the variable Y to half the value of X
analogWrite(5,x);// Motor A speed = x
digitalWrite(7,1);// Motor A direction forward
analogWrite(6,y); // Motor B speed = y
digitalWrite(8,1);// Motor B direction forward
digitalWrite(3,1); // Enable motor driver (STBY)
}

void LeftBackward ( float x){
  float y = x * 0.5;
analogWrite(5,x); // Motor A speed = x
digitalWrite(7,0); // Motor A direction backward
analogWrite(6,y); // Motor B speed = y
digitalWrite(8,0);// Motor B direction backward
digitalWrite(3,1); // Enable motor driver (STBY)
}

void RightForward ( float x){
  float y = x * 0.5;
analogWrite(5,y); // Motor A speed = y
digitalWrite(7,1); // Motor A direction forward
analogWrite(6,x); // Motor B speed = x
digitalWrite(8,1); // Motor B direction forward
digitalWrite(3,1); // Enable motor driver (STBY)
}

void RightBackward ( float x){
  float y = x * 0.5;
analogWrite(5,y); // Motor A speed = y
digitalWrite(7,0); // Motor A direction backward
analogWrite(6,x); // Motor B speed = x
digitalWrite(8,0); // Motor B direction backward
digitalWrite(3,1);// Enable motor driver (STBY)
}

void Stop (){
analogWrite(5,0); // Motor A speed = 0
digitalWrite(7,1);// Direction doesn't matter when speed = 0
analogWrite(6,0); // Motor B speed = 0
digitalWrite(8,1); // Direction doesn't matter
digitalWrite(3,1);// Enable motor driver (STBY)
} 
