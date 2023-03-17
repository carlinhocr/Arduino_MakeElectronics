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
long ignore = 0;

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
        Serial.println("Not a valid dice number");
        Serial.println(number);
        break;
  };
}

void iterateNumbers(int dice[], int lenghtDice, int delayNumbers = 1000){
  for (int position = 1; position < 7; position++) {
    lightNumber(dice,lenghtDice,position);
    delay(delayNumbers);
    turnOffLeds(dice,lenghtDice);
    delay(delayNumbers/2);
  };
}

void throwDice() {
  int diceNumber = random(1,7);
  int throwTimes = random(1,4);
  Serial.println("diceNumber");
  Serial.println(diceNumber);
  //light up dice randomly
  
  //turn on dice number
  for (int i = 0; i < throwTimes; i++){
    iterateNumbers(dice,lenghtDice,200);
  }  
  lightNumber(dice,lenghtDice,diceNumber);
  delay(20);
}

void checkButton () {
  delay (50);
  Serial.println("Inside Check Button");
  Serial.println("diceButton");
  Serial.println(digitalRead(diceButton));
  while (digitalRead(diceButton) == LOW) {
    delay(100);
    Serial.println("Inside While LOW");
    Serial.println(digitalRead(diceButton));
  };
  delay (50);
  while (digitalRead(diceButton) == HIGH) {
        delay(100);
    Serial.println("Inside While HIGH");
    Serial.println(digitalRead(diceButton));
  };
  ignore = 2000 + millis();
}

void testDice () {
  flashLeds(dice,lenghtDice,4,200);
  delay(1000);
  iterateLeds(dice, lenghtDice);
  delay(1000);
  iterateNumbers(dice, lenghtDice);
  delay(1000);
  iterateNumbers(dice, lenghtDice, 150);
  delay(1000);
  turnOffLeds(dice,lenghtDice);
  delay(1000);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(diceButton, INPUT_PULLUP);
  pinMode(diceDiagonal1, OUTPUT);
  pinMode(diceDiagonal2, OUTPUT);
  pinMode(diceMiddleLeds, OUTPUT);
  pinMode(diceCenterLed, OUTPUT);
  randomSeed(analogRead(2)); //to have different randoms numbers each time the sketch runs
  //Serial.println(analogRead(2));
  ignore = 2000 + millis();
  Serial.println(digitalRead(diceButton));
}

void loop() {
  //testDice();    
  checkButton();
  throwDice();  

  delay(200);
  Serial.println(digitalRead(diceButton));
  Serial.println(digitalRead(millis()));
  Serial.println(digitalRead(ignore));
  if (digitalRead(diceButton) == LOW) {
    checkButton();
  };   
}

