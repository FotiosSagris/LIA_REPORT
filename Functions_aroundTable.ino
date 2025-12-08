

  void setup() {
  pinMode(5,OUTPUT); // PWMA speed motor A
  pinMode(7,OUTPUT); // AIN_1 Direction motor A
  pinMode(3,OUTPUT); // Standy
  pinMode(6,OUTPUT); //  PWMB speed motor B
  pinMode(8,OUTPUT); // BIN_1 direction motor B
  }

  void loop() {
Forward(80);
delay(12000);
Right(70);
delay(800);
Forward(80);
delay(5000);
Right(70);
delay(900);
Forward(80);
delay(12000);
Right(70);
delay(900);
Forward(80);
delay(5000);
Stop();
delay(5000);
 }


void Forward ( int x) {
analogWrite(5,x);
digitalWrite(7,1);
analogWrite(6,x);
digitalWrite(8,1);
digitalWrite(3,1); 
 }

void Backward ( int x){
analogWrite(5,x);
digitalWrite(7,0);
analogWrite(6,x);
digitalWrite(8,0);
digitalWrite(3,1);
}

void Left ( int x){
analogWrite(5,x);
digitalWrite(7,1);
analogWrite(6,x);
digitalWrite(8,0);
digitalWrite(3,1);
}

void Right ( int x){
analogWrite(5,x);
digitalWrite(7,0);
analogWrite(6,x);
digitalWrite(8,1);
digitalWrite(3,1);
}

void LeftForward ( float x){
  float y = x * 0.5;
analogWrite(5,x);
digitalWrite(7,1);
analogWrite(6,y);
digitalWrite(8,1);
digitalWrite(3,1);
}

void LeftBackward ( float x){
  float y = x * 0.5;
analogWrite(5,x);
digitalWrite(7,0);
analogWrite(6,y);
digitalWrite(8,0);
digitalWrite(3,1);
}

void RightForward ( float x){
  float y = x * 0.5;
analogWrite(5,y);
digitalWrite(7,1);
analogWrite(6,x);
digitalWrite(8,1);
digitalWrite(3,1);
}

void RightBackward ( float x){
  float y = x * 0.5;
analogWrite(5,y);
digitalWrite(7,0);
analogWrite(6,x);
digitalWrite(8,0);
digitalWrite(3,1);
}

void Stop (){
analogWrite(5,0);
digitalWrite(7,1);
analogWrite(6,0);
digitalWrite(8,1);
digitalWrite(3,1);}