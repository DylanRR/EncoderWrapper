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
  delay(1000); // Adjust the delay as needed
}