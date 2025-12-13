#include <Servo.h>
Servo myServo ;

#define trigPin 13 
#define echoPin 12 

float distance;
long duration;

  void setup() {
  pinMode(5,OUTPUT); // PWMA speed motor A
  pinMode(7,OUTPUT); // AIN_1 Direction motor A
  pinMode(3,OUTPUT); // Standy
  pinMode(6,OUTPUT); //  PWMB speed motor B
  pinMode(8,OUTPUT); // BIN_1 direction motor B
  pinMode(echoPin, INPUT); 
  pinMode(trigPin, OUTPUT);
  Serial.begin(9600);
  myServo.attach(10);
  }


void loop() {
    float distance = GetDistance(); // front sensor

    if (distance > 35) {
Forward(75);       // Move forward at speed 50
ServoStraight();   // Keep servo straight
    }
    else { // Front blocked
Stop();
ServoLeft();       // Check left side

delay(500);        // Small delay to stabilize sensor
float leftDistance = GetDistance(); // measure left

        if (leftDistance > 35) {
            ServoStraight();
            Left(75); // move diagonally left forward
        }
        else { // Left blocked
            ServoRight();   // Check right side
            delay(500);
            float rightDistance = GetDistance(); // measure right

            if (rightDistance > 35) {
                ServoStraight();
                Right(75); // move diagonally right forward
            }
            else { // All blocked
                ServoStraight();
                Backward(75);    // Move backward
                delay(500);
                // Rotate 180° in place
                Left(100);
                delay(1100);     // Adjust timing to rotate 180°
                Stop();
            }
        }
    }

    delay(1000); // small delay before next loop
}
void ServoLeft(){
  myServo.write(180);
}

void ServoRight(){
  myServo.write(0);
}

void ServoStraight(){
  myServo.write(90);
}

float GetDistance(){
  digitalWrite(trigPin,LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);

digitalWrite(trigPin, LOW);

duration = pulseIn (echoPin, HIGH);
return (duration *0.0343) / 2;
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
