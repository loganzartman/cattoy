#include <AccelStepper.h>

#define PIN_LED_BUILTIN 13
#define PIN_STEPPER1_STEP 7
#define PIN_STEPPER1_DIR 8

#define STEPPER_SPEED_SNEAK 80.0
#define STEPPER_SPEED_SWING 400.0
#define STEPPER_SPEED_WIGGLE 800.0
#define STEPPER_ACCELERATION_SNEAK 250.0
#define STEPPER_ACCELERATION_SWING 500.0
#define STEPPER_ACCELERATION_WIGGLE 1000.0
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
  flash(3);
}

void wiggle() {
  stepper.setMaxSpeed(STEPPER_SPEED_WIGGLE);
  stepper.setAcceleration(STEPPER_ACCELERATION_WIGGLE);
  int dir = 1;
  int intensity = random(80, 150);
  for (int i = random(7, 12); i > 0; --i) {
    stepper.move(intensity * dir);
    stepper.runToPosition();
    dir *= -1;
  }
}

void swing(int dir) {
  stepper.setMaxSpeed(STEPPER_SPEED_SWING);
  stepper.setAcceleration(STEPPER_ACCELERATION_SWING);
  stepper.move(random(500, 2000) * dir);
  stepper.runToPosition();
}

void sneak(int dir) {
  stepper.setMaxSpeed(STEPPER_SPEED_SNEAK);
  stepper.setAcceleration(STEPPER_ACCELERATION_SNEAK);
  stepper.move(random(250, 1000) * dir);
  stepper.runToPosition();
}

bool justDelayed = false;
void loop() {
  // choose action
  long choice = random(3 + 3);
  if (choice == 0) {
    if (random(2) == 0)
      swing(1);
    else
      swing(-1);
  }
  else if (choice == 1) {
    wiggle();
  }
  else if (choice == 2) {
    if (random(2) == 0)
      sneak(1);
    else
      sneak(-1);
  }
  else if (!justDelayed) {
    delay(random(2000, 20000));
    justDelayed = true;
  }
  justDelayed = false;
}
