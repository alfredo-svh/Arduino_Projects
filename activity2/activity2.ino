int ledPin=3; // LED connected to pin 3

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT); //sets pin as output
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  digitalWrite(ledPin, HIGH); // turns led on
  delay(5000); // waits 5 seconds
  digitalWrite(ledPin, LOW); //turns led off
  delay (3000); // waits 3 seconds
  for (i=0;i<10;i++){ //turns it on and off 10 times
    digitalWrite(ledPin, HIGH); //turns it on
    delay(1000); //waits one second
    digitalWrite(ledPin, LOW); // turns led off
    delay(1000); //waits one second
  }
}
