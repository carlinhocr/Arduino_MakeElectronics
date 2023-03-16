#define diceButton 2
#define diceDiagonal1 3
#define diceDiagonal2 4
#define diceMiddleLeds 5
#define diceCenterLed  6
// int diceButton = 2;
// int diceDiagonal1 = 3;
// int diceDiagonal2 = 4;
// int diceMiddleLeds = 5;
// int diceCenterLed = 6;
int dice[] = {diceDiagonal1,diceDiagonal2,diceMiddleLeds,diceCenterLed};
int number1[] = {diceCenterLed};
int number2[] = {diceDiagonal1};
int number3[] = {diceCenterLed, diceDiagonal1};
int number4[] = {diceDiagonal1, diceDiagonal2};
int number5[] = {diceDiagonal1, diceDiagonal2, diceCenterLed};
int number6[] = {diceDiagonal1, diceDiagonal2, diceMiddleLeds};
int numberOne[] = {diceCenterLed};

void turnOffLeds (int dice[]){
  int lenghtDice =  sizeof(dice) / sizeof(int);
  for (int position = 0; position < lenghtDice; position++) {
    Serial.println(dice[position]);
    Serial.println(lenghtDice);
    digitalWrite(dice[position], LOW);
  };
};

void testDice () {
  turnOffLeds(dice);
  delay(1000);
  turnOnLeds(dice);
  delay(1000);
  iterateLeds(dice);
  delay(1000);
  turnOffLeds(dice);
  delay(1000);
  turnOnLeds(number1);
  delay(1000);
  turnOnLeds(number2);
  delay(1000);
  turnOnLeds(number3);
  delay(1000);
  turnOnLeds(number4);
  delay(1000);
  turnOnLeds(number5);
  delay(1000);
  turnOnLeds(number6);
}

void turnOnLeds (int dice[]){
  int lenghtDice =  sizeof(dice) / sizeof(int);
  for (int position = 0; position < lenghtDice; position++) {
    Serial.println(dice[position]);
    Serial.println(lenghtDice);
    digitalWrite(dice[position], HIGH);
  };
};

void iterateLeds(int dice[]) {
  //ITERATOR to test all output pins
  int lenghtDice =  sizeof(dice) / sizeof(int);
  for (int position = 0; position < lenghtDice; position++) {
    digitalWrite(dice[position], HIGH);
    delay(1000);
    digitalWrite(dice[position], LOW);
  };
}

void setup() {
  // put your setup code here, to run once:
  pinMode(diceButton, INPUT);
  pinMode(diceDiagonal1, OUTPUT);
  pinMode(diceDiagonal2, OUTPUT);
  pinMode(diceMiddleLeds, OUTPUT);
  pinMode(diceCenterLed, OUTPUT);
}

void loop() {
  testDice();      
}

