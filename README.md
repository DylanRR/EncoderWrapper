
# EncoderWrapper Library

The **EncoderWrapper** library is an enhanced fork of the original Encoder library. It provides a simplified interface for working with rotary and linear position encoders, with additional functionality for speed tracking.

## Features

-**Wrapper Class**: Simplifies interaction with encoders by abstracting low-level details.

-**Speed Tracking**: Easily access the speed of the encoder for real-time applications.

- Fully compatible with the original Encoder library's functionality.
- Designed for rotary knobs, motor or shaft sensors, and other position sensors.

## Installation

1. Download the library from [GitHub](https://github.com/DylanRR/EncoderWrapper).
2. Add the library to your Arduino IDE:

   - Go to `Sketch` > `Include Library` > `Add .ZIP Library...`.
   - Select the downloaded `.zip` file.

## Usage

### Basic Example

```cpp
#include <Arduino.h>
#include <EncoderWrapper.h>

EncoderWrapper myEncoder(2, 3); // Replace with the actual pins you're using

void setup() {
    Serial.begin(9600);
    Serial.println("Encoder Test Started");
}

void loop() {
  float rpm = myEncoder.getRPM(100);
  int direction = (rpm > 0) ? 1 : (rpm < 0) ? -1 : 0; // Determine direction based on rpm

  Serial.print("Direction: ");
  Serial.print(direction);
  Serial.print(", RPM: ");
  Serial.println(rpm);
  delay(100); // Adjust the delay as needed
}
```
