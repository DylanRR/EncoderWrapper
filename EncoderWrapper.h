#ifndef ENCODERWRAPPER_H
#define ENCODERWRAPPER_H

#include <Arduino.h>
#include <Encoder.h>

constexpr int32_t OVERFLOW_PADDING = 10000;

class EncoderWrapper {
public:
  // Constructor
  EncoderWrapper(uint8_t pinA, uint8_t pinB);

  // Public methods
  float getSpeed();
  float getRPM(int countsPerRevolution);

private:
  uint8_t pinA;
  uint8_t pinB;
  volatile int32_t lastCount;
  volatile unsigned long lastTime;
  Encoder encoder;
  bool overflowDetected;

  int32_t getCount();
};

#endif // ENCODERWRAPPER_H