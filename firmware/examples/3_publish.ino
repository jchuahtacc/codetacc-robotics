// 3_publish.ino
//
// Example robotics code for CODE @ TACC
// Summer 2016 robotics curriculum, available at:
//
// https://github.com/CODE-at-TACC/summer-2016
//
// Copyright 2016, Texas Advanced Computing Center
// GNU GPLv3 License

/******************************************

Included libraries

******************************************/
#include "codetacc-robotics/codetacc-robotics.h"

/******************************************

Variables

******************************************/

UltrasonicSensor ultrasonic = UltrasonicSensor(2, 4);
double distance = 0;

/******************************************

Custom functions

******************************************/


/******************************************
void setup()

Runs once upon startup
******************************************/

void setup() {
  Particle.variable("distance", distance);
  Particle.publish("hello");
}

/******************************************
void loop()

Runs forever
******************************************/

void loop() {
  distance = ultrasonic.readCm();
  // Add "if" code here


  //
  delay(1000);
}
