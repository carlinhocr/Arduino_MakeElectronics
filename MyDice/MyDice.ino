#include <MyDice.h>
// diceButton=2
// diceDiagonal1=6
// diceDiagonal2=3,
// diceMiddleLeds=5
// diceCenterLed=4);

//MyDice dice1(2,6,3,5,4);
MyDice diceGreen(2,7,8,9,10);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
        // pinMode(7, OUTPUT);
        // pinMode(8, OUTPUT);
        // pinMode(9, OUTPUT);
        // pinMode(10, OUTPUT);
        // digitalWrite(7, HIGH);
        // digitalWrite(8, HIGH);
        // digitalWrite(9, HIGH);
        // digitalWrite(10, HIGH);
}

void loop() {
  //Serial.println(digitalRead(2));
  //dice1.rollDice();
  diceGreen.rollDice();
}
