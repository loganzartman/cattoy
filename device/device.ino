#include <AccelStepper.h>

#define PIN_LED_BUILTIN 13
#define PIN_STEPPER1_STEP 7
#define PIN_STEPPER1_DIR 8

#define STEPPER_MAX_SPEED 1200.0
#define STEPPER_ACCELERATION 2000.0
#define STEPPER_TRAVEL_STEPS 2000

AccelStepper stepper(AccelStepper::DRIVER, PIN_STEPPER1_STEP, PIN_STEPPER1_DIR);

void flash(int n) {
  for (int i = 0; i < n; ++i) {
    digitalWrite(PIN_LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(PIN_LED_BUILTIN, LOW);
    delay(200);
  }
}

void setup() {
  stepper.setMaxSpeed(STEPPER_MAX_SPEED);
  stepper.setAcceleration(STEPPER_ACCELERATION);
  pinMode(PIN_LED_BUILTIN, OUTPUT);
  flash(3);
}

void loop() {
  // move a random amount
  stepper.move(random(-2000, 2000));
  stepper.runToPosition();
  // wait a random time
  delay(random(200, 2000));
}
