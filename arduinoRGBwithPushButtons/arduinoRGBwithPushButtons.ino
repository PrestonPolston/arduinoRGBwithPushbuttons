int redButton = 2;
int greenButton = 4;
int blueButton = 7;
int redPin = 9;
int redValue = 1;
int redValueOld = 0;
bool redLight = false;
int greenPin = 10;
int greenValue = 1;
int greenValueOld = 0;
int greenLight = 0;
int bluePin = 11;
int blueValue = 1;
int blueValueOld = 0;
int blueLight = 0;
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
}
