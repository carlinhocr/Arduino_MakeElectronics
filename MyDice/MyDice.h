#ifndef MyDice_h
#define MyDice_h
#include "Arduino.h"
class MyDice {
public:
        MyDice(int diceButton, int diceDiagonal1, int diceDiagonal2,
        int diceMiddleLeds, int diceCenterLed);
        void rollDice();
private:
        int _diceButton;
        int _diceDiagonal1;
        int _diceDiagonal2;
        int _diceMiddleLedsint;
        int _diceCenterLed;
        int lenghtDice;
        int lenghtNumber1;
        int lenghtNumber2;
        int lenghtNumber3;
        int lenghtNumber4;
        int lenghtNumber5;
        int lenghtNumber6;
        void turnOffLeds (int dice[], int lenghtDice);
        void turnOnLeds (int dice[], int lenghtDice);
        void iterateLeds(int dice[], int lenghtDice);
        void flashLeds(int dice[], int lenghtDice, int flashTimes = 5, int delayLed = 100);
        void lightNumber(int dice[], int lenghtDice, int number);
        void iterateNumbers(int dice[], int lenghtDice, int delayNumbers = 1000);
        void testDice ();
        int number1[];
        int number2[];
        int number3[];
        int number4[];
        int number5[];
        int number6[];
        int _dice[];

};
#endif