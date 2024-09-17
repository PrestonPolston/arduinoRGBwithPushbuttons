int redButton = 2;
int greenButton = 4;
int blueButton = 8;
int redPin = 9;
int redValue = 1;
int redValueOld = 0;
bool redLight = false;
int greenPin = 10;
int greenValue = 1;
int greenValueOld = 0;
bool greenLight = false;
int bluePin = 11;
int blueValue = 1;
int blueValueOld = 0;
bool blueLight = false;
int br = 115200;
int delayTime = 250;
void setup() {
Serial.begin(br);
pinMode(redButton, INPUT);
pinMode(redPin, OUTPUT);
pinMode(greenButton, INPUT);
pinMode(greenPin, OUTPUT);
pinMode(blueButton, INPUT);
pinMode(bluePin, OUTPUT);
}

void loop() {
  // red LED logic
  redValue = digitalRead(redButton);
  if (redValue == 0 && redValueOld == 1){
    redLight = !redLight;
    digitalWrite(redPin, redLight ? HIGH : LOW);
    Serial.println(redLight ? "light is on" : "light is off");
  }
  redValueOld = redValue;

  // green LED logic
  greenValue = digitalRead(greenButton);
  if (greenValue == 0 && greenValueOld == 1){
    greenLight = !greenLight;
    digitalWrite(greenPin, greenLight ? HIGH : LOW);
    Serial.println(greenLight ? "light is on" : "light is off");
    delay(delayTime);
  }
  greenValueOld = greenValue;

  // blue LED logic
  blueValue = digitalRead(blueButton);
  if(blueValue == 0 && blueValueOld == 1){
      blueLight = !blueLight;
      digitalWrite(bluePin, blueLight ? HIGH : LOW); 
      Serial.println(blueLight ? "light is on" : "light is off");
      delay(delayTime);
  }
  blueValueOld = blueValue;
}
