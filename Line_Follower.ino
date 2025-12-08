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

void Forward(int x) {
  analogWrite(5, x);
  digitalWrite(7, 1);
  analogWrite(6, x);
  digitalWrite(8, 1);
  digitalWrite(3, 1);
}

void Left(int x) {
  analogWrite(5, x);
  digitalWrite(7, 1);
  analogWrite(6, x);
  digitalWrite(8, 0);
  digitalWrite(3, 1);
}

void Right(int x) {
  analogWrite(5, x);
  digitalWrite(7, 0);
  analogWrite(6, x);
  digitalWrite(8, 1);
  digitalWrite(3, 1);
}

void Stop() {
  analogWrite(5, 0);
  digitalWrite(7, 1);
  analogWrite(6, 0);
  digitalWrite(8, 1);
  digitalWrite(3, 1);
}



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