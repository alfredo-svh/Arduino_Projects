int motorFwd=11;
int motorBwd=12;

void setup() {
  pinMode(motorFwd, OUTPUT);
  pinMode(motorBwd, OUTPUT);
}

void loop() {
  drive_forward();
  delay(2000);
  motor_stop();

  drive_backward();
  delay(2000);
  motor_stop();
}

void motor_stop(){
  digitalWrite(motorFwd, LOW);
  digitalWrite(motorBwd, LOW);

  delay(2000);
}

void drive_forward(){
  digitalWrite(motorFwd, HIGH);
  digitalWrite(motorBwd, LOW);
}

void drive_backward(){
  digitalWrite(motorFwd, LOW);
  digitalWrite(motorBwd, HIGH);
}
