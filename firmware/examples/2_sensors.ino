// 2_sensors.ino
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

Adafruit_TMP007 thermopile = Adafruit_TMP007();
double temperature = 0;

/******************************************

Custom functions

******************************************/


/******************************************
void setup()

Runs once upon startup
******************************************/

void setup() {
  thermopile.begin();
  Particle.variable("temperature", temperature);
}

/******************************************
void loop()

Runs forever
******************************************/

void loop() {
  temperature = thermopile.readObjTempC();
  delay(1000);
}
