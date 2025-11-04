int cBtnPin = 33;
bool cBtnState = LOW;
bool cLastBtnState = LOW;
int cLedPin = 32;

int eBtnPin = 34;
bool eBtnState = LOW;
bool eLastBtnState = LOW;
int eLedPin = 31;

int gBtnPin = 35;
bool gBtnState = LOW;
bool gLastBtnState = LOW;
int gLedPin = 30;

int switchPin = 38;
bool switchState = LOW;

int octaveVal;

void setup() {
  pinMode(cBtnPin, INPUT);
  pinMode(cLedPin, OUTPUT);

  pinMode(eBtnPin, INPUT);
  pinMode(eLedPin, OUTPUT);

  pinMode(gBtnPin, INPUT);
  pinMode(gLedPin, OUTPUT);

  pinMode(switchPin, INPUT);
}

void loop() {
  cLastBtnState = cBtnState;
  cBtnState = digitalRead(cBtnPin);

  eLastBtnState = eBtnState;
  eBtnState = digitalRead(eBtnPin);

  gLastBtnState = gBtnState;
  gBtnState = digitalRead(gBtnPin);

  switchState = digitalRead(switchPin);

  if (switchState == HIGH) {
    octaveVal = 12;
  }

  else {
    octaveVal = 0;
  }

  if (cLastBtnState == LOW and cBtnState == HIGH) {
    usbMIDI.sendNoteOn(60 + octaveVal, 127, 1);
    digitalWrite(cLedPin, HIGH);
    delay(5);
  }

  if (cLastBtnState == HIGH and cBtnState == LOW) {
    usbMIDI.sendNoteOff(60 + octaveVal, 0, 1);
    digitalWrite(cLedPin, LOW);
    delay(5);
  }

  if (eLastBtnState == LOW and eBtnState == HIGH) {
    usbMIDI.sendNoteOn(64 + octaveVal, 127, 1);
    digitalWrite(eLedPin, HIGH);
    delay(5);
  }
  if (eLastBtnState == HIGH and eBtnState == LOW) {
    usbMIDI.sendNoteOff(64 + octaveVal, 0, 1);
    digitalWrite(eLedPin, LOW);
    delay(5);
  }

  if (gLastBtnState == LOW and gBtnState == HIGH) {
    usbMIDI.sendNoteOn(67 + octaveVal, 127, 1);
    digitalWrite(gLedPin, HIGH);
    delay(5);
  }
  if (gLastBtnState == HIGH and gBtnState == LOW) {
    usbMIDI.sendNoteOff(67 + octaveVal, 0, 1);
    digitalWrite(gLedPin, LOW);
    delay(5);
  }
}