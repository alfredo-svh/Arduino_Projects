int MarioFinale[] = {98, 131, 165, 196, 262, 330, 392, 330, 104, 139, 175, 208, 277, 349, 415, 349, 117, 147, 175, 233, 294, 349, 466, 466, 466, 466, 523};
int MarioTiming[] = {150, 150, 150, 150, 150, 150, 450, 450, 150, 150, 150, 150, 150, 150, 450, 450, 150, 150, 150, 150, 150, 150, 450, 150, 150, 150, 1250};

//above is the frequencies and durations for each note for the Mario Finale Song


int checkTenNotes[] = {5, 5, 5, 3, 5, 7, 7};

//this is the 'password' one must play to activate the finale

int motorFwd = 12;
int motorBwd = 2;

int button_c = 3;
int button_d = 4;
int button_e = 5;
int button_f = 6;
int button_g = 7;
int button_a = 8;
int button_b = 9;
int button_up = 10;
int button_down = 11;
int speaker = 13;

int state_c = 0;
int state_d = 0;
int state_e = 0;
int state_f = 0;
int state_g = 0;
int state_a = 0;
int state_b = 0;
int state_up = 0;
int state_down = 0;

//used to hold values of what buttons are being pushed

double octaveMultiplier = 1.00;
double cur_tone = 0;
int lastTime = 0;

int lastSevenNotes[] = {0, 0, 0, 0, 0, 0, 0};
char noteList[] = {'c', 'd', 'e', 'f', 'g', 'a', 'b'};
int frequencies[] = {523, 587, 659, 698, 784, 880, 988};
//basic 7 notes and their frequencies

void setup() {
  Serial.begin(9600);  
  Serial.println("--- Start Serial Monitor SEND_RCVE ---"); //This is used to detect whether or not buttons are working
  Serial.println(); 

  pinMode(motorFwd, OUTPUT);//Motor Drive
  pinMode(motorBwd, OUTPUT);
  
  pinMode(13, OUTPUT);//Speaker

  pinMode(11, INPUT);//Octave Switches
  pinMode(10, INPUT);
  
  pinMode(9, INPUT);//Piano Keys
  pinMode(8, INPUT);
  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(5, INPUT);
  pinMode(4, INPUT);
  pinMode(3, INPUT);
}

void loop() {
  state_c = digitalRead(button_c); //Here is where the state of each button is checked in each loop
  state_d = digitalRead(button_d);
  state_e = digitalRead(button_e);
  state_f = digitalRead(button_f);
  state_g = digitalRead(button_g);
  state_a = digitalRead(button_a);
  state_b = digitalRead(button_b);
  state_up = digitalRead(button_up);
  state_down = digitalRead(button_down);
  octaveMultiplier = 1; //the current octave of the note is reset to one every loop

  if((state_c == HIGH) || (state_d == HIGH) || //If any button is pressed that button is then the note to be played this loop, higher freq notes take priority
    (state_e == HIGH) || (state_f == HIGH) || 
    (state_g == HIGH) || (state_a == HIGH) || 
    (state_b == HIGH)) { 
    if (state_c == HIGH) {
      cur_tone = frequencies[0];

      addNoteList(button_c);
    } 
    if (state_d == HIGH) {
      cur_tone = frequencies[1];

      addNoteList(button_d);
    }
    if (state_e == HIGH) {
      cur_tone = frequencies[2];

      addNoteList(button_e);
    }
    if (state_f == HIGH) {
      cur_tone = frequencies[3];

      addNoteList(button_f);
    }
    if (state_g == HIGH) {
      cur_tone = frequencies[4];

      addNoteList(button_g);
    }
    if (state_a == HIGH) {
      cur_tone = frequencies[5];

      addNoteList(button_a);
    }
    if (state_b == HIGH) {
      cur_tone = frequencies[6];

      addNoteList(button_b);
    }

    if (state_up == HIGH && state_down == LOW) { //If the high or the low ocatave are pressed then change the octave multiplier
      octaveMultiplier /= 2;
    }
    if (state_down == HIGH && state_up == LOW) {
      octaveMultiplier *= 2;
    }

    if (state_up == HIGH && state_down == HIGH) { //When both octave buttons are pressed then the key only goes up a half-step, thus a sharp note
      octaveMultiplier *= 1.0595;
    }
   
    tone(13, (cur_tone * octaveMultiplier), 10); //Here we actually play the note and we can adjust the octave with the octaveMultiplier

    addNoteList(cur_tone * octaveMultiplier); //add the current note to the last played

    if (checkNotes() == 1) { //This is to check every loop whether or not the last 7 notes match the password
      Serial.println("Here");
      delay(500);

      drive_forward();
      delay(2000);
      for (int q = 0; q < 27; q++) { //if it matches then play mario finale song and raise the flag
        Serial.println(MarioFinale[q]);
        tone(13, MarioFinale[q], MarioTiming[q]);
        delay(MarioTiming[q] + 50);
      }

      motor_stop();

      drive_backward();
      delay(2000);
      motor_stop();
    }
  }
  else
  {
    digitalWrite(speaker, LOW); //otherwise do nothing
  }
}

void addNoteList(int note) { //This adds notes to the array of last seven notes
  int curTime = millis();
  if ((curTime - lastTime) > 75) { //This ensures that a note is only added once every time its pressed, otherwise every loop which is a couple ms the button would be added
    for (int i = 0; i < 7; i++) {
      lastSevenNotes[i] = lastSevenNotes[i + 1];
    }
    lastSevenNotes[6] = note;
    Serial.print(note);
    Serial.println();
    Serial.print('[');
    for (int j = 0; j < 7; j++) {
      Serial.print(lastSevenNotes[j]);
      Serial.print(',');
    }
    Serial.print(']');
    Serial.println();
  }
  lastTime = millis();
}

int checkNotes() {
  int checkSum = 0;
  for (int i = 0; i < 7; i++) {
    if (checkTenNotes[i] == lastSevenNotes[i]) {
      checkSum++;
    }
  }
  if (checkSum == 7) {
    return 1;
  }
  else {
    return 0;
  }
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

