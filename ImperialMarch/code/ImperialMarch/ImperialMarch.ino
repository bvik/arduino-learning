const byte COUNT = 39;
const double MULT = 1.5;
const byte LED_MIN = 2; 
const byte LED_MAX = 8;
int PIN_BUZZER = 8;


int frequences[COUNT] = {
  392, 392, 392, 311, 466, 392, 311, 466, 392,
  587, 587, 587, 622, 466, 369, 311, 466, 392,
  784, 392, 392, 784, 739, 698, 659, 622, 659,
  415, 554, 523, 493, 466, 440, 466,
  311, 369, 311, 466, 392
};
int durations[COUNT] = {
  350, 350, 350, 250, 100, 350, 250, 100, 700,
  350, 350, 350, 250, 100, 350, 250, 100, 700,
  350, 250, 100, 350, 250, 100, 100, 100, 450,
  150, 350, 250, 100, 100, 100, 450,
  150, 350, 250, 100, 750
};


void setup() {
  
  for (int i = LED_MIN; i <= LED_MAX; i++ ) {
     if (i != 3)
       pinMode(i, OUTPUT);  
  }
}

void loop() {
  for (int i = 0; i < COUNT; i++) {
    tone(PIN_BUZZER, frequences[i], durations[i]*MULT);
    for (int i = LED_MIN; i <= LED_MAX; i++ ) {
       if (i != 3)
        analogWrite(i, random(0, 254));  
    }    
    delay(durations[i]*MULT);  
  }
  noTone(PIN_BUZZER);
  for (int i = LED_MIN; i <= LED_MAX; i++ ) {
       if (i != 3)
         analogWrite(i, 0);  
    }    
  delay(500);
}
