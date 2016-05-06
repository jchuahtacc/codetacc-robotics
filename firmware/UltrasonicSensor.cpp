#include "codetacc-robotics/UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(int triggerPin, int echoPin) {
  trigger = triggerPin;
  echo = echoPin;
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

double UltrasonicSensor::readCm() {
  digitalWriteFast(trigger, HIGH);
  delayMicroseconds(10);
  digitalWriteFast(trigger, LOW);
  uint32_t duration = pulseIn(echo, HIGH);
  return duration / 29.0 / 2;
}
