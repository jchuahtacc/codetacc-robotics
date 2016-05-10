// 4_handler.ino
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

/******************************************

Custom functions

******************************************/

void handler(const char *event, const char *data) {
  forward();
  delay(1000);
  stop();
}

/******************************************
void setup()

Runs once upon startup
******************************************/

void setup() {

}

/******************************************
void loop()

Runs forever
******************************************/

void loop() {

}
