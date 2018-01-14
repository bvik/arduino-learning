#include "pitches.h"

// bvik
// Ambulance siren 

// notes in the melody:
int melody[] = {NOTE_C5, NOTE_F5};
int duration = 800;  
int minPin = 2;
int maxPin = 5;
 
void setup() {
	for (int i = minPin; i <= maxPin; i++) {
	  pinMode(i,OUTPUT);
	}
}
 
void loop() {  
  for (int thisNote = 0; thisNote < 2; thisNote++) {
		for (int i = minPin; i <= maxPin; i++) {
	  	digitalWrite(i, LOW);
		}

    tone(8, melody[thisNote], duration);

    digitalWrite(minPin + thisNote*2, HIGH);
    digitalWrite(minPin + thisNote*2 + 1, HIGH);

    delay(duration);
  }
}
