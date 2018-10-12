#include <Keyboard.h>
int downPin = 5;
// basically our previous state
bool isDown = false;
void setup() {
  Keyboard.begin();
  pinMode(downPin, INPUT_PULLUP);
}

void loop() {
  // check if state changed
  // run event function
  // update state
  // delay for debounce
  if ((!isDown) && (digitalRead(downPin) == LOW)) {
    onPedalDown();
    isDown = true;
    delay(100);
  }
  if (isDown && (digitalRead(downPin) == HIGH)) {
    onPedalUp();
    isDown = false;
    delay(100);
  }
}

// Event handlers
//Do whatever you want to do when the pedal starts being pressed down
void onPedalDown() {
  Keyboard.press(KEY_ESC);
  Keyboard.release(KEY_ESC);
  Keyboard.print("i");
}

//Do whatever you want to do when the pedal is released
void onPedalUp() {
  Keyboard.press(KEY_ESC);
  Keyboard.release(KEY_ESC);
}
