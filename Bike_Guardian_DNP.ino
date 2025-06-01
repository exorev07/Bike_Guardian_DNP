#include <NewPing.h>

// HCSR-04 can check up to 400 cm without error
#define MAX_DISTANCE 400

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

  // Startup signal
  for (int i = 0; i < 3; i++) {
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
  }
}

void loop() {
  int leftDist = USLeft.ping_cm();
  int midDist = USMid.ping_cm();
  int rightDist = USRight.ping_cm();

  handleLED(leftDist, LEDR);
  handleLED(rightDist, LEDL);

  if (leftDist < 100 || midDist < 100 || rightDist < 100) {
    beepBuzzer(10); // buzzer starts beeping rapidly to alert the rider
  }

  // for energy efficiency
  if (leftDist < 400 || midDist < 400 || rightDist < 400) {
    blinkRearLED(100); // blinks the LED installed behind the rider, to alert the traffic behind
  }
}

// distance logic    
void handleLED(int distance, int pin) {
  if (distance <= 100) {
    digitalWrite(pin, HIGH);
  } 
  else if (distance <= 200) {
    digitalWrite(pin, HIGH);
    delay(100);
    digitalWrite(pin, LOW);
    delay(100);
  } 
  else if (distance <= 300) {
    digitalWrite(pin, HIGH);
    delay(500);
    digitalWrite(pin, LOW);
    delay(500);
  } 
  else if (distance <= 400) {
    digitalWrite(pin, HIGH);
    delay(1000);
    digitalWrite(pin, LOW);
    delay(1000);
  } 
  else {
    digitalWrite(pin, LOW);
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
