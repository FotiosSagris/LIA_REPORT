/* This program controls the robotic car using the IR remote. Each IR button triggers a movement function like forward,backward,left,right
and stop. Also, I have button 1 to increase the speed and button 2 to decrease the speed. The increase and decrease speed is only when 
the car is stopped. This program uses IR signals, hex values for each button and functions.
*/

#include <IRremote.h> // including the IR remote external library

const int IR_RECEIVE_PIN = 9; // Define the pin connected to the IR receiver
int x = 50; // setting the base speed to 50

void setup() {
  pinMode(5, OUTPUT); // PWMA speed motor A
  pinMode(7, OUTPUT); // AIN_1 Direction motor A
  pinMode(3, OUTPUT); // Standby
  pinMode(6, OUTPUT); // PWMB speed motor B
  pinMode(8, OUTPUT); // BIN_1 direction motor B
Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Initialize the receiver
}

void loop() {
  if (IrReceiver.decode()) {
Forward(x);
Backward(x);
Right(x);
Left(x);
Stop();
increaseSpeed();
decreaseSpeed();

 IrReceiver.resume();
  }
        Serial.print("Current speed (bit value): ");
    Serial.println(x);
}

void Forward(int x) {
  if ( IrReceiver.decodedIRData.decodedRawData == 0xB946FF00){
analogWrite(5,x); // Motor A speed = x
digitalWrite(7,1); // Motor A direction forward
analogWrite(6,x);// Motor B speed = x
digitalWrite(8,1);// Motor B direction forward
digitalWrite(3,1); // Enable motor driver (STBY)
  }
}

void Backward ( int x){
  if ( IrReceiver.decodedIRData.decodedRawData == 0xEA15FF00){
analogWrite(5,x); // Motor A speed = x
digitalWrite(7,0); // Motor A direction forward
analogWrite(6,x); // Motor B speed = x
digitalWrite(8,0); // Motor B direction forward
digitalWrite(3,1); // Enable motor driver (STBY)
 }
}
void Left ( int x){
     if ( IrReceiver.decodedIRData.decodedRawData == 0xBB44FF00){
analogWrite(5,x); // Motor A speed = x
digitalWrite(7,1); // Motor A direction backward
analogWrite(6,x); // Motor B speed = x
digitalWrite(8,0); // Motor B direction backward
digitalWrite(3,1); // Enable motor driver (STBY)
}
}
void Right ( int x){
       if ( IrReceiver.decodedIRData.decodedRawData == 0xBC43FF00){
analogWrite(5,x); // Motor A speed = x
digitalWrite(7,0); // Motor A direction backward
analogWrite(6,x); // Motor B speed = x
digitalWrite(8,1); // Motor B direction forward
digitalWrite(3,1); // Enable motor driver (STBY)
}
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
    if ( IrReceiver.decodedIRData.decodedRawData ==0xBF40FF00 ){
analogWrite(5,0); // Motor A speed = 0
digitalWrite(7,1);// Direction doesn't matter when speed = 0
analogWrite(6,0); // Motor B speed = 0
digitalWrite(8,1); // Direction doesn't matter
digitalWrite(3,1);
} // Enable motor driver (STBY)
}

void increaseSpeed() {
  if (IrReceiver.decodedIRData.decodedRawData == 0xE916FF00) {  // Speed+ button
    x += 10;
    if (x > 255){
      x=255;
    }

    }
  }

void decreaseSpeed(){  
  if (IrReceiver.decodedIRData.decodedRawData == 0xE619FF00) {  // Speed+ button
    x -= 10;
    if (x > 255){
      x=255;
    }
  }
}
