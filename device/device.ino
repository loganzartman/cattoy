#include "worm.h"
#include "ribbon.h"
#include "pinout.h"

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

void loop() {
//  worm::loop();
  ribbon::loop();
}
