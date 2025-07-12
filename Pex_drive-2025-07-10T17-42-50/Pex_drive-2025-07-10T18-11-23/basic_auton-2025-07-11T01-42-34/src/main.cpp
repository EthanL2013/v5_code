/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\liu_b                                            */
/*    Created:      Thu Jul 10 2025                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Right                motor         2               
// Left                 motor         1               
// Intake               motor         5               
// Scoring              motor         3               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
    
void start(double distance) {
  Intake.spin(reverse, 200, rpm);
  Left.setVelocity(100, percent);
  Right.setVelocity(100, percent);

  double gearRatio = 1.0/1;
  double diameter = 4;
  double t = distance / (gearRatio * diameter * 3.14);
  Left.spinFor(forward, t, turns, false);
  Right.spinFor(forward, t, turns, false);
}

void turn_1(int turnDegree) {
  Left.setVelocity(100, percent);
  Right.setVelocity(100, percent);
  Left.spinFor(forward, turnDegree, degrees, false);
  Right.spinFor(reverse, turnDegree, degrees, false);
}

void turn_2(int turnDegree) {
  Left.setVelocity(100, percent);
  Right.setVelocity(100, percent);
  Left.spinFor(reverse, turnDegree, degrees, false);
  Right.spinFor(forward, turnDegree, degrees, false);
}

void end(double distance){
  Left.setVelocity(100, percent);
  Right.setVelocity(100,percent);

  double gearRatio = 1.0/1;
  double diameter = 4;
  double t = distance / (gearRatio * diameter * 3.14);
  Left.spinFor(reverse, t, turns, false);
  Right.spinFor(reverse, t, turns, false);
}

void score_1() {
  Scoring.setVelocity(100, percent);
  Scoring.spinFor(forward, 360, degrees);
}

void score_2() {
  Scoring.setVelocity(100, percent);
  Scoring.spin(forward);
  wait(5, sec);
  Scoring.stop();
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  wait(3, sec);
  start(50);
  wait(0, sec);
  score_1();
  score_1();
  wait(5, sec);
  end(24);
  wait(5, sec);
  turn_2(90);
  wait(5, sec);
  start(14);
  wait(5, sec);
  turn_2(90);
  wait(5, sec);
  start(14);
  wait(5, sec);
  score_2();
}
