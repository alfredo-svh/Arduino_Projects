int ledPin=13; // LED connected to digital pin 13
int ledPin1=11;
int ledPin2=8;
 
void setup() {
  pinMode(ledPin, OUTPUT); //sets the digital pin as output
  pinMode(ledPin1,OUTPUT); //sets the digital pin as output
  pinMode(ledPin2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(ledPin,HIGH); // sets the LED on
digitalWrite(ledPin1,LOW);
delay(2000); //waits for 2 seconds
digitalWrite(ledPin, LOW); //turns LED off
digitalWrite(ledPin1,HIGH);
delay(1000); // waits for a second
digitalWrite(ledPin2,HIGH);
delay (1000);
digitalWrite(ledPin2,LOW);
delay(1000);

}
