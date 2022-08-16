unsigned int inP[2] = {8, 9},
                      outP[3] = {10, 11, 12},
                                onSw = 13;
bool btn[7];
unsigned int leds[7] = {1, 2, 3, 4, 5, 6, 7};

void setup() {
  Serial.begin(9600); 
}

void loop() {
  while (true) {
    if (digitalRead(onSw))
      digitalWrite(leds[7], HIGH);
    else digitalWrite(leds[7], LOW);
    for (unsigned int i = 0; i < 7; i++)
      btn[i] = false;
    for (unsigned int i = 0; i < 2; i++) {
      digitalWrite(inP[i], HIGH);
      for (unsigned int o = 0; o < 3; o++) {
        if (digitalRead(outP[o])){
          digitalWrite(leds[i + 2 * o], HIGH);
          Serial.println(i + 2 * o);
        }
        else digitalWrite(leds[i + 2 * o], LOW);
      }
      digitalWrite(inP[i], LOW);
    }
  }
}
