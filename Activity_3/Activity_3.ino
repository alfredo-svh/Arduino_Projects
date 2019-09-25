int ledPin=12; // LED connected to pin 12
int inPin =13; //pushbutton connected to pin 13

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT); //sets pin as output
  pinMode(ledPin,INPUT);//sets pin to input
}

void loop() {
  // put your main code here, to run repeatedly:
  int n;
  n=digitalRead(inPin);
  if(n>0)
  {
    digitalWrite(ledPin,HIGH);//turns led on
    delay(3000);
    digitalWrite(ledPin,LOW);//turns led off
  }
}

