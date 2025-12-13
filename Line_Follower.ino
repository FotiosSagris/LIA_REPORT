void setup() {
  pinMode(5, OUTPUT); // PWMA speed motor A
  pinMode(7, OUTPUT); // AIN_1 Direction motor A
  pinMode(3, OUTPUT); // Standby
  pinMode(6, OUTPUT); // PWMB speed motor B
  pinMode(8, OUTPUT); // BIN_1 direction motor B

  pinMode(A0, INPUT); // Right sensor
  pinMode(A1, INPUT); // Middle sensor
  pinMode(A2, INPUT); // Left sensor

  Serial.begin(9600);
}

void loop() {
  LineFollower();  // continuously follow the line
}

void Forward ( int x) {
analogWrite(5,x); // Motor A speed = x
digitalWrite(7,1); // Motor A direction forward
analogWrite(6,x);// Motor B speed = x
digitalWrite(8,1);// Motor B direction forward
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
void Stop (){
analogWrite(5,0); // Motor A speed = 0
digitalWrite(7,1);// Direction doesn't matter when speed = 0
analogWrite(6,0); // Motor B speed = 0
digitalWrite(8,1); // Direction doesn't matter
digitalWrite(3,1);} // Enable motor driver (STBY)



void LineFollower() {
  float M = analogRead(A1);
  float L = analogRead(A2);
  float R = analogRead(A0);

  if (M > 500 && M < 850) {
    Forward(75);
  }
  else if (L > 500 && L < 850) {
    Left(75);
  }
  else if (R > 500 && R < 850) {
    Right(75);
  }
  else if (R < 400 && L < 400 && M < 400) {
    Left(75); // spin to find line
  }
  else {
    Stop(); // all sensors off → stop
  }
}
