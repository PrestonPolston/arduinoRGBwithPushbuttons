int redButton = 2;
int greenButton = 4;
int blueButton = 7;
int redPin = 9;
int redValue = 1;
int redValueOld = 0;
bool redLight = true;
int greenPin = 10;
int greenValue = 1;
int greenValueOld = 0;
bool greenLight = true;
int bluePin = 11;
int blueValue = 1;
int blueValueOld = 0;
bool blueLight = true;
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
    if (redLight == true) {
      digitalWrite(redPin, HIGH);
      Serial.println("light is on");
      delay(delayTime);
    }
     if (redLight == false) {
      digitalWrite(redPin, LOW);
      Serial.println("light is off");
      delay(delayTime);
    }
    redLight = !redLight;
  }
  redValueOld = redValue;

  // green LED logic
  greenValue = digitalRead(greenButton);
  if (greenValue == 0 && greenValueOld == 1){
    if(greenLight == true){
      digitalWrite(greenPin, HIGH);
      Serial.println("light is on");
      delay(delayTime);
    }
    if(greenLight == false){
      digitalWrite(greenPin, LOW);
      Serial.println("light is off");
      delay(delayTime); 
    }
    greenLight = !greenLight;
  }
  greenValueOld = greenValue;

  // blue LED logic
  blueValue = digitalRead(blueButton);
  if(blueValue == 0 && blueValueOld == 1){
    if (blueLight == true){
      digitalWrite(bluePin, HIGH);
      Serial.println("light is on");
      delay(delayTime);
    }
    if(blueLight == false){
      digitalWrite(bluePin, LOW);
      Serial.println("light is off");
      delay(delayTime);
    }
    blueLight = !blueLight;
  }
  blueValueOld = blueValue;
}
