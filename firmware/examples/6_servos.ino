// 6_servo.ino
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

Servo myServo;

Adafruit_MotorShield shield = Adafruit_MotorShield();
Adafruit_DCMotor *leftMotor = shield.getMotor(1);
Adafruit_DCMotor *rightMotor = shield.getMotor(2);

Adafruit_TMP007 thermopile = Adafruit_TMP007();
double hottestTemp = 0;
double hottestPosition = 0;

UltrasonicSensor ultrasonic = UltrasonicSensor(2, 4);
double distance = 0;

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
void scanning();

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

void scanning() {
  hottestTemp = 0;
  hottestPosition = 0;

  for (int position = 0; position < 180; position++) {
    myServo.write(position);
    double currentTemp = thermopile.readObjTempC();
    if (currentTemp > hottestTemp) {
      hottestPosition = position;
      hottestTemp = currentTemp;
    }
    delay(5);
  }

  for (int position = 180; position > 0; position--) {
    myServo.write(position);
    double currentTemp = thermopile.readObjTempC();
    if (currentTemp > hottestTemp) {
      hottestPosition = position;
      hottestTemp = currentTemp;
    }
    delay(5);
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

  thermopile.begin();
  Particle.variable("hottestTemp", hottestTemp);
  Particle.variable("hottestPosition", hottestPosition);

  myServo.attach(3);
  myServo.write(90);

  state = scanning;
  Particle.publish("state", "scanning");
}

/******************************************
void loop()

Runs forever
******************************************/

void loop() {
  state();
}
