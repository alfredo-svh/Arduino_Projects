int sLength = 7; //number of notes
int sTempo = 240; //beats per minute
int sMeasure = 4; //beats per measure
int sNoteList[] = {9, 9, 9, 7, 9, 11, 4}; //0-20; C3-B5 (0-6 lower, 7-13 standard, 14-20 higher)
double sTimingList[] = {.5, .5, .5, .25, .25, 1, 1.5}; //quarter: 1; whole: 4; eighth: .5; etc

int LED_C = 2;
int LED_D = 3;
int LED_E = 4;
int LED_F = 5;
int LED_G = 6;
int LED_A = 7;
int LED_B = 8;

int LED_UP = 9;
int LED_DOWN = 10;


void setup() {
  pinMode(LED_C, OUTPUT); //Note LEDs
  pinMode(LED_D, OUTPUT);
  pinMode(LED_E, OUTPUT);
  pinMode(LED_F, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);
  
  pinMode(LED_UP, OUTPUT); //Octave LEDs
  pinMode(LED_DOWN, OUTPUT);
}

void loop() {
   displaySong();
  
}

void displaySong() {
  int curNote = 0;

  for (int i = 0; i < sLength; i++) { //for each note in the song
    curNote = 0;
    if (sNoteList[i] < 7) { // if the note is a low octave display the low octave light, and same for high
      digitalWrite(LED_DOWN, HIGH);
      curNote = sNoteList[i] + 7;
    }
    else if(sNoteList[i] > 13) {
      digitalWrite(LED_UP, HIGH);
      curNote = sNoteList[i] - 7;
    }
    else {
      curNote = sNoteList[i];
    }
    digitalWrite(curNote - 5, HIGH); //turn on LED for the correct note for the currect time calculated below
    delay(60 / (sTempo / sMeasure) * 1000 * sTimingList[i]);

    digitalWrite(curNote - 5, LOW);//turns off all LEDs for 60 ms before moving on
    digitalWrite(LED_UP, LOW);
    digitalWrite(LED_DOWN, LOW);
    delay(60);
  }
}
