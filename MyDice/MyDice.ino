#include <MyDice.h>
// diceButton=2
// diceDiagonal1=6
// diceDiagonal2=3,
// diceMiddleLeds=5
// diceCenterLed=4);

int _diceButton=2;

MyDice diceRed(2,6,3,5,4);
MyDice diceGreen(2,7,8,9,10);

void checkButton() {
  delay (50);
  while (digitalRead(_diceButton) == LOW) {
    delay(100);
  };
  delay (50);
  while (digitalRead(_diceButton) == HIGH) {
        delay(100);
  };
  randomSeed(millis());
}

void iterateNumbers(){
  diceRed.turnOffDice();
  diceGreen.turnOffDice();
  delay(300);
  for (int position = 1; position < 7; position++) {
    diceRed.lightNumber(position);
    diceGreen.lightNumber(position);
    delay(200);
    diceRed.turnOffDice();
    diceGreen.turnOffDice();
    delay(200);
  };
}

void throwDice() {
  //light up dice randomly
  //turn on dice number
  Serial.println("En Throw dice");
  randomSeed(millis()); //to have different randoms numbers each time the sketch runs
  int diceNumberRed = random(1,7);
  int diceNumberGreen = random(1,7);
  int throwTimes = random(1,4);
  for (int i = 0; i < throwTimes; i++){
    iterateNumbers();
  }  
  diceRed.lightNumber(diceNumberRed);
  diceGreen.lightNumber(diceNumberGreen);

  delay(20);
}

void twoDiceConcurrently(){

  checkButton();
  throwDice();
}

void oneDiceWithButton(){
  diceRed.rollDice();
}

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
  twoDiceConcurrently();
}
