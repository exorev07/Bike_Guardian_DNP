#include <NewPing.h>

#define MAX_DISTANCE 400  // Max distance to check (in cm)

#define LEDL 8
#define LEDR 9
#define BUZZER 10
#define REARLED 11

NewPing USLeft(2, 3, MAX_DISTANCE);
NewPing USMid(4, 5, MAX_DISTANCE);
NewPing USRight(6, 7, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
  pinMode(LEDL, OUTPUT);
  pinMode(LEDR, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(REARLED, OUTPUT);

  digitalWrite(BUZZER, HIGH);
  digitalWrite(LEDL, HIGH);
  digitalWrite(LEDR, HIGH);
  digitalWrite(REARLED, HIGH);
  delay(100);
  digitalWrite(BUZZER, LOW);
  digitalWrite(LEDL, LOW);
  digitalWrite(LEDR, LOW);
  digitalWrite(REARLED, LOW);
  delay(100);
  digitalWrite(BUZZER, HIGH);
  digitalWrite(LEDL, HIGH);
  digitalWrite(LEDR, HIGH);
  digitalWrite(REARLED, HIGH);
  delay(100);
  digitalWrite(BUZZER, LOW);
  digitalWrite(LEDL, LOW);
  digitalWrite(LEDR, LOW);
  digitalWrite(REARLED, LOW);
  delay(100);
  digitalWrite(BUZZER, HIGH);
  digitalWrite(LEDL, HIGH);
  digitalWrite(LEDR, HIGH);
  digitalWrite(REARLED, HIGH);
  delay(100);
  digitalWrite(BUZZER, LOW);
  digitalWrite(LEDL, LOW);
  digitalWrite(LEDR, LOW);
  digitalWrite(REARLED, LOW);
}

void loop() {
  int leftDist = USLeft.ping_cm();
  int midDist = USMid.ping_cm();
  int rightDist = USRight.ping_cm();

  handleLED(leftDist, LEDR);
  handleLED(rightDist, LEDL);

  if (leftDist < 15 || midDist < 15 || rightDist < 15) {
    beepBuzzer(10);
  }

  if (leftDist < 50 || midDist < 50 || rightDist < 50) {
    blinkRearLED(100);
  }
}

void handleLED(int distance, int pin) {
  if (distance > 40 && distance <= 50) {
    digitalWrite(pin, HIGH);
    delay(500);
    digitalWrite(pin, LOW);
    delay(500);
  } else if (distance > 25 && distance <= 40) {
    digitalWrite(pin, HIGH);
    delay(250);
    digitalWrite(pin, LOW);
    delay(250);
  } else if (distance > 10 && distance <= 25) {
    digitalWrite(pin, HIGH);
    delay(100);
    digitalWrite(pin, LOW);
    delay(100);
  } else if (distance >= 0 && distance <= 10) {
    digitalWrite(pin, HIGH);
    delay(25);
    digitalWrite(pin, LOW);
    delay(25);
  } else {
    digitalWrite(pin, LOW);  // Turn off if out of range
  }
}

void beepBuzzer(int duration) {
  digitalWrite(BUZZER, HIGH);
  delay(duration);
  digitalWrite(BUZZER, LOW);
  delay(duration);
}

void blinkRearLED(int duration) {
  digitalWrite(REARLED, HIGH);
  delay(duration);
  digitalWrite(REARLED, LOW);
  delay(duration);
}
