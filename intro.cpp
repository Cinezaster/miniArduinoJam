#include <avr/pgmspace.h>
#include <arduino.h>

extern byte intro_sequence;

int ledState = LOW;             
long previousMillis = 0;       
long interval = 500;


void intro() {
  
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    // set the LED with the ledState of the variable:
    for (int i = 9; i < 13; i++) {
      digitalWrite(i, ledState);
    }
    intro_sequence++;
    if  (intro_sequence == 4) {
      interval = 100;
    }
  }
}
