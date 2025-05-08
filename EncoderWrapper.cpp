#include "EncoderWrapper.h"

// Constructor
EncoderWrapper::EncoderWrapper(uint8_t pinA, uint8_t pinB)
  : pinA(pinA),
    pinB(pinB),
    encoder(pinA, pinB),
    lastCount(0),
    lastTime(millis()),
    overflowDetected(false) {}


float EncoderWrapper::getRPM(int countsPerRevolution) {
  float speed = getSpeed();

  if (countsPerRevolution > 0) {
      return (speed * 60.0) / countsPerRevolution;
  } else {
      return 0;
  }
}

//Returns the speed of the encoder in counts per second
float EncoderWrapper::getSpeed() {
  unsigned long currentTime = millis();
  int32_t currentCount = getCount();

  unsigned long timeDiff = currentTime - lastTime;
  float speed = (timeDiff > 0) ? (currentCount - lastCount) * 1000.0 / timeDiff : 0; //1000.0 must be float to avoid integer division & floating-point promotion

  if (!overflowDetected) {
    lastCount = currentCount;
  }
  else {
    lastCount = 0; // Reset last count if overflow is detected
    overflowDetected = false; // Reset overflow flag
  }
  lastTime = millis(); // Recalling millis() to get the most accurate time possible
  return speed;
}

int32_t EncoderWrapper::getCount() {
  int32_t currentCount = encoder.read();

  // Check for overflow
  constexpr int32_t OVERFLOW_PADDING = 10000;
  if (abs(currentCount) > (INT32_MAX - OVERFLOW_PADDING)) {
      overflowDetected = true;
      encoder.write(0); // Reset the encoder count to 0
  } else {
      overflowDetected = false;
  }

  return currentCount;
}