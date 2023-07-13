#pragma once
#include "stepper.h"

namespace worm {
const float SPEED_SNEAK = 80.0;
const float SPEED_SWING = 400.0;
const float SPEED_WIGGLE = 800.0;
const float ACCELERATION_SNEAK = 250.0;
const float ACCELERATION_SWING = 500.0;
const float ACCELERATION_WIGGLE = 1000.0;

void wiggle() {
  stepper.setMaxSpeed(SPEED_WIGGLE);
  stepper.setAcceleration(ACCELERATION_WIGGLE);
  int dir = 1;
  int intensity = random(80, 150);
  for (int i = random(7, 12); i > 0; --i) {
    stepper.move(intensity * dir);
    stepper.runToPosition();
    dir *= -1;
  }
}

void swing(int dir) {
  stepper.setMaxSpeed(SPEED_SWING);
  stepper.setAcceleration(ACCELERATION_SWING);
  stepper.move(random(500, 2000) * dir);
  stepper.runToPosition();
}

void sneak(int dir) {
  stepper.setMaxSpeed(SPEED_SNEAK);
  stepper.setAcceleration(ACCELERATION_SNEAK);
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
};
