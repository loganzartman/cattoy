#include "stepper.h"

namespace ribbon {
int dir = 1;

const float accel =  2000.0;
const float maxSpeed = 1600.0;

void wiggle() {
  stepper.setAcceleration(accel);
  stepper.setMaxSpeed(maxSpeed);
  for (int i = 0; i < 10; ++i) {
    stepper.move(0.1 * travel_steps * dir);
    stepper.runToPosition();
    dir *= -1;
  }
}

void flick() {
  stepper.setAcceleration(accel);
  stepper.setMaxSpeed(maxSpeed);
  stepper.move(0.25 * travel_steps * dir);
  stepper.runToPosition();
  dir *= -1;
}

void loop() {
  wiggle();
  delay(2000);
  flick();
  delay(500);
  flick();
  delay(3000);
}
};
