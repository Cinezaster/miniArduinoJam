#include <arduino.h>
#include "stage.h"

int ledStatetwo = LOW;             
long previousMillistwo = 0;       
long intervaltwo = 500;

extern byte sequence;
extern byte SimonSays[];
extern byte level;

void stageUpdate() {
  ShowLedSequence();
  GetButtonPress();
  CompareOk();
}

void ShowLedSequence() {
  for (int i = 0; i < level; i++) {
    digitalWrite(9 + SimonSays[0+i], HIGH);
    delay(500);
    digitalWrite(9 + SimonSays[0+i], LOW);
    delay(200);
  }
}

void GetButtonPress(){

}

boolean CompareOk(){
  bool state = true;
  
  return state;
}
