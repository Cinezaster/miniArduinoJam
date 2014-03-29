#include <avr/pgmspace.h>
#include <arduino.h>

extern byte intro_sequence;
// Variables will change:
int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 500;           // interval at which to blink (milliseconds)


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
    if  (intro_sequence == 5) {
      interval = 100;
    }
  }
}
