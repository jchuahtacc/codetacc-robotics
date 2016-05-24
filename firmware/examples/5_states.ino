// 5_states.ino
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

//UltrasonicSensor ultrasonic = UltrasonicSensor(2, 4);
double distance = 0;

Adafruit_MotorShield shield = Adafruit_MotorShield();
Adafruit_DCMotor *leftMotor = shield.getMotor(1);
Adafruit_DCMotor *rightMotor = shield.getMotor(2);

UltrasonicSensor ultrasonic = UltrasonicSensor(2, 4);

void (*state)();

/******************************************

Function prototypes;

******************************************/

int forward(String);
int left(String);
int right(String);
int stop(String);

void waiting();
void driving();

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

State functions

******************************************/

void waiting() {
  stop();
  distance = ultrasonic.readCm();
  if (distance > 150) {
    state = driving;
    Particle.publish("state", "driving");
  }
}

void driving() {
  forward();
  distance = ultrasonic.readCm();
  if (distance < 50) {
      state = waiting;
      Particle.publish("state", "waiting");
  }
}

/******************************************
void setup()

Runs once upon startup
******************************************/

void setup() {
  shield.begin();
  leftMotor->setSpeed(150);
  rightMotor->setSpeed(150);

  Particle.variable("distance", distance);

  state = waiting;
  Particle.publish("state", "waiting");
}

/******************************************
void loop()

Runs forever
******************************************/

void loop() {
  state();
}
