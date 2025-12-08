/* This program uses functions (Forward, Backward, Stop,etc) to control the movement of our robotic car around a table using
Motor A and Motor B on the car. Each movement function sets the motor speed and direction.
*/

  void setup() {
  pinMode(5,OUTPUT); // PWMA speed motor A
  pinMode(7,OUTPUT); // AIN_1 Direction motor A
  pinMode(3,OUTPUT); // Standy
  pinMode(6,OUTPUT); //  PWMB speed motor B
  pinMode(8,OUTPUT); // BIN_1 direction motor B
  }

  void loop() {
Forward(80); // go forward at 80 speed
delay(12000);// stay at that speed for 12 seconds
Right(70); // turn right at 70 speed
delay(800); // turn for 0.8 seconds
Forward(80); // go forward at 80 speed
delay(5000); // stay forward for 5 seconds
Right(70); // turn right at 70 speed
delay(900);// turn for 0.9 seconds
Forward(80);// go forward at 80 speed
delay(12000); // move forward for 12 seconds
Right(70);// turn right at 70 speed
delay(900);// turn for 0.9 seconds
Forward(80); // go forward at 80 speed
delay(5000); // stay forward for 5 seconds
Stop(); // stop the car
delay(5000);// stop the car for 5 seconds
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
digitalWrite(3,1);} // Enable motor driver (STBY)
