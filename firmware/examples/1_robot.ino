// 1_robot.ino
//
// Example robotics code fro CODE @ TACC
// Summer 2016 robotics curriculum, available at:
//
// https://github.com/CODE-at-TACC/summer-2016
//
// Copyright 2016, Texas Advanced Computing Center
// GNU GPLv3 License

/******************************************

Included libraries

******************************************/
#include <codetacc-robotics.h>

/******************************************

Variables

******************************************/

Adafruit_MotorShield shield = Adafruit_MotorShield();
Adafruit_DCMotor *leftMotor = shield.getMotor(1);
Adafruit_DCMotor *rightMotor = shield.getMotor(2);

/******************************************

Custom functions

******************************************/

int forward(String params = "") {
  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);
  return 1;
}

int left(String params = "") {
  leftMotor->run(BACKWARD);
  rightMotor->run(FORWARD);
  return 1;
}

int right(String params = "") {
  leftMotor->run(FORWARD);
  rightMotor->run(BACKWARD);
  return 1;
}

int stop(String params = "") {
  leftMotor->run(RELEASE);
  rightMotor->run(RELEASE);
  return 1;
}


/******************************************
void setup()

Runs once upon startup
******************************************/

void setup() {
  shield.begin();
  leftMotor->setSpeed(150);
  rightMotor->setSpeed(150);
}

/******************************************
void loop()

Runs forever
******************************************/

void loop() {
  forward();
  delay(1000);
  stop();
  delay(1000);
  left();
  delay(1000);
  right();
  delay(1000);
}
