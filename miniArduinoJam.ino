#include "intro.h"
#include "stage.h"

#define GAME_STATE_INIT      0
#define GAME_STATE_PLAYING   1
#define GAME_STATE_GAMEOVER  3

#define led_red_pin = 9;
#define led_green_pin = 10;
#define led_yellow_pin = 11;
#define led_white_pin = 12;

#define button_red_pin = 2;
#define button_green_pin = 3;
#define button_yellow_pin = 4;
#define button_white_pin = 5;

unsigned int game_state = GAME_STATE_INIT;
byte intro_sequence;
byte SimonSays[16];
byte level;

void setup() {
  // put your setup code here, to run once:
  
  for (int i = 2; i < 6; i++) {
    pinMode(i, INPUT);
  } 
  for (int i = 9; i < 13; i++) {
    pinMode(i, OUTPUT);
  }
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
 switch (game_state) {
   case GAME_STATE_INIT:
   {
     intro();
     if (intro_sequence > 11) {
       for (byte i = 0; i < 16; i++){
         SimonSays[i] = random(0,4);
       }
       level = 3;
       game_state = GAME_STATE_PLAYING;
     }
     break;
   }
   case GAME_STATE_PLAYING:
   {
     stageUpdate();
     break;
   }
 } 
  
}
