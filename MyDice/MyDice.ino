#include <MyDice.h>
// diceButton=2
// diceDiagonal1=6
// diceDiagonal2=3,
// diceMiddleLeds=5
// diceCenterLed=4);

MyDice dice1(2,6,3,5,4);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  //Serial.println(digitalRead(2));
  dice1.rollDice();
}
