#include "Arduino.h"
#include "MyDice.h"
MyDice::MyDice(int diceButton, int diceDiagonal1, int diceDiagonal2,
        int diceMiddleLeds, int diceCenterLed) {
        pinMode(diceButton, INPUT_PULLUP);
        pinMode(diceDiagonal1, OUTPUT);
        pinMode(diceDiagonal2, OUTPUT);
        pinMode(diceMiddleLeds, OUTPUT);
        pinMode(diceCenterLed, OUTPUT);
        randomSeed(analogRead(2)); //to have different randoms numbers each time the sketch runs
        int _diceButton = diceButton;
        int _diceDiagonal1 = diceDiagonal1;
        int _diceDiagonal2 = diceDiagonal2;
        int _diceMiddleLeds = diceMiddleLeds;
        int _diceCenterLed = diceCenterLed;
        int _dice[] = {_diceDiagonal1,_diceDiagonal2,_diceMiddleLeds,_diceCenterLed};
        int lenghtDice =  sizeof(_dice)/sizeof(_dice[0]);
        int number1[] = {_diceCenterLed};
        int lenghtNumber1 =  sizeof(number1)/sizeof(number1[0]);
        int number2[] = {_diceDiagonal1};
        int lenghtNumber2 =  sizeof(number2)/sizeof(number2[0]);
        int number3[] = {_diceCenterLed, _diceDiagonal1};
        int lenghtNumber3 =  sizeof(number3)/sizeof(number3[0]);
        int number4[] = {_diceDiagonal1, _diceDiagonal2};
        int lenghtNumber4 =  sizeof(number4)/sizeof(number4[0]);
        int number5[] = {_diceDiagonal1, _diceDiagonal2, _diceCenterLed};
        int lenghtNumber5 =  sizeof(number5)/sizeof(number5[0]);
        int number6[] = {_diceDiagonal1, _diceDiagonal2, _diceMiddleLeds};
        int lenghtNumber6 =  sizeof(number6)/sizeof(number6[0]);
    }
void MyDice::rollDice(){
  checkButton();
  throwDice(); 
};

void MyDice::turnOffLeds (int dice[], int lenghtDice){
  for (int position = 0; position < lenghtDice; position++) {
    digitalWrite(dice[position], LOW);
  };
};

void MyDice::turnOnLeds (int dice[], int lenghtDice){
  for (int position = 0; position < lenghtDice; position++) {
    digitalWrite(dice[position], HIGH);
  };
};

void MyDice::iterateLeds(int dice[], int lenghtDice) {
  //ITERATOR to test all output pins
  for (int position = 0; position < lenghtDice; position++) {
    digitalWrite(dice[position], HIGH);
    delay(1000);
    digitalWrite(dice[position], LOW);
  };
}

void MyDice::flashLeds(int dice[], int lenghtDice, int flashTimes = 5, int delayLed = 100){
  for (int i = 0; i < flashTimes; i++){
    turnOnLeds(dice,lenghtDice);
    delay(delayLed);
    turnOffLeds(dice,lenghtDice);
    delay(delayLed);;
  };
}

void MyDice::lightNumber(int dice[], int lenghtDice, int number){
  switch (number)  {
   
    case 1:
        turnOnLeds(number1, lenghtNumber1);
        break;
    case 2:
        turnOnLeds(number2, lenghtNumber2);
        break;
    case 3:
        turnOnLeds(number3, lenghtNumber3);
        break;
    case 4:
        turnOnLeds(number4, lenghtNumber4);
        break;
    case 5:
        turnOnLeds(number5, lenghtNumber5);
        break;
    case 6:
        turnOnLeds(number6, lenghtNumber6);
        break;
    default:
        //do nothing
        Serial.println("Not a valid dice number");
        Serial.println(number);
        break;
  };
}

void MyDice::iterateNumbers(int dice[], int lenghtDice, int delayNumbers = 1000){
  for (int position = 1; position < 7; position++) {
    lightNumber(dice,lenghtDice,position);
    delay(delayNumbers);
    turnOffLeds(dice,lenghtDice);
    delay(delayNumbers/2);
  };
}

void MyDice::throwDice() {
  int diceNumber = random(1,7);
  int throwTimes = random(1,4);
  Serial.println("diceNumber");
  Serial.println(diceNumber);
  //light up dice randomly
  
  //turn on dice number
  for (int i = 0; i < throwTimes; i++){
    iterateNumbers(_dice,lenghtDice,200);
  }  
  lightNumber(_dice,lenghtDice,diceNumber);
  delay(20);
}

void MyDice::checkButton () {
  delay (50);
  while (digitalRead(_diceButton) == LOW) {
    delay(100);
  };
  delay (50);
  while (digitalRead(_diceButton) == HIGH) {
        delay(100);
  };
}

void MyDice::testDice () {
  flashLeds(_dice,lenghtDice,4,200);
  delay(1000);
  iterateLeds(_dice, lenghtDice);
  delay(1000);
  iterateNumbers(_dice, lenghtDice);
  delay(1000);
  iterateNumbers(_dice, lenghtDice, 150);
  delay(1000);
  turnOffLeds(_dice,lenghtDice);
  delay(1000);
}
