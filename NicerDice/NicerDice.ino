#define diceButton 2
#define diceDiagonal1 6
#define diceDiagonal2 3
#define diceMiddleLeds 5
#define diceCenterLed  4
int dice[] = {diceDiagonal1,diceDiagonal2,diceMiddleLeds,diceCenterLed};
int lenghtDice =  sizeof(dice)/sizeof(dice[0]);
int number1[] = {diceCenterLed};
int lenghtNumber1 =  sizeof(number1)/sizeof(number1[0]);
int number2[] = {diceDiagonal1};
int lenghtNumber2 =  sizeof(number2)/sizeof(number2[0]);
int number3[] = {diceCenterLed, diceDiagonal1};
int lenghtNumber3 =  sizeof(number3)/sizeof(number3[0]);
int number4[] = {diceDiagonal1, diceDiagonal2};
int lenghtNumber4 =  sizeof(number4)/sizeof(number4[0]);
int number5[] = {diceDiagonal1, diceDiagonal2, diceCenterLed};
int lenghtNumber5 =  sizeof(number5)/sizeof(number5[0]);
int number6[] = {diceDiagonal1, diceDiagonal2, diceMiddleLeds};
int lenghtNumber6 =  sizeof(number6)/sizeof(number6[0]);

void turnOffLeds (int dice[], int lenghtDice){
  for (int position = 0; position < lenghtDice; position++) {
    digitalWrite(dice[position], LOW);
  };
};

void turnOnLeds (int dice[], int lenghtDice){
  for (int position = 0; position < lenghtDice; position++) {
    digitalWrite(dice[position], HIGH);
  };
};

void iterateLeds(int dice[], int lenghtDice) {
  //ITERATOR to test all output pins
  for (int position = 0; position < lenghtDice; position++) {
    digitalWrite(dice[position], HIGH);
    delay(1000);
    digitalWrite(dice[position], LOW);
  };
}

void flashLeds(int dice[], int lenghtDice, int flashTimes = 5, int delayLed = 100){
  for (int i = 0; i < flashTimes; i++){
    turnOnLeds(dice,lenghtDice);
    delay(delayLed);
    turnOffLeds(dice,lenghtDice);
    delay(delayLed);;
  };
}

void lightNumber(int dice[], int lenghtDice, int number){
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
        break;
  };
}

void iterateNumbers(int dice[], int lenghtDice){
  for (int position = 1; position < 7; position++) {
    lightNumber(dice,lenghtDice,position);
  };
}

void testDice () {
  flashLeds(dice,lenghtDice,4,200);
  delay(1000);
  iterateLeds(dice, lenghtDice);
  delay(1000);
  iterateNumbers(dice, lenghtDice);
  delay(1000);
  turnOffLeds(dice,lenghtDice);
  delay(1000);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(diceButton, INPUT);
  pinMode(diceDiagonal1, OUTPUT);
  pinMode(diceDiagonal2, OUTPUT);
  pinMode(diceMiddleLeds, OUTPUT);
  pinMode(diceCenterLed, OUTPUT);
}

void loop() {
  testDice();      
}

