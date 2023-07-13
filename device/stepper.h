#pragma once
#include <AccelStepper.h>
#include "pinout.h"

const int travel_steps = 2000;
AccelStepper stepper(AccelStepper::DRIVER, PIN_STEPPER1_STEP, PIN_STEPPER1_DIR);
