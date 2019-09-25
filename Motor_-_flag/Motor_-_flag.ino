int motorpin=13;
int directionpin=5;

void setup() {
  pinMode (motorpin, OUTPUT);
}

void loop() {
  //if sequence is successfully played:
    flag();
}

void flag(){
  digitalWrite(motorpin, HIGH);
  delay(2000);
  digitalWrite(motorpin, LOW);
  delay(5000);
  digitalWrite(directionpin, HIGH);
  digitalWrite(motorpin, HIGH);
  delay(2000);
  digitalWrite(motorpin, LOW);
  delay(250);
  digitalWrite(directionpin, LOW);
}
